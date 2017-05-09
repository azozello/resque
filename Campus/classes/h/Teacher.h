//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_TEACHER_H
#define CAMPUS_TEACHER_H

#include <array>
#include "Liver.h"

using namespace std;

class Teacher : public Liver {
private:
    string status;
public:
    Teacher();

    Teacher(bool sex, const string &name, const Room &room, const string &status);

    const string &getStatus() const;

    void setStatus(const string &status);
};


#endif //CAMPUS_TEACHER_H
