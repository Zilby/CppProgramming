#include "Task.h"

using namespace std;
using namespace asst06;

Task::Task(const int& code, bool flag)
noexcept : code_(code), flag_(flag) {}

int Task::getCode() const noexcept {
  return code_;
}

int Task::getFlag() const noexcept {
  return flag_;
}
  
string Task::toString() const noexcept {
  if (flag_) {

    // returns quit if the flag is true
    return "Quit(" + to_string(code_) + ")";
  } else {

    // returns continue if the flag is false
    return "Continue(" + to_string(code_) + ")";
  }
}
