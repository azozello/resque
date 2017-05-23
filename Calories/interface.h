#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <QDialog>
#include <QLabel>
#include <vector>
#include <QtWidgets>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "loader.h"
#include "product.h"
#include "calculator.h"
#include "addinterface.h"

using namespace std;

class Interface : public QDialog
{
    Q_OBJECT

public:
    Interface(QWidget *parent=0);

private:
    AddInterface *ai;
    QLabel *nlbl1;
    QLabel *wlbl1;
    QLineEdit *nl1;
    QLineEdit *wl1;

    QLabel *nlbl2;
    QLabel *wlbl2;
    QLineEdit *nl2;
    QLineEdit *wl2;


    QLabel *nlbl3;
    QLabel *wlbl3;
    QLineEdit *nl3;
    QLineEdit *wl3;

    QPushButton *ok;
    QPushButton *add;

private slots:
    void setEnable(QString str);
    void okClicked();
    void addClicked();
    void addDone();

signals:
    void first(QString name, QString weight);
    void second(vector<QString> names, vector<QString> weights);
    void error();
};

class Messedger : public QObject
{
    Q_OBJECT
public slots:
    void first(QString name, QString weight)
    {
        Calculator *c = new Calculator();
        Loader *l = new Loader();
        Product p = l->getProductByName(name);

        QMessageBox msg;

        Product np = c->count(p,weight.toInt());

        QString mes = "Total: \n";
        mes +=  "Carbons:    "+QString::number(np.getCarbons())+
                "\nProteins:    "+QString::number(np.getProteins())+
                "\nFat:    "+QString::number(np.getFat())+
                "\nCcal:    "+QString::number(np.getCcal()/1000);

        delete c,l,p;
        msg.setText(mes);
        msg.exec();
    }

    void second(vector<QString> names, vector<QString> weights)
    {
        Calculator *c = new Calculator();
        Loader *l = new Loader();
        vector<Product> products;
        vector<int> ws;

        for (int i=0; i<names.size(); i++)
        {
            products.insert(products.end(), l->getProductByName(names[i]));
        }

        for (int i=0; i<weights.size(); i++)
        {
            cout<<weights[i].toStdString()<<endl;
            ws.insert(ws.end(), weights[i].toInt());
        }

        QMessageBox msg;

        Product np = c->count(products,ws);

        QString mes = "Total: \n";
        mes +=  "Carbons:    "+QString::number(np.getCarbons())+
                "\nProteins:    "+QString::number(np.getProteins())+
                "\nFat:    "+QString::number(np.getFat())+
                "\nCcal:    "+QString::number(np.getCcal()/1000);

        delete c,l;
        msg.setText(mes);
        msg.exec();
    }

    void error()
    {
        QMessageBox msg;
        msg.setText("Unexpected values!");
        msg.exec();
    }
};

#endif // INTERFACE_H
