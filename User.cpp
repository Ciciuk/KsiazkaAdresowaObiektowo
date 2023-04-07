#include "User.h"


void User::setId(int newId) {
	userId = newId;
}
void User::setLogin(string newLogin) {
	userLogin = newLogin;
}
void User::setPassword(string newPassword) {
	userPassword = newPassword;
}

int User::getId() {
	return userId;
}
string User::getLogin() {
	return userLogin;
}
string User::getPassword() {
	return userPassword;
}