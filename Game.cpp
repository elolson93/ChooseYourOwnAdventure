#include "Game.h"
// #include "Loader.h"
// #include "Saver.h"
// #include "UserDB.h"
#include <iostream>

using namespace std;

Game::Game() {
	m_db = new UserDB();
}

Game::~Game() {
	delete m_db;
}

void Game::displayGameTitle() {
	cout << endl << "Welcome to Choose Your Own Adventure!" << endl;
	cout << "Developed by Eric Olson" << endl;
	cout << "2017" << endl << endl;
}

User* Game::newGame() {
	string player_name;
	cout << "Enter the name for the new player: ";
	cin >> player_name;

	User* temp_user = new User(player_name);
	int key = m_db->insertUser(temp_user);
	return m_db->loadUser(key);
}

User* Game::loadGame() {
	if (m_db->getSize() == 0) {
		m_loader = new Loader();
		m_loader->loadGames(m_db);
		delete m_loader;
	}

	int input = 0;

	if (m_db->getSize() == 0) {
		cout << "There are no games to load" << endl << endl;
	} else {
		m_db->viewUsers();
	}

	cout << "Choose a game to load or press 0 to go back: " << endl;
	cin >> input;

	if (input == 0) {
		return NULL;
	} else {
		return m_db->loadUser(input);
	}
}

int Game::deletePlayer() {
	if (m_db->getSize() == 0) {
		m_loader = new Loader();
		m_loader->loadGames(m_db);
		delete m_loader;
	}
	int input = 0;

	if (m_db->getSize() == 0) {
		cout << "There are no games to load" << endl;
	} else {
		m_db->viewUsers();
	}

	cout << "Choose a game to delete or press 0 to go back: " << endl;
	cin >> input;

	if (input == 0) {
		return -1;
	} else {
		return m_db->deleteUser(input);
	}
}

int main()
{
	Game* game = new Game();

	game->displayGameTitle();

	int option = 0;
	while (option == 0) {
		cout << "Please select an option from the list below:" << endl;
		cout << "1. ) Load Game" << endl;
		cout << "2. ) Delete Game" << endl;
		cout << "3. ) Start New Game" << endl;
		cout << "4. ) Quit" << endl;
		cin >> option;

		switch (option) {
			case 1: {
				cout << endl << "Load game selected." << endl << endl;
				User* temp = game->loadGame();
				temp->viewPlayer();
				break;
			}
			case 2: {
				cout << "Delete game selected." << endl;
				game->deletePlayer();
				option = 0;
				cout << endl;
				break;
			}
			case 3: {
				cout << endl << "New game selected" << endl << endl;
				User* temp = game->newGame();
				temp->viewPlayer();
				break;
			}
			case 4: {
				cout << "Quit selected" << endl;
				break;
			} 
			default: {
				cout << "Please select a valid option!" << endl << endl;
				option = 0;
			}
		}
	}



	// Saver* saver = new Saver;
	// cout << "Saving the games..." << endl;
	// saver->saveGames(db);

	return 0;
}