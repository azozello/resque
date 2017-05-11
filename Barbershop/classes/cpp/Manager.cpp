//
// Created by azozello on 12.05.17.
//

#include "../h/Manager.h"
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

vector<Order> Manager::loadOrders() {
    vector<Order> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Barbershop/data/orders.txt");
    int vectorIndex = 0;
    while(file) {
        Order *tempItem = new Order();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setHairDress(temp[i]);
            } else if(i==1){
                tempItem->setPrice(stof(temp[i]));
            } else if(i==2){
                tempItem->setHairDresser(temp[i]);
            }
        }
        if (tempItem->getHairDress()!="") {
            result.insert(result.end(), *tempItem);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<HairDress> Manager::loadHairDresses() {
    vector<HairDress> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Barbershop/data/hairDresses.txt");
    int vectorIndex = 0;
    while(file) {
        HairDress *tempItem = new HairDress();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setName(temp[i]);
            } else if(i==1){
                tempItem->setPrice(stof(temp[i]));
            }
        }
        if (tempItem->getName()!="") {
            result.insert(result.end(), *tempItem);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<HairDresser> Manager::loadHairDressers() {
    vector<HairDresser> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Barbershop/data/hairDressers.txt");
    int vectorIndex = 0;
    while(file) {
        HairDresser *tempItem = new HairDresser();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setName(temp[i]);
            } else if(i==1){
                tempItem->setSurname(temp[i]);
            } else if(i==2){
                tempItem->setSalary(stof(temp[i]));
            }
        }
        if (tempItem->getName()!="") {
            result.insert(result.end(), *tempItem);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

Order Manager::getOrderByName(string name) {
    Order *temp = new Order();
    temp->setPrice(100);
    temp->setHairDresser("HairDresser");
    temp->setHairDress("HairDress");

    vector<Order> all = loadOrders();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getHairDress()==name){
            temp->setPrice(all[i].getPrice());
            temp->setHairDresser(all[i].getHairDresser());
        }
    }
    return *temp;
}

HairDress Manager::getHairDressByName(string name) {
    HairDress *temp = new HairDress();
    temp->setPrice(100);
    temp->setName("city");

    vector<HairDress> all = loadHairDresses();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setPrice(all[i].getPrice());
        }
    }
    return *temp;
}

HairDresser Manager::getHairDresserByName(string name) {
    HairDresser *temp = new HairDresser();
    temp->setSurname("surname");
    temp->setSalary(200);
    temp->setName("name");

    vector<HairDresser> all = loadHairDressers();
    for (int i = 0; i < all.size(); i++) {
        if (all[i].getName()==name){
            temp->setName(name);
            temp->setSurname(all[i].getSurname());
            temp->setSalary(all[i].getSalary());
        }
    }
    return *temp;
}

void Manager::addOrder(Order order) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/orders.txt",ios::app);
    fout<<order.getHairDress()<<" "<<order.getPrice()<<" "<<order.getHairDresser()<<endl;
    fout.close();
}

void Manager::addHairDress(HairDress hairDress) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/hairDresses.txt",ios::app);
    fout<<hairDress.getName()<<" "<<hairDress.getPrice()<<endl;
    fout.close();
}

void Manager::addHairDresser(HairDresser hairDresser) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Barbershop/data/hairDressers.txt",ios::app);
    fout<<hairDresser.getName()<<" "<<hairDresser.getSurname()<<" "<<hairDresser.getSalary()<<endl;
    fout.close();
}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}

Manager::Manager() {}

Manager::Manager(bool sex, const string &name, const string &password) : Human(sex, name), password(password) {}
