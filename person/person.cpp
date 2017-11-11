#include "person.hpp"
#include<string>
#include <vector>

Person::Person(){};

Person::Person(string firstName, string lastName, vector<string> facePicturesPath){
  setFirstName(firstName);
  setLastName(lastName);
  setFacePicturesPath(facePicturesPath);
}

string Person::getFirstName() {
  return lastName;
}

void Person::setFirstName(string firstNome) {
  this->firstName = firstName;
}

string Person::getLastName() {
  return lastName;
}
void Person::setLastName(string lastNome) {
  this->lastName = lastName;
}

vector<string> Person::getFacePicturesPath() {
  return facePicturesPath;
}

void Person::setFacePicturesPath(vector<string> facePicturesPath) {
  this->facePicturesPath = facePicturesPath;
}
