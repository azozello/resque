//
// Created by azozello on 09.05.17.
//

#ifndef CAMPUS2_STAFF_H
#define CAMPUS2_STAFF_H

#include "Human.h"

class Staff : public Human {
private:
    float salary;
    string job;
public:
    Staff(bool sex, const string &name, float salary, const string &job);
    Staff();

    float getSalary() const;

    void setSalary(float salary);

    const string &getJob() const;

    void setJob(const string &job);
};


#endif //CAMPUS2_STAFF_H
