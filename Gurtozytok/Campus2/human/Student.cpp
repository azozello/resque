#include "Student.h"

Student::Student(bool sex, const string &name, const string &group, const Room &room) : Human(sex, name), group(group),
                                                                                        room(room) {}
Student::Student() {}

const string &Student::getGroup() const {
    return group;
}

void Student::setGroup(const string &group) {
    Student::group = group;
}

const Room &Student::getRoom() const {
    return room;
}

void Student::setRoom(const Room &room) {
    Student::room = room;
}


