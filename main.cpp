#include "users/student.hpp"
#include "config/database.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){

  // Database db;

  // db->excuteQuery("CREATE TABLE person"); 
 	
 	vector<string> disciplines;

 	disciplines.push_back("Topicos 1");
	
	Student student;

	student.setCpf("039.040.531-08");
	student.setRegistry("11/0128796");
	student.setDisciplines(disciplines);

	std::cout<< student.getCpf() <<std::endl;

  return 0;
}
