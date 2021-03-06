//
// Created by azozello on 10.05.17.
//

#include <fstream>
#include <algorithm>
#include "../h/Manager.h"

Manager::Manager(const string &name, const string &password) : Human(name), password(password) {}

Manager::Manager() {}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}

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
        iter j = find_if(i, s.end(), space);
        if(i!=s.end()){
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

vector<Bus> Manager::loadBuses(){
    vector<Bus> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/AutoStation/data/buses.txt");
    int vectorIndex = 0;
    while(file) {
        Bus *bus = new Bus();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                bus->setName(temp[i]);
            } else if(i==1){
                bus->setMaxPassanger(stoi(temp[i]));
            } else if(i==2){
                bus->setConsumption(stof(temp[i]));
            }
        }
        if (bus->getName()!="") {
            result.insert(result.end(), *bus);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Truck> Manager::loadTrucks() {
    vector<Truck> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/AutoStation/data/trucks.txt");
    int vectorIndex = 0;
    while(file) {
        Truck *truck = new Truck();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                truck->setName(temp[i]);
            } else if(i==1){
                truck->setWeight(stoi(temp[i]));
            } else if(i==2){
                truck->setConsumption(stof(temp[i]));
            }
        }
        if (truck->getName()!="") {
            result.insert(result.end(), *truck);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<City> Manager::loadCities() {
    vector<City> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/AutoStation/data/cities.txt");
    int vectorIndex = 0;
    while(file) {
        City *city = new City();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                city->setName(temp[i]);
            } else if(i==1){
                city->setDistance(stoi(temp[i]));
            }
        }
        if (city->getName()!="") {
            result.insert(result.end(), *city);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Driver> Manager::loadDrivers(){
    vector<Driver> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/AutoStation/data/drivers.txt");
    int vectorIndex = 0;
    while(file) {
        Driver *driver = new Driver();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                driver->setName(temp[i]);
            } else if(i==1){
                driver->setSalary(stof(temp[i]));
            }
        }
        if (driver->getName()!="") {
            result.insert(result.end(), *driver);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Repairer> Manager::loadRepairers() {
    vector<Repairer> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/AutoStation/data/repairers.txt");
    int vectorIndex = 0;
    while(file) {
        Repairer *repairer = new Repairer();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                repairer->setName(temp[i]);
            } else if(i==1){
                repairer->setSalary(stof(temp[i]));
            }
        }
        if (repairer->getName()!="") {
            result.insert(result.end(), *repairer);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

void Manager::saveBuses(vector<Bus> buses) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/buses.txt", ios::trunc);
    for (int i = 0; i < buses.size(); ++i) {
        fout<<buses[i].getName()<<" "<<buses[i].getMaxPassanger()<<" "<<buses[i].getConsumption()<<endl;
    }
    fout.close();
}

void Manager::saveTrucks(vector<Truck> trucks) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/trucks.txt", ios::trunc);
    for (int i = 0; i < trucks.size(); ++i) {
        fout<<trucks[i].getName()<<" "<<trucks[i].getWeight()<<" "<<trucks[i].getConsumption()<<endl;
    }
    fout.close();
}

void Manager::saveCities(vector<City> cities) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/cities.txt", ios::trunc);
    for (int i = 0; i < cities.size(); ++i) {
        fout<<cities[i].getName()<<" "<<cities[i].getDistance()<<endl;
    }
    fout.close();
}

void Manager::saveDrivers(vector<Driver> drivers) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/drivers.txt", ios::trunc);
    for (int i = 0; i < drivers.size(); ++i) {
        fout<<drivers[i].getName()<<" "<<drivers[i].getSalary()<<endl;
    }
    fout.close();
}

void Manager::saveRepeirers(vector<Repairer> repairers) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/repeirers.txt", ios::trunc);
    for (int i = 0; i < repairers.size(); ++i) {
        fout<<repairers[i].getName()<<" "<<repairers[i].getSalary()<<endl;
    }
    fout.close();
}

void Manager::deleteBus(Bus bus) {
    vector<Bus> allBuses = loadBuses();
    vector<Bus> saveBuse;
    for (int i = 0; i < allBuses.size(); ++i) {
        if (allBuses[i].getName() != bus.getName() && allBuses[i].getMaxPassanger() != bus.getMaxPassanger()){
            saveBuse.insert(saveBuse.end(), allBuses[i]);
        }
    }
    saveBuses(saveBuse);
}

void Manager::deleteTruck(Truck truck) {
    vector<Truck> allTrucks = loadTrucks();
    vector<Truck> saveTruck;
    for (int i = 0; i < allTrucks.size(); ++i) {
        if (allTrucks[i].getName() != truck.getName() && allTrucks[i].getWeight() != truck.getWeight()){
            saveTruck.insert(saveTruck.end(), allTrucks[i]);
        }
    }
    saveTrucks(saveTruck);
}

void Manager::deleteCity(City city) {
    vector<City> allCities = loadCities();
    vector<City> saveCitie;
    for (int i = 0; i < allCities.size(); ++i) {
        if (allCities[i].getName() != city.getName() && allCities[i].getDistance() != city.getDistance()){
            saveCitie.insert(saveCitie.end(), allCities[i]);
        }
    }
    saveCities(saveCitie);
}

void Manager::deleteDriver(Driver driver) {
    vector<Driver> allDrivers = loadDrivers();
    vector<Driver> saveDriver;
    for (int i = 0; i < allDrivers.size(); ++i) {
        if (allDrivers[i].getName() != driver.getName() && allDrivers[i].getSalary() != driver.getSalary()){
            saveDriver.insert(saveDriver.end(), allDrivers[i]);
        }
    }
    saveDrivers(saveDriver);
}

void Manager::deleteRepairer(Repairer repairer) {
    vector<Repairer> allRepairers = loadRepairers();
    vector<Repairer> saveRepaire;
    for (int i = 0; i < allRepairers.size(); ++i) {
        if (allRepairers[i].getName() != repairer.getName() && allRepairers[i].getSalary() != repairer.getSalary()){
            saveRepaire.insert(saveRepaire.end(), allRepairers[i]);
        }
    }
    saveRepeirers(saveRepaire);
}

void Manager::addBus(Bus bus) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/buses.txt",ios::app);
    fout<<bus.getName()<<" "<<bus.getMaxPassanger()<<" "<<bus.getConsumption()<<endl;
    fout.close();
}

