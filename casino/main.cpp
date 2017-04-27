#include <iostream>
#include <fstream>
#include "game/Bones.h"

void leave(float money){
    std::ofstream fout("/home/azozello/CLionProjects/casino/money/Money.txt", std::ios::app);
    fout << "Money: " << money;
    fout << std::endl;
    fout.close();
}

void play(Bones bones) {
    int seat;
    float money = 0;
    cout<<"Choose your seat: "<<endl;
    cin>>seat;
    cout<<"Choose your money: "<<endl;
    while (money>0){
        int flag = 0;
        cout<<"Enter 1 to play, 0 to leave"<<endl;
        cin>>flag;
        if (flag==0){
            leave(money);
            return;
        } else if (flag==1){
            int winner = bones.play();
            if (seat==winner){
                cout<<"You win!";
                money += (bones.getPrice()*bones.getPlayers());
            } else {
                cout<<"You lose!";
                money -= bones.getPrice();
            }
        } else {
            cout<<"Unknown Command"<<endl;
        }
    }
}

void help(){
    cout << "Enter 1 to play, 0 to leave" << endl;
}

int main() {
    while (true) {
        int flag;
        help();
        cin>>flag;
        if (flag==0){
            return 1;
        } else if(flag==1){
            string name;
            float price;
            int bones;
            int players;

            Bones *game = new Bones();
            cout << "Enter price" << endl;
            cin>>price;
            cout << "Enter bones amount" << endl;
            cin>>bones;
            cout << "Enter players amount" << endl;
            cin>>players;

            game->setBones(bones);
            game->setPrice(price);
            game->setPlayers(players);

            play(*game);
        } else {
            cout<<"Unknown command"<<endl;
        }
    }
}


