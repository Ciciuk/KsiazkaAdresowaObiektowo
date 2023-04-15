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
    int currentUserId;

    Contact contactDataGathering();
    bool checkIfEmptyContacts();
    void displayRecord(vector<Contact>::iterator placeInStructureToDisplay);

   public:
    ContactManager(string contactFileName) : contactFile(contactFileName) {
    }

    void loadContactsFromFile(int userId);
    void displayAllContacts();
    void insertNewContact();
};

#endif