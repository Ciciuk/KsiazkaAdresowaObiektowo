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

void ContactManager::removeContact() {
    int idToDelete;
    vector<Contact>::iterator contactToRemove;

    if (checkIfEmptyContacts())
        return;

    displayAllContacts();
    cout << endl;
    cout << "Podaj ID kontaktu ktory chcesz usunac: ";
    idToDelete = AditionalMethods::getId();

    system("cls");
    contactToRemove = find_if(contacts.begin(), contacts.end(), [idToDelete](Contact vi) { return vi.getContactId() == idToDelete; });  // wyrazenie lambda  - przeszukuje wektor contact i zwraca iterator do pozycji ktorej id jest rowne idToDelete
    if (contactToRemove == contacts.end()) {
        cout << "Nie znaleziono takiego ID ";
        system("pause");
        
        return ;
    }

    displayRecord(contactToRemove);
    cout << endl;
    cout << "Jesli chcesz usunac powyzszy kontakt wcisnij 't' " << endl;

    if (AditionalMethods::getOneChar() == 't') {
        contactFile.saveToFileAfterContactRemove(contactToRemove->getContactId());
        contacts.erase(contactToRemove);
        cout << "Kontakt został usuniety " << endl;
        system("pause");
    }
}

void ContactManager::editRecordMenu(vector<Contact>::iterator& contactToEdit) {
    while (1) {
        system("cls");
        displayRecord(contactToEdit);
        displayEditMenu();
        switch (AditionalMethods::getOneChar()) {
            case '1':
                cout << "Edytuj imie: " << endl;
                contactToEdit->setName(AditionalMethods::getWholeLine());
                break;
            case '2':
                cout << "Edytuj nazwisko: " << endl;
                contactToEdit->setSurname(AditionalMethods::getWholeLine());
                break;
            case '3':
                cout << "Edytuj nr. tel: " << endl;
                contactToEdit->setPhoneNumber(AditionalMethods::getWholeLine());
                break;
            case '4':
                cout << "Edytuj email: " << endl;
                contactToEdit->setEmail(AditionalMethods::getWholeLine());
                break;
            case '5':
                cout << "Edytuj adres: " << endl;
                contactToEdit->setAdress(AditionalMethods::getWholeLine());
                break;
            case '6':
                return;
                break;
            default:
                break;
        }
    }
}

void ContactManager::editContact() {
    int idToEdit;
    vector<Contact>::iterator contactToEdit;

    if (checkIfEmptyContacts())
        return;

    displayAllContacts();
    cout << endl;
    cout << "Podaj ID kontaktu ktory chcesz edytowac: ";
    idToEdit = AditionalMethods::getId();
    system("cls");

    contactToEdit = find_if(contacts.begin(), contacts.end(), [idToEdit](Contact vi) { return vi.getContactId() == idToEdit; });  ////wyrazenie lambda  - przeszukuje wektor contact i zwraca iterator do pozycji ktorej id jest rowne idToEdit

    if (contactToEdit == contacts.end()) {
        cout << "Nie znaleziono takiego ID ";
        system("pause");
        ;
        return;
    }

    editRecordMenu(contactToEdit);
    contactFile.saveToFileAfterContactEdit(contactToEdit);
}

void ContactManager::displayEditMenu() {
    cout << "1. Edytuj imie" << endl;
    cout << "2. Edytuj nazwisko" << endl;
    cout << "3. Edytuj numer telefonu" << endl;
    cout << "4. Edytuj adres e-mail" << endl;
    cout << "5. Edytuj adres zamieszkania" << endl;
    cout << "6. Wyjdz" << endl;
}

void ContactManager::displayContactByName() {
    string searchingName;

    if (checkIfEmptyContacts())
        return;

    cout << "Podaj Imie ktore chcesz wyszukac: ";
    searchingName = AditionalMethods::getWholeLine();
    system("cls");

    for (vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++) {
        if (i->getName() == searchingName)
            displayRecord(i);
    }

    system("pause");
}

void ContactManager::displayContactBySurname() {
    string searchingSurname;

    if (checkIfEmptyContacts())
        return;

    cout << "Podaj Nazwisko ktore chcesz wyszukac: ";
    searchingSurname = AditionalMethods::getWholeLine();
    system("cls");

    for (vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++) {
        if (i->getSurname() == searchingSurname)
            displayRecord(i);
    }

    system("pause");
    ;
}