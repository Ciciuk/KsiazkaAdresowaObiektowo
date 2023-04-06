#include "AdressBook.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>


AdressBook::AdressBook() {
	userDataBaseName = "uzytkownicy.txt";
}

void AdressBook::insertNewUser() {
	User user;

	user = userDataGathering();

	if (Users.empty())
		user.settId(1);
	else
		user.settId(Users.back().gettId() + 1);

	Users.push_back(user);
	saveNewUser(user);
	cout << "Rejestracja zakonczona" << endl << endl;
}
User AdressBook::userDataGathering() {
	User user;
	string login;

	do {
		cout << "Podaj login: " << endl;
		login = getWholeLine();
	}while (checkIfLoginIsNotUnique(login));
	user.settLogin(login);
	cout << "Podaj haslo: " << endl;
	user.settPassword(getWholeLine());

	return user;
}
bool AdressBook::checkIfLoginIsNotUnique(string login) {
	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].gettLogin() == login) {
			cout << "Login juz istnieje, podaj inny login" << endl;
			system("pause");
			return true;
		}
	}

	return false;
}
string AdressBook::getWholeLine() {
	string line;

	cin.sync();
	getline(cin, line);

	return line;
}
void AdressBook::saveNewUser(User newUser) {
	fstream userDataBase;

	userDataBase.open(userDataBaseName.c_str(), ios::out | ios::app);
	userDataBase << mergeUserLine(newUser) << endl;

	userDataBase.close();
}
string AdressBook::mergeUserLine(User data) {
	string line = "";

	line += to_string(data.gettId()) + '|';
	line += data.gettLogin() + '|';
	line += data.gettPassword() + '|';

	return line;
}