#include "../h/Head.h"

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

Head::Head() {}

vector<Good> Head::loadGoods() {
    vector<Good> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/OSBB/files/history.txt");
    while(file) {
        Good *good = new Good();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                good->setName(temp[i]);
            } else if(i==1){
                good->setPrice(stof(temp[i]));
            }
        }
        if (good->getName()!="") {
            result.insert(result.end(), *good);
        }
    }
    file.close();
    return result;
}

void Head::buyGood(Good good) {
    ofstream out("/home/azozello/CLionProjects/OutSource/OSBB/files/history.txt", ios::app);
    out<<good.getName()<<" "<<good.getPrice()<<endl;
    out.close();
}

void Head::makeEvent(Event event) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/OSBB/files/events/"+event.getName()+".txt", ios::trunc);
    fout<<event.getDescription()<<endl;
    fout.close();
    ofstream out("/home/azozello/CLionProjects/OutSource/OSBB/files/list.txt", ios::app);
    out<<event.getName()<<endl;
    out.close();
}

void Head::deleteEvent(Event event) {
    vector<string> oldNames = loadEventNames();
    vector<string> newNames;
    for (int i = 0; i < oldNames.size(); i++) {
        if (oldNames[i] != event.getName()){
            newNames.insert(newNames.end(),oldNames[i]);
        }
    }
    saveEventNames(newNames);
}

Event Head::getEventByName(string event) {
    Event *temp = new Event();
    string tempDescription, tempStr;
    ifstream file("/home/azozello/CLionProjects/OutSource/OSBB/files/events/"+event+".txt");
    while(file) {
        string str;
        getline(file, str);
        if (str!="") {
            tempDescription += str;
        }
    }
    file.close();
    temp->setName(event);
    temp->setDescription(tempDescription);
    return *temp;
}

vector<Event> Head::loadEvents() {
    vector<Event> result;
    vector<string> names = loadEventNames();
    for (int i = 0; i < names.size(); i++) {
        Event *temp = new Event();
        string tempDescription, tempStr;
        ifstream file("/home/azozello/CLionProjects/OutSource/OSBB/files/events/"+names[i]+".txt");
        while(file) {
            string str;
            getline(file, str);
            if (str!="") {
                tempDescription += str;
            }
        }
        file.close();
        temp->setName(names[i]);
        temp->setDescription(tempDescription);
        result.insert(result.end(),*temp);
    }
    return result;
}

void Head::saveEventNames(vector<string> names) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/OSBB/files/list.txt", ios::trunc);
    for (int i = 0; i < names.size(); ++i) {
        fout<<names[i]<<endl;
    }
    fout.close();
}

void Head::deleteEventDescriptio(string name) {
    //remove(name);
}

vector<string> Head::loadEventNames() {
    vector<string> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/OSBB/files/list.txt");
    while(file) {
        string str;
        getline(file, str);
        if (str!="") {
            result.insert(result.end(), str);
        }
    }
    file.close();
    return result;
}

const string &Head::getPassword() const {
    return password;
}

void Head::setPassword(const string &password) {
    Head::password = password;
}

