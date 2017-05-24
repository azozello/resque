#include "productlist.h"

ProductList::ProductList(QWidget *parent) : QDialog(parent)
{
    Loader *l = new Loader();

    Namel = new QLabel("Name: ");
    ccall = new QLabel("Ccal: ");
    protl = new QLabel("Proteins: ");
    fatl = new QLabel("Fat: ");
    carbl = new QLabel("Carbons: ");

    QHBoxLayout *line1 = new QHBoxLayout;
    QVBoxLayout *all = new QVBoxLayout;

    ok = new QPushButton("Close");

    line1->addWidget(Namel);
    line1->addWidget(ccall);
    line1->addWidget(protl);
    line1->addWidget(fatl);
    line1->addWidget(carbl);

    connect(ok,SIGNAL(clicked()),this,SLOT(okClick()));

    all->addLayout(line1);

    vector<Product> allProducts = l->getAllProducts();

    for(int i=0; i < allProducts.size(); i++)
    {
        QHBoxLayout *tempHL = new QHBoxLayout;

        QLabel *tempNL = new QLabel(allProducts[i].getName());
        QLabel *tempCcalL = new QLabel(QString::number(allProducts[i].getCcal()));
        QLabel *tempPL = new QLabel(QString::number(allProducts[i].getProteins()));
        QLabel *tempFL = new QLabel(QString::number(allProducts[i].getFat()));
        QLabel *tempCarL = new QLabel(QString::number(allProducts[i].getCarbons()));

        tempHL->addWidget(tempNL);
        tempHL->addWidget(tempCcalL);
        tempHL->addWidget(tempPL);
        tempHL->addWidget(tempFL);
        tempHL->addWidget(tempCarL);

        all->addLayout(tempHL);
    }

    all->addWidget(ok);
    setLayout(all);
}

void ProductList::okClick()
{
    emit toMainMenu();
}
