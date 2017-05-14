//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_REPAIRER_H
#define AUTOSTATION_REPAIRER_H


#include "Human.h"

class Repairer : public Human{
private:
    float salary;
public:
    Repairer();

    Repairer(const string &name, float salary);

    float getSalary() const;

    void setSalary(float salary);
};


#endif //AUTOSTATION_REPAIRER_H
