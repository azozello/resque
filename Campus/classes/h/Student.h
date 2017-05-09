//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_STUDENT_H
#define CAMPUS_STUDENT_H

#include "Liver.h"

using namespace std;

class Student : public Liver {
private:
    string group;
    int year;
public:
    Student();

    Student(bool sex, const string &name, const Room &room, const string &group, int year);

    const string &getGroup() const;

    void setGroup(const string &group);

    int getYear() const;

    void setYear(int year);
};


#endif //CAMPUS_STUDENT_H
