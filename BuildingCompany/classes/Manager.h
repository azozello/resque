//
// Created by azozello on 25.05.17.
//

#ifndef BUILDINGCOMPANY_MANAGER_H
#define BUILDINGCOMPANY_MANAGER_H

#include <vector>
#include <array>
#include <fstream>
#include "Building.h"

using namespace std;

class Manager {
private:
    string password, name;
    void saveBuildings(vector<Building> buildings);
    void saveFlats(vector<Flat> flats);
public:
    Manager();

    vector<Building> loadBuildings();
    vector<Flat> loadFlats();
    int loadMoney();

    void deleteBuilding(Building *building);
    void deleteFlat(Flat *flat);

    void addBuilding(Building *building);
    void addFlat(Flat *flat);
    void setMoney(int money);

    const string &getPassword() const;
    void setPassword(const string &password);
    const string &getName() const;
    void setName(const string &name);
};


#endif //BUILDINGCOMPANY_MANAGER_H
