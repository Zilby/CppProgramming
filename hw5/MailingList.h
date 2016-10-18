#ifndef ASST05_MAILINGLIST_H
#define ASST05_MAILINGLIST_H

#include <string>
#include <vector>
#include "Person.h"

namespace asst05 {

/**
 * A mailing list class. This class is able to add new subscribers, 
 * find all the emails of a given person in the list, and return its name. 
 *
 * @author Alexander Zilbersher
 */


class MailingList {
public:
  /**
   * Construct a mailing list.
   */
  MailingList(/** The name of the list. */ 
	 const std::string& name) noexcept;
  
  /**
   * Gets the name of this mailing list
   * @return the name of this list
   */
  std::string getName() const noexcept;
  
  /**
   * Adds a subscriber email to this mailing list.  
   */
  void subscribe(/** The email to be added */
		 const std::string& e) noexcept;

  /**
   * Determines a vector of all the emails of the given person
   * and returns it. 
   * @return the person's emails. 
   */
  std::vector<std::string>
    getSubscriptionAddresses(/** The person whose emails you're
				 looking for */ Person& p) noexcept;

private:
  /** The list of email addresses */
  std::vector<std::string> emails_;
  /** The name of the mailing list */
  std::string name_;
  /** A flag to indicate if emails are sorted */
  bool sorted_;
};
}

#endif
