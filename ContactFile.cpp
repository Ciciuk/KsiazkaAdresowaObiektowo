#include "ContactFile.h"

int ContactFile::getLastContactId() {
    return lastContactId;
}

void ContactFile::saveNewContactInFile(Contact newContact) {
    fstream contactFile;

    contactFile.open(getFileName().c_str(), ios::out | ios::app);
    contactFile << mergeContactLine(newContact) << endl;
    contactFile.close();

    lastContactId = newContact.getContactId();
}

string ContactFile::mergeContactLine(Contact data) {
    string line = "";

    line += to_string(data.getContactId()) + '|';
    line += to_string(data.getUserId()) + '|';
    line += data.getName() + '|';
    line += data.getSurname() + '|';
    line += data.getPhoneNumber() + '|';
    line += data.getEmail() + '|';
    line += data.getAdress() + '|';

    return line;
}

vector<Contact> ContactFile::loadContactsFromFile(int userId) {
    fstream contactFile;
    string line, temp;
    Contact data;
    vector<Contact> contacts;
    int currentUserId = userId;

    contactFile.open(getFileName().c_str(), ios::in);

    while (getline(contactFile, line, '|')) {
        if (line == "\n")
            break;
        data.setContactId(atoi(line.c_str()));
        getline(contactFile, line, '|');
        data.setUserId(atoi(line.c_str()));
        getline(contactFile, temp, '|');
        data.setName(temp);
        getline(contactFile, temp, '|');
        data.setSurname(temp);
        getline(contactFile, temp, '|');
        data.setPhoneNumber(temp);
        getline(contactFile, temp, '|');
        data.setEmail(temp);
        getline(contactFile, temp, '|');
        data.setAdress(temp);
        if (currentUserId == data.getUserId())
            contacts.push_back(Contact(data));
        lastContactId = data.getContactId();
    }

    contactFile.close();

    return contacts;
}

void ContactFile::saveToFileAfterContactRemove(int contactToDeleteId) {
    fstream userFile, tempUserFile;
    string line;

    userFile.open(getFileName().c_str(), ios::in);
    tempUserFile.open(*(getFileName().c_str()) + "_temp.txt", ios::out | ios::trunc);

    while (getline(userFile, line)) {
        if (stoi((line.substr(0, line.find('|')))) != contactToDeleteId) {
            tempUserFile << line << endl;
            lastContactId = stoi((line.substr(0, line.find('|'))));
        }
    }

    userFile.close();
    tempUserFile.close();

    remove("adresaci.txt");
    rename(*(getFileName().c_str()) + "_temp.txt", "adresaci.txt");
}