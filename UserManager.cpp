#include "UserManager.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>




void UserManager::newUserRegistration() {
	//User user;

	userDataGathering();

	if (users.empty())
		newUser.setId(1);
	else
		newUser.setId(users.back().getId() + 1);

	users.push_back(newUser);
	userDatabase.saveNewUserInDataBase(newUser);
	cout << "Rejestracja zakonczona" << endl << endl;
}

void UserManager::userDataGathering() {
	//User user;
	string login;

	do {
		cout << "Podaj login: " << endl;
		login = AditionalMethods::getWholeLine();
	} while (checkIfLoginIsNotUnique(login));
	newUser.setLogin(login);
	cout << "Podaj haslo: " << endl;
	newUser.setPassword(AditionalMethods::getWholeLine());

	//return user;
}

bool UserManager::checkIfLoginIsNotUnique(string login) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getLogin() == login) {
			cout << "Login juz istnieje, podaj inny login" << endl;
			system("pause");
			return true;
		}
	}

	return false;
}