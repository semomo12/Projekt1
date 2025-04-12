#pragma once
#include <vector>
#include "Person.h"
#include "FileHandler.h"

using namespace std;

class PersonHandler
{
private:
	vector<Person> persons;
	FileHandler filehandler;
public:
	PersonHandler();
	~PersonHandler();

	static int generatePersonId();

	void loadBorrower();
	void saveUserToFile(int personID, const string& personName, long long phoneNumber);

	void addUser(const Person& person);
	void removeUser(int loanId);
	void removeUserFromFile(int loanId);

	Person* getPersonById(int LoanID);

};
