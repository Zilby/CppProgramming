#include <vector>
#include <string>
#include <stdexcept>
#include "PositiveList.h"
using namespace std;
using namespace asst04;

double PositiveList::addPositive(double d) noexcept {
  // a boolean for whether it is a valid positive number
  bool valid = true;

  // iterates through the list to see if the number is already included
  for (double d2 : numbers_) {
    if (d == d2) {

      // if it has been included it will invalidate the number
      valid = false;
      break;
    }
  }
  
  // if the number is valid add it and return it 
  if (valid && d > 0.0) {
    numbers_.push_back(d);
    return d;
  } else {

    //otherwise return 0
    return 0.0;
  }
}

double PositiveList::removePositive(double d) noexcept {

  // iterate through the list to try to find the double
  for (auto i = numbers_.begin(); i != numbers_.end(); ++i) {
    if (*i == d) {

      // if it is found, erase and return it
      numbers_.erase(i);
      return d; 
    }
  }

  // otherwise return 0
  return 0.0;
}

double PositiveList::computeAverage() const {

  // throw an error for an empty list
  if(numbers_.size() == 0) {
    throw length_error("There are no positive numbers");
  }
  double total = 0.0;
  double nums = 0.0;

  // iterate through the list to sum up the total number
  // of positive numbers and their sum total
  for (const auto& e : numbers_) {
    total += e;
    ++nums;
  }

  // calculate and return the average
  return total / nums;
}
