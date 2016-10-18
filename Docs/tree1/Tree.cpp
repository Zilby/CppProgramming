#include <vector>
#include <iostream>
#include <stdexcept>
#include "Tree.h"
using namespace std;
using namespace tree1;

Tree::Tree(istream& in) : Tree(readWord(in), 0, in) {}

Tree::Tree(const string& label, const int depth, istream& in) : label_(label), depth_(depth) {

  // The list of children must begin with a left bracket.

  const string bracket = readWord(in);
  if (bracket != "[") {
    throw domain_error("Incorrect tree format: list does not start with a left bracket");
  }

  // Read the subtrees until a right bracket.

  for(;;) {
    const string word = readWord(in);

    // If the word is a right bracket, then the tree is complete.

    if (word == "]") {
      return;
    }

    // Otherwise, construct a tree and add it to the children.

    children_.push_back(Tree(word, depth_ + 1, in));
  }
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

void Tree::print(ostream& out) const {

  // The indentation is twice the depth of the tree.

  const string indentation(2 * depth_, ' ');

  // Indent the label and open the child list with a left bracket.

  out << indentation << label_ << " [";

  // If there are no children, then end the list on the same line.

  if (children_.empty()) {
    out << " ]" << endl;
  } else {

    // If there are children, then list them on separate lines.

    out << endl;

    // Explore the tree recursively using depth-first search.

    for (const Tree& child : children_) {
      child.print(out);
    }

    // Close the list with an indented right bracket.

    out << indentation << "]" << endl;
  }
}
