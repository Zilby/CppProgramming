#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Tree.h"
#include "Node.h"
using namespace std;
using namespace tree3;

Tree::Tree() {

  // The default tree has just one root node.

  nodes_.push_back(Node("root", 0));

  // Set the limits of the nodes in the tree.

  setNodeLimits();
}

Tree::Tree(istream& in) {

  // Read the tree.

  readTree(in);

  // Set the limits of the nodes in the tree.

  setNodeLimits();
}

void Tree::clear() {
  nodes_.clear();
}

void Tree::readTree(istream& in) {

  // The main idea behind the non-recursive
  // algorithm for reading a tree is that each
  // left parenthesis increases the depth by 1 and
  // each right parenthesis decreases the depth by
  // 1.  The depth is initially -1, so that the
  // root node has depth 0.  When the depth
  // returns to -1, the parentheses balance and
  // the tree is complete.

  int depth = -1;

  // The expression for the tree must begin with a
  // left parenthesis.  Empty trees are not allowed.

  string leftParenthesis = readWord(in);
  if (leftParenthesis != "(") {
    throw domain_error("Invalid expression");
  }
  ++depth;

  // Loop over the nodes.  The loop invariant is a
  // left parenthesis has just been read, and a
  // label is expected.

  for (;;) {

    // The left parenthesis has already been read.
    // It must be followed by a label.

    string label = readWord(in);
    if (label == "(" || label == ")") {
      throw domain_error("Invalid expression");
    }

    // A label could consist of several words.
    // This loop could be omitted if labels are
    // required to be words without any
    // whitespace.

    string word;
    for (;;) {
      word = readWord(in);
      if (word == "(" || word == ")") {
	break;
      }
      label = label + " " + word;
    }

    // Add a new node with the label and depth

    nodes_.push_back(Node(label, depth));

    // At this point the word is a parenthesis.
    // There could be any number of left
    // parentheses before a right parenthesis.
    // The loop invariant: the word is a
    // parenthesis.

    while (word == ")") {

      // Every right parenthesis decreases the
      // depth by 1.

      --depth;

      // If the depth is -1, the tree is complete.
      
      if (depth == -1) {
	return;
      }

      // Read the next word.  The if statement
      // guarantees the loop invariant that the
      // word is a parenthesis.

      word = readWord(in);
      if (word != "(" && word != ")") {

	// No other word is allowed

	throw domain_error("Invalid expression");
      }
    }

    // By the loop invariant the word is a
    // parenthesis.  By the while condition, when
    // the loop ends the word is a right
    // parenthesis.  Since a right parenthesis has
    // been found, the depth increases by 1.

    ++depth;
  }
}

void Tree::setNodeLimits() {

  // This must be done whenever the tree has been
  // modified because the iterators include
  // information about the whole container.  In
  // particular, the end iterator will change when
  // another node is added to the tree.

  for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    iter->setLimits(iter, nodes_.end());
  }
}

void Tree::addNode(const string& label, int depth) {
  if (nodes_.empty()) {

    // If the tree is empty, then the new node is the root.

    nodes_.push_back(Node(label, depth));
    setNodeLimits();
  } else {

    // If the tree is nonempty, then the depth
    // must be within limits for the depth to be
    // meaningful for the new node.

    if (depth <= nodes_.front().getDepth()) {
      throw domain_error("Attempt to add another root node to a tree");
    } else if (depth > nodes_.back().getDepth() + 1) {
      throw domain_error("Attempt to add a node with too great a depth");
    } else {

      // If the depth is okay, then add the new
      // node and set the node limits.

      nodes_.push_back(Node(label, depth));
      setNodeLimits();
    }
  }
}

void Tree::print(ostream& out) const {
  if (!nodes_.empty()) {
    nodes_.front().print(out);
    out << endl;
  }
}

void Tree::print(ostream& out, const string& label) const {
  for (vector<Node>::const_iterator iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    if (iter->getLabel() == label) {
      iter->print(out);
      out << endl;
    }
  }
  /* Alternative iteration syntax
  for (const Node& node : nodes_) {
    if (node.getLabel() == label) {
      node.print(out);
      out << endl;
    }
  }
  */
}

string Tree::readWord(istream& in) {

  // Check that there is something to read.

  if (!in) {
    throw domain_error("Unexpected end of input");
  }

  // Read the next word and return it.

  string word;
  in >> word;
  return word;
}
