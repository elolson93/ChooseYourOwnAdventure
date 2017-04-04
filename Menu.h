#ifndef MENU_H
#define MENU_H

#include "Loader.h"
#include "UserDB.h"

class Menu {
private:
	Loader m_loader;
	UserDB m_db;
public:
	Menu();
	~Menu();
	void displayTitle();
	void displayOptions();
	User newGameSelected();
	int deletePlayerSelected();
	User loadGameSelected();
};

#endif

Menu() {
	//initialize loader
	//initialize db
	//m_loader.loadGames(m_db);
}

~Menu() {
	//delete loader
}

void Menu::displayTitle() {

}

void Menu::displayOptions() {

}

User Menu::newGameSelected() {
	string player_name;
	cout << "Enter the name for the new player: ";
	getline(cin, player_name);

	User temp_user(player_name);
	int key = m_db.insertUser(temp_user);
	return m_db.loadUser(key);
}

int Menu::deletePlayerSelected() {
	int input = 0;

	if (m_db.getSize() == 0) {
		cout << "There are no games to load" << endl;
	} else {
		m_db.viewUsers();
	}

	cout << "Choose a game to delete or press 0 to go back: ";
	cin >> input;

	if (input == 0) {
		return null;
	} else {
		return m_db.deleteUser(input);
	}
}

User Menu::loadGameSelected() {
	int input = 0;

	if (m_db.getSize() == 0) {
		cout << "There are no games to load" << endl;
	} else {
		m_db.viewUsers();
	}

	cout << "Choose a game to load or press 0 to go back: ";
	cin >> input;

	if (input == 0) {
		return null;
	} else {
		return m_db.loadUser(input);
	}
}
