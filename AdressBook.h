
#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AdressBook {

	UserManager userManager;

public:
	AdressBook(string userDatabaseName);
	void registration();
	void logging();

};
