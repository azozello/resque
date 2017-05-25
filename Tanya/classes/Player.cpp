//
// Created by azozello on 24.05.17.
//

#include "Player.h"

Player::Player() {}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}
