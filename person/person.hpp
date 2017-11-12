#ifndef _PERSON_HPP
#define _PERSON_HPP

#include <string>
#include <vector>
using namespace std;

class Person{
protected:
  string firstName;
  string lastName;
  string cpf;
  vector<string> facePicturesPath;
public:
  Person();
  Person(string name, string lastName, vector<string> facePictures);
  string getFirstName();
  void setFirstName(string firstName);
  
  string getLastName();
  void setLastName(string lastName);

  void setCpf(string cpf);
  string getCpf();
  
  vector<string> getFacePicturesPath();
  void setFacePicturesPath(vector<string> facePicturesPath);

  void addPerson(Person p);
  Person getPerson();
};


#endif
