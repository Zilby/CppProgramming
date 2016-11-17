#include "TaskFactory.h"
#include "Task.h"

using namespace std;
using namespace asst06;

TaskFactory::TaskFactory(const int& codes, const int& seed)
  noexcept: codes_(codes){
  // utilizes our seed
  srand(seed);
}

Task TaskFactory::getNextTask(bool flag) noexcept {
  // generates a new task using our seed and the given
  // number of codes. 
  Task t(rand() % codes_, flag);
  return t;
}
