#include "Action.h"
#include "Task.h"

using namespace std;
using namespace asst06;

Action::Action(const int code, SharedMap& map, TaskFactory& f)
noexcept  : code_(code), map_(map), fact_(f) {}

void Action::operator()() noexcept {
  for(;;) {
    // Get a task from the shared map
    Task t = map_.unmap(code_);

    // If the task is a quit task then end the loop
    if(t.getFlag()) {
      break;
    } else {

      // Add a randomly generated task to the shared map
      map_.map(fact_.getNextTask());
    }
  }
}
