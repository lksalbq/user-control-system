#include "reserve.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include "util/util.hpp"
using namespace util;

Reserve::Reserve(){};
  
Reserve::Reserve(int id,Person author, string purpose,string roomNumber,string initSchedule, 
	string endSchedule, bool recurrent,vector<Person> persons){
	
	setId(id);
	setAuthor(author);
	setPurpose(purpose);
	setRoom(roomNumber);
	setInitSchedule(initSchedule);
	setEndSchedule(endSchedule);
	setRecurrent(recurrent);
	setPersons(persons);		
}

Reserve::Reserve(json j){
	this->id = j.at("id");

    //get author
    json ja = json{{"person",j.at("author")}};
    Person pa(ja);
    this->author = pa;

	this->purpose = j.at("purpose").get<std::string>();	
	this->roomNumber = j.at("roomNumber").get<std::string>();	;

	this->initSchedule = j.at("initSchedule").get<std::string>();
	this->endSchedule = j.at("endSchedule").get<std::string>();
	this->recurrent = j.at("recurrent");
	
    json personsJson = j.at("persons");

	for (int i =0; i< personsJson.size(); i++) {
        json pj(personsJson[i]);
        Person p(pj);
        this->persons.push_back(p);
	}

}


void Reserve::setId(int id){
	this->id = id;
}  
int Reserve::getId(){
	return this->id;
}

Person Reserve::getAuthor(){
	return this->author;
}

void Reserve::setAuthor(Person author){
	this->author = author;
}
  
string Reserve::getPurpose(){
	return this->purpose;
}

void Reserve::setPurpose(string purpose){
	this->purpose = purpose;
}

string Reserve::getRoom(){
	return this->roomNumber;
}

void Reserve::setRoom(string roomNumber){
	this->roomNumber = roomNumber;
}

string Reserve::getInitSchedule(){
	return this->initSchedule;	
}

void Reserve::setInitSchedule(string initSchedule){
	this->initSchedule = initSchedule;	
}


string Reserve::getEndSchedule(){
	return this->endSchedule;	
}

void Reserve::setEndSchedule(string endSchedule){
	this->endSchedule = endSchedule;	
}


bool Reserve::getRecurrent(){
	return this->recurrent;	
}

void Reserve::setRecurrent(bool recurrent){
	this->recurrent = recurrent;	
}


json Reserve::getPersons(){
	json j;
	for (int i =0; i< this->persons.size(); i++){
        j.push_back(this->persons[i].person_to_json_reserve());
	}	
	return j;
}

void Reserve::setPersons(vector<Person> persons){
	this->persons = persons;	
}

json Reserve::to_json(){
	json j;
	j = json{{"id", this->getId()}, {"author", this->getAuthor().person_to_json()},
	{"purpose", this->getPurpose()},{"roomNumber", this->getRoom()},
	{"initSchedule", this->getInitSchedule()},{"endSchedule",this->getEndSchedule()},
    {"recurrent",this->getRecurrent()},{"persons",this->getPersons()}};
	return j;
}

string Reserve::getPathName(){
	return "reservations";
}

int Reserve::getNextId(){
	string p = "json_db/reservations";
	string id = "0";
	vector<int> nextIdVec;
	int nextId = 0;
    if (boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
      	boost::filesystem::directory_iterator end_iter;

		for (boost::filesystem::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
			id = dir_itr->path().filename().string();
			util::removeJsonFormat(id);
			int temp = nextId;			
			nextIdVec.push_back(stoi(id));
			
		}
    }else{
  		return nextId;
  	}
  	nextId = *max_element(nextIdVec.begin(), nextIdVec.end());
  	return nextId+1;
}
