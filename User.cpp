#include "User.h"


void User::settId(int newId) {
	userId = newId;
}
void User::settLogin(string newLogin) {
	userLogin = newLogin;
}
void User::settPassword(string newPassword) {
	userPassword = newPassword;
}

int User::gettId() {
	return userId;
}
string User::gettLogin() {
	return userLogin;
}
string User::gettPassword() {
	return userPassword;
}