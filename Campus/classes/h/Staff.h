//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_STAFF_H
#define CAMPUS_STAFF_H


#include <array>
#include "Human.h"

using namespace std;

class Staff : public Human {
private:
    string job;
    float salary;
public:
    Staff();

    Staff(bool sex, const string &name, const string &job, float salary);

    const string &getJob() const;

    void setJob(const string &job);

    float getSalary() const;

    void setSalary(float salary);
};


#endif //CAMPUS_STAFF_H
