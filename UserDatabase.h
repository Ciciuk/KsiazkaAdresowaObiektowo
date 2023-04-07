#ifndef USERDATABASE_H
#define USERDATABASE_H


#include <string>
#include <fstream>
#include <vector>

#include "User.h"

using namespace std;

class UserDatabase {
	string userDataBaseName;
	fstream userDataBase;

	string mergeUserLine(User data);

public:
	UserDatabase();
	void saveNewUserInDataBase(User newUser);
	vector <User> loadUsersFromDataBase();
};
#endif   