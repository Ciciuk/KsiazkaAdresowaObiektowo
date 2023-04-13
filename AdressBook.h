
#include "ContactManager.h"
#include "UserManager.h"

using namespace std;

class AdressBook {
    UserManager userManager;
    ContactManager contactManager;

    void displayMainMenu();
    void displayInternalMenu();
    char getOneChar();
    void internalMenu();

   public:
    AdressBook(string userDatabaseName, string contactDatabaseName);
    void registration();
    void logging();
    void loginMenu();
};
