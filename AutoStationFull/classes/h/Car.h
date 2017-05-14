//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_CAR_H
#define AUTOSTATION_CAR_H

#include <array>

using namespace std;

class Car {
private:
    string name;
    float consumption;
public:
    Car(float consumption);

    Car();

    float getConsumption() const;

    void setConsumption(float consumption);

    const string &getName() const;

    void setName(const string &name);
};


#endif //AUTOSTATION_CAR_H
