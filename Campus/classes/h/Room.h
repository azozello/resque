//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_ROOM_H
#define CAMPUS_ROOM_H

#include <array>

using namespace std;

class Room {
private:
    int number;
    std::string info;
public:
    Room();

    int getNumber() const;
    const string &getInfo() const;

    void setNumber(int number);
    void setInfo(const string &info);
    Room(int number);
};


#endif //CAMPUS_ROOM_H
