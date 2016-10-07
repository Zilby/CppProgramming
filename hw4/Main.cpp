#include <iostream>
#include "PositiveList.h"
using namespace std;
using namespace asst04;

/**
 * @namespace asst04 This program tests the positive list class
 * by testing its functions addPositive, removePositive, and computeAverage. 
 *
 * @author Alexander Zilbersher
 */

/**
 * The main program for our task. 
 * @return the exit status. Normal status is 0. If there is an exception it
 * will return a status of 1. 
 */

int main() {
  
  // generate our list
  PositiveList p;

  // attempt to add a mix of positive and negative numbers
  cout << p.addPositive(5.4) << endl;
  cout << p.addPositive(-5.4) << endl;
  cout << p.addPositive(11.9) << endl;
  cout << p.addPositive(11.9) << endl;
  cout << p.addPositive(1.2) << endl;
  cout << p.addPositive(-8.3) << endl;

  // compute the average of said numbers
  cout << p.computeAverage() << endl;

  // attempt to remove a mix of positive, negative and
  // non-existent numbers
  cout << p.removePositive(5.4) << endl;
  cout << p.removePositive(-5.4) << endl;
  cout << p.removePositive(11.9) << endl;
  cout << p.removePositive(1.3) << endl;
  cout << p.removePositive(1.2) << endl;

  // tries to compute the average again
  try {
    cout << p.computeAverage();
  }  catch (const exception& e) {

    // If an exception was thrown, print what it says.

    cerr << e.what() << endl;

    // Return an error status code.

    return 1;
  }
  
  // return normal status
  return 0;
}
