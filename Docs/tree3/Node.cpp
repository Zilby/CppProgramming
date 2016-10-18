#include <vector>
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;
using namespace tree3;

Node::Node(const string& label, int depth) : label_(label), depth_(depth) {}

void Node::setLimits(const vector<Node>::iterator& begin,
		     const vector<Node>::iterator& end) {
  begin_ = begin;
  end_ = end;
  valid_ = true;
}

bool Node::isValid() const {
  return valid_;
}

void Node::invalidate() {
  valid_ = false;
}

string Node::getLabel() const {
  return label_;
}

int Node::getDepth() const {
  return depth_;
}

void Node::print(ostream& out) const {

  // Check that begin_ and end_ are valid

  if (!isValid()) {
    throw domain_error("Attempt to print an invalid tree");
  }

  // Print the nodes until the the depth returns
  // to the the initial value

  int depth = depth_ - 1;
  for (auto iter = begin_;; ++iter) {

    // Close any open expressions

    while (depth >= iter->depth_) {
      out << " )";
      --depth;

      // Return if the whole expression is now closed

      if (depth < depth_) {
	return;
      }
    }

    // Open any new expressions to make the depth
    // equal to the depth of the node.

    while (depth < iter->depth_) {
      out << " (";
      ++depth;
    }

    // The depth is now equal to iter->depth_

    out << " " << iter->getLabel();

    // If the end has been reached, then close all
    // parentheses

    if (iter + 1 == end_) {
      while (depth >= depth_) {
	out << " )";
	--depth;
      }
      return;
    }
  }
}
