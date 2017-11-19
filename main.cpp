#include "users/student.hpp"
#include "users/professor.hpp"
#include "discipline/discipline.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "config/json.hpp"
#include "util/util.hpp"
// for convenience
using json = nlohmann::json;
using namespace std;
using namespace util;

int main(int argc, char **argv){

	Discipline discipline;

	discipline.setName("Tecnicas de Programcao 1");
	discipline.setDescription("Descricao");
	discipline.setDepartment("CIC");

 	vector<string> disciplinesS;
 	
 	disciplinesS.push_back(discipline.getName());
	
	Student student;

	student.setRegistry("17/0149439");
	student.setFirstName("Lucas");
	student.setLastName("de Albuquerque Silva");
	student.setCpf("039.040.531-08");
	student.setFacePicturesPath("/home/lucas/"+student.getRegistry());

	Student student2;

	student2.setRegistry("11/0128796");
	student2.setFirstName("Lucas OLd");
	student2.setLastName("Silva");
	student2.setCpf("039.040.531-08");
	student2.setFacePicturesPath("/home/lucas1/"+student.getRegistry());

	vector<Student> students;

	students.push_back(student);
	students.push_back(student2);

	discipline.setStudents(students);

	Professor professor;

	professor.setFunctionalRegistry("1111112222");
	professor.setFirstName("Teofilo");

	discipline.setProfessor(professor);

	professor.setDisciplines(disciplinesS);
	student.setDisciplines(disciplinesS);

	json j = util::readJson("pretty.json");
	Student s(j);

	cout<< s.getFirstName() << endl;
	cout<< s.getFacePicturesPath() << endl;

	util::saveJson(s.getCpf(),s.to_json());

  return 0;
}
