#include "Person.h"

Person::Person(int personID, const string& personName, long long phoneN): personID(personID), personName(personName), phoneNumber(phoneN)
{
}

Person::~Person()
{
}


string Person::getPersonInfo() const {
    return "\nyour details:\nPersonal ID : " + to_string(personID) + "\nyour Name : " + personName + "\nyour PhoneNumber : " + to_string(phoneNumber)+ "\n";
}


int Person::getPersonID() const {
    return personID;
}
