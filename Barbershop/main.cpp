
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
    string anyKey, name, surname;
    float salary, price;
    Manager *manager = new Manager();
    manager->setName("name");
    manager->setPassword("password");
    Order *order = new Order();
    HairDress *hairDress = new HairDress();
    HairDresser *hairDresser = new HairDresser();

    vector<Order> orders = manager->loadOrders();
    vector<HairDress> hairDresses = manager->loadHairDresses();
    vector<HairDresser> hairDressers = manager->loadHairDressers();

    rec(manager->getPassword());

    while (true){
        int flag = 0;
        cout<<"Enter 1 to add new HairDress"<<endl;
        cout<<"Enter 2 to add new HairDresser"<<endl;
        cout<<"Enter 3 to show history"<<endl;
        cout<<"Enter 4 to show HairDresses"<<endl;
        cout<<"Enter 5 to show HairDressers"<<endl;
        cout<<"Enter 6 to make order"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cin>>flag;
        switch (flag){
            default:
                cout<<"Unknown command"<<endl;
                break;
            case 0:
                delete order,hairDress,hairDresser;
                return 1;
            case 1:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter price: "<<endl;
                cin>>price;
                hairDress->setName(name);
                hairDress->setPrice(price);
                manager->addHairDress(*hairDress);
                break;
            case 2:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter surname: "<<endl;
                cin>>surname;
                cout<<"Enter salary: "<<endl;
                cin>>salary;
                hairDresser->setName(name);
                hairDresser->setSurname(surname);
                hairDresser->setSalary(salary);
                manager->addHairDresser(*hairDresser);
                break;
            case 3:
                orders = manager->loadOrders();
                for (int i = 0; i < orders.size(); ++i) {
                    cout<<"HairDress: "<<orders[i].getHairDress()
                        <<"   HairDresser: "<<orders[i].getHairDresser()
                        <<"   Price: "<<orders[i].getPrice()<<endl;
                }
                cout<<"Press any key"<<endl;
                cin>>anyKey;
                break;
            case 4:
                hairDresses = manager->loadHairDresses();
                for (int i = 0; i < hairDresses.size(); ++i) {
                    cout<<"HairDress: "<<hairDresses[i].getName()
                        <<"   Price: "<<hairDresses[i].getPrice()<<endl;
                }
                cout<<"Press any key"<<endl;
                cin>>anyKey;
                break;
            case 5:
                hairDressers = manager->loadHairDressers();
                for (int i = 0; i < hairDressers.size(); ++i) {
                    cout<<"Name: "<<hairDressers[i].getName()
                        <<"   Surname: "<<hairDressers[i].getSurname()
                        <<"   Salary: "<<hairDressers[i].getSalary()<<endl;
                }
                cout<<"Press any key"<<endl;
                cin>>anyKey;
                break;
            case 6:
                float resultPrice = 0;
                cout<<"Enter HairDress name: "<<endl;
                cin>>name;
                HairDress tempDress = manager->getHairDressByName(name);

                cout<<"Enter HairDresser name: "<<endl;
                cin>>name;
                HairDresser tempDresser = manager->getHairDresserByName(name);

                resultPrice = tempDress.getPrice() + (tempDresser.getSalary()/2);

                order->setPrice(resultPrice);
                order->setHairDresser(tempDresser.getName());
                order->setHairDress(tempDress.getName());

                manager->addOrder(*order);

                cout<<"Price: "<<resultPrice<<endl;
                break;
        }
    }
}