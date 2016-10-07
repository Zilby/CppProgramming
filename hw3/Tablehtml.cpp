#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include "Tablehtml.h"
using namespace std;
using namespace tables;

Tablehtml::Tablehtml(istream& in) {

  // the current word being added to sets
  string word;

  // the current set being added to the table
  vector<string> set;
  
  while (in >> word) {
    set.push_back(word);

    // once a set reaches a size of 5 it is added
    // to the table and cleared
    if (set.size() == 5) {
      sets_.push_back(set);
      set.clear();
    }
  }
}

void Tablehtml::print(ostream& out) {

  // a vector of 5 to keep track of how many
  // repeats a word has in a column (ie: how
  // many times it can skip adding text)
  vector<int> skips;
  
  for (int i = 0; i < 5; ++i) {
    skips.push_back(0);
  }

  // our output string
  string output = "<table border='1'>\n";

  // iterates through our table to add the appropriate
  // text to our output
  for (unsigned int i = 0; i < sets_.size(); ++i) {

    // if this word is a repeat, it will be skipped
    for (int j = 0; j < 5; ++j) {
      if (skips[j] > 0) {
	--skips[j];
      } else {

	// otherwise check if any words after it are
	// repeats and add to skips accordingly
	string s = sets_[i][j];
	for (auto k = i + 1; k < sets_.size(); ++k) {
	  if (s.compare(sets_[k][j]) == 0) {
	    ++skips[j];
	  } else {
	    break;
	  }
	}

	// then add the appropriate output for this word
	// and use skips to determine its rowspan
	output += ("<tr><td rowspan='" +
		    std::to_string(skips[j] + 1)
		    + "'>" + s + "</td>");
      }
    }
    output += "\n";
  }

  // finalize the output
  output += "</table>";

  // output the output
  out << output << endl;
}
