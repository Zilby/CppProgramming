#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include "Rockets.h"
using namespace std;
using namespace rocket2;

void Rockets::addRocket(const std::string& name, double payload, 
			const std::string& manufacturer) {
  rockets_.push_back(Rocket(name, payload, manufacturer));
}

void Rockets::sortByName() {
  sort(rockets_.begin(), rockets_.end(), 
       [](const Rocket& rocket1, const Rocket& rocket2)
       { return rocket1.getName() < rocket2.getName(); });
}

void Rockets::sortByPayload() {
  sort(rockets_.begin(), rockets_.end(), 
       [](const Rocket& rocket1, const Rocket& rocket2)
       { return rocket1.getPayload() < rocket2.getPayload(); });
}
 
void Rockets::sortByManufacturer() {
  sort(rockets_.begin(), rockets_.end(), 
       [](const Rocket& rocket1, const Rocket& rocket2)
       { return rocket1.getManufacturer() < rocket2.getManufacturer(); });
}

string Rockets::getHtmlTable() const {

  // The table start tag and column headings

  string table = "<table border='1'>\n"
    "<tr><th>Name</th><th>Payload</th><th>Manufacturer</th></tr>";

  // Get the matrix of entries in the table.

  vector<vector<string>> matrix;
  for (const Rocket& rocket : rockets_) {
    matrix.push_back({rocket.getName(), to_string(rocket.getPayload()), rocket.getManufacturer()});
  }

  // Loop over rockets

  for (unsigned int r = 0; r < matrix.size(); ++r) {
    table += "<tr>";

    // Loop over rocket fields

    for (unsigned int f = 0; f < matrix.at(r).size(); ++f) {

      // An entry is included only if it is the initial one in its column.

      if (r == 0 || matrix.at(r).at(f) != matrix.at(r-1).at(f)) {

	// Count the number of repeats below it.

	int n = 1;
	for (unsigned int k = r+1; k < matrix.size(); ++k) {
	  if (matrix.at(k).at(f) == matrix.at(r).at(f)) {
	    ++n;
	  } else {
	    break;
	  }
	}

	// Add the entry to the string.

	table += "<td rowspan='" + to_string(n) + "'>" + matrix.at(r).at(f) + "</td>";
      }
    }
    table += "</tr>\n";
  }

  // The table end tag
  
  table += "</table>\n";
  return table;
}

string Rockets::getCategorizedHtmlTable() {

  // Map by category

  unordered_multimap<string, Rocket> category2rocket;
  for (Rocket rocket : rockets_) {
    category2rocket.insert({rocket.getCategory(), rocket});
  }

  // The table start tag and column headings

  string table = "<table border='1'>\n"
    "<tr><th>Category</th><th>Name</th><th>Payload</th>"
    "<th>Manufacturer</th></tr>\n";

  // The outer loop is by category

  for (const string& category : { "Small", "Medium", "Heavy", "SuperHeavy" }) {

    // The inner loop is over rockets in one category

    auto pair = category2rocket.equal_range(category);
    for (auto iter = pair.first; iter != pair.second; ++iter) {

      // Only the first row for a category shows the category name
      
      if (iter == pair.first) {
	table += "<tr><td rowspan='" + to_string(category2rocket.count(category)) + "'>"
	  + category + "</td>";
      }
      
      // Show the rest of the fields
      
      table += "<td>" + iter->second.getName() + "</td>";
      table += "<td>" + to_string(iter->second.getPayload()) + "</td>";
      table += "<td>" + iter->second.getManufacturer() + "</td>";
      table += "</tr>\n";
    }
  }

  // The table end tag

  table += "</table>\n";
  return table;
}
