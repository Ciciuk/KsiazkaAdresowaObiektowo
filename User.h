#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string userLogin;
    string userPassword;

   public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getLogin();
    string getPassword();
};

#endif