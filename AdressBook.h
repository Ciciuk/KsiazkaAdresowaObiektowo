#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include "AditionalMethods.h"
#include "ContactManager.h"
#include "UserManager.h"

using namespace std;

class AdressBook {
    UserManager userManager;
    ContactManager *contactManager;
    const string CONTACT_FILE_NAME;


public:
    AdressBook(string userFileName, string contactFileName) : userManager(userFileName), CONTACT_FILE_NAME(contactFileName) {
        contactManager = NULL;
    };

    ~AdressBook(){
        delete contactManager;
        contactManager = NULL;
    };

    void displayMainMenu();
    void displayInternalMenu();
    void registration();
    void logging();
    void loginMenu();
    void insertNewContact();
    void displayAllContacts();
    void changePassword();
    void logout();
    bool isSomeUserLogged();
    void removeContact();
    void editContact();
    void displayByName();
    void displayBySurname();
};
#endif