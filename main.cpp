#include <iostream>

#include "AdressBook.h"

using namespace std;

int main() {
    char menuChoice;

    AdressBook adressBook("uzytkownicy.txt", "adresaci.txt");

        while (1) {
            system("cls");
            adressBook.displayMainMenu();
            menuChoice = AditionalMethods::getOneChar();
            switch (menuChoice) {
                case '1':
                    adressBook.logging();
                    break;
                case '2':
                    adressBook.registration();
                    break;
                case '9':
                    return 0;
                default:
                    break;
            }
            while (adressBook.isSomeUserLogged()) {
                system("cls");
                adressBook.displayInternalMenu();
                menuChoice = AditionalMethods::getOneChar();
                switch (menuChoice) {
                    case '1':
                        adressBook.insertNewContact();
                        break;
                    case '2':
                        // displayContactByName(contacts);
                        break;
                    case '3':
                        // displayContactBySurname(contacts);
                        break;
                    case '4':
                        adressBook.displayAllContacts();
                        break;
                    case '5':
                        // lastId = removeContactSequence(contacts, lastId);
                        break;
                    case '6':
                        // editContactSequence(contacts);
                        break;
                    case '7':
                        adressBook.changePassword();
                        break;
                    case '9':
                        adressBook.logout();
                        break;
                    default:
                        break;
                }
            }
        
        }
    

       
    return 0;
}

#include "Contact.h"

int contact_constructor_test_main(){
Contact contact(1,2,"Kamil Adrian", "Tumulec");
cout << "ID: " << contact.getContactId() << endl;
cout << "IMIE: " << contact.getName() << endl;
cout << "Nazwisko: " << contact.getSurname() << endl;
cout << "Numer tel.: " << contact.getPhoneNumber() << endl;
return 0;

}