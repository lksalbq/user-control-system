#ifndef _EMPLOYEETYPE_HPP
#define _EMPLOYEETYPE_HPP

#include<string>
#include "../person/person.hpp"
#include "config/json.hpp"

using nlohmann::json;
class EmployeeType{

private:
	string type;
	string company;
	bool internal;
public:
	EmployeeType();
	EmployeeType(string type,string company, bool internal);
	EmployeeType(json j);

	void setType(string type);
	string getType();
	
	void setCompany(string company);
	string getCompany();
	
	void setInternal(bool internal);
	bool getInternal();

	json to_json();
};
#endif 