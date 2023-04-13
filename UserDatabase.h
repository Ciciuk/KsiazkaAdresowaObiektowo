#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <fstream>
#include <string>
#include <vector>

#include "User.h"

using namespace std;

class UserDatabase {
    const string userDataBaseName;

    string mergeUserLine(User data);

   public:
    UserDatabase(string USERDATABASENAME);
    void saveNewUserInDataBase(User newUser);
    vector<User> loadUsersFromDataBase();
    void saveUserAfterPaswordChange(vector<User> users);
};
#endif