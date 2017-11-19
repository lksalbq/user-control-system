#ifndef _RESERVE_HPP
#define _RESERVE_HPP

#include <string>
#include <vector>
#include "../room/room.hpp"
#include "../person/person.hpp"
#include "config/json.hpp"

using nlohmann::json;

using namespace std;

class Reserve{
protected:
  int id;
  Person author;
  string purpose;
  string roomNumber;
  time_t initSchedule;
  time_t endSchedule;
  bool recurrent;
  vector<Person> persons;
public:
  Reserve();
  Reserve(int id,Person author, string purpose,string roomNumber, 
  time_t initSchedule, time_t endSchedule,bool recurrent,vector<Person> persons);
  Reserve(json j);

  int getId();
  void setId(int id);

  Person getAuthor();
  void setAuthor(Person author);
  
  string getPurpose();
  void setPurpose(string purpose);

  string getRoom();
  void setRoom(string roomNumber);

  void setInitSchedule(time_t initSchedule);
  time_t getInitSchedule();
  
  void setEndSchedule(time_t endSchedule);
  time_t getEndSchedule();

  void setRecurrent(bool recurrent);
  bool getRecurrent();

  void setPersons(vector<Person> persons);
  json getPersons();

  json to_json();

  string getPathName();
  int getNextId();
};
#endif
