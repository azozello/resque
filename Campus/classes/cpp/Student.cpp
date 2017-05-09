//
// Created by azozello on 08.05.17.
//

#include "../h/Student.h"

Student::Student() {}

const string &Student::getGroup() const {
    return group;
}

void Student::setGroup(const string &group) {
    Student::group = group;
}

int Student::getYear() const {
    return year;
}

void Student::setYear(int year) {
    Student::year = year;
}

Student::Student(bool sex, const string &name, const Room &room, const string &group, int year) : Liver(sex, name,
                                                                                                        room),
                                                                                                  group(group),
                                                                                                  year(year) {}
