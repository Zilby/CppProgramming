#ifndef TREE1_TREE_H
#define TREE1_TREE_H

#include <iostream>
#include <vector>

namespace tree1 {

/**
 * A simple tree class.  A tree has a label and a list of child trees.  The
 * tree can only be constructed by reading it from an input stream.  This class
 * is not the most efficient way to construct a tree.  The purpose of the class
 * is to introduce object-oriented programming techniques.
 *
 * @author Ken Baclawski
 */
class Tree {
public:
  /**
   * Construct a tree by parsing an input stream.  
   * An exception is thrown if the input is
   * not a valid tree.
   */
  Tree(/** The input stream that specifies
           the tree. */ std::istream& in);

  /**
   * Print this tree on an output stream.
   * The tree is traversed and the labels
   * are printed in depth-first order.  
   * The output of this method can be used
   * as input to the constructor.
   */
  void print(/** The output stream the tree will
     be printed on. */ std::ostream& out) const;

private:
  /** The label of this tree. */
  const std::string label_;
  /** The depth of this tree. */
  const int depth_ = 0;
  /** The subtrees of this tree. */
  std::vector<Tree> children_;

  /**
   * Recursively parse a tree from 
   * an input stream.  This method throws
   * an exception if the end of data has 
   * been reached without finding a word.
   */
  Tree(/** The label of the tree. */ 
           const std::string& label,
       /** The depth of the tree. */ const int depth,
       /** The input stream for reading 
           the subtrees. */ std::istream& in);

  /**
   * Read one word from the input stream.  
   * This method throws an exception if
   * the end of data has been reached 
   * without finding a word.
   *
   * @return The word that was extracted 
   * from the input stream.
   */
  static std::string readWord(
    /** The input stream. */ std::istream& in);
};

}

#endif
