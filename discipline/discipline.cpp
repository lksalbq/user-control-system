#include "discipline.hpp"
#include<string>
#include <vector>
#include "../config/database.hpp"
#include "../users/student.hpp"
#include "../users/professor.hpp"

Discipline::Discipline(){};
  
Discipline::Discipline(string code,string name, string description,string department, string disciplineClass){
	setCode(code);
	setName(name);
	setDescription(description);
	setDepartment(department);
	setDisciplineClass(disciplineClass);	
}

Discipline::Discipline(json j){
	this->code = j.at("code").get<std::string>();
	this->name = j.at("name").get<std::string>();
	this->description = j.at("description").get<std::string>();
	this->department = j.at("department").get<std::string>();
	this->disciplineClass = j.at("disciplineClass").get<std::string>();
}


void Discipline::setCode(string code){
	this->code = code;
}  
string Discipline::getCode(){
	return this->code;
}

string Discipline::getName(){
	return this->name;
}

void Discipline::setName(string name){
	this->name = name;
}
  
string Discipline::getDescription(){
	return this->description;
}

void Discipline::setDescription(string description){
	this->description = description;
}

string Discipline::getDepartment(){
	return this->department;
}

void Discipline::setDepartment(string department){
	this->department = department;
}

void Discipline::setDisciplineClass(string disciplineClass){
	this->disciplineClass = disciplineClass;	
}


string Discipline::getDisciplineClass(){
	return this->disciplineClass;	
}

json Discipline::to_json(){
	json j;
	j = json{{"code", this->getCode()}, {"name", this->getName()},{"description", this->getDepartment()},{"department", this->getDepartment()},{"disciplineClass", this->getDisciplineClass()}};
	return j;
}