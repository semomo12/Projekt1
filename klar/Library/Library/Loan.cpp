#include "Loan.h"
#include <iostream>
#include <fstream>
#include <sstream>

Loan::Loan(int loanId, int mediaId, string date, string mediaName)
    : loanId(loanId), mediaId(mediaId), loanDate(date),mediaName(mediaName) {
}

Loan::~Loan()
{
}

int Loan::getLoanId() const {
    return loanId;
}

string Loan::getLoanDate() const {
    return loanDate;
}


int Loan::getMediaId() const {
    return mediaId;
}

string Loan::getLoanInfo() const {
    return "\nLoan ID: " + to_string(loanId) + "\nMedia Name: " + mediaName + "\nLoan Date: " + loanDate;
}

string Loan::getMediaName() const
{
    return this->mediaName;
}
