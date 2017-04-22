#ifndef GAME_H
#define GAME_H

#include "Loader.h"
#include "Saver.h"
#include "UserDB.h"

class Game {
private:
	Saver* m_saver;
	UserDB* m_db;
	Loader* m_loader;
	
public:
	Game();
	~Game();
	void displayGameTitle();
	User* newGame();
	User* loadGame();
	int deletePlayer();

};

#endif