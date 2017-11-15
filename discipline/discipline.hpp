#ifndef _DISCIPLNE_HPP
#define _DISCIPLINE_HPP

#include <string>
#include <vector>
#include "../config/database.hpp"
#include "../users/student.hpp"
#include "../users/professor.hpp"

using namespace std;

class Discipline: public Database{
protected:
  int id;
  string name;
  string description;
  string department;
  time_t initSchedule;
  time_t endSchedule;
  vector<Student> students;
  Professor professor;
public:
  Discipline();
  Discipline(string name, string description,string department, time_t initSchedule, time_t endSchedule,  vector<Student> students, Professor professor);
  
  int getId();

  string getName();
  void setName(string name);
  
  string getDescription();
  void setDescription(string description);

  string getDepartment();
  void setDepartment(string department);

  void setInitSchedule(time_t initSchedule);
  time_t getInitSchedule();
  
  void setEndSchedule(time_t endSchedule);
  time_t getEndSchedule();

  void setStudents(vector<Student> students);
  string getStudents();

  void setProfessor(Professor professor);
  Professor getProfessor();
  
  void saveDiscipline();
};
#endif
