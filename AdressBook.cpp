#include "AdressBook.h"

AdressBook::AdressBook() {
	userManager.loadUsersFromDataBase();
}
void AdressBook::registration() {
	userManager.newUserRegistration();
}
void AdressBook::logging() {
	userManager.logginng();
}

