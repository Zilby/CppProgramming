#ifndef ASST06_ACTION_H
#define ASST06_ACTION_H

#include "SharedMap.h"
#include "TaskFactory.h"

namespace asst06 {

/**
 * An action object for a thread.  An action
 * object specifies the execution code and
 * associated data for a thread.
 *
 * @author Alex Zilbersher
 */
  
class Action {
public:
  /**
   * Construct an action object.
   */
  Action(/** The code of this action. */
	 const int code,
	 /** The map of this action. */
	 SharedMap& map,
	 /** The task factory for this action. */
	 TaskFactory& f) noexcept;

  /**
   * The procedure that this action runs. It adds a
   * new random task to the multimap for every task
   * with its code until it reaches a quit task
   */
  void operator()() noexcept;

private:
  /** 
   * The code of this action. 
   */
  const int code_;

  /** 
   * The map of this action. 
   */
  SharedMap& map_;

  /** 
   * The task factory of this action. 
   */
  TaskFactory& fact_;
};

}

#endif
