#include "discipline.hpp"
#include<string>
#include <vector>
#include "../config/database.hpp"
#include "../users/student.hpp"
#include "../users/professor.hpp"

Discipline::Discipline(){};
  
Discipline::Discipline(string name, string description,string department, time_t initSchedule, time_t endSchedule,  vector<Student> students, Professor professor){
	setName(name);
	setDescription(description);
	setDepartment(department);
	setInitSchedule(initSchedule);
	setEndSchedule(endSchedule);
	setStudents(students);
	setProfessor(professor);
}
  
int Discipline::getId(){
	return this->id;
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

void Discipline::setInitSchedule(time_t initSchedule){
	this->initSchedule = initSchedule;	
}

time_t Discipline::getInitSchedule(){
	return this->initSchedule;
}
  
void Discipline::setEndSchedule(time_t endSchedule){
	this->endSchedule = endSchedule;
}

time_t Discipline::getEndSchedule(){
	return this->endSchedule;
}

void Discipline::setStudents(vector<Student> students){
	this->students = students;
}
string Discipline::getStudents(){
	string student;
	for(int i = 0; i < this->students.size();i++){
		student.append(students[i].getRegistry()+",");
	}
	return student;
} 

void Discipline::setProfessor(Professor professor){
	this->professor = professor;
}
Professor Discipline::getProfessor(){
	return this->professor;
}

void saveDiscipline(){}