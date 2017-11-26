#include "users/student.hpp"
#include "users/professor.hpp"
#include "users/employee.hpp"
#include "discipline/discipline.hpp"
#include "room/room.hpp"
#include "cam-interface/camInterface.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "config/json.hpp"
#include "util/util.hpp"
using namespace util;
// for convenience
using json = nlohmann::json;
using namespace std;


int main(int argc, char **argv){

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;

	Student student;

	student.setRegistry("17/0149439");
	student.setFirstName("Lucas");
	student.setLastName("de Albuquerque Silva");
	student.setCpf("039.040.531-08");

	string stFace = util::createFacePicturesPath(student.getPathName(),student.getRegistry());
	student.setFacePicturesPath(stFace);

	Employee g;
	g.setFunctionalRegistry("10209850");
	g.setFirstName("Maria");
	g.setLastName("de Albuquerque Silva");
	g.setCpf("152.880.051-68");

	//set face picture path
	util::saveJson(g.getPathName(),g.getFunctionalRegistry(),g.to_json());
	string facePath = util::createFacePicturesPath(g.getPathName(),g.getFunctionalRegistry());
	g.setFacePicturesPath(facePath);
	util::saveJson(g.getPathName(),g.getFunctionalRegistry(),g.to_json());

	Employee e;

	string registry = "10209850";
	json j = util::readJson(util::getJsonFullPath(e.getPathName(),registry));

	Employee emp(j);

	cout << emp.getFacePicturesPath() <<endl;

	// CamInterface cam;
	// cam.setFilePath(student.getFacePicturesPath());
	// cam.setWindowName("MOSOQ");
	// cam.openVideoCapture(false);

	CamInterface cam2;
	cam2.setFilePath(util::createFacePicturesPath(student.getPathName(),student.getRegistry()));
	//cam2.setFilePath(emp.getFacePicturesPath());
	cam2.setWindowName("MOSOQ");
	int a = cam2.openVideoCapture(true);
	
	if(a>=1){
		cout<<"FACE RECONHECIDA"<<endl;
	}else{
		cout<<"FACE NAO RECONHECIDA"<<endl;
	}

  return 0;
}
