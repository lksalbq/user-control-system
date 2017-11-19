#include "employee.hpp"
#include<string>

Employee::Employee(){};

Employee::Employee(string functionalRegistry,EmployeeType employeeType){
  setFunctionalRegistry(functionalRegistry);
  setEmployeeType(employeeType);
}
Employee::Employee(json j) {
	this->firstName = j.at("person").at("firstName").get<std::string>();
	this->lastName = j.at("person").at("lastName").get<std::string>();
	this->cpf = j.at("person").at("cpf").get<std::string>();
	this->facePicturesPath = j.at("person").at("facePicturesPath").get<std::string>();
	this->functionalRegistry = j.at("functionalRegistry").get<std::string>();
	
	//creating employeeType
	EmployeeType employeeType(j);
	this->employeeType = employeeType;
}

string Employee::getFunctionalRegistry() {
  return functionalRegistry;
}
void Employee::setFunctionalRegistry(string functionalRegistry) {
  this->functionalRegistry = functionalRegistry;
}

EmployeeType Employee::getEmployeeType() {
  return employeeType;
}

void Employee::setEmployeeType(EmployeeType employeeType) {
  this->employeeType = employeeType;
}

json Employee::to_json() {
  json j;
  j = json{{"person", this->person_to_json()},{"functionalRegistry", this->getFunctionalRegistry()},{"employee-type",this->getEmployeeType().to_json()}};
  return j;
}