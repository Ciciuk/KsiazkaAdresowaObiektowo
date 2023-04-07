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
	string userDatabaseName;
	UserDatabase userDatabase(userDatabaseName);

	User newUser;
	User loggedUser; 



	void userDataGathering();
	bool checkIfLoginIsNotUnique(string login);
	bool  checkIfEmptyUsers(); 
	bool checkPassword(vector <User>::iterator i); 
	bool checkLoginAndPassword();

public:
	UserManager(string userDatabaseName);
	void loadUsersFromDataBase();
	void newUserRegistration();
	void logginng();
};

#endif