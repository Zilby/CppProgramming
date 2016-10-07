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
   * Add a positive number to the list and returns it. 
   * Any duplicate or negative numbers will be ignored, 
   * and the function will return 0.0. 
   */
  double addPositive(/** The double to be added */
		   double d);

  /**
   * Removes a positive number from the list and returns 
   * it. If it is not found the function will return 0.0. 
   */
  double removePositive(/** The double to be removed */
		      double d);

  /**
   * Computes the average of all the doubles in the list and
   * returns it. If no doubles are in the list it will throw 
   * an error stating that 'There are no positive numbers'. 
   */
  double computeAverage() const;

private:
  /** The vector of positive numbers */
  std::vector<double> numbers_;
};
}

#endif
