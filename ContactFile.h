#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "Contact.h"

using namespace std;

class ContactFile {
    const string contactFileName;
    int lastContactId;

    string mergeContactLine(Contact data);

   public:
    ContactFile(string CONTACTFILENAME) : contactFileName(CONTACTFILENAME) {
        lastContactId = 0;
    }

    int getLastContactId();
    int getCurrentUserId();
    void setLastContactId(int newLastContactId);

    void saveNewContactInFile(Contact newUser);
    vector<Contact> loadContactsFromFile(int userId);
};
#endif