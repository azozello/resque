//
// Created by azozello on 10.05.17.
//

#ifndef AUTOSTATION_MANAGER_H
#define AUTOSTATION_MANAGER_H

#include <vector>
#include "Human.h"
#include "Driver.h"
#include "City.h"
#include "Repairer.h"
#include "Truck.h"
#include "Bus.h"

class Manager : public Human {
private:
    string password;
    int speedLimit;
public:
    Manager();

    Manager(const string &name, const string &password);

    const string &getPassword() const;

    void setPassword(const string &password);

    vector<Driver> loadDrivers();
    vector<City> loadCities();
    vector<Repairer> loadRepairers();
    vector<Truck> loadTrucks();
    vector<Bus> loadBuses();

    void addBus(Bus bus);
    void addTruck(Truck truck);
    void addCity(City city);
    void addDriver(Driver driver);
    void addRepairer(Repairer repairer);

    Truck getTruckByName(string name);
    Bus getBusByName(string name);
    City getCityByName(string name);
    Driver getDriverByName(string name);

    int getSpeedLimit() const;

    void setSpeedLimit(int speedLimit);
};


#endif //AUTOSTATION_MANAGER_H
