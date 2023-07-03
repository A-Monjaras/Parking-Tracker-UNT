#include "permitpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PermitPage w;
    w.show();
    return a.exec();
}
