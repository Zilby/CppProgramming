#ifndef ROCKET_ROCKETS_H
#define ROCKET_ROCKETS_H

#include <algorithm>
#include <vector>
#include <tuple>
#include "Rocket.h"

namespace rocket {

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
   * Test whether two rocket lists are the same.
   * @return Whether the rockets have the same
   * rockets in the same order.
   */
  bool operator==(/** The other rocket list with which to test. */
		  const Rockets& other) const;

  /**
   * Test whether two rocket lists have the same
   * rockets.
   * @return Whether the rockets have the same
   * rockets possibly in a different order.
   */
  bool isSameSet(/** The other rocket list with which to test. */
		 const Rockets& other) const;

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

  /**
   * The type of a triple consisting of a category
   * and two iterators.  This is used for the
   * elements returned by partitionByCategory.
   */
  typedef std::tuple
  <std::string, 
   std::vector<Rocket>::const_iterator, 
   std::vector<Rocket>::const_iterator> Triple;

  /**
   * Partition the list by category.
   * @return a vector of triples each of which has
   * a category and iterators for the beginning
   * and end of each subsequence.
   */
  std::vector<Triple> partitionByCategory();
};

}

#endif
