
#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AdressBook {

	UserManager userManager;
	ContactManager contactManager;

	void  displayMainlMenu();
	void  displayInternalMenu();
	char getOneChar();
	void internalMenu();
public:
	AdressBook(string userDatabaseName, string contactDatabaseName);
	void registration();
	void logging();
	void loginMenu();
};
