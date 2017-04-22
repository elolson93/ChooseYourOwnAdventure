#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>
#include <vector>
#include "UserDB.h"

class Loader {
private:
	std::string m_file_name;
	std::ifstream m_input;
public:
	void parseLine(std::string line, std::string delimeter, std::vector<std::string>* vec);
	Loader();
	~Loader();
	void loadGames(UserDB* db);
};

#endif