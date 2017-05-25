//
// Created by azozello on 24.05.17.
//

#ifndef TANYA_TRACK_H
#define TANYA_TRACK_H

#include <vector>
#include <iostream>
#include "Player.h"

using namespace std;

class Track {
private:
    string name;
    int age;
    vector<Player> players;
    int throwBall(int rv){
        int t = time(0);
        srand(rv*t);
        long temp = rand()%10+1;
        return (int)temp;
    }
    void step(int rv){
        for (int i = 0; i < players.size(); i++) {
            int temp = throwBall(i*rv);
            if (temp == 10){
                players[i].setScore(players[i].getScore()+(temp*3));
                cout<<players[i].getName()<<"  throws strike!"<<endl;
            } else {
                players[i].setScore(players[i].getScore()+temp);
                cout<<players[i].getName()<<"  throws: "<<temp<<endl;
            }
        }
        cout<<endl;
    }
public:
    Track();
    void play(){
        cout<<"Game"<<endl;
        int win = 0;
        for (int i = 0; i < 10; i++) {
            step(i);
            cout<<"Score: "<<endl;
            for (int j = 0; j < players.size(); j++) {
                cout<<players[j].getName()<<"  --  "<<players[j].getScore()<<endl;
            }
            cout<<endl;
        }
        int tempScore = players[0].getScore();
        for (int j = 1; j < players.size(); j++) {
            if (players[j].getScore() > tempScore){
                tempScore = players[j].getScore();
                win = j;
            }
        }
        cout<<"Winner - "<<players[win].getName()<<"!!!"<<endl;
        cout<<endl;
    }
    void addPlayer(Player *player){
        players.insert(players.end(),*player);
    }
    const vector<Player> &getPlayers() const;
    void setPlayers(const vector<Player> &players);

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);
};


#endif //TANYA_TRACK_H
