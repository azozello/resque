//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_TRUCK_H
#define AUTOSTATION_TRUCK_H

#include "Car.h"

class Truck : public Car{
private:
    int weight;
public:
    Truck();

    Truck(float consumption, int weight);

    int getWeight() const;

    void setWeight(int weight);
};


#endif //AUTOSTATION_TRUCK_H
