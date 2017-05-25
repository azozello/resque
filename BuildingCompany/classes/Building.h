//
// Created by azozello on 25.05.17.
//

#ifndef BUILDINGCOMPANY_BUILDING_H
#define BUILDINGCOMPANY_BUILDING_H

#include <array>
#include <vector>
#include "Flat.h"

using namespace std;

class Building {
private:
    int hash;
    string street;
    int adress;
    vector<Flat> flats;
public:
    Building();

    void addFlat(Flat *flat){
        flats.insert(flats.end(), *flat);
    }

    void deleteFlat(Flat *flat){
        vector<Flat> newFlat;
        for (int i = 0; i < flats.size(); i++) {
            if (flats[i].getBuilding() != flat->getBuilding() && flats[i].getNumber() != flat->getNumber()){
                newFlat.insert(newFlat.end(), flats[i]);
            }
        }
        flats = newFlat;
    }

    int getHash() const;

    void setHash(int hash);

    const string &getStreet() const;

    void setStreet(const string &street);

    int getAddres() const;

    void setAddres(int addres);

    const vector<Flat> &getFlats() const;

    void setFlats(const vector<Flat> &flats);
};


#endif //BUILDINGCOMPANY_BUILDING_H
