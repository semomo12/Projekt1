#pragma once
#include <string>
#include "Media.h"

using namespace std;

class Loan {
private:
    int loanId;
    int mediaId;  
    string loanDate;
    string mediaName;


public:
    Loan(int loanId, int mediaId, string date, string mediaName);
    ~Loan();
    int getLoanId() const;
    string getLoanDate() const;
    int getMediaId() const;
    string getMediaName() const;
    string getLoanInfo() const;
};



