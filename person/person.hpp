#ifndef _PERSON_HPP
#define _PERSON_HPP

#include <string>
#include <vector>
#include "config/json.hpp"

using nlohmann::json;
using namespace std;

class Person{
protected:
  string firstName;
  string lastName;
  string cpf;
  string facePicturesPath;

public:
  Person();
  Person(string name, string lastName,string facePicturesPath);
  Person(json j);
  
  string getFirstName();
  void setFirstName(string firstName);
  
  string getLastName();
  void setLastName(string lastName);

  void setCpf(string cpf);
  string getCpf();
  
  string getFacePicturesPath();
  void setFacePicturesPath(string facePicturesPath);

  void addPerson(Person p);
  Person getPerson();

  json person_to_json();
  json person_to_json_reserve();
  void savePerson();
};
#endif
