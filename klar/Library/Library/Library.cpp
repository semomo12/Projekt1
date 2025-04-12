#include "Library.h"
#include "Loan.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Library::Library() :loanHandler(nullptr),personHandler(nullptr)
{
    loanHandler = new LoanHandler();
    personHandler = new PersonHandler();

    mediaHandler.loadMedia();
    personHandler->loadBorrower();
    loanHandler->loadLoansFromFile();
}

Library::~Library() {

    if (loanHandler) {
        delete loanHandler;
        loanHandler = nullptr;
    }

    if (personHandler) {
        delete personHandler;
        personHandler = nullptr;
    }

}


bool Library::isValidMediaIDFromUser(const string& mediaType, int mediaID)
{
    if (mediaType == "Book") {
        return mediaID >= 11 && mediaID <= 20;
    }
    else if (mediaType == "Movie") {
        return mediaID >= 21 && mediaID <= 30;
    }
    else if (mediaType == "Audiobook") {
        return mediaID >= 1 && mediaID <= 10;
    }
    else {
        return false;
    }
}




void Library::borrowMedia(const string& mediaType) {
    cout << "Borrowing media of type: " << mediaType << endl;

    mediaHandler.showAvailableMedia(mediaType);
    int mediaID;
    while (true) {
        mediaID = inputHandler.getInt("Enter the ID of the media you want to borrow: ");
        if (isValidMediaIDFromUser(mediaType, mediaID)) {
            break;
        }
        else {
            cout << "Invalid media ID.\n Please try again.\n";
        }
    }

    Media* selectedMedia = mediaHandler.getMediaById(mediaID);
    if (!selectedMedia) {
        cout << "Invalid media ID.\n Try again.\n";
        return;
    }
    string mediaNameToShow = selectedMedia->getMediaName();
    cout << "Selected media ID: " << selectedMedia->getMediaId() << endl;
    cout << "Selected media name: " << mediaNameToShow << endl;
 
    if (loanHandler->isMediaAlreadyLoaned(mediaID)) {
        cout << "This media is already borrowed.\n Please choose another one.\n";
        return;
    }
    cout << "This media is available to borrow!" << endl;


    string personName = inputHandler.getString("please enter your name: ");
    cout << personName << endl;
    long long phoneNumber = inputHandler.getPhonNrAsString("Enter your phone number: ");
    cout << phoneNumber << endl;
    system("cls");

    int loanId = personHandler->generatePersonId();

    Person person(loanId, personName, phoneNumber);
    personHandler->addUser(person);

    string loanDate = loanHandler->generateLoanDate();

    string mediaName = selectedMedia->getMediaName();

    // Skapa Loan-objekt
    Loan newLoan(loanId, mediaID, loanDate, mediaName);
    loanHandler->addLoan(newLoan);


    // Skriv ut låneinformationen 
    cout << "\nMedia successfully borrowed!\n";
    cout << "Loan ID: " << loanId << "\n";
    cout << "Media ID: " << mediaID << "\n";
    cout << "media type: " << mediaType << "\n";
    cout << "Media Name: " << mediaNameToShow << "\n";
    cout << "your personal ID: " << loanId << "\n";
    cout << "Borrow Date: " << loanDate << "\n";

    loanHandler->saveLoanToFile(loanId, selectedMedia);
    mediaHandler.removeMedia(mediaID);

    personHandler->saveUserToFile(loanId, personName, phoneNumber);
}


void Library::returnMedia(int loanID) {

    Loan* loanToReturn = loanHandler->getLoanById(loanID);
    if (loanToReturn == nullptr) {
        cout << "Loan with ID: " << loanID << " not found!" << endl;
        return;
    }

    Person* personWhoReturn = personHandler->getPersonById(loanID);
    if (personWhoReturn == nullptr) {
        cout << "Person with ID: " << loanID << " not found!" << endl;
        return; 
    }

 
    int mediaID = loanToReturn->getMediaId();
    if (loanToReturn->getLoanId() == loanID) 
    {
        cout << personWhoReturn->getPersonInfo() << endl;
        cout << loanToReturn->getLoanInfo() << endl;  
    }
    
    string correctLoanInfo = inputHandler.getString("\nDo you want to return this media??\n Answer, yes/no: ");
    if (correctLoanInfo == "yes") {
        loanHandler->removeLoanFromFile(loanID);
        loanHandler->removeLoan(loanID);
        personHandler->removeUser(loanID);
        personHandler->removeUserFromFile(loanID);

        cout << "media successfully returned" << endl;
    }


    else {
        cout << "Probably, you are writing it wrong, Please try again!\n";
    }
  

}
