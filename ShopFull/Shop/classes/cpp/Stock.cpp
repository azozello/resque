//
// Created by azozello on 02.05.17.
//

#include <iostream>
#include "../h/Stock.h"
#include "../h/Cash.h"

vector<Item> Stock::orderItem(Item item, int quantity) {
    vector<Item> deal;
    float currentCash = Cash::getCash();
    float dealSum = item.getBuyPrice()*quantity;
    cout<<"current cash: "<<currentCash<<" deal sum: "<<dealSum<<endl;
    if (currentCash>dealSum){
        for (int i = 0; i < quantity; ++i) {
            deal.insert(deal.end(),item);
        }
        Cash::changeCash(currentCash-dealSum);
        return deal;
    } else{
        cout<<"You have no money, so i will gift you one "<<item.getName()<<endl;
        deal.insert(deal.end(),item);
        return deal;
    }
}