#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include<string>
#include "../person/person.hpp"
#include "../config/database.hpp"

using namespace std;

class Student: public Person{

private:
	string registry;
	vector<string> disciplines;
	Database db;
public:
	Student();
	Student(string registry,vector<string>disciplines);
	
	void setRegistry(string registry);
	void setDisciplines(vector<string> disciplines);
	
	string getRegistry();
	vector<string> getDisciplines();

	void saveStudent();
};
#endif 