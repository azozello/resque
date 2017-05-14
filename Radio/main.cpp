#include <iostream>
#include "classes/h/Song.h"
#include "classes/h/Caster.h"
#include "classes/h/Advertise.h"
#include "classes/h/Programm.h"

int main() {
    Song *song = new Song();
    Caster *caster = new Caster();
    Advertise *advertise = new Advertise();
    Programm *programm = new Programm();
    float salary, price;
    string name, surname, author, path;
    int flag;
    while (true) {
        cout << "Enter 1 to create program" << endl;
        cout << "Enter 2 to get program" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> flag;
        switch (flag) {
            default:
                cout << "Unknown command" << endl;
                break;
            case 0:
                return 1;
            case 1:
            menu:
                cout << "Enter 1 to add song" << endl;
                cout << "Enter 2 to add advertise" << endl;
                cout << "Enter 0 to return" << endl;
                cin >> flag;
                switch (flag){
                    default:
                        cout << "Unknown command" << endl;
                        goto menu;
                    case 0:
                        break;
                    case 1:
                        cout << "Enter price:" << endl;
                        cin >> price;
                        cout << "Enter author:" << endl;
                        cin >> author;
                        cout << "Enter path(file name):" << endl;
                        cin >> path;
                        song->setPrice(price);
                        song->setAuthor(author);
                        song->setPath(path);
                        programm->addSong(*song);
                        goto menu;
                    case 2:
                        cout << "Enter price:" << endl;
                        cin >> price;
                        cout << "Enter author:" << endl;
                        cin >> author;
                        cout << "Enter path(file name):" << endl;
                        cin >> path;
                        advertise->setPrice(price);
                        advertise->setAuthor(author);
                        advertise->setPath(path);
                        programm->addAdvertise(*advertise);
                        goto menu;
                }
                break;
            case 2:
                cout<<"Program: "<<endl;
                programm->getProgramm();
                break;
        }
    }
}