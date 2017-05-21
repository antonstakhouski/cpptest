#include "person.h"
#include "studentcard.h"
#include "date.h"
#include "WidgetWithButton.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    Person me = Person("Стаховский", "Антон", "Владимирович", "777" );
    Person noname = me;

    StudentCard test;
    test.show();
    date entry{2000, 7, 17};
    date received{2000, 8, 20};
    date valid{2003, 6, 30};
    StudentCard full("Имярекин", "Имярек", "Имярекович", "0505005", "КСиС", "дневная", "0955427",
                     entry, received, valid);
    full.show();
    test = full;
    test.show();

    QApplication a(argc, argv);

//    WidgetWithButton b;
//    b.show();
    return a.exec();
}
