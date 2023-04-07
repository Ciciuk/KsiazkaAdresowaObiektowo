#include "Contact.h"


	void Contact::setContactId(int newContactId) {
		contactId = newContactId;
	}

	void Contact::setUserId(int newUserId) {
		userId = newUserId;
	}

	void Contact::setName(string newName) {
		contactName = newName;
	}

	void Contact::setSurname(string newSurname) {
		contactSurname = newSurname;
	}

	void Contact::setPhoneNumber(string newPhoneNumber) {
		contactPhoneNumber = newPhoneNumber;
	}

	void Contact::setEmail(string newEmail) {
		contactEmail = newEmail;
	}

	void Contact::setAdress(string newAdress) {
		contactAdress = newAdress;
	}

	int Contact::getContactId() {
		return contactId;
	}

	int Contact::getUserId() {
		return userId;
	}

	string Contact::getName() {
		return contactName;
	}
	string Contact::getSurname() {
		return contactSurname;
	}
	string Contact::getPhoneNumber() {
		return contactPhoneNumber;
	}
	string Contact::getEmail() {
		return contactEmail;
	}
	string Contact::getAdress() {
		return contactAdress;
	}