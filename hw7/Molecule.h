#ifndef ASST07_MOLECULE_H
#define ASST07_MOLECULE_H

#include <string>
#include <set>
#include "Atom.h"
#include <iostream>

namespace asst07 {

/**
 * A struct for comparing Atoms in our output set for 
 * getAtoms. It organizes them alphabetically and takes
 * out duplicates. 
 */ 

struct cmp {
    bool operator()(const Atom* a, const Atom* b) {
      if(a==b) {
	return false;
      } else {
	if (a->getSymbol() == b->getSymbol()) {
	  return a > b;
	} else {
	  return a->getSymbol() < b->getSymbol();
	}
      }
    }
};

 
/**
 * A molecule class. Molecule represents a chemical arrangement of 
 * atoms, containing a set of bonds as well as a name. It has functions
 * to add bonds, return its name, return all of its atoms, get its 
 * formula and a destructor method for deleting all of its atoms. 
 *
 * @author Alex Zilbersher
 */ 

  class Molecule {
public:

  /**
   * Construct a molecule.
   */
  Molecule(/** The name of the molecule */ 
	   const std::string& name) noexcept;

  /**
   * Destruct a molecule.
   */
  ~Molecule() noexcept;
  
  /**
   * Get the name of the molecule.
   * @return The molecule's name.
   */
  std::string getName() const noexcept;

  /**
   * Adds a bond to the molecule. Also makes 
   * the atoms in the bond into parts of
   * the molecule
   */
  void addBond(/** The bond to be added */
	       const std::set<Atom*> bond) noexcept;

  /**
   * Gets the set of all atoms of the molecule. Any atoms
   * that are not the same, even if they are of the same element,
   * are returned. 
   * @return the set of all atoms. 
   */
  std::set<Atom*, cmp> getAtoms() const noexcept;

  /**
   * Get the formula of the molecule.
   * @return The molecule's formula.
   */
  std::string getFormula() const noexcept;
  
private:
  /**
   * The name of this molecule
   */
  std::string name_;
  
  /**
   * The bonds of this molecule
   */
  std::set<std::set<Atom*>> bonds_;
  
};

}

#endif
