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
#include "ContactFile.h"

using namespace std;

class ContactManager {
    vector<Contact> contacts;
    ContactFile contactFile;
    const int CURRENT_USER_ID;

    Contact contactDataGathering();
    bool checkIfEmptyContacts();
    void displayRecord(vector<Contact>::iterator placeInStructureToDisplay);

   public:
    ContactManager(string contactFileName, int userId) : contactFile(contactFileName), CURRENT_USER_ID(userId) {
        contacts = contactFile.loadContactsFromFile(userId);
    }

   // void loadContactsFromFile(int userId);
    void displayAllContacts();
    void insertNewContact();
};

#endif