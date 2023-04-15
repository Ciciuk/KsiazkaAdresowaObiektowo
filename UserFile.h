#ifndef USERFILE_H
#define USERFILE_H

#include <fstream>
#include <string>
#include <vector>

#include "User.h"

using namespace std;

class UserFile {
    const string USER_FILE_NAME;

    string mergeUserLine(User data);

public:
    UserFile(string userFileName) : USER_FILE_NAME(userFileName) {
    }
    void saveNewUserInFile(User newUser);
    vector<User> loadUsersFromFile();
    void saveUserAfterPaswordChange(vector<User> users);
};
#endif