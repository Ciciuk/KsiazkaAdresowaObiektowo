#ifndef USERFILE_H
#define USERFILE_H

#include <fstream>
#include <string>
#include <vector>

#include "User.h"

using namespace std;

class UserFile {
    const string userFileName;

    string mergeUserLine(User data);

   public:
    UserFile(string USERFILENAME) : userFileName(USERFILENAME) {
    }
    void saveNewUserInFile(User newUser);
    vector<User> loadUsersFromFile();
    void saveUserAfterPaswordChange(vector<User> users);
};
#endif