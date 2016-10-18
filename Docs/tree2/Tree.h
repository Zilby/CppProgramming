#ifndef TREE2_TREE_H
#define TREE2_TREE_H

#include <iostream>
#include <vector>

namespace tree2 {

/**
 * A sortable tree class.  A tree has a label and
 * identifier and may have a list of child trees.  The
 * tree can only be constructed by reading it from an
 * input stream.  The sort method sorts the children of
 * every subtree by their labels.
 *
 * @author Ken Baclawski
 */
class Tree {
public:
  /**
   * Construct a tree from an input stream.  An
   * exception is thrown if the input is not a valid
   * tree.
   */
  Tree(/** The input stream that is being read. */
       std::istream& in);

  /**
   * Print this tree to an output stream.  The tree is
   * traversed and the labels are printed in
   * depth-first order.  The output of this method can
   * be used as input to the constructor.
   */
  void print(/** The output stream the tree will 
    be printed on. */ std::ostream& out) const;

  /**
   * Sort the tree.  For every subtree the children are
   * sorted reverse alphabetically by their labels.
   */
  void sort();

private:
  /** The label of this tree. */
  std::string label_;
  /** The depth of this tree. */
  int depth_ = 0;
  /** The subtrees of this tree. */
  std::vector<Tree> children_;
  /** The identifier of the next tree. */
  static int nextId_;
  /** The identifier of the tree. */
  int id_ = 0;

  /**
   * Recursively parse a tree from an input
   * stream.  This method throws an exception if the
   * end of data has been reached without finding a
   * word.
   */
  Tree(/** The label of the tree. */ const std::string& label,
       /** The depth of the tree. */ const int depth,
       /** The input stream for reading the subtrees. */ std::istream& in);

  /**
   * Read one word from the input stream.  This method
   * throws an exception if the end of data has been
   * reached without finding a word.
   *
   * @return The word that was extracted from the input stream.
   */
  static std::string readWord(/** The input stream. */ std::istream& in);
};

}

#endif
