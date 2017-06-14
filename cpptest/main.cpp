#include "studentcard.h"
#include "driverlicence.h"
#include "WidgetWithButton.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetWithButton b;
    b.show();
    return a.exec();
}
