#ifndef GAME_H
#define GAME_H

#include "Loader.h"
#include "Saver.h"
#include "UserDB.h"
#include "SceneManager.h"

class Game {
private:
	Saver* m_saver;
	UserDB* m_db;
	Loader* m_loader;
	User* m_user;
	SceneManager* m_manager;
	
public:
	Game();
	~Game();
	void displayGameTitle();
	User* newGame();
	User* loadGame();
	int deletePlayer();
	void setActiveUser(User* user);
	User* getActiveUser();
	void save();
	void play();

};

#endif