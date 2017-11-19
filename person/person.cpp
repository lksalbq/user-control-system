#include "person.hpp"
#include<string>
#include <vector>
#include "../config/database.hpp"

Person::Person(){};

Person::Person(string firstName, string lastName,string facePicturesPath){
  setFirstName(firstName);
  setLastName(lastName);
  setCpf(cpf);
  setFacePicturesPath(facePicturesPath);
}

string Person::getFirstName() {
  return firstName;
}

void Person::setFirstName(string firstName) {
  this->firstName = firstName;
}

string Person::getLastName() {
  return lastName;
}
void Person::setLastName(string lastName) {
  this->lastName = lastName;
}
string Person::getCpf() {
  return cpf;
}

void Person::setCpf(string cpf) {
  this->cpf = cpf;
}

string Person::getFacePicturesPath() {
  return facePicturesPath;
}

void Person::setFacePicturesPath(string facePicturesPath) {
  this->facePicturesPath = facePicturesPath;
}

json Person::person_to_json() {
  json j;
  j = json{{"firstName", this->getFirstName()}, {"lastName", this->getLastName()},{"cpf", this->getCpf()},{"facePicturesPath", this->getFacePicturesPath()}};
  return j;
}