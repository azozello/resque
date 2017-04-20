#include <iostream>
#include "core/store/Oil.h"
#include "core/store/Petrol.h"

using namespace std;

float cash;
float oilPrice;

void rec(){
    string password = "password";
    string youEnter;
    cout<<"Please enter password:"<<endl;
    cin>>youEnter;
    if (youEnter==password){
        return;
    } else {
        cout<<"Wrong password"<<endl;
        cout<<"Please enter password:"<<endl;
        rec();
    }
}

void help(){
    cout<<"Enter 1 to buy A80"<<endl;
    cout<<"Enter 2 to buy A92"<<endl;
    cout<<"Enter 3 to buy A95"<<endl;
    cout<<"Enter 4 to show help menu"<<endl;
    cout<<"Enter 0 to exit"<<endl;
}

void buyPetrol(){}

int main() {

    Oil *oil;
    Petrol *A80;
    Petrol *A92;
    Petrol *A95;

    rec();

    cout<<"Enter today`s oil price(per 1 barrel): "<<endl;
    cin>>oilPrice;

    oil = new Oil(oilPrice);
    A80 = new Petrol(oil->getPrice(),"A80",2.5);
    A92 = new Petrol(oil->getPrice(),"A92",3);
    A95 = new Petrol(oil->getPrice(),"A95",3.5);

    cout<<oil->getPrice()<<"$"<<endl<<endl;
    cout<<"A80 costs : "<<A80->getPrice()<<"$"<<endl;
    cout<<"A92 costs : "<<A92->getPrice()<<"$"<<endl;
    cout<<"A95 costs : "<<A95->getPrice()<<"$"<<endl<<endl;

    help();

    while (true){
        int temp = 0;
        cin>>temp;
        switch (temp){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                help();
                break;
            case 0:
                return 200;
            default:
                cout<<"Unknown command"<<endl;
                help();
                break;
        }
        return 0;
    }
}
