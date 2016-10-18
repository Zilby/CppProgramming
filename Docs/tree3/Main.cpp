#include <iostream>
#include <stdexcept>
#include "Tree.h"
using namespace std;
using namespace tree3;

/**
 * @namespace tree3 Non-Recursive Tree Structure.
 * The tree structure is read from the standard
 * input, and then printed to the standard output.
 * In addition, all subtrees labeled with "B" are
 * printed.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the non-recursive tree structure.
 * Read a tree, sort it and print it.
 *
 * @return The status code.  Status is 0 for
 * normal termination and 1 for an error termination.
 */
int main() {

  // Catch any exceptions that might be thrown.

  try {

    // Create a default tree and print it.

    Tree tree1;
    tree1.print(cout);

    // Clear the tree and add some nodes.

    tree1.clear();
    tree1.addNode("another root", -4);
    tree1.addNode("a child", -3);
    tree1.addNode("another child", -3);
    tree1.print(cout);

    // Read a tree from the standard input.

    Tree tree2(cin);

    // Print the tree on the standard output.

    tree2.print(cout);

    // Print subtrees with label B.

    tree2.print(cout, "B");

    // This should throw an exception

    Tree tree3(cin);
  } catch (const exception& e) {

    // If an exception was thrown, print what it says.

    cerr << e.what() << endl;

    // Return an error status code.

    return 1;
  }

  // Return normal status.

  return 0;
}
