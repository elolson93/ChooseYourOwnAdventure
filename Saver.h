#ifndef SAVER_H
#define SAVER_H

#include <string>
#include <fstream>
#include "UserDB.h"

class Saver {
private:
	std::string m_file_name;
	std::ofstream m_output;
public:
	Saver();
	~Saver();
	void saveGames(UserDB* db);
};

#endif