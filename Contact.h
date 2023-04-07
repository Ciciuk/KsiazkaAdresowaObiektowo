#ifndef CONTACT_H
#define CONTACT_H


#include <iostream>

using namespace std;

class Contact {
	int contactId;
	int userId;
	string contactName;
	string contactSurname;
	string contactPhoneNumber;
	string contactEmail;
	string contactAdress;


public:
	void setContactId(int newId);
	void setUserId(int newUserId);
	void setName(string newName);
	void setSurname(string newSurname);
	void setPhoneNumber(string newPhoneNumber);
	void setEmail(string newEmail);
	void setAdress(string newAdress);

	int getContactId();
	int getUserId();
	string getName();
	string getSurname();
	string getPhoneNumber();
	string getEmail();
	string getAdress();
};

#endif