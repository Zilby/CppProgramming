#include "Molecule.h"

using namespace std;
using namespace asst08;

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
  set<Atom*> atoms = getAtoms();

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
  
set<Atom*> Molecule::getAtoms() const noexcept {
  
  // our output set
  set<Atom*> output;
  auto lambda = [&output](int id, Atom* atom) mutable
    { output.insert(atom); };
  traverse(lambda);
  return output;
}

string Molecule::getFormula() const noexcept {
  string output = "";
  string c = "1";
  int n = 0;
  multiset<string> symbols;
  for(Atom* atom : getAtoms()) {
    symbols.insert(atom->getSymbol());
  }  
  // adds up the number of each unique atom
  // once all have been added, it adds the
  // symbol for the atom and its number
  for(string s : symbols) {
    if (c == "1") {
      c = s;
      output += c;
    }
    if(s == c) {
      ++n;
    } else {
      c = s;
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
     
void Molecule::traverse(function<void(int, Atom*)> f) const noexcept {
  int id = 1;
  for(set<Atom*> atoms : bonds_) {
    for(Atom* atom : atoms) {

      // traverses our atoms and
      // applies the function to each
      // atom
      f(id, atom);
    }

    // increments our bond id
    ++id;
  }
}

int Molecule::bondCount(Atom* a) const noexcept {
  int total = 0;
  int currentID = 0;
  auto lambda = [&a, &total, &currentID](int id, Atom* atom) mutable

  // if the atom is the same and not part of the same bond
  // (which shouldn't happen but in case it does), the total
  // count is incremented and the current bond id is set
    { if((atom == a) && (currentID != id)) {
	 ++total;
	 currentID = id;
      }
    };
  traverse(lambda);
  return total;
}
