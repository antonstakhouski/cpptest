#include "studentcard.h"
#include <iostream>

StudentCard::StudentCard(): Person(), faculty("KSIS"), educationForm("dnevnaya"), cardId("0123456"),
    entryDate{1970, 1, 1}, receiveDate{1970, 2, 5}, validThroughDate{1973, 6, 30}
{
}

//StudentCard::StudentCard(string _lastName, string _firstName, string _middleName, string _id,
//                         string _faculty, string _educationForm, string _cardId,
//                         date _entryDate, date _receiveDate, date _validThroughDate):
//    Person::Person(_lastName, _firstName, _middleName, _id),
//    faculty(_faculty),
//    educationForm(_educationForm),
//    cardId(_cardId),
//    entryDate(_entryDate),
//    receiveDate{_receiveDate},
//    validThroughDate{_validThroughDate}
//{
//}

StudentCard::StudentCard(const StudentCard &copy):
    Person(copy),
    faculty(copy.faculty),
    educationForm(copy.educationForm),
    cardId(copy.cardId),
    entryDate(copy.entryDate),
    receiveDate(copy.receiveDate),
    validThroughDate(copy.validThroughDate)
{

}

void StudentCard::show()
{
    Person::show();
    cout << "Faculty: " << faculty << endl;
    cout << "Education form: " << educationForm << endl;
    cout << "Card ID: " << cardId << endl;
    cout << "Entry date: " << entryDate.year << "." << entryDate.month << "."
         << entryDate.day << endl;
    cout << "Card received at: " << receiveDate.year << "." << receiveDate.month << "."
         << receiveDate.day << endl;
    cout << "Valid through: " << validThroughDate.year << "." << validThroughDate.month << "."
         << validThroughDate.day << endl;
}
