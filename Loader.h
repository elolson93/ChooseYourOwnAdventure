#ifndef LOADER_H
#define LOADER_H

#include <string>

class Loader: public FileAccessor {
private:
	//
public:
	Loader();
	Loader(std::string file_name);
	~Loader();
	void loadGames(UserDB db);
};

#endif