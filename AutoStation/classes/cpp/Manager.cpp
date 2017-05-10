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

