#include "employeetype.hpp"
#include<string>

EmployeeType::EmployeeType(){};

EmployeeType::EmployeeType(string type,string company, bool internal){
  setType(type);
  setCompany(company);
  setInternal(internal);
}

EmployeeType::EmployeeType(json j){
  this->type = j.at("employee-type").at("type").get<std::string>();
  this->company = j.at("employee-type").at("company").get<std::string>();
  this->internal = j.at("employee-type").at("internal");   
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