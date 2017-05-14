//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_BUS_H
#define AUTOSTATION_BUS_H


#include "Car.h"

class Bus : public Car{
private:
    int maxPassanger;
public:
    Bus();

    Bus(float consumption, int maxPassanger);

    int getMaxPassanger() const;

    void setMaxPassanger(int maxPassanger);
};


#endif //AUTOSTATION_BUS_H
