#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

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

#include "loader.h"
#include "product.h"

//Window with list of products
class ProductList : public QDialog
{
    Q_OBJECT
public:
    ProductList(QWidget *parent=0);
private:
    QLabel *Namel, *ccall, *protl, *fatl, *carbl;
    QPushButton *ok;
private slots:
    void okClick();
signals:
    void toMainMenu();
};


#endif // PRODUCTLIST_H
