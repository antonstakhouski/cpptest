#include <QApplication>

#include "containerform.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ContainerForm form;
    form.show();

    return a.exec();
}
