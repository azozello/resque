#include <iostream>
#include "classes/h/Head.h"

void rec(string password){
    string youEnter;
    cout<<"Please enter password:"<<endl;
    cin>>youEnter;
    if (youEnter==password){
        return;
    } else {
        cout<<"Wrong password"<<endl;
        cout<<"Please enter password:"<<endl;
        rec(password);
    }
}

int main() {
    string name, surname, description;
    int flag;
    float price;
    Head *head = new Head();

    head->setName("Name");
    head->setSurname("Surname");
    head->setPassword("password");

    Good *good = new Good();
    Event *event = new Event();
    while (true) {
        cout << "Enter 1 to enter as member" << endl;
        cout << "Enter 2 to enter as head" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> flag;
        switch (flag){
            default:
                cout<<"Unknown command"<<endl;
                break;
            case 0:
                return 1;
            case 1:
            memberMenu:
                cout << "Enter 1 to see events" << endl;
                cout << "Enter 2 to see history" << endl;
                cout << "Enter 0 return" << endl;
                cin>>flag;
                switch (flag){
                    default:
                        cout<<"Unknown command"<<endl;
                        goto memberMenu;
                    case 0:
                        break;
                    case 1: {
                        vector<Event> events = head->loadEvents();
                        for (int i = 0; i < events.size(); i++) {
                            cout << events[i].getName() << " " << events[i].getDescription() << endl;
                        }
                        goto memberMenu;
                    }
                    case 2: {
                        vector<Good> goods = head->loadGoods();
                        for (int i = 0; i < goods.size(); i++) {
                            cout << goods[i].getName() << " " << goods[i].getPrice() << endl;
                        }
                        goto memberMenu;
                    }
                }
                break;
            case 2:
                rec(head->getPassword());
            headMenu:
                cout << "Enter 1 to buy something" << endl;
                cout << "Enter 2 to add event" << endl;
                cout << "Enter 3 to delete event" << endl;
                cout << "Enter 0 return" << endl;
                cin>>flag;
                switch (flag){
                    default:
                        cout<<"Unknown command"<<endl;
                        goto headMenu;
                    case 0:
                        break;
                    case 1: {
                        cout<<"Enter name: "<<endl;
                        cin>>name;
                        cout<<"Enter price: "<<endl;
                        cin>>price;
                        good->setName(name);
                        good->setPrice(price);
                        head->buyGood(*good);
                        cout<<"Success"<<endl;
                        goto headMenu;
                    }
                    case 2: {
                        cout<<"Enter name: "<<endl;
                        cin>>name;
                        cout<<"Enter date: "<<endl;
                        cin>>description;
                        event->setName(name);
                        event->setDescription(description);
                        head->makeEvent(*event);
                        cout<<"Success"<<endl;
                        goto headMenu;
                    }
                    case 3: {
                        cout<<"Enter name: "<<endl;
                        cin>>name;
                        head->deleteEvent(head->getEventByName(name));
                        cout<<"Success"<<endl;
                        goto headMenu;
                    }
                }
                break;
        }
    }
}