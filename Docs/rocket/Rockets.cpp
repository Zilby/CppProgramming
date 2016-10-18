#include <vector>
#include <tuple>
#include <algorithm>
#include "Rockets.h"
using namespace std;
using namespace rocket;

void Rockets::addRocket(const std::string& name, double payload, const std::string& manufacturer) {
  rockets_.push_back(Rocket(name, payload, manufacturer));
}

bool Rockets::operator==(const Rockets& otherRockets) const {
  return rockets_ == otherRockets.rockets_;
}

bool Rockets::isSameSet(const Rockets& otherRockets) const {
  if (rockets_.size() != otherRockets.rockets_.size()) {
    return false;
  }
  return is_permutation(rockets_.begin(), rockets_.end(), 
			otherRockets.rockets_.begin());
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

vector<Rockets::Triple> Rockets::partitionByCategory() {

  // The partition is a list of triples

  vector<Rockets::Triple> partition;

  // Partition small rockets

  auto endSmall = 
    stable_partition(rockets_.begin(), rockets_.end(),
		     [](const Rocket& rocket)
		     { return rocket.getCategory() == Rocket::Category::Small; });
  partition.push_back(Triple("Small", rockets_.begin(), endSmall));

  // Partition medium rockets

  auto endMedium = 
    stable_partition(endSmall, rockets_.end(),
		     [](const Rocket& rocket)
		     { return rocket.getCategory() == Rocket::Category::Medium; });
  partition.push_back(Triple("Medium", endSmall, endMedium));

  // Partition heavy rockets

  auto endHeavy = 
    stable_partition(endMedium, rockets_.end(),
		     [](const Rocket& rocket)
		     { return rocket.getCategory() == Rocket::Category::Heavy; });
  partition.push_back(Triple("Heavy", endMedium, endHeavy));

  // The last partition consists of the super heavy rockets

  partition.push_back(Triple("Super Heavy", endHeavy, rockets_.end()));

  // Return the full partition

  return partition;
}

string Rockets::getHtmlTable() const {

  // The table start tag and column headings

  string table = "<table border='1'>\n"
    "<tr><th>Name</th><th>Payload</th><th>Manufacturer</th></tr>\n";

  // Each rocket is shown in one row of the table

  for (const Rocket& rocket : rockets_) {
    table += "<tr>" + rocket.getHtmlTableEntries() + "</tr>\n";
  }

  // The table end tag

  table += "</table>\n";
  return table;
}

string Rockets::getCategorizedHtmlTable() {

  // Partition the rockets with one group per category

  vector<Rockets::Triple> partition = partitionByCategory();

  // The table start tag and column headings

  string table = "<table border='1'>\n"
    "<tr><th>Category</th><th>Name</th><th>Payload</th><th>Manufacturer</th></tr>";

  // The outer loop is by category

  for (const Rockets::Triple& triple : partition) {

    // Compute the number of rockets in this category

    int rocketCount = get<2>(triple) - get<1>(triple);

    // Do not show anything if the category is empty

    if (rocketCount > 0) {

      // The inner loop is over rockets in one category

      for (auto iter = get<1>(triple); iter != get<2>(triple); ++iter) {

	// Only the first row in the table
	// includes the category

	if (iter == get<1>(triple)) {
	  table += "<tr><td rowspan='" + to_string(rocketCount) + "'>"
	    + get<0>(triple) + "</td>"
	    + iter->getHtmlTableEntries() + "</tr>\n";
	} else {
	  table += "<tr>" + iter->getHtmlTableEntries() + "</tr>\n";
	}
      }
    }
  }

  // The table end tag

  table += "</table>\n";
  return table;
}
