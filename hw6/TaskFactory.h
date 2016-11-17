#ifndef ASST06_TASKFACTORY_H
#define ASST06_TASKFACTORY_H

#include "Task.h"

namespace asst06 {

/**
 * A TaskFactory is a generator for the Task class. 
 * It takes in a number of codes and a seed to generate
 * random tasks. 
 *
 * @author Alex Zilbersher
 */
class TaskFactory {
public:

  /**
   * Construct a TaskFactory with a given number of codes
   * and seed for code numbers. 
   */
  TaskFactory(/** the number of codes*/
	      const int& codes,
	      /** the seed for code numbers*/
	      const int& seed) noexcept;

  /**
   * Makes a new randomly generated task. The flag is 
   * specified as a parameter, but will default to false. 
   *
   * @return the new task
   */
  Task getNextTask(/** the flag for the new task*/
		   bool flag = false) noexcept;

private:

  /**
   * the number of different codes that can be generated
   */
  int codes_;
};

}

#endif
