#include "Saver.h"

using namespace std;

Saver::Saver() {
	m_file_name = "game_save_data.txt";
	m_output.open(m_file_name);
}

Saver::~Saver() {
	m_output.close();
}

void Saver::saveGames(UserDB* db) {
	for (int i = 0; i < db->getSize(); ++i)
	{
		User* temp = db->loadUser(i);
		m_output << temp->getUserName() << "," << temp->getCurrentScene();
		m_output << "," << temp->getCurrentScore() << endl;
	}
}