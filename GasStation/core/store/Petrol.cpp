#include "Petrol.h"

Petrol::Petrol() {}

Petrol::Petrol(float price) : Oil(price) {}

Petrol::Petrol(float price, const string &name, float coef) : Oil(price), name(name), coef(coef) {}

const string &Petrol::getName() const {
    return name;
}

void Petrol::setName(const string &name) {
    Petrol::name = name;
}

float Petrol::getCoef() const {
    return coef;
}

void Petrol::setCoef(float coef) {
    Petrol::coef = coef;
}

float Petrol::getPrice() const {
    return (Oil::getPrice()/Petrol::barrel)*Petrol::getCoef();
}

Petrol::~Petrol() {

}
