#include "AdressBook.h"

AdressBook::AdressBook(string userDatabaseName) : userManager(userDatabaseName) {
	userManager.loadUsersFromDataBase();
}
void AdressBook::registration() {
	userManager.newUserRegistration();
}
void AdressBook::logging() {
	userManager.logginng();
}

