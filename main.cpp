#include "users/student.hpp"
#include "users/professor.hpp"
#include "discipline/discipline.hpp"
#include "room/room.hpp"
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
	student.setFacePicturesPath("/home/lucas/"+student.getRegistry());

	Student student2;

	student2.setRegistry("11/0128796");
	student2.setFirstName("Lucas OLd");
	student2.setLastName("Silva");
	student2.setCpf("039.040.531-08");
	student2.setFacePicturesPath("/home/lucas1/"+student.getRegistry());

	Professor professor;

	professor.setFunctionalRegistry("1111112222");
	professor.setFirstName("Teofilo");

	vector<Person> persons;

	persons.push_back(student);
	persons.push_back(student);

	Reserve r(0,professor,"Aula X" ,"23-A",t, t, true,persons);
	r.setId(r.getNextId());

	vector<Reserve> resrevations;
	resrevations.push_back(r);

	Room room;
	room.setRoomNumber("23-A-b..5");
	room.setReservations(resrevations);

	cout<<r.getId()<<endl;

	//util::saveJson(room.getPathName(),room.getRoomNumber(),room.to_json());
	util::saveJson(r.getPathName(),std::to_string(r.getId()),r.to_json());


  return 0;
}
