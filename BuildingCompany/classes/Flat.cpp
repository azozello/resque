//
// Created by azozello on 25.05.17.
//

#include "Flat.h"

Flat::Flat() {}

int Flat::getSquare() const {
    return square;
}

void Flat::setSquare(int square) {
    Flat::square = square;
}

int Flat::getPrice() const {
    return price;
}

void Flat::setPrice(int price) {
    Flat::price = price;
}

int Flat::getBuilding() const {
    return building;
}

void Flat::setBuilding(int building) {
    Flat::building = building;
}

int Flat::getNumber() const {
    return number;
}

void Flat::setNumber(int number) {
    Flat::number = number;
}
