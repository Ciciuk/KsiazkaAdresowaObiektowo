#include "AdressBook.h"

void AdressBook::registration() {
    userManager.newUserRegistration();
}
void AdressBook::logging() {
    if (userManager.logginng()) {
        contactManager.loadContactsFromFile(userManager.getLoggedUserId());
        internalMenu();
    }
}

void AdressBook::loginMenu() {
    char menuChoice;

    while (1) {
        system("cls");
        displayMainMenu();
        menuChoice = AditionalMethods::getOneChar();
        switch (menuChoice) {
            case '1':
                logging();
                break;
            case '2':
                registration();
                break;
            case '9':
                return;
            default:
                break;
        }
    }
}

void AdressBook::internalMenu() {
    char menuChoice;

    if (userManager.getLoggedUserId() == 0)
        return;

    while (1) {
        system("cls");
        displayInternalMenu();
        menuChoice = AditionalMethods::getOneChar();
        switch (menuChoice) {
            case '1':
                contactManager.insertNewContact();
                break;
            case '2':
                // displayContactByName(contacts);
                break;
            case '3':
                // displayContactBySurname(contacts);
                break;
            case '4':
                contactManager.displayAllContacts();
                break;
            case '5':
                // lastId = removeContactSequence(contacts, lastId);
                break;
            case '6':
                // editContactSequence(contacts);
                break;
            case '7':
                userManager.changePassword();
                break;
            case '9':
                return;
            default:
                break;
        }
    }
}

void AdressBook::displayMainMenu() {
    cout << "1. Logowanie" << endl;
    cout << "2. Rejestracja" << endl;
    cout << "9. Wyjdz" << endl;
}

void AdressBook::displayInternalMenu() {
    cout << "1. Dodaj adresata" << endl;
    // cout << "2. Wyszukaj po imieniu" << endl;
    // cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl wszystkich adresatow" << endl;
    // cout << "5. Usun adresata" << endl;
    // cout << "6. Edytuj adresata" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
}