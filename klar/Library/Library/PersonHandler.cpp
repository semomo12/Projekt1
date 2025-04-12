#include "PersonHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;


PersonHandler::PersonHandler()
{
}

PersonHandler::~PersonHandler()
{
}

int PersonHandler::generatePersonId()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> distrib(1000, 9999);
    return distrib(gen);
}

void PersonHandler::loadBorrower()
{
    ifstream file("userLog.txt");
    if (!file.is_open()) {
        cout << "Could not load users.\n" << endl;
        return;
    }
    string line;
    bool isFirstLine = true;
    while (getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue; 
        }
        if (line.empty()) {
            continue; 
        }
        line = filehandler.removeSpaces(line);
        stringstream ss(line);
        string name;
        int personId = 0;
        long long phoneNr= 0;
        if (getline(ss, line, ',')) personId = stoi(line);
        if (getline(ss, line, ',')) name = line;
        if (getline(ss, line, ',')) phoneNr = stoll(line);
        Person person(personId, name, phoneNr);
        persons.push_back(person);

    }

    file.close();
}

void PersonHandler::saveUserToFile(int personID, const string& personName, long long phoneNumber)
{
    ofstream file("userLog.txt", ios::app);
    if (!file.is_open()) {
        cout << "Could not save user.\n";
        return;
    }
    file.seekp(0, ios::end);
    if (file.tellp() > 0) {
        file << "\n";
    }
    file << personID << "," << personName << "," << phoneNumber;

    file.close();
}

void PersonHandler::addUser(const Person& person)
{
    persons.push_back(person);
}

void PersonHandler::removeUser(int loanId)
{
    for (auto it = persons.begin(); it != persons.end(); ++it) {
        if (it->getPersonID() == loanId) {
            persons.erase(it);
            break;
        }
    }
}

void PersonHandler::removeUserFromFile(int loanId)
{
    ifstream inputFile("userLog.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Could not open loans.txt for reading.\n";
        return;
    }
    if (!tempFile.is_open()) {
        cout << "Error: Could not open temp.txt for writing.\n";
        return;
    }

    string line;
    bool isFirstLine = true;
    while (getline(inputFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            tempFile << line << "\n";
            continue;
        }
        if (line.empty()) {
            continue;
        }
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ',');
        try {
            int personIdFromFile = stoi(idStr);
            if (personIdFromFile != loanId) {
                tempFile << line << "\n";
            }
        }
        catch (const invalid_argument&) {
            cout << "Error: Invalid personID in file.\n";
            continue; 
        }
    }

    inputFile.close();
    tempFile.close();

    // Radera den ursprungliga filen och byta namn på den tillfälliga filen
    if (remove("userLog.txt") != 0) {
        cout << "Error: Could not remove the original loan file.\n";
        return;
    }

    if (rename("temp.txt", "userLog.txt") != 0) {
        cout << "Error: Could not rename the temporary file.\n";
        return;
    }
}

Person* PersonHandler::getPersonById(int LoanID)
{
    for (auto& person : persons) {
        if (person.getPersonID() == LoanID) {
            return &person;
        }
    }
    return nullptr;
}
