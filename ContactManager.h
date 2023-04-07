#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H


#include <iostream>
#include <vector>

#include "Contact.h"
#include "AditionalMethods.h"
#include "ContactDatabase.h"

using namespace std;

class ContactManager {
	vector <Contact> contacts;
	ContactDatabase contactDatabase;

	Contact newContact;

	void contactDataGathering();
	bool  checkIfEmptyContacts();
	void displayRecord(vector <Contact>::iterator placeInStructureToDisplay);

public:
	ContactManager(string contactDatabaseName, int userId);

	void displayAllContacts();
	void loadContactsFromDataBase();
	void insertNewContact();

};

#endif