#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "AditionalMethods.h"
#include "Contact.h"
#include "ContactDatabase.h"

using namespace std;

class ContactManager {
    vector<Contact> contacts;
    ContactDatabase contactDatabase;

    Contact newContact;

    void contactDataGathering();
    bool checkIfEmptyContacts();
    void displayRecord(vector<Contact>::iterator placeInStructureToDisplay);

   public:
    ContactManager(string contactDatabaseName) : contactDatabase(contactDatabaseName) {
    }

    void loadContactsFromDataBase(int userId);
    void displayAllContacts();
    void insertNewContact();
};

#endif