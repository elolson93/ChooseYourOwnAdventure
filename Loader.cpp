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

void Loader::loadGames(UserDB* db) {
	string line;
	if (m_input.is_open()) {
    	while ( getline (m_input, line) ) {
        vector<string> temp_vector;
        parseLine(line, ",", &temp_vector);
      	User* temp = new User(temp_vector.at(0), stoi(temp_vector.at(1)), stoi(temp_vector.at(2)));
      	db->insertUser(temp);
    }
    m_input.close();
  } else {
  	cout << "Unable to load games" << endl;
  }
}

void Loader::parseLine(string line, string delimeter, vector<string>* vec) {
  size_t pos = 0;
  string token;
  while ((pos = line.find(delimeter)) != std::string::npos) {
    token = line.substr(0, pos);
    vec->push_back(token);
    line.erase(0, pos + delimeter.length());
  }
  vec->push_back(line);
}