#ifndef _PROFESSOR_HPP
#define _PROFESSOR_HPP

#include<string>
#include "../person/person.hpp"
using namespace std;
#include "config/json.hpp"

using nlohmann::json;
class Professor: public Person{

private:
	string functionalRegistry;
	vector<string> disciplines;

public:
	Professor();
	Professor(string functionalRegistry,vector<string>disciplines);
	Professor(json j);
	
	void setFunctionalRegistry(string functionalRegistry);
	void setDisciplines(vector<string> disciplines);

	string getFunctionalRegistry();
	vector<string> getDisciplines();

	json to_json();
};
#endif 