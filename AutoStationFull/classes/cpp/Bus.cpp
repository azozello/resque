//
// Created by azozello on 10.05.17.
//

#include "../h/Bus.h"

Bus::Bus(float consumption, int maxPassanger) : Car(consumption), maxPassanger(maxPassanger) {}

Bus::Bus() {}

int Bus::getMaxPassanger() const {
    return maxPassanger;
}

void Bus::setMaxPassanger(int maxPassanger) {
    Bus::maxPassanger = maxPassanger;
}
