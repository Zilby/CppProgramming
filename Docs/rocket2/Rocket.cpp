#include <string>
#include "Rocket.h"
using namespace std;
using namespace rocket2;

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

string Rocket::getCategory() const {
  if (payload_ < 2.0) {
    return "Small";
  } else if (payload_ < 20.0) {
    return "Medium";
  } else if (payload_ < 50.0) {
    return "Heavy";
  } else {
    return "SuperHeavy";
  }
}
