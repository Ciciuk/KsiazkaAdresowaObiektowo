#ifndef CONTACTDATABASE_H
#define CONTACTDATABASE_H


#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> 

#include "Contact.h"

using namespace std;

class ContactDatabase {
	const string contactDataBaseName;
	fstream contactDataBase;
	int lastContactId;
	int currentUserId;

	string mergeContactLine(Contact data);

public:
	ContactDatabase(string CONTACTDATABASENAME);
	ContactDatabase(string CONTACTDATABASENAME, int userId); // narazie nie uzywane

	int getLastContactId();
	int getCurrentUserId();
	void setLastContactId(int newLastContactId);

	void saveNewContactInDataBase(Contact newUser);
	vector <Contact> loadContactsFromDataBase(int userId);
};
#endif   