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


    void borrowMedia(const string& mediaType);  // låneprocessen
    void returnMedia(int loanID); // återlämning

    bool isValidMediaIDFromUser(const string& mediaType, int mediaID);

};

