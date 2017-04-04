#include "Loader.h"
#include "Saver.h"
#include "UserDB.h"

int main()
{
	UserDB db;
	//Menu menu;
	Saver saver;
	Loader loader;

	//menu.displayTitle();
	//menu.displayOptions();

	cout << "Loading the games..." << endl << endl;
	loader.loadGames(db);

	cout << "Viewing the loaded games..." << endl;
	db.viewGames();

	cout << endl << "Saving the games..." << endl;
	saver.saveGames(db);

	return 0;
}