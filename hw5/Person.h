#ifndef ASST05_PERSON_H
#define ASST05_PERSON_H

#include <vector>
#include <string>

namespace asst05 {

/**
 * A person class. A person has a name, number and list of emails, 
 * and has a getter for each. A person may also add an email (including
 * duplicates). 
 *
 * @author Alexander Zilbersher
 */


class Person {
public:
  /**
   * Construct a person.
   */
  Person(/** The name of the person. */ 
	 const std::string& name,
	 /** The phone number of the person. */
	 const std::string& number) noexcept;

  /**
   * Construct a person with an email.
   */
  Person(/** The name of the person. */ 
	 const std::string& name,
	 /** The phone number of the person. */
	 const std::string& number,
	 /** The email of the person. */
	 const std::string& email) noexcept;
  
  /**
   * Gets the name of this person and returns it. 
   * @return the name of this person.
   */
  std::string getName() const noexcept;

  /**
   * Gets the number of this person and returns it.  
   * @return the phone number of this person.
   */
  std::string getPhoneNumber() const noexcept;

  /**
   * Gets the emails of this person and returns it.  
   * @return the emails of this person. 
   */
  std::vector<std::string> getEmailAddresses() noexcept;

  /**
   * Adds an email to the email list. 
   */
  void addEmail(const std::string& e) noexcept;

private:
  /** The person's name */
  std::string name_;
  /** The person's phone number */
  std::string number_;
  /** The vector of email addresses */
  std::vector<std::string> emails_;
  /** A flag to indicate if emails are sorted */
  bool sorted_;
  
};
}

#endif
