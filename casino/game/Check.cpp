//
// Created by azozello on 14.05.17.
//

#include <iostream>
#include <fstream>
#include "Check.h"

Check::Check(const string &game, float money) : game(game), money(money) {}

Check::Check() {}

void Check::print() {
    ofstream fout("/home/azozello/CLionProjects/OutSource/casino/money/check.txt", ios::trunc);
    fout<<"Money: "<<money<<"   Player: "<<name<<"   Game: "<<game<<endl;
    fout.close();
}

const string &Check::getGame() const {
    return game;
}

void Check::setGame(const string &game) {
    Check::game = game;
}

float Check::getMoney() const {
    return money;
}

void Check::setMoney(float money) {
    Check::money = money;
}

const string &Check::getName() const {
    return name;
}

void Check::setName(const string &name) {
    Check::name = name;
}
