#ifndef ROCKET2_ROCKETS_H
#define ROCKET2_ROCKETS_H

#include <algorithm>
#include <vector>
#include <tuple>
#include "Rocket.h"

namespace rocket2 {

/**
 * A list of rockets.  The list can be sorted
 * using various criteria.
 *
 * @author Ken Baclawski
 */
class Rockets {
public:
  /**
   * Add a rocket to the list.
   */
  void addRocket(/** The name of the rocket. */ 
		 const std::string& name,
		 /** The payload of the rocket. */
		 double payload,
		 /** The manufacturer of the rocket. */
		 const std::string& manufacturer);

  /**
   * Sort the list by name.
   */
  void sortByName();

  /**
   * Sort the list by payload.
   */
  void sortByPayload();

  /**
   * Sort the list by manufacturer.
   */
  void sortByManufacturer();

  /**
   * Show the list of rockets using an HTML table.
   * @return A string showing the list of all rockets.
   */
  std::string getHtmlTable() const;

  /**
   * Show the list of rockets by category using an HTML table.
   * This method sorts the rockets by category.
   * @return A string showing the categorized list of all rockets.
   */
  std::string getCategorizedHtmlTable();

private:
  /**
   * The list of rockets.
   */
  std::vector<Rocket> rockets_;
};

}

#endif
