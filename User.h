#include <iostream>

using namespace std;

class User {
	int userId;
	string userLogin;
	string userPassword;

public:
	void settId(int newId);
	void settLogin(string newLogin);
	void settPassword(string newPassword);

	int gettId();
	string gettLogin();
	string gettPassword();
};
