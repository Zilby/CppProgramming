#include <iostream>
#include "Person.h"
#include "MailingList.h"
using namespace std;
using namespace asst05;

/**
 * @namespace asst05 This program tests the MailingList and Person classes. 
 * It will initialize and fill out several mailing lists and people and then
 * print the resultant matrices to cout.  
 *
 * @author Alexander Zilbersher
 */

/**
 * The main program for our task. 
 * @return the exit status. Normal status is 0. 
 */

int main() {

  //initializes mailing lists
  MailingList d("Dracula");
  d.subscribe("erzebet@example.org");
  d.subscribe("cork@nobility.org");

  MailingList i("Irish Nobility");
  i.subscribe("boyle@example.org");
  i.subscribe("lambart@example.org");
  i.subscribe("digby@example.org");
  i.subscribe("guinness@example.org");

  MailingList h("Hungarian Nobility");
  h.subscribe("ecsed@nobility.org");

  //initializes people
  Person j("John Boyle", "555-1000", "boyle@example.org");
  j.addEmail("cork@nobility.org");

  Person r("Robert Lambart", "555-1001");
  r.addEmail("lambart@example.org");
  r.addEmail("cavan@nobility.org");

  Person e("Edward Digby", "555-1002");
  e.addEmail("digby@example.org");
  e.addEmail("digby@nobility.org");

  Person g("Gwendolen Guinness", "555-1003");
  g.addEmail("guinness@example.org");
  g.addEmail("iveagh@nobility.org");

  Person b("Bathory Erzebet", "555-1004");
  b.addEmail("erzebet@example.org");
  b.addEmail("ecsed@nobility.org");

  Person a("Antoinette Louise Alberte Suzanne Grimaldi", "555-1005");
  a.addEmail("grimaldi@example.org");
  a.addEmail("massy@nobility.org"); 

  // constructs vectors of lists and people
  vector<MailingList> lists = {d, i, h};
  vector<Person> people = {j, r, e, g, b, a};

  // starts building the html output
  string output = "<table border='1'>\n<tr><th>Person</th><th>Phone Number</th>";

  // adds the header of lists to the output
  for(MailingList m : lists) {
    output += "<th>" + m.getName() + "</th>";
  }

  output += "</tr>\n";

  // adds the people to the html list
  for(Person p : people) {
    output += "<tr><td>" + p.getName() + "</td><td>" + p.getPhoneNumber() + "</td>";
    for(MailingList m : lists) {
      output += "<td>";
      if(m.getSubscriptionAddresses(p).size() > 0) {
	output += "yes";
      } else {
	output += "no";
      }
      output += "</td>";
    }
    output += "</tr>\n";
  }

  output += "</table>\n";
  
  cout << output;
  
  // return normal status
  return 0;
}
