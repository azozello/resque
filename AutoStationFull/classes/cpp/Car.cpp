//
// Created by azozello on 10.05.17.
//

#include "../h/Car.h"

Car::Car(float consumption) : consumption(consumption) {}

Car::Car() {}

float Car::getConsumption() const {
    return consumption;
}

void Car::setConsumption(float consumption) {
    Car::consumption = consumption;
}

const string &Car::getName() const {
    return name;
}

void Car::setName(const string &name) {
    Car::name = name;
}
