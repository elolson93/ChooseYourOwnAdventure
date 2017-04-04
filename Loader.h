#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>
#include "UserDB.h"

class Loader {
private:
	std::string m_file_name;
	std::ifstream m_input;
public:
	Loader();
	~Loader();
	void loadGames(UserDB db);
};

#endif