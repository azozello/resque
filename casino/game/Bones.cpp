#include <iostream>
#include "Bones.h"

Bones::Bones() {}

Bones::Bones(const string &name, float price, int players, int bones) : Game(name, price, players), bones(bones) {}

int Bones::play() {
    int scores [getPlayers()];
    for (int i=0;i<getPlayers();i++){
        int tempScore = 0;
        for (int j = 0; j < getBones(); ++j) {
            tempScore += cast();
        }
        scores[i] = tempScore;
        cout<<"Temp score: "<<tempScore<<endl;
    }
    return chooseWinner(scores,getPlayers());
}

int Bones::chooseWinner(int scores [], int length) {
    int temp = 0;
    for (int i = 0; i < length; i++) {
        if (scores[i] > temp){
            cout<<scores[i]<<" "<<i<<endl;
            temp = i;
        }
    }
    return temp;
}

int Bones::cast() {
    srand(time(0));
    long temp = rand()%7+1;
    cout<<"Rand: "<<temp<<endl;
    return (int)temp;
}

void Bones::setBones(int bones) {
    Bones::bones = bones;
}

int Bones::getBones() const {
    return bones;
}

