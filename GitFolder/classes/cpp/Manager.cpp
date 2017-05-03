//
// Created by azozello on 02.05.17.
//

#include <algorithm>
#include <fstream>
#include "../h/Manager.h"

Manager::Manager(const string &name, const string &password) : name(name), password(password) {}

Manager::Manager() {}

inline bool space(char c){
    return std::isspace(c);
}

inline bool notspace(char c){
    return !std::isspace(c);
}

std::vector<string> split(const std::string& s){
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

vector<Item> Manager::loadItems() {
    vector<Item> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Shop/files/items.txt");
    int vectorIndex = 0;
    while(file) {
        Item *tempItem = new Item();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setName(temp[i]);
            } else if(i==1){
                tempItem->setSellPrice(stof(temp[i]));
            } else if(i==2){
                tempItem->setBuyPrice(stof(temp[i]));
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

void Manager::addItem(Item item) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Shop/files/items.txt",ios::app);
    fout<<item.getName()<<" "<<item.getSellPrice()<<" "<<item.getBuyPrice()<<" "<<endl;
    fout.close();
}

const string &Manager::getName() const {
    return name;
}

void Manager::setName(const string &name) {
    Manager::name = name;
}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}
