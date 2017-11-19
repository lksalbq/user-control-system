#ifndef _DISCIPLNE_HPP
#define _DISCIPLINE_HPP

#include <string>
using namespace std;
#include "config/json.hpp"

using nlohmann::json;

class Discipline{
protected:
  string code;
  string name;
  string description;
  string department;
  string disciplineClass;

public:
  Discipline();
  Discipline(string code,string name, string description,string department, string disciplineClass);
  Discipline(json j);  

  string getCode();
  void setCode(string code);

  string getName();
  void setName(string name);
  
  string getDescription();
  void setDescription(string description);

  string getDepartment();
  void setDepartment(string department);

  string getDisciplineClass();
  void setDisciplineClass(string disciplineClass);


  json to_json();

};
#endif
