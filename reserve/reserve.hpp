#ifndef _DISCIPLNE_HPP
#define _DISCIPLINE_HPP

#include <string>
#include <vector>
#include "../config/database.hpp"
#include "../discipline/discipline.hpp"
#include "../room/room.hpp"

using namespace std;

class Reserve: public Database{
protected:
  int id;
  string author;
  string purpose;
  Discipline discipline;
  Room room;
  time_t initSchedule;
  time_t endSchedule;
  vector<Person> persons;
public:
  Discipline();
  Discipline(string author, string purpose,Discipline discipline,Room room, time_t initSchedule, time_t endSchedule,  vector<Person> persons);
  
  int getId();

  string getAuthor();
  void setAuthor(string author);
  
  string getPurpose();
  void setPurpose(string purpose);

  Discipline getDiscipline();
  void setDiscipline(Discipline discipline);

  Discipline getRoom();
  void setRoom(Room room);

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
