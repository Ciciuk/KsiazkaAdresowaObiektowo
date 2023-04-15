#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include "AditionalMethods.h"
#include "ContactManager.h"
#include "UserManager.h"

using namespace std;

class AdressBook {
    UserManager userManager;
    ContactManager contactManager;



   public:
    AdressBook(string userFileName, string contactFileName) : userManager(userFileName), contactManager(contactFileName) {}

    void displayMainMenu();
    void displayInternalMenu();
    void registration();
    void logging();
    void loginMenu();
    void insertNewContact();
    void displayAllContacts();
    void changePassword();
    int getLoggedUserId();
    void logout();
};
#endif