#include "employeetype.hpp"
#include<string>

EmployeeType::EmployeeType(){};

EmployeeType::EmployeeType(string type,string company, bool internal){
  setType(type);
  setCompany(company);
  setInternal(internal);
}

string EmployeeType::getType() {
  return type;
}
void EmployeeType::setType(string type) {
  this->type = type;
}

string EmployeeType::getCompany() {
  return company;
}

void EmployeeType::setCompany(string company) {
  this->company = company;
}

bool EmployeeType::getInternal() {
  return internal;
}

void EmployeeType::setInternal(bool internal) {
  this->internal = internal;
}

json EmployeeType::to_json(){
	json j;
	j = json{{"type", this->getType()},{"company", this->getCompany()},{"internal",this->getInternal()}};
	return j;
}
