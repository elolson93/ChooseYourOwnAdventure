#ifndef USER_DB_H
#define USER_DB_H

#include <vector>
#include "User.h"

class UserDB {
private:
	std::vector<User*> m_vector;
public:
	UserDB();
	int getSize();
	int insertUser(User* user);
	int deleteUser(int num);
	User* loadUser(int num);
	void viewUsers();
};

#endif