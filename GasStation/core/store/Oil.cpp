#include "Oil.h"

float Oil::getPrice() const {
    return price;
}

Oil::~Oil() {

}

Oil::Oil() {}

Oil::Oil(float price) : price(price) {}
