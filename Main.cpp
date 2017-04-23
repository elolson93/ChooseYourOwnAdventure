#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	Game* game = new Game();

	game->displayGameTitle();

	int option = 0;
	int startGame = 0;
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
				User* temp_user = game->loadGame();
				if (temp_user != NULL) {
					game->setActiveUser(temp_user);
					startGame = 1;
				} else {
					option = 0;
					cout << endl;
				}
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
				game->setActiveUser(game->newGame());
				startGame = 1;
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

	if (startGame) {
		game->play();
		cout << endl << "Thank you for playing" << endl << endl;
		game->save();
	} 
	delete game;
	
	return 0;
}