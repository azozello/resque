//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_LIVER_H
#define CAMPUS_LIVER_H

#include "Human.h"
#include "Room.h"

class Liver : public Human {
private:
    Room room;
public:
    Liver();
    Liver(bool sex, const string &name, const Room &room);

    const Room &getRoom() const;

    void setRoom(const Room &room);
};


#endif //CAMPUS_LIVER_H
