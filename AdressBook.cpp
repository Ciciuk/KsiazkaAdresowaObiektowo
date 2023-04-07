#include "AdressBook.h"

AdressBook::AdressBook(string userDatabaseName) : userManager(userDatabaseName) {
	userManager.loadUsersFromDataBase();
}

void AdressBook::registration() {
	userManager.newUserRegistration();
}
void AdressBook::logging() {
	if (userManager.logginng()) {
		ContactManager contactManager("adresaci.txt", userManager.getLoggedUserId());
		contactManager.loadContactsFromDataBase();
		contactManager.displayAllContacts();
	}
}

