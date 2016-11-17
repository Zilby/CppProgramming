#ifndef ASST08_MOLECULE_H
#define ASST08_MOLECULE_H

#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include "Atom.h"

namespace asst08 {
 
/**
 * A molecule class. Molecule represents a chemical arrangement of 
 * atoms, containing a set of bonds as well as a name. It has functions
 * to add bonds, return its name, return all of its atoms, get its 
 * formula, get the number of bonds an atom is in,  and a destructor 
 * method for deleting all of its atoms.  
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
  std::set<Atom*> getAtoms() const noexcept ;

  /**
   * Get the formula of the molecule.
   * @return The molecule's formula.
   */
  std::string getFormula() const noexcept;

  /**
   * Traverses all of the atoms in our bonds and applies a function 
   * to them. It will apply the function to every atom in every bond, 
   * applying it multiple times to the same atom if it is contained
   * in more than one bond. 
   */
  void traverse(/** the function to be applied */
		std::function<void(int, Atom*)> f) const noexcept ;

  /**
   * Counts the number of bonds this atom is part of. 
   * @return the number of bonds. 
   */
  int bondCount(/** the atom whose bonds are counted */
		Atom* a) const noexcept ;
  
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
