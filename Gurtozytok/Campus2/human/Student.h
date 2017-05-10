//
// Created by azozello on 09.05.17.
//

#ifndef CAMPUS2_STUDENT_H
#define CAMPUS2_STUDENT_H


#include "Human.h"
#include "../area/Room.h"

class Student : public Human {
private:
    string group;
    Room room;
public:
    Student();

    Student(bool sex, const string &name, const string &group, const Room &room);

    const string &getGroup() const;

    void setGroup(const string &group);

    const Room &getRoom() const;

    void setRoom(const Room &room);

};


#endif //CAMPUS2_STUDENT_H
