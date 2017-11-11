#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include<string>
#include "../person/person.hpp"
using namespace std;

class Student: public Person{

private:
	string cpf;
	string registry;
	vector<string> disciplines;

public:
	Student();
	Student(string cpf,string registry,vector<string>disciplines);

	void setCpf(string cpf);
	void setRegistry(string registry);
	void setDisciplines(vector<string> disciplines);

	string getCpf();
	string getRegistry();
	vector<string> getDisciplines();
};
#endif 