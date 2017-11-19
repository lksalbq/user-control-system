#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

#include<string>
#include "../person/person.hpp"
#include "employeetype.hpp"
#include "config/json.hpp"

using nlohmann::json;
using namespace std;

class Employee: public Person{

private:
	string functionalRegistry;
	EmployeeType employeeType;
public:
	Employee();
	Employee(string functionalRegistry,EmployeeType employeeType);
	Employee(json j);

	void setFunctionalRegistry(string functionalRegistry);
	void setEmployeeType(EmployeeType EmployeeType);

	string getFunctionalRegistry();
	EmployeeType getEmployeeType();

	json to_json();
};
#endif 