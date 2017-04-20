#ifndef GASSTATION_ORDER_H
#define GASSTATION_ORDER_H


#include "../store/Petrol.h"

class Order {
public:
    Order();
    Order(Petrol *petrol, int liters);

    Petrol *getPetrol();
    int getLiters();

    void save();
    float getOrdersPrice();

    virtual ~Order();

private:
    Petrol *petrol;
    int liters;
};


#endif //GASSTATION_ORDER_H
