#ifndef ASST06_SHAREDMAP_H
#define ASST06_SHAREDMAP_H

#include <string>
#include <map>
#include <mutex>
#include <condition_variable>
#include <stack>
#include "Task.h"

namespace asst06 {

/**
 * The shared map for our tasks and codes. 
 * This class maps codes to different tasks, as
 * well as having capabilities to unmap codes and
 * represent the mappings as a string. 
 *
 * @author Alex Zilbersher
 */
class SharedMap {
public:

  /**
   * Maps a task to its code in our multimap
   */
  void map(/** the task to be mapped*/
	   const Task t) noexcept;

  /**
   * unmaps the first task found for a given code
   * if no code is found, it will wait. 
   *
   * @return the task that has been removed from 
   * the multimap
   */
  Task unmap(/** the code used to find a matchin task*/
	     const int code) noexcept;

  /**
   * Returns our multimap as a string showing each pairing
   * of code to task eg: 1 -> Continue(1)
   *
   * @return this map represented as a string
   */
  std::string showMap() noexcept;
  
private:

  /**
   * The map of codes and tasks
   */
  std::multimap<int, Task> map_;

  /**
   * The lockable object used for setting locks.
   */
  std::mutex lockableObject_;

  /**
   * The notifier for our design pattern.
   */
  std::condition_variable notifier_;

};

}

#endif
