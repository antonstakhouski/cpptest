#include <QApplication>
#include "listwidget.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ListWidget w;
    w.show();

    return a.exec();
}
