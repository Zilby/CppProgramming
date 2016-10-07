#include <iostream>
#include "Tablehtml.h"
using namespace std;
using namespace tables;

/**
 * @namespace Assignment3 This program takes in sets of 5 words and prints
 * an html table using these words. Any additional words outside a set will
 * be ignored. 
 *
 * @author Alexander Zilbersher
 */

/**
 * The main program for our task. 
 * @return the exit status. Normal status is 0. 
 */

int main() {
  
  // read in the input for our html table
  Tablehtml t(cin);

  // print out the output
  t.print(cout);
  
  // return normal status
  return 0;
}
