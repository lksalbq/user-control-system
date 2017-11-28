#ifndef _ROOM_HPP
#define _ROOM_HPP

#include <string>
#include <vector>
#include "../reserve/reserve.hpp"
#include "config/json.hpp"

using nlohmann::json;
using namespace std;


class Reserve;

class Room{
protected:
  string roomNumber;
  vector<Reserve> reservations;

public:
  Room();
  Room(string roomNumber, vector<Reserve> reservations);
  Room(json j);
  
  string getRoomNumber();
  void setRoomNumber(string roomNumber);

  json getReservations();
  vector<Reserve> getReservationsVec();
  void setReservations(vector<Reserve> reservation);
  
  json to_json();

  string getPathName();
};
#endif
