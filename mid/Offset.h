#ifndef ASST05_OFFSET_H
#define ASST05_OFFSET_H

#include <vector>

namespace asst05 {

class Offset {
  
public:
  void addNumber(const double a, const double b) noexcept;

  std::vector<double> getShiftedDifferenceList(unsigned int shiftAmount) const;

  double getAverage(unsigned int shiftAmount) const;

private:

  std::vector<double> list1_;
  std::vector<double> list2_;
  
};
}

#endif
