#include "UserDB.h"
#include <iostream>

using namespace std;

UserDB::UserDB() {}

int UserDB::getSize() {
	return m_vector.size();
}

int UserDB::insertUser(User* user) {
	m_vector.push_back(user);
	return m_vector.size() - 1;
}

int UserDB::deleteUser(int num) {
	delete m_vector.at(num);
	m_vector.erase(m_vector.begin() + num);
	return 1;
}

User* UserDB::loadUser(int num) {
	return m_vector.at(num);
}

void UserDB::viewUsers() {
	vector<User*>::iterator it;
	int i = 1;
	for (it = m_vector.begin(); it < m_vector.end(); it++, i++) {
		cout << i << ". ";
		(*it)->viewPlayer();
		cout << endl;
	}
}