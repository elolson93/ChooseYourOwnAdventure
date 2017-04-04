#include <iostream>
#include "Loader.h"
#include "User.h"

using namespace std;

Loader::Loader() {
	m_file_name = "game_save_data.txt";
	m_input.open(m_file_name);
}

Loader::~Loader() {
	m_input.close();
}

void Loader::loadGames(UserDB db) {
	string line;
	if (m_input.is_open()) {
    	while ( getline (m_input, line) ) {
    		//parse line
    		//set variables
      		User temp();
      		db.insertUser(temp);
    }
    m_input.close();
  } else {
  	cout << "Unable to load games" << endl;
  }
}