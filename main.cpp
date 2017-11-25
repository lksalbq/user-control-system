#include "users/student.hpp"
#include "users/professor.hpp"
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

	//set face picture path
	string facePath = util::createFacePicturesPath(student.getPathName(),student.getRegistry());
	student.setFacePicturesPath(facePath);

	util::createDirectory(student.getPathName());
	util::saveJson(student.getPathName(),student.getRegistry(),student.to_json());

	Student s;

	string registry = "17/0149439";
	json j = util::readJson(util::getJsonFullPath(s.getPathName(),registry));

	Student st(j);

	cout << st.getFacePicturesPath() <<endl;

	CamInterface cam;
	cam.setFilePath(st.getFacePicturesPath());
	cam.setWindowName("MOSOQ");
	cam.setMorePictures(true);

	cam.openVideoCapture();
	
  return 0;
}
