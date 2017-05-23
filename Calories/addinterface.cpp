#include "addinterface.h"

using namespace std;

AddInterface::AddInterface(QWidget *parent) : QDialog(parent)
{
    Namel = new QLabel("Name: ");
    ccall = new QLabel("Ccal: ");
    protl = new QLabel("Proteins: ");
    fatl = new QLabel("Fat: ");
    carbl = new QLabel("Carbons: ");

    Namele = new QLineEdit;
    ccalle = new QLineEdit;
    protle = new QLineEdit;
    fatle = new QLineEdit;
    carble = new QLineEdit;

    QHBoxLayout *line1 = new QHBoxLayout;
    QHBoxLayout *line2 = new QHBoxLayout;
    QHBoxLayout *line3 = new QHBoxLayout;
    QHBoxLayout *line4 = new QHBoxLayout;
    QHBoxLayout *line5 = new QHBoxLayout;

    ok = new QPushButton("Add");

    line1->addWidget(Namel);
    line1->addWidget(Namele);

    line2->addWidget(ccall);
    line2->addWidget(ccalle);

    line3->addWidget(protl);
    line3->addWidget(protle);

    line4->addWidget(fatl);
    line4->addWidget(fatle);

    line5->addWidget(carbl);
    line5->addWidget(carble);

    QVBoxLayout *all = new QVBoxLayout;
    all->addLayout(line1);
    all->addLayout(line2);
    all->addLayout(line3);
    all->addLayout(line4);
    all->addLayout(line5);
    all->addWidget(ok);

    connect(ok,SIGNAL(clicked()),this,SLOT(okClick()));

    setLayout(all);
    setWindowTitle("Adder");
}

void AddInterface::okClick()
{
    ofstream fout("/home/azozello/Sasha/files/products.txt", ios::app);
    //pfc
    int ic = ccalle->text().toInt();
    float fp  = protle->text().toFloat();
    float ff  = fatle->text().toFloat();
    float fc  = carble->text().toFloat();
    fout<<Namele->text().toStdString()<<" "<<fp<<" "<<ff<<" "<<fc<<" "<<ic<<endl;
    fout.close();
    emit success();
}
