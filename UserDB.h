#ifndef USER_DB_H
#define USER_DB_H

#include <map>
#include "User.h"

class UserDB {
private:
	std::map<int, User> m_map;
public:
	UserDB();
	int getSize();
	void insertUser(User user);
	void deleteUser(int num);
	User loadUser(int num);
	void viewUsers();
};

#endif