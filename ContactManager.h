#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
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
    ContactManager(string contactDatabaseName);
    ContactManager(string contactDatabaseName, int userId);

    void loadContactsFromDataBase(int userId);
    void displayAllContacts();
    void insertNewContact();
};

#endif