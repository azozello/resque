//
// Created by azozello on 09.05.17.
//

#ifndef CAMPUS2_ROOM_H
#define CAMPUS2_ROOM_H

#include "Hostel.h"

class Room : public Hostel {
private:
    int number;
public:
    Room();
    Room(const string &name, int number);
    Room getRoomByNumber(int number);

    int getNumber() const;

    void setNumber(int number);
};

#endif //CAMPUS2_ROOM_H
