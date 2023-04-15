#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include "AditionalMethods.h"
#include "ContactManager.h"
#include "UserManager.h"

using namespace std;

class AdressBook {
    UserManager userManager;
    ContactManager contactManager;

    void displayMainMenu();
    void displayInternalMenu();
    void internalMenu();

   public:
    AdressBook(string userFileName, string contactFileName) : userManager(userFileName), contactManager(contactFileName) {
        userManager.loadUsersFromFile();
    }
    
    void registration();
    void logging();
    void loginMenu();
};
#endif