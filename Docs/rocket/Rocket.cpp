#include <string>
#include "Rocket.h"
using namespace std;
using namespace rocket;

Rocket::Rocket(const string& name, double payload, const string& manufacturer) 
  : name_(name), payload_(payload), manufacturer_(manufacturer) {}

string Rocket::getName() const {
  return name_;
}

double Rocket::getPayload() const {
  return payload_;
}

string Rocket::getManufacturer() const {
  return manufacturer_;
}

bool Rocket::operator==(const Rocket& otherRocket) const {
  return name_ == otherRocket.name_
    && payload_ == otherRocket.payload_
    && manufacturer_ == otherRocket.manufacturer_;
}

Rocket::Category Rocket::getCategory() const {
  if (payload_ < 2.0) {
    return Category::Small;
  } else if (payload_ < 20.0) {
    return Category::Medium;
  } else if (payload_ < 50.0) {
    return Category::Heavy;
  } else {
    return Category::SuperHeavy;
  }
}

string Rocket::getHtmlTableEntries() const {
  return "<td>" + name_ + "</td><td>" + to_string(payload_) + "</td><td>" + manufacturer_ + "</td>";
}
