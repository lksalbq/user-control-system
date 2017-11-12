#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

#include<string>
#include "../person/person.hpp"
#include "employeetype.hpp"

using namespace std;

class Employee: public Person{

private:
	string functionalRegistry;
	EmployeeType type;
public:
	Employee();
	Employee(string functionalRegistry,EmployeeType type);

	void setFunctionalRegistry(string functionalRegistry);
	void setEmployeeType(EmployeeType EmployeeType);

	string getFunctionalRegistry();
	EmployeeType getEmployeeType();
};
#endif 