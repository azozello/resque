//
// Created by azozello on 14.05.17.
//

#ifndef CASINO_ROULETTE_H
#define CASINO_ROULETTE_H


#include "Game.h"

class Roulette : public Game {
private:
    int lastField;
public:
    Roulette();

    Roulette(const string &name, float price, int players, int lastField);

    int play() override;

    int getLastField() const;

    void setLastField(int lastField);
};


#endif //CASINO_ROULETTE_H
