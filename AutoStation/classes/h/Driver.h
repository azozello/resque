//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_DRIVER_H
#define AUTOSTATION_DRIVER_H


#include "Human.h"

class Driver : public Human{
private:
    float salary;
public:
    Driver();

    Driver(const string &name, float salary);

    float getSalary() const;

    void setSalary(float salary);
};


#endif //AUTOSTATION_DRIVER_H
