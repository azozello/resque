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

    add = new QPushButton("Add new Product");

    QHBoxLayout *product1 = new QHBoxLayout;
    product1->addWidget(nlbl1);
    product1->addWidget(nl1);
    product1->addWidget(wlbl1);
    product1->addWidget(wl1);

    QHBoxLayout *product2 = new QHBoxLayout;
    product2->addWidget(nlbl2);
    product2->addWidget(nl2);
    product2->addWidget(wlbl2);
    product2->addWidget(wl2);

    QHBoxLayout *product3 = new QHBoxLayout;
    product3->addWidget(nlbl3);
    product3->addWidget(nl3);
    product3->addWidget(wlbl3);
    product3->addWidget(wl3);

    QVBoxLayout *all = new QVBoxLayout;
    all->addLayout(product1);
    all->addLayout(product2);
    all->addLayout(product3);
    all->addWidget(ok);
    all->addWidget(add);

    ai = new AddInterface(0);

    connect(nl1,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(nl2,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(nl3,SIGNAL(textChanged(QString)),this,SLOT(setEnable(QString)));
    connect(ok,SIGNAL(clicked()),this,SLOT(okClicked()));
    connect(add,SIGNAL(clicked()),this,SLOT(addClicked()));
    connect(ai,SIGNAL(success()),this,SLOT(addDone()));

    setLayout(all);
    setWindowTitle("Calories counter");
}

void Interface::addDone()
{
    ai->close();
}

void Interface::addClicked()
{
    ai->show();
}

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
