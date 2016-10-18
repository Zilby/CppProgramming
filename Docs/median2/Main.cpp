#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * \namespace median2 Median number task.  This program reads numbers from the
 * standard input and computes the median of the numbers.  The median number is
 * the middle number when the numbers are in sorted order.  If there is an odd
 * number of numbers, then there is exactly one median number.  If the number
 * of numbers is even (and at least 2), then the median is the average of the
 * two middle numbers.  If no numbers are entered, then print that no numbers
 * were entered and return status code 1.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the median number task.
 * @return The exit status: 0 if there is at least one number in the input and 1
 * otherwise.
 *
 */
int main() {

  // Read all input numbers into a vector.

  double number;
  vector<double> numbers;
  while (cin >> number) {
    numbers.push_back(number);
  }

  // Check for the possibility of no numbers.

  if (numbers.empty()) {
    cout << "No numbers were entered." << endl;

    // Status code is 1.

    return 1;
  }

  // Sort the set of numbers.

  sort(numbers.begin(), numbers.end());

  // The result will depend on whether the number of numbers is even or odd.

  const auto middle = numbers.size() / 2;
  const double median = ((numbers.size() % 2) == 0)?
    0.5 * (numbers.at(middle - 1) + numbers.at(middle)) : 
    numbers.at(middle);

  // Change the precision and print the median.

  const auto originalPrecision = cout.precision(3);
  cout << "Median is " << median << endl;
  cout.precision(originalPrecision);

  // Status code is 0.

  return 0;
}
