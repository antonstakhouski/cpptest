#ifndef STUDENTCARD_H
#define STUDENTCARD_H

#include "person.h"
#include "date.h"
#include <string>

using namespace std;

class StudentCard : public Person
{
public:
    StudentCard();
//    StudentCard(string _lastName, string _firstName, string _middleName, string _id,
//                string _faculty, string _educationForm, string _cardId,
//                date _entryDate, date _receiveDate, date _validThroughDate);
    StudentCard(const StudentCard& copy);
    void show();

private:
    string faculty;
    string educationForm;
    string cardId;

    date entryDate;
    date receiveDate;
    date validThroughDate;
};

#endif // STUDENTCARD_H
