#include "AditionalMethods.h"

using namespace std;

string AditionalMethods::getWholeLine()
{
	string line;

	cin.sync();
	getline(cin, line);

	return line;
}
