#include "AdressBook.h"

void AdressBook::registration() {
    userManager.newUserRegistration();
}
void AdressBook::logging() {
    if (userManager.logginng()) 
        contactManager = new ContactManager(CONTACT_FILE_NAME, userManager.getLoggedUserId());
}

void AdressBook::insertNewContact(){
    contactManager->insertNewContact();
}

void AdressBook::displayAllContacts(){
    contactManager->displayAllContacts();
}

void AdressBook::changePassword(){
    userManager.changePassword();
}

void AdressBook::logout() {
    userManager.setLoggedUserId(0);
    delete contactManager;
    contactManager = NULL;
}

bool AdressBook::isSomeUserLogged(){
    return (userManager.getLoggedUserId() != 0);
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