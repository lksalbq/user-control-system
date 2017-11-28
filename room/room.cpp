#include "room.hpp"
#include "util/util.hpp"
using namespace util;

Room::Room(){};
  
Room::Room(string roomNumber, vector<Reserve> reservations){
	setRoomNumber(roomNumber);
	setReservations(reservations);
}

Room::Room(json j){
	this->roomNumber = j.at("roomNumber").get<std::string>();
	json reservationsJson = j.at("reservations");

	for (int i =0; i< reservationsJson.size(); i++) {
  		Reserve r(reservationsJson[i]);
  		this->reservations.push_back(r);
	}

}

void Room::setRoomNumber(string roomNumber){
	this->roomNumber = roomNumber;
}  

string Room::getRoomNumber(){
	return this->roomNumber;
}

json Room::getReservations(){
	json j;
	for (int i =0; i< this->reservations.size(); i++){
		j.push_back(this->reservations[i].to_json());
	}
	return j;
}

vector<Reserve> Room::getReservationsVec(){
	return this->reservations;
}

void Room::setReservations(vector<Reserve> reservations){
	this->reservations = reservations;	
}

json Room::to_json(){
	json j;
	j = json{{"roomNumber", this->getRoomNumber()}, {"reservations", this->getReservations()}};
	return j;
}

string Room::getPathName(){
	return "rooms";
}