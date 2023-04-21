#include "UserFile.h"

void UserFile::saveNewUserInFile(User newUser) {
    fstream userFile;

    userFile.open(getFileName().c_str(), ios::out | ios::app);

    userFile << mergeUserLine(newUser) << endl;

    userFile.close();
}

string UserFile::mergeUserLine(User data) {
    string line = "";

    line += to_string(data.getId()) + '|';
    line += data.getLogin() + '|';
    line += data.getPassword() + '|';

    return line;
}

vector<User> UserFile::loadUsersFromFile() {
    string line;
    string temp;
    vector<User> users;
    User data;
    fstream userFile;

    userFile.open(getFileName().c_str(), ios::in);

    while (getline(userFile, line, '|')) {
        if (line == "\n")
            break;
        data.setId(atoi(line.c_str()));
        getline(userFile, temp, '|');
        data.setLogin(temp);
        getline(userFile, temp, '|');
        data.setPassword(temp);
        users.push_back(User(data));
    }

    userFile.close();
    return users;
}

void UserFile::saveUserAfterPaswordChange(vector<User> users) {  // tutaj nie wiem czy lepiej zapisac sobie u�ytkownik�w w tej klasie, przesy�a� ich do tej funkcji czy zrobic jeszcze raz proces wczytywania z pliku
    fstream userFile;
    string tempFileName = getFileName().c_str();

    userFile.open(getFileName().c_str(), ios::out | ios::trunc);

    for (auto i = users.begin(); i < users.end(); i++) {
        userFile << mergeUserLine(*i) << endl;
    }

    userFile.close();
}