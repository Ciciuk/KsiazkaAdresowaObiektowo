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
    Contact(int _contactId = 0, int _userId = 0, string _contactName = "", string _contactSurname = "", string _contactPhoneNumber = "", string _contactEmail = "", string _contactAdress = ""){
        this->contactId = _contactId;
        this->userId = _userId;
        this->contactName = _contactName;
        this->contactSurname = _contactSurname;
        this->contactPhoneNumber = _contactPhoneNumber;
        this->contactEmail = _contactEmail;
        this->contactAdress = _contactAdress;
    };
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