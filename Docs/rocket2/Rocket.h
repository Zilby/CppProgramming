#ifndef ROCKET2_ROCKET_H
#define ROCKET2_ROCKET_H

#include <string>

namespace rocket2 {

/**
 * A rocket.  It includes the name, the payload in
 * Mg (metric tons), and the manufacturer.
 *
 * @author Ken Baclawski
 */
class Rocket {
public:
  /**
   * Construct a rocket.
   */
  Rocket(/** The name of the rocket. */ 
	 const std::string& name,
	 /** The payload of the rocket. */
	 double payload,
	 /** The manufacturer of the rocket. */
	 const std::string& manufacturer);

  /**
   * Get the name of the rocket.
   * @return The rocket name.
   */
  std::string getName() const;

  /**
   * Get the payload to LEO in Mg.
   * @return The payload.
   */
  double getPayload() const;

  /**
   * Get the manufacturer.
   * @return The name of the manufacturer.
   */
  std::string getManufacturer() const;

  /**
   * Get the category of the rocket.  The category is determined by the payload.
   *
   * @return The category of this rocket as a string.
   */
  std::string getCategory() const;

private:
  /**
   * The name of the rocket.
   */
  std::string name_;

  /**
   * The payload to LEO in Mg.
   */
  double payload_ = 0.0;

  /**
   * The manufacturer.
   */
  std::string manufacturer_;
};

}

#endif
