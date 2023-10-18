#include "Addition.h"


using namespace std;


char GetCorrectChar()
{
	char x;
	while ((cin >> x).fail() || cin.peek() != '\n' || !(strchr("yn", x)))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter \"y\" or \"n\": ";
	}
	return x;
}
