#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

class AdressBook {

	int idLoggedUser;

	string userDataBaseName;

	vector <User> Users;

	
	User userDataGathering();
	string getWholeLine();
	void saveNewUser(User newUser);
	string mergeUserLine(User data);
	bool checkIfLoginIsNotUnique(string login);

public:
	AdressBook();
	void insertNewUser();
};
