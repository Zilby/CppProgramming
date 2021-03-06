#ifndef ASST07_ATOM_H
#define ASST07_ATOM_H

#include <string>
#include <stdexcept>

namespace asst07 {

class Molecule;
  
/**
 * An atom class. This class represents a chemical atom, 
 * having a symbol and a molecule that it is part of. 
 * If no molecule has been assigned, it has a nullptr instead. 
 * Atoms have functions to get their symbols and molecules, as
 * well as set their molecules if so far unassigned. 
 *
 * @author Alex Zilbersher
 */
  
class Atom {
public:

  /**
   * Construct an atom.
   */
  Atom(/** The symbol of the atom */ 
       const char& symbol) noexcept;

  /**
   * Get the symbol of the atom.
   * @return The atom's symbol.
   */
  char getSymbol() const noexcept;

  /**
   * Get the molecule of the atom.
   * @return The atom's molecule.
   */
  Molecule* getMolecule() const noexcept;

  /**
   * Set the Molecule of the atom. If a
   * molecule is already set, it will throw
   * an error stating "Molecule has already 
   * been set."
   */
  void setMolecule(/** The molecule to be set to */
		   Molecule* m);
  
private:

  /**
   * The symbol of this atom
   */
  char symbol_;

  /**
   * The molecule of this atom
   */
  Molecule* molecule_ = nullptr;
};

}

#endif
