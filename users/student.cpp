#include "student.hpp"
#include<string>

Student::Student(){};

Student::Student(string registry,vector<string>disciplines){
  setRegistry(registry);
  setDisciplines(disciplines);
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
