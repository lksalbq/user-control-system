#include "employee.hpp"
#include<string>

Employee::Employee(){};

Employee::Employee(string functionalRegistry,EmployeeType type){
  setFunctionalRegistry(functionalRegistry);
  setEmployeeType(type);
}

string Employee::getFunctionalRegistry() {
  return functionalRegistry;
}
void Employee::setFunctionalRegistry(string functionalRegistry) {
  this->functionalRegistry = functionalRegistry;
}

EmployeeType Employee::getEmployeeType() {
  return type;
}

void Employee::setEmployeeType(EmployeeType type) {
  this->type = type;
}
