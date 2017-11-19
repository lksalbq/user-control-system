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

	void setType(string type);
	void setCompany(string company);
	void setInternal(bool internal);

	string getType();
	string getCompany();
	bool getInternal();

	json to_json();
};
#endif 