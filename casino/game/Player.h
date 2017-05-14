//
// Created by azozello on 14.05.17.
//

#ifndef CASINO_PLAYER_H
#define CASINO_PLAYER_H

#include <array>

using namespace std;

class Player {
private:
    float money;
    string name;
public:
    Player(float money, const string &name);

    Player();

    float getMoney() const;

    void setMoney(float money);

    const string &getName() const;

    void setName(const string &name);
};


#endif //CASINO_PLAYER_H
