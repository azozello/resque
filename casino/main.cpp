#include <iostream>
#include <fstream>
#include "game/Bones.h"
#include "game/Roulette.h"
#include "game/Player.h"
#include "game/Check.h"

int main() {
    string name, game;
    int seat, flag;
    float money = 0;
    float price;
    int bonesAmount;
    int players;

    Bones *bones = new Bones();
    Roulette *roulette = new Roulette();
    Player *player = new Player();
    Check *check = new Check();

    start:

    cout<<"Enter name: "<<endl;
    cin>>name;
    cout<<"Enter money: "<<endl;
    cin>>money;

    player->setMoney(money);
    player->setName(name);

    while (true){
        cout<<"Enter 1 to play bones"<<endl;
        cout<<"Enter 2 to play roulette"<<endl;
        cout<<"Enter 3 to show money"<<endl;
        cout<<"Enter 0 to take money and leave"<<endl;
        cin>>flag;
        switch (flag){
            default:
                cout<<"Unknown command"<<endl;
                break;
            case 0:
                check->setName(player->getName());
                check->setGame(game);
                check->setMoney(player->getMoney());
                check->print();
                return 1;
            case 1:
                bones->setName("Bones");
                cout<<"Enter price"<<endl;
                cin>>price;

                if (price>money) goto start;

                bones->setPrice(price);
                cout<<"Enter players"<<endl;
                cin>>players;
                bones->setPlayers(players);
                cout<<"Enter bones"<<endl;
                cin>>bonesAmount;
                bones->setBones(bonesAmount);

                cout<<"Enter seat"<<endl;
                cin>>seat;

                if (seat == bones->play()){
                    money += players*price;
                } else {
                    money -=price;
                }
                player->setMoney(money);
                break;
            case 2:
                roulette->setName("Roulette");
                cout<<"Enter price"<<endl;
                cin>>price;

                if (price>money) goto start;

                roulette->setPrice(price);

                cout<<"Enter players"<<endl;
                cin>>players;
                roulette->setPlayers(players);

                cout<<"Enter seat"<<endl;
                cin>>seat;

                if (seat == bones->play()){
                    money += players*price;
                } else {
                    money -=price;
                }
                player->setMoney(money);
                break;
            case 3:
                cout<<"Money: "<<money<<endl;
                break;
        }
    }
}


