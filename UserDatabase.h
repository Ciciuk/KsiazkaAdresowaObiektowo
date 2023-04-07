#ifndef USERDATABASE_H
#define USERDATABASE_H


#include <string>
#include <fstream>

#include "User.h"

using namespace std;

class UserDatabase {
	string userDataBaseName;
	fstream userDataBase;

	string mergeUserLine(User data);

public:
	UserDatabase();

	void saveNewUserInDataBase(User newUser);

};
#endif