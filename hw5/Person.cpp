#include <vector>
#include <string>
#include <algorithm>
#include "Person.h"
using namespace std;
using namespace asst05;

Person::Person(const string& name,
	       const string& number) noexcept : name_(name),
  number_(number),
  sorted_(true) {}

Person::Person(const string& name, const string& number,
	       const string& email) noexcept : name_(name), number_(number),
  sorted_(true) {
  addEmail(email);
}

vector<string> Person::getEmailAddresses() noexcept {
  // sorts the emails if unsorted
  if(!sorted_) {
    sort(emails_.begin(), emails_.end());
    sorted_ = true;
  }
  return emails_;
}

string Person::getName() const noexcept {
  return name_;
}

string Person::getPhoneNumber() const noexcept {
  return number_;
}

void Person::addEmail(const string& e) noexcept {
  // adds the email
  emails_.push_back(e);

  // flags that the emails are no longer sorted
  sorted_ = false;
}
