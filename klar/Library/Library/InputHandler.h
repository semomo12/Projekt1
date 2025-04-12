#pragma once
#include <string>

using namespace std;

class InputHandler {
public:
	InputHandler();
	~InputHandler();


	string getString(string message = "", bool acceptEmptyString = false);
	int getInt(string message, size_t minRange = 0, size_t maxRange = 0);
	bool isNumber(string str); 

	long long getPhonNrAsString(const string& message);
};
