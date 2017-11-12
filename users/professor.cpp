#include "professor.hpp"
#include<string>

Professor::Professor(){};

Professor::Professor(string functionalRegistry,vector<string>disciplines){
  setFunctionalRegistry(functionalRegistry);
  setDisciplines(disciplines);
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
