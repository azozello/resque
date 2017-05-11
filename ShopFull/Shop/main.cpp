#include <iostream>
#include "classes/h/Manager.h"
#include "classes/h/Order.h"
#include "classes/h/Cash.h"
#include "classes/h/Stock.h"

Manager *manager = new Manager("Eugenia","qwerty");
Stock *stock = new Stock();
Cash *cash = new Cash();
vector<Item> items = manager->loadItems();

void orderItems(Item item, int amount){
    items.insert(items.end(),stock->orderItem(item,amount)[0]);
    manager->addItem(item);
}

int rec(){
    string password = "qwerty";
    string youEnter;
    cout<<"Please enter password:"<<endl;
    cin>>youEnter;
    if (youEnter == password){
        return 0;
    } else if(youEnter == "exit") {
        return 1;
    }
    else {
        cout<<"Wrong password"<<endl;
        rec();
    }
}

void help(){
    for (int i = 0; i < items.size(); ++i) {
        cout<<items[i].getName()<<" "<<items[i].getSellPrice()<<" "<<"number: "<<i<<endl;
    }
}

void makeOrder(){
    Order *order = new Order();
    Item item;
    int amount = 0, number = 0;
    cout<<"Enter item`s number: "<<endl;
    cin>>number;
    cout<<"Enter it`s amount: "<<endl;
    cin>>amount;
    item = items[number];
    order->addItem(item);
    cash->changeCash(cash->getCash()+order->getPrice());
    cout<<"success"<<endl;
}

int main() {
    while (true) {
        int toDo;
        cout << "Enter 1 to enter as Client" << endl;
        cout << "Enter 2 to enter as Manager" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> toDo;

        switch (toDo) {
            default:
                cout << "Unknown command" << endl;
                break;
            case 0:
                return 1;
            case 1:
                help();
                makeOrder();
                break;
            case 2:
                int flag = rec();
                if (flag == 1) return 1;
            man :
                cout<<"To show cash enter 1"<<endl;
                cout<<"To order items from stock enter 2"<<endl;
                cout<<"To exit enter 0"<<endl;
                cin>>flag;
                switch(flag){
                    default:
                        break;
                    case 0:
                        break;
                    case 1:
                        cout<<"Cash: "<<cash->getCash()<<endl;
                        goto man;
                    case 2:
                        Item *item = new Item();
                        string name;
                        int amount;
                        float sellPrice, buyPrice;

                        cout<<"Enter item`s name: "<<endl;
                        cin>>name;
                        cout<<"Enter sellPrice: "<<endl;
                        cin>>sellPrice;
                        cout<<"Enter buyPrice: "<<endl;
                        cin>>buyPrice;
                        cout<<"Enter amount"<<endl;
                        cin>>amount;

                        item->setSellPrice(sellPrice);
                        item->setBuyPrice(buyPrice);
                        item->setName(name);
                        orderItems(*item,amount);
                        cout<<"Success"<<endl;
                        goto man;
                }
                break;
        }
    }
}