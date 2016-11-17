#include "Atom.h"
#include <stdexcept>

using namespace std;
using namespace asst08;

Atom::Atom(const string& symbol) noexcept : symbol_(symbol) {}

string Atom::getSymbol() const noexcept {
  return symbol_;
}

Molecule* Atom::getMolecule() const noexcept {
  return molecule_;
}

void Atom::setMolecule(Molecule* m) { 
  if((molecule_!=nullptr) && (molecule_!=m)) {
    throw logic_error("Molecule has already been set.");
  } else {
    molecule_ = m;
  }
}
