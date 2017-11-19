#include "student.hpp"
#include<string>

Student::Student(){};

Student::Student(string registry,vector<string>disciplines){
  setRegistry(registry);
  setDisciplines(disciplines);
}


Student::Student(json j) {
	this->firstName = j.at("person").at("firstName").get<std::string>();
	this->lastName = j.at("person").at("lastName").get<std::string>();
	this->cpf = j.at("person").at("cpf").get<std::string>();
	this->facePicturesPath = j.at("person").at("facePicturesPath").get<std::string>();
  this->registry = j.at("registry").get<std::string>();
  this->disciplines = j.at("disciplines").get<std::vector<string>>();
}

string Student::getRegistry() {
  return registry;
}
void Student::setRegistry(string registry) {
  this->registry = registry;
}

vector<string> Student::getDisciplines() {
  return disciplines;
}

void Student::setDisciplines(vector<string> disciplines) {
  this->disciplines = disciplines;
}

json Student::to_json() {
	json j;
    j = json{{"person", this->person_to_json()},{"registry", this->getRegistry()}, {"disciplines", this->getDisciplines()}};
    return j;
}
