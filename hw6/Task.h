#ifndef ASST06_TASK_H
#define ASST06_TASK_H

#include <string>

namespace asst06 {

/**
 * A Task is a task to be performed by an action in a 
 * thread. It contains a code, as well as a flag indicating
 * whether it should continue or quit. 
 *
 * @author Alex Zilbersher
 */
class Task {
public:
  /**
   * construct a task with a code and a flag. The default
   * value for a flag is false. 
   */
  Task(/** the code to be initialized */
       const int& code,
       /** the value of the flag, defaulted to false */
       bool flag = false) noexcept;

  /** 
   * get this task's code. 
   *
   * @return this task's code.
   */ 
  int getCode() const noexcept;

  /** 
   * get this task's flag. 
   *
   * @return this task's flag.
   */ 
  int getFlag() const noexcept;

  /**
   * returns this task's value as a string. If
   * its flag is false, it will return 
   * 'Continue', if its flag is true it will 
   * return 'Quit' as well as its code in parens
   *
   * @return the string value of this code. 
   */
  std::string toString() const noexcept;

private:
  /** 
   * The task's code
   */
  int code_;

  /** 
   * The task's flag
   */
  bool flag_;
    
};

}

#endif
