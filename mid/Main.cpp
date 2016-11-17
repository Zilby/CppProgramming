#include "Offset.h"
#include "Weighting.h"

#include <iostream>
#include <vector>
using namespace std;
using namespace asst05;

/**
 * @namespace asst05 This program tests the MailingList and Person classes. 
 * It will initialize and fill out several mailing lists and people and then
 * print the resultant matrices to cout.  
 *
 * @author Alexander Zilbersher
 */

/**
 * The main program for our task. 
 * @return the exit status. Normal status is 0. 
 */

int main() {
  Offset o;
  o.addNumber(1, 2);
  o.addNumber(3, -2);
  o.addNumber(6, 5);
  
  vector<double> v =  o.getShiftedDifferenceList(1);
  for(unsigned int i = 0; i < v.size(); ++i) {
    cout << v.at(i) << endl;
  }
  cout << o.getAverage(1) << endl;  

  Weighting w;
  w.addWeight(1);
  w.addWeight(3);
  w.addWeight(6);
  cout << "next" << endl;
  cout << w.getWeightedAverage({5, 1, 2}) << endl;
  cout << w.getTrimmedWeightedAverage({5, 1, 2}) << endl;
  return 0;
}
