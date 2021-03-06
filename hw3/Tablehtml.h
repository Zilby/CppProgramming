#ifndef TABLES_TABLEHTML_H
#define TABLES_TABLEHTML_H

#include <iostream>
#include <vector>
#include <string>

/**
 * A printable html table class. An html table has a 2D 
 * vector of words and a print method to print out the
 * table. 
 *
 * @author Alexander Zilbersher
 */
namespace tables {

  class Tablehtml {
  public:
    /**
     * Construct a table from an input stream. Any words
     * not in a set of 5 will be ignored. 
     */
    Tablehtml(/** The input stream that is being read. */
       std::istream& in);

    /**
     * Print this table to an output stream. This will be 
     * printed in html code format. 
     */
    void print(/** The output stream the tree will 
    be printed on. */ std::ostream& out);

  private:
    /** The 2D vector of sets of words */
    std::vector<std::vector<std::string>> sets_;
  };
}

#endif
