#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Interface *w = new Interface(0);
    w->show();

    Messedger *m = new Messedger;

    QObject::connect(w,SIGNAL(first(QString, QString)),m,SLOT(first(QString, QString)));
    QObject::connect(w,SIGNAL(second(vector<QString>,vector<QString>)),m,SLOT(second(vector<QString>,vector<QString>)));
    QObject::connect(w,SIGNAL(error()),m,SLOT(error()));

    return a.exec();
}
