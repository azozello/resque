#ifndef GASSTATION_PETROL_H
#define GASSTATION_PETROL_H

#include <array>

using namespace std;

#include "Oil.h"

class Petrol : Oil {
public:
    Petrol();
    Petrol(float price);
    Petrol(float price, const string &name, float coef);

    const string &getName() const;
    float getCoef() const;

    void setName(const string &name);
    void setCoef(float coef);
    /**
     *@return price for 1 liter
     */
    float getPrice() const override;

    virtual ~Petrol();

private:
    const int barrel = 160;
    string name;
    float coef;
};


#endif //GASSTATION_PETROL_H
