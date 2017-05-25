//
// Created by azozello on 24.05.17.
//

#ifndef TANYA_PLAYER_H
#define TANYA_PLAYER_H


#include "Human.h"

class Player : public Human{
private:
    int score;
public:
    Player();

    int getScore() const;

    void setScore(int score);
};


#endif //TANYA_PLAYER_H
