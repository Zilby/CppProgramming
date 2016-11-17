#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Weighting.h"

using namespace std;
using namespace asst05;

void Weighting::addWeight(double weight) noexcept {
  weights_.push_back(weight);
}

vector<double> Weighting::getWeightedList(const vector<double>& list) const {
  if (list.size() != weights_.size()) {
    throw domain_error("blah");
  }
  vector<double> weightedList;
  for (unsigned int i = 0; i < list.size(); ++i) {
    weightedList.push_back(list.at(i) * weights_.at(i));
  }
  return weightedList;
}

double Weighting::getWeightedAverage(const vector<double>& list) const {
  vector<double> weightedList = getWeightedList(list);
  double sum = 0;
  for (const auto& element : weightedList) {
    sum += element;
  }
  return sum / weights_.size();
}

double Weighting::getTrimmedWeightedAverage(const vector<double>& list) const {
  if (weights_.size() < 3) {
    throw domain_error("blah");
  }

  vector<double> weightedList = getWeightedList(list);

  double max = weightedList.at(0);
  double min = weightedList.at(0);
  double sum = 0;
  for (unsigned int i = 0; i < weights_.size(); ++i) {
    if(weightedList.at(i) > max) {
      max = weightedList.at(i);
    }
    if(weightedList.at(i) < min) {
      min = weightedList.at(i);
    }
  }
  for (unsigned int i = 0; i < weights_.size(); ++i) {
    if(!((weightedList.at(i) == max)||(weightedList.at(i) == min))) {
      sum += weightedList.at(i);
    }
  }
  return sum / (weights_.size() - 2);
}
