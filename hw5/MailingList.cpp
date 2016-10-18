#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "MailingList.h"
#include "Person.h"
using namespace std;
using namespace asst05;

MailingList::MailingList(const string& n) noexcept : name_(n) {}

void MailingList::subscribe(const string& e) noexcept{
  emails_.push_back(e);
  
  // flags that the emails are no longer sorted
  sorted_ = false;
}

vector<string> MailingList::getSubscriptionAddresses(Person& p) noexcept{
  // sorts the emails if unsorted
  if(!sorted_) {
    sort(emails_.begin(), emails_.end());
    sorted_ = true;
  }

  //gets the person's emails
  vector<string> pemails = p.getEmailAddresses();
  
  //constructs the vector of this person's emails in this mailing list
  vector<string> results;
  set_intersection(emails_.begin(), emails_.end(),
		   pemails.begin(), pemails.end(),
		   back_inserter(results));
  return results;
}

string MailingList::getName() const noexcept{
  return name_;
}

