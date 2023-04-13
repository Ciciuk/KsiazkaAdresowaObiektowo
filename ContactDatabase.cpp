#include "ContactDatabase.h"

ContactDatabase::ContactDatabase(string CONTACTDATABASENAME) : contactDataBaseName(CONTACTDATABASENAME) {
    currentUserId = 0;
    lastContactId = 0;
}

ContactDatabase::ContactDatabase(string CONTACTDATABASENAME, int userId) : contactDataBaseName(CONTACTDATABASENAME) {
    currentUserId = userId;
}

int ContactDatabase::getLastContactId() {
    return lastContactId;
}

int ContactDatabase::getCurrentUserId() {
    return currentUserId;
}

void ContactDatabase::setLastContactId(int newLastContactId) {
    lastContactId = newLastContactId;
}

void ContactDatabase::saveNewContactInDataBase(Contact newContact) {
    fstream contactDataBase;

    contactDataBase.open(contactDataBaseName.c_str(), ios::out | ios::app);
    contactDataBase << mergeContactLine(newContact) << endl;

    contactDataBase.close();
}

string ContactDatabase::mergeContactLine(Contact data) {
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

vector<Contact> ContactDatabase::loadContactsFromDataBase(int userId) {
    fstream contactDataBase;
    string line, temp;
    Contact data;
    vector<Contact> contacts;
    currentUserId = userId;

    contactDataBase.open("adresaci.txt", ios::in);

    while (getline(contactDataBase, line, '|')) {
        if (line == "\n")
            break;
        data.setContactId(atoi(line.c_str()));
        getline(contactDataBase, line, '|');
        data.setUserId(atoi(line.c_str()));
        getline(contactDataBase, temp, '|');
        data.setName(temp);
        getline(contactDataBase, temp, '|');
        data.setSurname(temp);
        getline(contactDataBase, temp, '|');
        data.setPhoneNumber(temp);
        getline(contactDataBase, temp, '|');
        data.setEmail(temp);
        getline(contactDataBase, temp, '|');
        data.setAdress(temp);
        if (currentUserId == data.getUserId())
            contacts.push_back(Contact(data));
        lastContactId = data.getContactId();
    }

    contactDataBase.close();

    return contacts;
}