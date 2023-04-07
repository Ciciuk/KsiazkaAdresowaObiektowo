#ifndef USERMENAGER_H
#define USERMENAGER_H


#include <iostream>
#include <vector>

#include "User.h"
#include "AditionalMethods.h"
#include "UserDatabase.h"

using namespace std;

class UserManager {
	vector <User> users;

	UserDatabase userDatabase;

	User newUser;

	void userDataGathering();
	bool checkIfLoginIsNotUnique(string login);

public:
	void newUserRegistration();
};

#endif