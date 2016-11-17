#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test of the asst08 package
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "Molecule.h"

using namespace std;
using namespace asst08;

/**
 * @namespace asst08 This package demonstrates pointers, 
 * memory management, lambdas and the boost package. 
 *
 * @author Alexander Zilbersher
 */

/**
 * This test case constructs a water, salt, and empty molecule, 
 * checks that they have the right names, checks that the molecules
 * have the correct formulas, checks that each molecules has the 
 * correct set of atoms, checks that every atom belongs to the correct 
 * molecule, and checks that every atom has the correct bond count.  
 */
BOOST_AUTO_TEST_CASE(molecule_test1) {
    
  // Creates the water molecule
  Molecule w("water");

  // Creates the Atoms
  Atom* h1 = new Atom("H");
  Atom* h2 = new Atom("H");
  Atom* o = new Atom("O");

  // Creates the bonds
  set<Atom*> b1;
  b1.emplace(h1);
  b1.emplace(o);
  set<Atom*> b2;
  b2.emplace(h2);
  b2.emplace(o);

  // Adds the bonds
  w.addBond(b1);
  w.addBond(b2);
  
  // Create the salt molecule
  Molecule s("salt");
  
  // Creates the Atoms
  Atom* na = new Atom("Na");
  Atom* cl = new Atom("Cl");

  // Creates the bonds
  set<Atom*> b3;
  b3.emplace(na);
  b3.emplace(cl);

  // Adds the bonds
  s.addBond(b3);

  // Create the empty molecule
  Molecule e("empty");

  // Checks if each molecule has the right name
  BOOST_CHECK_EQUAL(w.getName(), "water");
  BOOST_CHECK_EQUAL(s.getName(), "salt");
  BOOST_CHECK_EQUAL(e.getName(), "empty");

  // Checks if each molecule has the right formula
  BOOST_CHECK_EQUAL(w.getFormula(), "H2O");
  BOOST_CHECK_EQUAL(s.getFormula(), "ClNa");
  BOOST_CHECK_EQUAL(e.getFormula(), "");

  // Checks that water has the correct set of atoms
  set<Atom*> a1;
  a1.insert(h1);
  a1.insert(h2);
  a1.insert(o);

  set<Atom*> a2 = w.getAtoms();
  
  BOOST_CHECK_EQUAL_COLLECTIONS(a1.begin(), a1.end(),
				a2.begin(), a2.end());

  // Checks that salt has the correct set of atoms
  set<Atom*> a3;
  a3.insert(na);
  a3.insert(cl);
  
  set<Atom*> a4 = s.getAtoms();
  
  BOOST_CHECK_EQUAL_COLLECTIONS(a3.begin(), a3.end(),
				a4.begin(), a4.end());

  // Checks that the empty molecule has the correct set of atoms
  set<Atom*> a5;
  
  set<Atom*> a6 = e.getAtoms();
  
  BOOST_CHECK_EQUAL_COLLECTIONS(a5.begin(), a5.end(),
				a6.begin(), a6.end());

  // Checks that all of water's atoms belong to it
  Molecule* m1 = h1->getMolecule();
  BOOST_CHECK_EQUAL(m1, &w);
  Molecule* m2 = h2->getMolecule();
  BOOST_CHECK_EQUAL(m2, &w);
  Molecule* m3 = o->getMolecule();
  BOOST_CHECK_EQUAL(m3, &w);

  // Checks that all of salt's atoms belong to it
  Molecule* m4 = na->getMolecule();
  BOOST_CHECK_EQUAL(m4, &s);
  Molecule* m5 = cl->getMolecule();
  BOOST_CHECK_EQUAL(m5, &s);

  // Checks that each atom has the correct number of bonds
  BOOST_CHECK_EQUAL(w.bondCount(h1), 1);
  BOOST_CHECK_EQUAL(w.bondCount(h2), 1);
  BOOST_CHECK_EQUAL(w.bondCount(o), 2);
  BOOST_CHECK_EQUAL(s.bondCount(na), 1);
  BOOST_CHECK_EQUAL(s.bondCount(cl), 1);

}

/**
 * This test case checks that an exception is thrown 
 * if an atom is in two molecules.
 */
BOOST_AUTO_TEST_CASE(molecule_test2) {
  // Create the molecules
  Molecule m1("molecule1");
  Molecule m2("molecule2");
  
  // Create the atoms
  Atom* a1 = new Atom("A");
  Atom* a2 = new Atom("A");

  // Create the bond
  set<Atom*> b1;
  b1.emplace(a1);
  b1.emplace(a2);

  // Adds the bond
  m1.addBond(b1);
  
  // Checks if an exception is thrown if the atom
  // is added to a different molecule
  BOOST_CHECK_THROW(a1->setMolecule(&m2), logic_error);
}
