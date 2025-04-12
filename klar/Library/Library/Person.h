#pragma once
#include <string>
using namespace std;

class Person
{

private:
    int personID;
    string personName;
    long long phoneNumber;


public:
    Person(int personID =0, const string& personName="", long long phoneN=0);
    ~Person();
    int getPersonID() const;

    string getPersonInfo() const;

};
