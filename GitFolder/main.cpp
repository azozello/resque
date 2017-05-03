#include <iostream>
#include "classes/h/Manager.h"
#include "classes/h/Order.h"
#include "classes/h/Cash.h"
#include "classes/h/Stock.h"

int main() {
    Manager *m = new Manager();
    vector<Item> test = m->loadItems();
    for (int i = 0; i < test.size(); i++) {
        cout<<test[i].getName()<<" "<<test[i].getSellPrice()<<" "<<test[i].getBuyPrice()<<" "<<endl;
    }
    Order *o = new Order();
    o->setProducts(test);
    Item *item = new Item("Banana",2.0,1.0);
    o->addItem(*item);
    cout<<o->getPrice()<<endl;
    Cash::changeCash(100);
    cout<<Cash::getCash()<<endl;
    Stock *stock = new Stock();
    stock->orderItem(*item,6);
    cout<<Cash::getCash()<<endl;
    return 0;
}