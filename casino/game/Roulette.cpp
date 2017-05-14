//
// Created by azozello on 14.05.17.
//

#include <iostream>
#include "Roulette.h"

Roulette::Roulette(const string &name, float price, int players, int lastField) : Game(name, price, players),
                                                                                  lastField(lastField) {}

Roulette::Roulette() {}

int Roulette::getLastField() const {
    return lastField;
}

void Roulette::setLastField(int lastField) {
    Roulette::lastField = lastField;
}

int Roulette::play() {
    srand(time(0));
    long temp = rand()%36+1;
    cout<<"Rand: "<<temp<<endl;
    return (int)temp;
}
