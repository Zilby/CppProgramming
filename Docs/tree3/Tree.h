#ifndef TREE3_TREE_H
#define TREE3_TREE_H

#include <iostream>
#include <vector>
#include "Node.h"

namespace tree3 {

/**
 * A nonrecursive tree structure.  A tree can be
 * constructed by reading it from an input stream
 * or programmatically.  A default tree is has
 * just one root node.  The format for a tree is a
 * lisp-style expression.
 *
 * @author Ken Baclawski
 */
class Tree {
public:
  /**
   * Construct a default tree.
   */
  Tree();

  /**
   * Construct a tree from an input stream.  This
   * is done non-recursively.  An exception is
   * thrown if the input is not a valid tree.
   */
  Tree(/** The input stream that is being read. */
       std::istream& in);

  /**
   * Add another node to the tree.
   *
   * @throw domain_error if the depth is not
   * compatible with adding it to the tree.
   */
  void addNode(/** The label of the new node. */
	       const std::string& label, 
	       /** The depth of the new node. */
	       int depth);

  /**
   * Clear the tree, making it empty.
   */
  void clear();

  /**
   * Print this tree to an output stream.  This is
   * done non-recursively and the output can be
   * used as input to the constructor
   */
  void print(/** The output stream the tree will 
    be printed on. */ std::ostream& out) const;

  /**
   * Print all of the subtrees with a specified
   * label to an output stream.
   */
  void print(/** The output stream the subtrees will be printed on. */
	     std::ostream& out,
	     /** The label of the subtrees to be printed. */
	     const std::string& label) const;

private:
  /**
   * The nodes in the tree in depth-first order.
   */
  std::vector<Node> nodes_;

  /**
   * Non-recursively read a balanced list-style
   * expression for a tree.
   */
  void readTree(/** The input stream that is being read. */
		std::istream& in);

  /**
   * Set the node limits.
   */
  void setNodeLimits();

  /**
   * Read one word from the input stream.  This
   * method throws an exception if the end of data
   * has been reached without finding a word.
   *
   * @return The word that was extracted from the
   * input stream.
   */
  static std::string readWord(/** The input stream. */ 
			      std::istream& in);
};

}

#endif
