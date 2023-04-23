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
    fstream contactFile, tempUserFile;
    string line;

    contactFile.open(getFileName().c_str(), ios::in);
    tempUserFile.open(("temp_" + getFileName()).c_str(), ios::out | ios::trunc);

    while (getline(contactFile, line)) {
        if (stoi((line.substr(0, line.find('|')))) != contactToDeleteId) {
            tempUserFile << line << endl;
            lastContactId = stoi((line.substr(0, line.find('|'))));
        }
    }

    contactFile.close();
    tempUserFile.close();

    remove(getFileName().c_str());
    rename(("temp_" + getFileName()).c_str(), getFileName().c_str());
}

void ContactFile::saveToFileAfterContactEdit(vector<Contact>::iterator contactToEdit) {
    fstream contactFile, tempCoontactFile;
    string line;
   // string name = "temp_" + *(getFileName().c_str());
 //   string name = "temp_" + getFileName();

    contactFile.open(getFileName().c_str(), ios::in);
    tempCoontactFile.open(("temp_" + getFileName()).c_str(), ios::out | ios::trunc);

    while (getline(contactFile, line)) {
        if (stoi((line.substr(0, line.find('|')))) != contactToEdit->getContactId())
            tempCoontactFile << line << endl;
        else if (stoi((line.substr(0, line.find('|')))) == contactToEdit->getContactId())
            tempCoontactFile << mergeContactLine(*contactToEdit) << endl;
    }

    contactFile.close();
    tempCoontactFile.close();

    remove(getFileName().c_str());
    rename(("temp_" + getFileName()).c_str(), getFileName().c_str());
}