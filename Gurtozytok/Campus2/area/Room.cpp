//
// Created by azozello on 09.05.17.
//

#include <vector>
#include "Room.h"
#include "../human/Manager.h"

Room::Room(const string &name, int number) : Hostel(name), number(number) {}

Room::Room() {}

Room Room::getRoomByNumber(int number) {
    Manager *manager = new Manager();
    Room *room = new Room();
    vector<Room> all = manager->loadRooms();
    for (int i = 0; i < all.size(); ++i) {
        if (all[i].getNumber()==number){
            return all[i];
        }
    }
    room->setName("New");
    room->setNumber(number);
    return *room;
}


int Room::getNumber() const {
    return number;
}

void Room::setNumber(int number) {
    Room::number = number;
}
