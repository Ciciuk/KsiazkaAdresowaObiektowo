#include "ContactManager.h"

void ContactManager::insertNewContact() {
    Contact newContact;

    newContact = contactDataGathering();

    contacts.push_back(newContact);
    contactFile.saveNewContactInFile(newContact);

    cout << "Nowy kontakt dodany." << endl;
    system("pause");
}

Contact ContactManager::contactDataGathering() {
    Contact newContact;

    system("cls");
    cout << setw(20) << "-------Dodawanie Kontaktu----------" << endl;

    cout << "Podaj imie: ";
    newContact.setName(AditionalMethods::getWholeLine());
    cout << "Podaj nazwisko: ";
    newContact.setSurname(AditionalMethods::getWholeLine());
    cout << "Podaj nr. tel ";
    newContact.setPhoneNumber(AditionalMethods::getWholeLine());
    cout << "Podaj e-mail: ";
    newContact.setEmail(AditionalMethods::getWholeLine());
    cout << "Podaj adres: ";
    newContact.setAdress(AditionalMethods::getWholeLine());

    newContact.setUserId(CURRENT_USER_ID);
    newContact.setContactId(contactFile.getLastContactId() + 1);

    return newContact;
}

bool ContactManager::checkIfEmptyContacts() {
    if (contacts.empty()) {
        cout << "Brak kontaktow ";
        system("pause");
        return true;
    }

    return false;
}

void ContactManager::displayAllContacts() {
    if (checkIfEmptyContacts())
        return;

    system("cls");

    for (vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++) {
        displayRecord(i);
    }

    system("pause");
}

void ContactManager::displayRecord(vector<Contact>::iterator placeInStructureToDisplay) {
    cout << left << setw(20) << "ID:" << placeInStructureToDisplay->getContactId() << endl;
    cout << left << setw(20) << "Imie:" << placeInStructureToDisplay->getName() << endl;
    cout << left << setw(20) << "Nazwisko:" << placeInStructureToDisplay->getSurname() << endl;
    cout << left << setw(20) << "Nr.tel:" << placeInStructureToDisplay->getPhoneNumber() << endl;
    cout << left << setw(20) << "Adres e-mail:" << placeInStructureToDisplay->getEmail() << endl;
    cout << left << setw(20) << "Adres:" << placeInStructureToDisplay->getAdress() << endl;
    cout << endl;
}
