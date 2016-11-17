#include "SharedMap.h"
#include "Task.h"

using namespace std;
using namespace asst06;

void SharedMap::map(const Task t) noexcept {

  // Lock the object.

  unique_lock<mutex> lock(lockableObject_);
    
  // We now have exclusive access to the map.
  // Insert the code and task into the map
    
  map_.insert({t.getCode(), t});

  // Release the lock.

  lock.unlock();

  // Notify a waiting thread that the map is
  // able to be accessed. 

  notifier_.notify_one();
}

Task SharedMap::unmap(const int code) noexcept {

  // Lock the object.

  unique_lock<mutex> lock(lockableObject_);
    
  // We now have exclusive access to the map.
  // Try to find a task with a matching code
    
  while(map_.find(code) == map_.end()) {
    // if no such task can be found, wait. 
    notifier_.wait(lock);
  }
  Task t = map_.find(code)->second;
  // remove the task
  map_.erase(map_.find(code));
  
  // Release the lock.

  lock.unlock();

  // Notify a waiting threads that the map is able to
  // be accessed again. 
  notifier_.notify_one();

  // return the task that was removed. 
  return t;
}

string SharedMap::showMap() noexcept {
  string output = "";
  
  // iterate through the map to add each instance
  // to the output string
  for(auto iter = map_.begin(); iter != map_.end(); ++iter){
    output += to_string((*iter).first) + " -> " +
      (*iter).second.toString() + "\n";
  }
  return output;
}
