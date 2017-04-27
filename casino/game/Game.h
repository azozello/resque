#ifndef CASINO_GAME_H
#define CASINO_GAME_H

#include <array>

using namespace std;

class Game {
private:
    std::string name;
    float price;
    int players;
public:
    virtual int play();

    Game(const string &name, float price, int players);
    Game();

    virtual ~Game();

    virtual const string &getName() const;

    virtual void setName(const string &name);

    virtual float getPrice() const;

    virtual void setPrice(float price);

    virtual int getPlayers() const;

    virtual void setPlayers(int players);
};


#endif //CASINO_GAME_H
