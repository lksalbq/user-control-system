#include "users/student.hpp"
#include "config/database.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){

  	Database db;

  	//db.executeSimpleQuery("CREATE TABLE Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255));"); 

 	vector<string> disciplines;

 	disciplines.push_back("Topicos 1");
	
	Student student;

	student.setCpf("039.040.531-08");
	student.setRegistry("11/0128796");
	student.setDisciplines(disciplines);

	//db.executeSimpleQuery("INSERT INTO Persons values(2,'Albuquerque','Lucas','QE 15 conjunto R','Guaronha');");

	vector<string> result;

	result = db.executeQuery("Select * from Persons");

	for(int i=0; i < result.size(); i++){
		cout<< result[i] << endl;		
	}

	std::cout<< student.getCpf() <<std::endl;

  return 0;
}
