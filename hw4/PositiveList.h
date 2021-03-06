#ifndef ASST04_POSITIVELIST_H
#define ASST04_POSITIVELIST_H

#include <vector>

namespace asst04 {

/**
 * A positive list class. This class is able to add numbers,
 * remove numbers and calculate the numbers' average. 
 *
 * @author Alexander Zilbersher
 */


class PositiveList {
public:
  /**
   * Add a positive number to the list 
   * Any duplicate or negative numbers will be ignored
   * @return either the number if it is added, or 0.0 
   * if it is ignored
   */
  double addPositive(/** The double to be added */
		   double d) noexcept;

  /**
   * Removes a positive number from the list. 
   * If it is not found it will be ignored.
   * @return either the number removed or 0.0 if it is 
   * ignored. 
   */
  double removePositive(/** The double to be removed */
		      double d) noexcept;

  /**
   * Computes the average of all the doubles in the list and
   * returns it. If no doubles are in the list it will throw 
   * an error stating that 'There are no positive numbers'. 
   * @return the average of the numbers in the list. 
   */
  double computeAverage() const;

private:
  /** The vector of positive numbers */
  std::vector<double> numbers_;
};
}

#endif
