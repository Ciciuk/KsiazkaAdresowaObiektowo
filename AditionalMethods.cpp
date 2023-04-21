#include "AditionalMethods.h"

using namespace std;

string AditionalMethods::getWholeLine(){
	string line;

	cin.sync();
	getline(cin, line);

	return line;
}

char AditionalMethods::getOneChar() {
        string input = "";
        char sign = {0};

        while (true) {
            cin.sync();
            getline(cin, input);
            if (input.length() == 1) {
                sign = input[0];
                break;
            }
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }

        return sign;
}

int AditionalMethods::getId() {
        string line;
        int number = 0;

        while (true) {
            cin.sync();
            getline(cin, line);
            stringstream input(line);
            if (input >> number)
                break;
            cout << "Niepoprawne ID wpisz ponownie" << endl;
        }

        return number;
}