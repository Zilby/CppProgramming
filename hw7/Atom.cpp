#include "Atom.h"

using namespace std;
using namespace asst07;

Atom::Atom(const char& symbol) noexcept : symbol_(symbol) {}

char Atom::getSymbol() const noexcept {
  return symbol_;
}


Molecule* Atom::getMolecule() const noexcept {
  return molecule_;
}

void Atom::setMolecule(Molecule* m) { 
  if(molecule_==m) {
    throw invalid_argument("Molecule has already been set.");
  } else {
    molecule_ = m;
  }
}
