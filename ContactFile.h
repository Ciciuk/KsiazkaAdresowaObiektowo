#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "Contact.h"

using namespace std;

class ContactFile {
    const string CONTACT_FILE_NAME;
    int lastContactId;

    string mergeContactLine(Contact data);

   public:
    ContactFile(string contatFileName) : CONTACT_FILE_NAME(contatFileName) {
        lastContactId = 0;
    }

    int getLastContactId();

    void saveNewContactInFile(Contact newUser);
    vector<Contact> loadContactsFromFile(int userId);
};
#endif