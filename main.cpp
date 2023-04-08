#include <iostream>

#include "AdressBook.h"

using namespace std;

int main() {
	AdressBook adressBook("uzytkownicy.txt", "adresaci.txt");
	//adressBook.registration();
	//adressBook.registration();
	adressBook.loginMenu();
	//adressBook.logging();
	//adressBook.registration();
	//adressBook.logging();


	return 0;
}
