#ifndef GAME_H
#define GAME_H

class Game {
private:
	//Make singleton?
	Saver m_saver;
	UserDB m_db;
	Menu m_menu;
	
public:
	void start();

};

#endif