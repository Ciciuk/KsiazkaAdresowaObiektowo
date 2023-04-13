#ifndef CONTACTDATABASE_H
#define CONTACTDATABASE_H

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "Contact.h"

using namespace std;

class ContactDatabase {
    const string contactDataBaseName;
    int lastContactId;
    int currentUserId;

    string mergeContactLine(Contact data);

   public:
    ContactDatabase(string CONTACTDATABASENAME);
    ContactDatabase(string CONTACTDATABASENAME, int userId);  // narazie nie uzywane

    int getLastContactId();
    int getCurrentUserId();
    void setLastContactId(int newLastContactId);

    void saveNewContactInDataBase(Contact newUser);
    vector<Contact> loadContactsFromDataBase(int userId);
};
#endif