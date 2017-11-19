#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include<string>
#include "../person/person.hpp"
#include "config/json.hpp"

using nlohmann::json;
using namespace std;

class Student: public Person{

private:
	string registry;
	vector<string> disciplines;

public:
	Student();
	Student(string registry,vector<string>disciplines);
	Student(json j);

	void setRegistry(string registry);
	void setDisciplines(vector<string> disciplines);
	
	string getRegistry();
	vector<string> getDisciplines();

	json to_json();
	void saveStudent();
};
#endif 