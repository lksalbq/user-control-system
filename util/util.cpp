
#include "util.hpp"

//save json to a specific path
void util::saveJson(string identifierPath,string fileName,json j){
    
    util::sanitize(fileName);
    util::createDirectory(util::getexepath()+"/json_db");
	util::createDirectory(util::getexepath()+"/json_db/"+identifierPath);
	string rootPath = util::getexepath()+"/json_db/"+identifierPath+"/"+fileName+".json";
	
    std::ofstream o(rootPath);
	o << std::setw(4) << j << std::endl;

	std::cout<< "Json saved on dir>>"+rootPath<<std::endl;
}	

json util::readJson(string identifierPath){
	// read a JSON file
	std::ifstream i(identifierPath);
	json j;
	i >> j;
	return j;
}


string util::getexepath(){
  char result[ PATH_MAX ];
  ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
  std::string path = std::string( result, (count > 0) ? count : 0 );
  return path.substr(0, path.find_last_of("\\/"));
}

void util::createDirectory(string path){
	boost::filesystem::path dir(path);
	if(boost::filesystem::create_directory(dir)) {
		std::cout << "Success" << "\n";
	}else{
		std::cout << "Path already exists!" << "\n";
	}	
}

void util::sanitize(std::string &stringValue){
    // Add backslashes.
    for (auto i = stringValue.begin();;) {
        auto const pos = std::find_if(
            i, stringValue.end(),
            [](char const c) { return '\\' == c || '\'' == c || '"' == c; }
        );
        if (pos == stringValue.end()) {
            break;
        }
        i = std::next(stringValue.insert(pos, '\\'), 2);
    }

    // Removes others.
    stringValue.erase(
        std::remove_if(
            stringValue.begin(), stringValue.end(), [](char const c) {
                return '\n' == c || '\r' == c || '\0' == c || '\x1A' == c || '-' == c || '.' == c || '/' == c || '/' == c;
            }
        ),
        stringValue.end()
    );
}

void util::removeJsonFormat(std::string &stringValue){
    stringValue.erase(stringValue.size()-5,5);
}

string util::createFacePicturesPath(string identifier, string pathName){
    util::sanitize(pathName);
    util::createDirectory(util::getexepath()+"/json_db/"+identifier+"/faces-path");
    util::createDirectory(util::getexepath()+"/json_db/"+identifier+"/faces-path/"+pathName);
    return util::getexepath()+"/json_db/"+identifier+"/faces-path/"+pathName;
}

string util::getJsonFullPath(string pathName,string fileId){
    util::sanitize(fileId);
    return util::getexepath()+"/json_db/"+pathName+"/"+fileId+".json";
}