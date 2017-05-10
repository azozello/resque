#include <iostream>
#include "classes/h/Manager.h"

using namespace std;

void rec(string password){
    string youEnter;
    cout<<"Please enter password:"<<endl;
    cin>>youEnter;
    if (youEnter==password){
        return;
    } else {
        cout<<"Wrong password"<<endl;
        cout<<"Please enter password:"<<endl;
        rec(password);
    }
}

int main() {
    string anyKey,name;
    int distance, weight, passengers;
    float salary, consumption;
    Manager *manager = new Manager();
    manager->setName("name");
    manager->setPassword("password");
    manager->setSpeedLimit(90);
    City *city = new City();
    Bus *bus = new Bus();
    Driver *driver = new Driver();
    Repairer *repairer = new Repairer();
    Truck *truck = new Truck();

    vector<Bus> buses = manager->loadBuses();
    vector<Truck> trucks = manager->loadTrucks();
    vector<City> cities = manager->loadCities();
    vector<Driver> drivers = manager->loadDrivers();
    vector<Repairer> repairers = manager->loadRepairers();

    rec(manager->getPassword());

    while (true){
        int flag = 0;
        cout<<"Enter 1 to add new bus"<<endl;
        cout<<"Enter 2 to add new truck"<<endl;
        cout<<"Enter 3 to add new city"<<endl;
        cout<<"Enter 4 to add new driver"<<endl;
        cout<<"Enter 5 to add new repairer"<<endl;
        cout<<"Enter 6 to show station info"<<endl;
        cout<<"Enter 7 to count rout price"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cin>>flag;
        switch (flag){
            default:
                cout<<"Unknown command"<<endl;
                break;
            case 0:
                delete bus,truck,city,driver,repairer;
                return 1;
            case 1:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter passengers: "<<endl;
                cin>>passengers;
                cout<<"Enter consumption: "<<endl;
                cin>>consumption;
                bus->setName(name);
                bus->setMaxPassanger(passengers);
                bus->setConsumption(consumption);
                manager->addBus(*bus);
                break;
            case 2:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter weight: "<<endl;
                cin>>weight;
                cout<<"Enter consumption: "<<endl;
                cin>>consumption;
                truck->setName(name);
                truck->setWeight(weight);
                truck->setConsumption(consumption);
                manager->addTruck(*truck);
                break;
            case 3:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter distance: "<<endl;
                cin>>distance;
                city->setName(name);
                city->setDistance(distance);
                manager->addCity(*city);
                break;
            case 4:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter salary per hour: "<<endl;
                cin>>salary;
                driver->setName(name);
                driver->setSalary(salary);
                manager->addDriver(*driver);
                break;
            case 5:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter salary per hour: "<<endl;
                cin>>salary;
                repairer->setName(name);
                repairer->setSalary(salary);
                manager->addRepairer(*repairer);
                break;
            case 6:
            menu:
                cout<<"Enter 1 to show buses"<<endl;
                cout<<"Enter 2 to show trucks"<<endl;
                cout<<"Enter 3 to show cities"<<endl;
                cout<<"Enter 4 to show drivers"<<endl;
                cout<<"Enter 5 to show repairers"<<endl;
                cout<<"Enter 0 to return"<<endl;
                cin>>flag;
                switch (flag){
                    default:
                        cout<<"Unknown command"<<endl;
                        goto menu;
                    case 0:
                        break;
                    case 1:
                        buses = manager->loadBuses();
                        for (int i = 0; i < buses.size(); ++i) {
                            cout<<"Name: "<<buses[i].getName()
                                <<"   Passengers: "<<buses[i].getMaxPassanger()
                                <<"   Consumption: "<<buses[i].getConsumption()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 2:
                        trucks = manager->loadTrucks();
                        for (int i = 0; i < trucks.size(); ++i) {
                            cout<<"Name: "<<trucks[i].getName()
                                <<"   Weight: "<<trucks[i].getWeight()
                                <<"   Consumption: "<<trucks[i].getConsumption()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 3:
                        cities = manager->loadCities();
                        for (int i = 0; i < cities.size(); ++i) {
                            cout<<"Name: "<<cities[i].getName()
                                <<"   Distance: "<<cities[i].getDistance()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 4:
                        drivers = manager->loadDrivers();
                        for (int i = 0; i < drivers.size(); ++i) {
                            cout<<"Name: "<<drivers[i].getName()
                                <<"   Salary: "<<drivers[i].getSalary()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 5:
                        repairers = manager->loadRepairers();
                        for (int i = 0; i < repairers.size(); ++i) {
                            cout<<"Name: "<<repairers[i].getName()
                                <<"   Salary: "<<repairers[i].getSalary()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                }
                break;
            case 7:
            start:
                Truck tempTruck;
                Bus tempBus;
                float resultPrice = 0;
                float tempDistance = 0;
                float cons = 0;
                cout<<"Enter city`s name: "<<endl;
                cin>>name;
                City tempCity = manager->getCityByName(name);

                cout<<"Enter driver`s name: "<<endl;
                cin>>name;
                Driver tempDriver = manager->getDriverByName(name);

                cout<<"Enter 1 for truck:"<<endl;
                cout<<"Enter 2 for bus:"<<endl;
                cout<<"Enter 0 for return:"<<endl;
                cin>>flag;
                switch(flag){
                    default:
                        cout<<"Wrong command"<<endl;
                        goto start;
                    case 0:
                        break;
                    case 1:
                        cout<<"Enter truck`s name: "<<endl;
                        cin>>name;
                        tempTruck = manager->getTruckByName(name);

                        tempDistance = (float) tempCity.getDistance();
                        cons = tempTruck.getConsumption();

                        resultPrice =
                                (tempDriver.getSalary()*(tempCity.getDistance()/manager->getSpeedLimit())
                                + tempDistance * cons);
                        break;
                    case 2:
                        cout<<"Enter bus`s name: "<<endl;
                        cin>>name;
                        tempBus = manager->getBusByName(name);

                        tempDistance = (float) tempCity.getDistance();
                        cons = tempBus.getConsumption();

                        resultPrice =
                                (tempDriver.getSalary()*(tempCity.getDistance()/manager->getSpeedLimit())
                                 + tempDistance * cons);
                        break;
                }
                cout<<"Price: "<<resultPrice<<endl;
                break;
        }
    }
}