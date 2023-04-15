#include "ContactFile.h"

int ContactFile::getLastContactId() {
    return lastContactId;
}

void ContactFile::saveNewContactInFile(Contact newContact) {
    fstream contactFile;

    contactFile.open(CONTACT_FILE_NAME.c_str(), ios::out | ios::app);
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

    contactFile.open(CONTACT_FILE_NAME.c_str(), ios::in);

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