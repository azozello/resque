//
// Created by azozello on 14.05.17.
//

#ifndef CASINO_CHECK_H
#define CASINO_CHECK_H

#include <array>

using namespace std;

class Check {
private:
    string name, game;
    float money;
public:
    Check();

    Check(const string &game, float money);

    const string &getGame() const;

    void setGame(const string &game);

    float getMoney() const;

    void setMoney(float money);

    const string &getName() const;

    void setName(const string &name);

    void print();
};


#endif //CASINO_CHECK_H
