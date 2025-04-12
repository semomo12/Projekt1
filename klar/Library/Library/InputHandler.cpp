#include "InputHandler.h"

#include <iostream>

using namespace std;


InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

string InputHandler::getString(string message, bool acceptEmptyString)
{
	string theInput;
	cout << message;
	getline(cin, theInput);

	while (!acceptEmptyString && theInput.empty()) {
		cout << "Please enter a non-empty string.\n";
		cout << message;
		getline(cin, theInput);
	}
	return theInput;
}


int InputHandler::getInt(string message, size_t minRange, size_t maxRange)
{
	string theInput;
	cout << message;
	getline(cin, theInput);
	if (minRange == 0 && maxRange == 0) {
		while (!isNumber(theInput)) {
			cout << "Please enter a valid number.\n";
			cout << message;
			getline(cin, theInput);
			
		}
	}
	else { 
		while (!(isNumber(theInput) && stoi(theInput) >= minRange && stoi(theInput) <= maxRange)) {
			cout << "Please enter a valid number.\n";
			cout << message;
			getline(cin, theInput);
		}
	}
	return stoi(theInput);
}

bool InputHandler::isNumber(string str)
{
	if (str == "") return false;
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

long long InputHandler::getPhonNrAsString(const string& message)
{
	string input;
	cout << message;
	getline(cin, input);

	while (!isNumber(input)) {
		cout << "Please enter a valid number!\n";
		cout << message;
		getline(cin, input);
	}

	return stoll(input); 
}

