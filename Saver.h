#ifndef SAVER_H
#define SAVER_H

#include <string>
#include "User.h"

class Saver: public FileAccessor {
private:
	//
public:
	Saver();
	Saver(std::string file_name);
	~Saver();
	void saveGame(User user);
};

#endif