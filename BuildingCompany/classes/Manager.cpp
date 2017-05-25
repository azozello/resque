//
// Created by azozello on 25.05.17.
//

#include "Manager.h"
#include <algorithm>

inline bool space(char c){
    return std::isspace(c);
}

inline bool notspace(char c){
    return !std::isspace(c);
}

vector<string> split(const string& s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i!=s.end()){
        i = find_if(i, s.end(), notspace);
        iter j= find_if(i, s.end(), space);
        if(i!=s.end()){
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

void Manager::saveBuildings(vector<Building> buildings) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/buildings.txt",ios::trunc);
    for (int i = 0; i < buildings.size(); i++) {
        fout << buildings[i].getStreet() << " " << buildings[i].getAddres() << " " << buildings[i].getHash() << endl;
    }
    fout.close();
}

void Manager::saveFlats(vector<Flat> flats) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/flats.txt",ios::trunc);
    for (int i = 0; i < flats.size(); i++) {
        fout << flats[i].getPrice() << " " << flats[i].getNumber() << " " << flats[i].getSquare() << " " << flats[i].getBuilding() << endl;
    }
    fout.close();
}

void Manager::addBuilding(Building *building) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/buildings.txt",ios::trunc);
    fout << building->getStreet() << " " << building->getAddres() << " " << building->getHash() << endl;
    fout.close();
}

void Manager::addFlat(Flat *flat) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/flats.txt",ios::app);
    fout << flat->getPrice() << " " << flat->getNumber() << " " << flat->getSquare() << " " << flat->getBuilding() << endl;
    fout.close();
}

void Manager::deleteBuilding(Building *building) {
    vector<Building> allFlats = loadBuildings();
    vector<Building> newFlats;
    for (int i = 0; i < allFlats.size(); i++) {
        if (allFlats[i].getHash() != building->getHash()){
            newFlats.insert(newFlats.end(), allFlats[i]);
        }
    }
    saveBuildings(newFlats);
}

void Manager::deleteFlat(Flat *flat) {
    vector<Flat> allFlats = loadFlats();
    vector<Flat> newFlats;
    for (int i = 0; i < allFlats.size(); i++) {
        if (allFlats[i].getBuilding() != flat->getBuilding() && allFlats[i].getNumber() != flat->getNumber()){
            newFlats.insert(newFlats.end(), allFlats[i]);
        }
    }
    saveFlats(newFlats);
}

vector<Building> Manager::loadBuildings() {
    vector<Building> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/BuildingCompany/data/buildings.txt");
    while(file) {
        Building *tempItem = new Building();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setStreet(temp[i]);
            } else if(i==1){
                tempItem->setAddres(stoi(temp[i]));
            } else if(i==2){
                tempItem->setHash(stoi(temp[i]));
            }
        }
        vector<Flat> allFlats = loadFlats();
        vector<Flat> flatsInBuilding;
        for (int j = 0; j < allFlats.size(); j++) {
            if (allFlats[j].getBuilding() == tempItem->getHash()){
                flatsInBuilding.insert(flatsInBuilding.end(), allFlats[j]);
            }
        }
        tempItem->setFlats(flatsInBuilding);
        if (tempItem->getStreet()!="") {
            result.insert(result.end(), *tempItem);
        }
    }
    file.close();
    return result;
}

vector<Flat> Manager::loadFlats() {
    vector<Flat> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/BuildingCompany/data/flats.txt");
    while(file) {
        Flat *tempItem = new Flat();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setPrice(stoi(temp[i]));
            } else if(i==1){
                tempItem->setNumber(stoi(temp[i]));
            } else if(i==2){
                tempItem->setSquare(stoi(temp[i]));
            }else if(i==3){
                tempItem->setBuilding(stoi(temp[i]));
            }
        }
        if (temp[0]!="") {
            result.insert(result.end(), *tempItem);
        }
    }
    file.close();
    return result;
}

int Manager::loadMoney() {
    ifstream file("/home/azozello/CLionProjects/OutSource/BuildingCompany/data/money.txt");
    int temp = 0;
    file >> temp;
    file.close();
    return temp;
}

void Manager::setMoney(int money) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/orders.txt",ios::trunc);
    fout << money;
    fout.close();
}

Manager::Manager() {}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}

const string &Manager::getName() const {
    return name;
}

void Manager::setName(const string &name) {
    Manager::name = name;
}
