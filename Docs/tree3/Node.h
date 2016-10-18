#ifndef TREE3_NODE_H
#define TREE3_NODE_H

#include <iostream>
#include <list>

namespace tree3 {

/**
 * A node of a tree.  Rather than maintain a collection of child node, each
 * node has parent node iterator.
 *
 * @author Ken Baclawski
 */
class Node {
public:
  /**
   * Use the generated default constructor.
   */
  Node() = default;

  /**
   * Construct a node and add it to a vector of nodes.
   */
  Node(/** The node label. */ const std::string& label,
       /** The depth of the node. */ int depth);

  /**
   * Set the limits of the subtree at this node
   * within all nodes in the tree.  Setting the
   * limits validates the node.
   */
  void setLimits(/** The beginning of the subtree. */
		 const std::vector<Node>::iterator& begin,
		 /** The end of the entire tree. */
		 const std::vector<Node>::iterator& end);

  /**
   * The label of a node.
   * @return The node label.
   */
  std::string getLabel() const;

  /**
   * The depth of a node.
   * @return The node depth.
   */
  int getDepth() const;

  /**
   * Print this node and its subtrees to an output
   * stream.  No recursion is required.  The
   * output is in Lisp format.
   */
  void print(/** The output stream the node will 
		 be printed on. */ std::ostream& out) const;

  /** Determine whether this node is valid. */
  bool isValid() const;

  /** Invalidate the node. */
  void invalidate();

private:
  /** The label of this node. */
  const std::string label_;
  /** The depth of this node. */
  const int depth_ = 0;
  /** The start of this subtree. */
  std::vector<Node>::iterator begin_;
  /** The end of the entire tree. */
  std::vector<Node>::iterator end_;
  /** Whether the node is valid. */
  bool valid_ = false;
};

}

#endif
