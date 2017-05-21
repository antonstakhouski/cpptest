#include "person.h"
#include "WidgetWithButton.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    Person me = Person("Стаховский", "Антон", "Владимирович", "777" );
    me.show();

    Person noname = me;
    noname.show();

    QApplication a(argc, argv);

//    WidgetWithButton b;
//    b.show();
    return a.exec();
}
