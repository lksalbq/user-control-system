#include <sys/types.h>
#include <sys/stat.h>
#include <boost/filesystem.hpp>
#include <string>
#include <limits.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "config/json.hpp"
using nlohmann::json;
using namespace std;

namespace util{
   void saveJson(string pathName, json j);
   json readJson(string path);
   string getexepath();
   void createDirectory(string path);
   void sanitize(std::string &stringValue);
}