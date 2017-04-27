#ifndef CASINO_BONES_H
#define CASINO_BONES_H

#include <array>

using namespace std;

#include "Game.h"

class Bones : Game {
private:
    int bones;
    int cast();
    int chooseWinner(int scores [],int length);
public:
    Bones(const string &name, float price, int players, int bones);
    Bones();
    int play() override;
    const string &getName() const override;
    void setName(const string &name) override;
    float getPrice() const override;
    void setPrice(float price) override;
    int getPlayers() const override;
    void setPlayers(int players) override;

    int getBones() const;
    void setBones(int bones);
};


#endif //CASINO_BONES_H
