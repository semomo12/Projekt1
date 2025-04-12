#pragma once
#include "Media.h"
#include "InputHandler.h"
#include "MediaHandler.h"
#include "Loan.h"
#include "LoanHandler.h"
#include "Person.h"
#include "PersonHandler.h"
#include <vector>

using namespace std;

class Library {
private:

    MediaHandler mediaHandler;   
    InputHandler inputHandler;

    LoanHandler* loanHandler;
    PersonHandler* personHandler;


public:
    Library();   
    ~Library();  


    void borrowMedia(const string& mediaType);  // l�neprocessen
    void returnMedia(int loanID); // �terl�mning

    bool isValidMediaIDFromUser(const string& mediaType, int mediaID);

};

