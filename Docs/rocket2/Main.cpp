#include <stdexcept>
#include <iostream>
#include "Rockets.h"
using namespace std;
using namespace rocket2;

/**
 * @namespace rocket2 Program for sorting a list of
 * rockets using various criteria.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for sorting a list of rockets.
 * Data is from the Wikipedia article
 * Comparison_of_orbital_launch_systems.
 *
 * @return The exit status.  Normal status is 0.
 */
int main() {
  try {

    // Populate the list of rockets.
    
    Rockets rockets;
    rockets.addRocket("Energia", 100, "NPO Energia");
    rockets.addRocket("Falcon 9 v1.1", 13.15, "SpaceX");
    rockets.addRocket("Falcon Heavy", 54.4, "SpaceX");
    rockets.addRocket("Falcon 1", 0.42, "SpaceX");
    rockets.addRocket("Epsilon", 1.2, "IHI Aerospace");
    rockets.addRocket("Falcon 9 v1.1FT", 22.8, "SpaceX");

    // Show the rocket list in the original order.

    cout << rockets.getHtmlTable() << endl;
    
    // Show the rocket list in payload order.
    
    rockets.sortByPayload();
    cout << rockets.getHtmlTable() << endl;
    
    // Show the rocket list in manufacturer order.
    
    rockets.sortByManufacturer();
    cout << rockets.getHtmlTable() << endl;
    
    // Show the rocket list in name order.
    
    rockets.sortByName();
    cout << rockets.getHtmlTable() << endl;
    
    // Partition by category.
    
    cout << rockets.getCategorizedHtmlTable() << endl;

  } catch (const exception& e) {

    // Print the exception message.

    cerr << e.what() << endl;
    return 1;
  }

  // Normal return

  return 0;
}
