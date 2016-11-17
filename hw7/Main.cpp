#include <string>
#include <iostream>
#include <vector>
#include "Atom.h"
#include "Molecule.h"

using namespace std;
using namespace asst07;

/**
 * @namespace asst07 This main function constructs a water
 * and benzene molecule and then prints out their formulas. 
 * It does so through the creation of atoms within their own 
 * memory space which is then deleted through their molecule's 
 * destructor method. 
 *
 * @author Alexander Zilbersher
 */

int main() {
  // Creates the water molecule
  Molecule w("water");

  // Creates the Atoms
  Atom* h1 = new Atom('H');
  Atom* h2 = new Atom('H');
  Atom* o1 = new Atom('O');

  // Creates the bonds
  set<Atom*> b1;
  b1.emplace(h1);
  b1.emplace(o1);
  set<Atom*> b2;
  b2.emplace(h2);
  b2.emplace(o1);

  // Adds the bonds
  w.addBond(b1);
  w.addBond(b2);

  // Prints out the water formula
  cout << w.getFormula() + "\n";

  // Creates the benzene molecule
  Molecule b("benzene");

  // Creates the Atoms
  Atom* h3 = new Atom('H');
  Atom* h4 = new Atom('H');
  Atom* h5 = new Atom('H');
  Atom* h6 = new Atom('H');
  Atom* h7 = new Atom('H');
  Atom* h8 = new Atom('H');
  Atom* c1 = new Atom('C');
  Atom* c2 = new Atom('C');
  Atom* c3 = new Atom('C');
  Atom* c4 = new Atom('C');
  Atom* c5 = new Atom('C');
  Atom* c6 = new Atom('C');

  // Creates the bonds
  set<Atom*> b3;
  b3.emplace(c1);
  b3.emplace(h3);
  set<Atom*> b4;
  b4.emplace(c2);
  b4.emplace(h4);
  set<Atom*> b5;
  b5.emplace(c3);
  b5.emplace(h5);
  set<Atom*> b6;
  b6.emplace(c4);
  b6.emplace(h6);
  set<Atom*> b7;
  b7.emplace(c5);
  b7.emplace(h7);
  set<Atom*> b8;
  b8.emplace(c6);
  b8.emplace(h8);
  set<Atom*> b9;
  b9.emplace(c1);
  b9.emplace(c2);
  b9.emplace(c3);
  b9.emplace(c4);
  b9.emplace(c5);
  b9.emplace(c6);

  // Adds the bonds
  b.addBond(b3);
  b.addBond(b4);
  b.addBond(b5);
  b.addBond(b6);
  b.addBond(b7);
  b.addBond(b8);
  b.addBond(b9);

  // Prints out the benzene formula
  cout << b.getFormula() + "\n";


  // Return normal status
  return 0;
}
