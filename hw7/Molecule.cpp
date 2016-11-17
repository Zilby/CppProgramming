#include "Molecule.h"

using namespace std;
using namespace asst07;

Molecule::Molecule(const string& name) noexcept : name_(name) {}


Molecule::~Molecule() noexcept {
  for(Atom* atom : getAtoms()) {
    // deletes all of our created atoms
    delete atom;
  }
}

string Molecule::getName() const noexcept {
  return name_;
}

void Molecule::addBond(const set<Atom*> bond) noexcept {
  set<Atom*, cmp> atoms = getAtoms();

  // adds the bond to our set
  bonds_.emplace(bond);

  // adds the molecule to new atoms
  bool contains = false;
  for(Atom* atom1 : bond) {
    for(Atom* atom2 : atoms) {
      if(atom1 == atom2) {
	contains = true;
	break;
      }
    }

    // skips the atom if the molecule
    // has already been assigned
    if(contains) {
      contains = false;
    } else {

      // otherwise sets the atom to this
      atom1->setMolecule(this);
    }
  }
}
  
set<Atom*, cmp> Molecule::getAtoms() const noexcept {
  set<Atom*, cmp> output;
  for(set<Atom*> atoms : bonds_) {
    for(Atom* atom : atoms) {

      // our compare struct sorts out duplicates
      output.insert(atom);
    }
  }
  return output;
}

string Molecule::getFormula() const noexcept {
  string output = "";
  char c = '1';
  int n = 0;

  // adds up the number of each unique atom
  // once all have been added, it adds the
  // symbol for the atom and its number
  for(Atom* atom : getAtoms()) {
    if (c == '1') {
      c = atom->getSymbol();
      output += c;
    }
    if(atom->getSymbol() == c) {
      ++n;
    } else {
      c = atom->getSymbol();
      if(n > 1) {
	output += to_string(n) + c;
	n = 1;
      } else {
	output += c;
      }
    }
  }
  if(n > 1) {
    output += to_string(n);
  }
  return output;
}
     
