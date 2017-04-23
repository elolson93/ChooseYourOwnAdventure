#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
	m_db = new UserDB();
	m_user = NULL;

	m_loader = new Loader();
	m_loader->loadGames(m_db);
	delete m_loader;
}

Game::~Game() {
	delete m_db;
	delete m_user;
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
		return m_db->loadUser(input-1);
	}
}

int Game::deletePlayer() {
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
		return m_db->deleteUser(input-1);
	}
}

void Game::setActiveUser(User* user) {
	m_user = user;
}

User* Game::getActiveUser() {
	return m_user;
}

void Game::save() {
	m_saver = new Saver();
	m_saver->saveGames(m_db);
	delete m_saver;
}

void Game::play() {
	m_manager = new SceneManager(m_user);
	cout << endl << "Beginning the adventure..." << endl << endl;
	m_manager->begin();
	delete m_manager;
}