#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "File.h"
#include "Contact.h"

using namespace std;

class ContactFile :public File{
    int lastContactId;
    string mergeContactLine(Contact data);

public:
    ContactFile(string contactFileName) : File(contactFileName) {
        lastContactId = 0;
    }

    int getLastContactId();

    void saveNewContactInFile(Contact newUser);
    vector<Contact> loadContactsFromFile(int userId);
};
#endif