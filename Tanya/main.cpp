#include <iostream>

#include "classes/Track.h"
#include "classes/Manager.h"

using namespace std;

void rec(string password){
    string youEnter;
    cin>>youEnter;
    if (youEnter==password){
        return;
    } else {
        cout<<"Wrong password"<<endl;
        cout<<"Please re-enter password:"<<endl;
        rec(password);
    }
}

int main() {
    string name;
    int flag, age;

    Manager *manager = new Manager();
    Track *track = new Track();
    manager->setName("Tanya");
    manager->setPassword("pass");

    while (true) {
        start:
        cout << "Enter 1 to enter as manager" << endl;
        cout << "Enter 2 to enter as client" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> flag;
        switch (flag) {
            default:
                "Unknown command";
                break;
            case 0:
                delete manager, track;
                return 0;
            case 1:{
                cout<<"Please enter password:"<<endl;
                rec(manager->getPassword());
                man:
                cout << "Enter 1 to show tracks" << endl;
                cout << "Enter 2 to change track" << endl;
                cout << "Enter 0 to return" << endl;
                cin >> flag;
                switch (flag){
                    default:
                        cout << "Unknown command"<<endl;
                        goto man;
                    case 0:
                        goto start;
                    case 1: {
                        vector<Track> all = manager->loadTracks();
                        for (int i = 0; i < all.size(); i++) {
                            cout << all[i].getName() << " " << all[i].getAge() << " " << i << endl;
                        }
                        goto man;
                    }
                    case 2:
                        cout<<"Enter index: "<<endl;
                        cin>>flag;
                        cout<<"Enter name: "<<endl;
                        cin>>name;
                        Track *nt = new Track();
                        nt->setName(name);
                        nt->setAge(0);
                        manager->changeTrack(flag,*nt);
                        cout<<"Success"<<endl;
                        goto man;
                }
            }
            case 2:{
                cout<<"Enter players number:"<<endl;
                cin>>flag;
                for (int i = 0; i < flag; i++) {
                    Player *p = new Player();
                    cout<<"Enter player"<<i+1<<" name: "<<endl;
                    cin>>name;
                    p->setName(name);
                    track->addPlayer(p);
                }
                track->play();
                break;
            }
        }
    }
}