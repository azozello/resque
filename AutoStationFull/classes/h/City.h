//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_CITY_H
#define AUTOSTATION_CITY_H

#include <array>

using namespace std;

class City {
private:
    string name;
    int distance;
public:
    City();

    City(const string &name, int distance);

    const string &getName() const;

    void setName(const string &name);

    int getDistance() const;

    void setDistance(int distance);
};


#endif //AUTOSTATION_CITY_H
