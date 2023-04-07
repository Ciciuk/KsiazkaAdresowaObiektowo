#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>


#include "User.h"
#include "AditionalMethods.h"
#include "UserDatabase.h"

using namespace std;

class UserManager {
	vector <User> users;
	UserDatabase userDatabase;

	User newUser;
	User loggedUser; 



	void userDataGathering();
	bool checkIfLoginIsNotUnique(string login);
	bool  checkIfEmptyUsers(); 
	bool checkPassword(vector <User>::iterator i); 
	bool checkLoginAndPassword();

public:
	UserManager(string userDatabaseName);

	int getLoggedUserId();

	void loadUsersFromDataBase();
	void newUserRegistration();
	bool logginng();
};

#endif