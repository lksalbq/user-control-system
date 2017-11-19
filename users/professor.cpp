#include "professor.hpp"
#include<string>

Professor::Professor(){};

Professor::Professor(string functionalRegistry,vector<string>disciplines){
  setFunctionalRegistry(functionalRegistry);
  setDisciplines(disciplines);
}

Professor::Professor(json j) {
	this->firstName = j.at("person").at("firstName").get<std::string>();
	this->lastName = j.at("person").at("lastName").get<std::string>();
	this->cpf = j.at("person").at("cpf").get<std::string>();
	this->facePicturesPath = j.at("person").at("facePicturesPath").get<std::string>();
  this->functionalRegistry = j.at("functionalRegistry").get<std::string>();
  this->disciplines = j.at("disciplines").get<std::vector<string>>();
}

string Professor::getFunctionalRegistry() {
  return functionalRegistry;
}
void Professor::setFunctionalRegistry(string functionalRegistry) {
  this->functionalRegistry = functionalRegistry;
}

vector<string> Professor::getDisciplines() {
  return disciplines;
}

void Professor::setDisciplines(vector<string> disciplines) {
  this->disciplines = disciplines;
}

json Professor::to_json() {
  json j;
  j = json{{"person", this->person_to_json()},{"functionalRegistry", this->getFunctionalRegistry()},{"disciplines",this->getDisciplines()}};
  return j;
}