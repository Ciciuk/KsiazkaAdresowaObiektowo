#include "UserManager.h"

int UserManager::getLoggedUserId() {
    return loggedUser.getId();
}

void UserManager::loadUsersFromFile() {
    users = userFile.loadUsersFromFile();
}

void UserManager::newUserRegistration() {
    system("cls");

    userDataGathering();

    if (users.empty())
        newUser.setId(1);
    else
        newUser.setId(users.back().getId() + 1);

    users.push_back(newUser);
    userFile.saveNewUserInFile(newUser);

    cout << "Rejestracja zakonczona" << endl;
    system("pause");
}

void UserManager::userDataGathering() {
    string login;

    cout << setw(20) << "----------Rejestracja----------- " << endl;

    do {
        cout << "Podaj login: " << endl;
        login = AditionalMethods::getWholeLine();
    } while (checkIfLoginIsNotUnique(login));
    newUser.setLogin(login);

    cout << "Podaj haslo: " << endl;
    newUser.setPassword(AditionalMethods::getWholeLine());
}

bool UserManager::checkIfLoginIsNotUnique(string login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << "Login juz istnieje, podaj inny login" << endl;
            system("pause");
            return true;
        }
    }

    return false;
}

bool UserManager::checkLoginAndPassword() {
    system("cls");
    string login;

    if (checkIfEmptyUsers())
        return false;

    cout << setw(20) << "----------Logowanie----------- " << endl;
    cout << "Podaj login:  " << endl;
    login = AditionalMethods::getWholeLine();

    for (vector<User>::iterator i = users.begin(); i < users.end(); i++) {
        if (login == i->getLogin()) {
            if (checkPassword(i)) {
                loggedUser = *i;
                return true;
            } else
                return false;
        }
    }

    cout << "Brak loginu w bazie danych:  ";
    system("pause");

    return false;
}

bool UserManager::checkIfEmptyUsers() {
    if (users.empty()) {
        cout << "Brak zarejestrowanych uzytkownikow ";
        system("pause");
        return true;
    }

    return false;
}

bool UserManager::checkPassword(vector<User>::iterator i) {
    string password;

    for (int j = 3; j > 0; j--) {
        cout << "Pozostalo Ci: " << j << " prob" << endl;
        cout << "Podaj haslo: " << endl;
        password = AditionalMethods::getWholeLine();
        if (password == i->getPassword()) {
            cout << "Gratuluje, poprawne haslo" << endl;
            system("pause");
            return true;
        } else {
            cout << "Nieprawidlowe haslo" << endl;
            cout << endl;
            system("pause");
        }
    }

    cout << "Wykorzystano wszystkie proby, nastapi przekierowanie na ekran glowny" << endl;
    system("pause");

    return false;
}

bool UserManager::logginng() {
    if (checkLoginAndPassword()) {
        cout << "Uzytkownik zalogowany ";
        system("pause");
        return true;
    } else {
        cout << "Nie udalo sie zalogowac! ";
        system("pause");
        return false;
    }
}

void UserManager::changePassword() {
    vector<User>::iterator i;
    for (i = users.begin(); i < users.end(); i++) {
        if (i->getId() == loggedUser.getId())
            break;
    }
    
    system("cls");
    cout << setw(20) << "----------Zmiana hasla----------- " << endl;
    cout << "Podaj nowe haslo: ";

    i->setPassword(AditionalMethods::getWholeLine());

    userFile.saveUserAfterPaswordChange(users);

    cout << "Haslo zostalo zmienione: ";
    system("pause");
}