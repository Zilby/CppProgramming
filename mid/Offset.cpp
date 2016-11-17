#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Offset.h"

using namespace std;
using namespace asst05;

void Offset::addNumber(const double a, const double b) noexcept {
  list1_.push_back(a);
  list2_.push_back(b);
}

vector<double> Offset::getShiftedDifferenceList(unsigned int shiftAmount) const {
  if (shiftAmount >= list1_.size()) {
    throw domain_error("The shift amount " + to_string(shiftAmount) +
		       " is too large for the lists which have size " +
		       to_string(list1_.size()));
  }

  vector<double> shiftedDifferenceList;

  for(unsigned int i=0; shiftAmount + i < list2_.size(); ++i) {
    shiftedDifferenceList.push_back(list1_.at(i+shiftAmount) - list2_.at(i));
  }
  return shiftedDifferenceList;
}

double Offset::getAverage(unsigned int shiftAmount) const {
  vector<double> shiftedDifferenceList = getShiftedDifferenceList(shiftAmount);
  double sum = accumulate(shiftedDifferenceList.begin(), shiftedDifferenceList.end(), 0.0);
  return sum / shiftedDifferenceList.size();
}
