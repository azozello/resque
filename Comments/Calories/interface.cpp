#include "interface.h"

Interface::Interface(QWidget *parent) : QDialog(parent)
{
    nlbl1 = new QLabel("Product");
    wlbl1 = new QLabel("Weight");
    nl1 = new QLineEdit;
    wl1 = new QLineEdit;

    nlbl2 = new QLabel("Product");
    wlbl2 = new QLabel("Weight");
    nl2 = new QLineEdit;
    wl2 = new QLineEdit;

    nlbl3 = new QLabel("Product");
    wlbl3 = new QLabel("Weight");
    nl3 = new QLineEdit;
    wl3 = new QLineEdit;

    ok = new QPushButton("Count");
    ok->setEnabled(false);

    list = new QPushButton("Show products");
    add = new QPushButton("Add new Product");

    //First line
    QHBoxLayout *product1 = new QHBoxLayout;
    product1->addWidget(nlbl1);
    product1->addWidget(nl1);
    product1->addWidget(wlbl1);
    product1->addWidget(wl1);

    //Second line
    QHBoxLayout *product2 = new QHBoxLayout;
    product2->addWidget(nlbl2);
    product2->addWidget(nl2);
    product2->addWidget(wlbl2);
    product2->addWidget(wl2);

    //Third line
    QHBoxLayout *product3 = new QHBoxLayout;
    product3->addWidget(nlbl3);
    product3->addWidget(nl3);
    product3->addWidget(wlbl3);
    product3->addWidget(wl3);

    //Main frame
    QVBoxLayout *all = new QVBoxLayout;
    all->addLayout(product1);
    all->addLayout(product2);
    all->addLayout(product3);
    all->addWidget(ok);
    all->addWidget(list);
    all->addWidget(add);

    ai = new AddInterface(0);
    pi = new ProductList(0);

    //Connect buttons with functions
    connect(nl1,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(nl2,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(nl3,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(ok,SIGNAL(clicked()),this,SLOT(okClicked()));
    connect(add,SIGNAL(clicked()),this,SLOT(addClicked()));
    connect(list,SIGNAL(clicked()),this,SLOT(listClicked()));
    connect(ai,SIGNAL(success()),this,SLOT(addDone()));
    connect(pi,SIGNAL(toMainMenu()),this,SLOT(listDone()));

    setLayout(all);
    setWindowTitle("Calories counter");
}

void Interface::listDone()
{
    pi->close();
}

void Interface::listClicked()
{
    pi->show();
}

void Interface::addDone()
{
    ai->close();
}

void Interface::addClicked()
{
    ai->show();
}

//Enable button "OK" when you enter text
void Interface::setEnable(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void Interface::okClicked()
{
   if(!nl1->text().isEmpty() && !wl1->text().isEmpty())
   {
       if(!nl2->text().isEmpty() && !wl2->text().isEmpty())
       {
           if(!nl3->text().isEmpty() && !wl3->text().isEmpty())
           {
               vector<QString> names, weights;

               names.insert(names.end(),nl1->text());
               names.insert(names.end(),nl2->text());
               names.insert(names.end(),nl3->text());

               weights.insert(weights.end(),wl1->text());
               weights.insert(weights.end(),wl2->text());
               weights.insert(weights.end(),wl3->text());

               emit second(names, weights);
           }
           else
           {
               vector<QString> names, weights;

               names.insert(names.end(),nl1->text());
               names.insert(names.end(),nl2->text());

               weights.insert(weights.end(),wl1->text());
               weights.insert(weights.end(),wl2->text());

               emit second(names, weights);
           }
       }
       else
       {
           emit first(nl1->text(), wl1->text());
       }
   }
   else
   {
       emit error();
   }
}
