#include <iostream>

#include "AdressBook.h"

using namespace std;

int main() {
    AdressBook adressBook("uzytkownicy.txt", "adresaci.txt");
    adressBook.loginMenu();

    return 0;
}
