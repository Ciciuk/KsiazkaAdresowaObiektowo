#include "UserDatabase.h"

UserDatabase::UserDatabase() {
	userDataBaseName = "uzytkownicy.txt";
}

void UserDatabase::saveNewUserInDataBase(User newUser) {
	

	userDataBase.open(userDataBaseName.c_str(), ios::out | ios::app);
	userDataBase << mergeUserLine(newUser) << endl;

	userDataBase.close();
}

string UserDatabase::mergeUserLine(User data) {
	string line = "";

	line += to_string(data.getId()) + '|';
	line += data.getLogin() + '|';
	line += data.getPassword() + '|';

	return line;
}