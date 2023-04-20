#ifndef USERFILE_H
#define USERFILE_H

#include <fstream>
#include <string>
#include <vector>

#include "File.h"
#include "User.h"

using namespace std;

class UserFile :public File{


    string mergeUserLine(User data);

public:
    UserFile(string userFileName) : File(userFileName) {
    }
    void saveNewUserInFile(User newUser);
    vector<User> loadUsersFromFile();
    void saveUserAfterPaswordChange(vector<User> users);
};
#endif