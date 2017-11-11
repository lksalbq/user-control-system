#include "student.hpp"
#include<string>

Student::Student(){};

Student::Student(string cpf,string registry,vector<string>disciplines){
  setCpf(cpf);
  setRegistry(registry);
  setDisciplines(disciplines);
}


string Student::getCpf() {
  return cpf;
}

void Student::setCpf(string cpf) {
  this->cpf = cpf;
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