void Manager::addTruck(Truck truck) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/trucks.txt",ios::app);
    fout<<truck.getName()<<" "<<truck.getWeight()<<" "<<truck.getConsumption()<<endl;
    fout.close();
}

void Manager::addCity(City city) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/cities.txt",ios::app);
    fout<<city.getName()<<" "<<city.getDistance()<<endl;
    fout.close();
}

void Manager::addDriver(Driver driver) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/drivers.txt",ios::app);
    fout<<driver.getName()<<" "<<driver.getSalary()<<endl;
    fout.close();
}

void Manager::addRepairer(Repairer repairer) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/AutoStation/data/repairers.txt",ios::app);
    fout<<repairer.getName()<<" "<<repairer.getSalary()<<endl;
    fout.close();
}

Driver Manager::getDriverByName(string name) {
    Driver *temp = new Driver();
    temp->setSalary(100);
    temp->setName("driver");

    vector<Driver> all = loadDrivers();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setName(name);
            temp->setSalary(all[i].getSalary());
        }
    }
    return *temp;
}

City Manager::getCityByName(string name) {
    City *temp = new City();
    temp->setDistance(100);
    temp->setName("city");

    vector<City> all = loadCities();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setName(name);
            temp->setDistance(all[i].getDistance());
        }
    }
    return *temp;
}

Bus Manager::getBusByName(string name) {
    Bus *temp = new Bus();
    temp->setMaxPassanger(1);
    temp->setConsumption(200);
    temp->setName("bus");

    vector<Bus> all = loadBuses();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setName(name);
            temp->setConsumption(all[i].getConsumption());
            temp->setMaxPassanger(all[i].getMaxPassanger());
        }
    }
    return *temp;
}

Truck Manager::getTruckByName(string name) {
    Truck *temp = new Truck();
    temp->setWeight(1000);
    temp->setConsumption(200);
    temp->setName("truck");

    vector<Truck> all = loadTrucks();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setName(name);
            temp->setConsumption(all[i].getConsumption());
            temp->setWeight(all[i].getWeight());
        }
    }
    return *temp;
}

int Manager::getSpeedLimit() const {
    return speedLimit;
}

void Manager::setSpeedLimit(int speedLimit) {
    Manager::speedLimit = speedLimit;
}

