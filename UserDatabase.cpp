#include "UserDatabase.h"

UserDatabase::UserDatabase(string USERDATABASENAME) : userDataBaseName(USERDATABASENAME) {
}

void UserDatabase::saveNewUserInDataBase(User newUser) {
    fstream userDataBase;

    userDataBase.open(userDataBaseName.c_str(), ios::out | ios::app);

    userDataBase << mergeUserLine(newUser) << endl;

    userDataBase.close();
}

string UserDatabase::mergeUserLine(User data) {
    string line = "";

    line += to_string(data.getId()) + '|';
    line += data.getLogin() + '|';
    line += data.getPassword() + '|';

    return line;
}

vector<User> UserDatabase::loadUsersFromDataBase() {
    string line;
    string temp;
    vector<User> users;
    User data;
    fstream userDataBase;

    userDataBase.open(userDataBaseName.c_str(), ios::in);

    while (getline(userDataBase, line, '|')) {
        if (line == "\n")
            break;
        data.setId(atoi(line.c_str()));
        getline(userDataBase, temp, '|');
        data.setLogin(temp);
        getline(userDataBase, temp, '|');
        data.setPassword(temp);
        users.push_back(User(data));
    }

    userDataBase.close();
    return users;
}

void UserDatabase::saveUserAfterPaswordChange(vector<User> users) {  // tutaj nie wiem czy lepiej zapisac sobie u�ytkownik�w w tej klasie, przesy�a� ich do tej funkcji czy zrobic jeszcze raz proces wczytywania z pliku
    fstream userDataBase;

    userDataBase.open(userDataBaseName, ios::out | ios::trunc);

    for (auto i = users.begin(); i < users.end(); i++) {
        userDataBase << mergeUserLine(*i) << endl;
    }

    userDataBase.close();
}