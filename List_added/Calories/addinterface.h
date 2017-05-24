#ifndef ADDINTERFACE_H
#define ADDINTERFACE_H

#include <QDialog>
#include <QObject>
#include <iostream>
#include <QLabel>
#include <vector>
#include <QtWidgets>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <fstream>

class AddInterface : public QDialog
{
    Q_OBJECT
public:
    AddInterface(QWidget *parent=0);
private:
    QLabel *Namel, *ccall, *protl, *fatl, *carbl;
    QLineEdit *Namele, *ccalle, *protle, *fatle, *carble;
    QPushButton *ok;
private slots:
    void okClick();
signals:
    void success();
};

#endif // ADDINTERFACE_H
