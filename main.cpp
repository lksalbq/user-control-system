#include "users/student.hpp"
#include "config/database.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){

 	vector<string> disciplines;
 	
 	disciplines.push_back("Topicos 1");
	
	Student student;

	student.setRegistry("17/0149439");
	student.setDisciplines(disciplines);
	student.setFirstName("Lucas");
	student.setLastName("de Albuquerque Silva");
	student.setCpf("039.040.531-08");
	student.setFacePicturesPath("/home/lucas/"+student.getRegistry());

	student.savePerson();
	student.closeConnection();	
	vector<string> result;

	try{
		result = student.executeQuery("Select * from person;");
  	}catch (sql::SQLException &e) {
  		cout << "# ERR: SQLException in " << __FILE__;
  		cout << __LINE__ << endl;
  		cout << "# ERR: " << e.what();
  		cout << " (MySQL error code: " << e.getErrorCode();
  		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  	}


	for(int i=0; i < result.size(); i++){
		cout<< result[i] << endl;		
	}

  return 0;
}
