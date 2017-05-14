//
// Created by azozello on 10.05.17.
//

#include "../h/Truck.h"

Truck::Truck(float consumption, int weight) : Car(consumption), weight(weight) {}

Truck::Truck() {}

int Truck::getWeight() const {
    return weight;
}

void Truck::setWeight(int weight) {
    Truck::weight = weight;
}
