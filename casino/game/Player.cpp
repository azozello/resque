//
// Created by azozello on 14.05.17.
//

#include "Player.h"

Player::Player(float money, const string &name) : money(money), name(name) {}

Player::Player() {}

float Player::getMoney() const {
    return money;
}

void Player::setMoney(float money) {
    Player::money = money;
}

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}
