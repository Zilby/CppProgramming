#include <iostream>
#include <stdexcept>
#include "Tree.h"
using namespace std;
using namespace tree2;

/**
 * \namespace tree2 Sortable Tree Structure.  The tree structure is read from
 * the standard input, sorted, and then printed to the standard output.  This
 * program is not the most efficient way to construct a tree.  The purpose of
 * the program is to introduce object-oriented programming techniques.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the sortable tree structure.  Read a tree, sort it and print it.
 * @return The status code.  Status is 0 for normal termination and 1 for incorrect input.
 */
int main() {

  // Catch any exceptions that might be thrown.

  try {

    // Read the tree.

    Tree tree(cin);

    // Sort the tree.

    tree.sort();

    // Print the tree.

    tree.print(cout);
  } catch (const exception& e) {

    // If an exception was thrown, print what it says.

    cerr << e.what() << endl;

    // Return an error status code.

    return 1;
  }

  // Return normal status.

  return 0;
}
