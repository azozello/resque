#include <bits/ios_base.h>
#include <ios>
#include <fstream>
#include "Order.h"

Order::Order() {}

Order::Order(Petrol *petrol, int liters) : petrol(petrol), liters(liters) {}

Petrol *Order::getPetrol() {
    return petrol;
}

int Order::getLiters() {
    return liters;
}

float Order::getOrdersPrice() {
    return liters*Order::getPetrol()->getPrice();
}

void Order::save() {
    std::ofstream fout("/home/azozello/CLionProjects/GasStation/core/data/History.txt", std::ios::app);

    fout << "Petrol: " << Order::getPetrol()->getName() << " | quantity: "
         << Order::getLiters();

    fout << std::endl;
    fout.close();
}

Order::~Order() {
    save();
}
