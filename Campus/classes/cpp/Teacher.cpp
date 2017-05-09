//
// Created by azozello on 08.05.17.
//

#include "../h/Teacher.h"

Teacher::Teacher() {}

const string &Teacher::getStatus() const {
    return status;
}

void Teacher::setStatus(const string &status) {
    Teacher::status = status;
}

Teacher::Teacher(bool sex, const string &name, const Room &room, const string &status) : Liver(sex, name, room),
                                                                                         status(status) {}
