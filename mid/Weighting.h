#ifndef ASST05_WEIGHTING_H
#define ASST05_WEIGHTING_H

#include <vector>

namespace asst05 {

class Weighting {
  
public:
  void addWeight(double weight) noexcept;

  std::vector<double> getWeightedList(const std::vector<double>& list) const;

  double getWeightedAverage(const std::vector<double>& list) const;

  double getTrimmedWeightedAverage(const std::vector<double>& list) const;
  

private:

  std::vector<double> weights_;
  
};
}

#endif
