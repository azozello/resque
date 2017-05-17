//
// Created by azozello on 17.05.17.
//

#ifndef OSBB_HEAD_H
#define OSBB_HEAD_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Human.h"
#include "Event.h"
#include "Good.h"

using namespace std;

class Head : public Human{
private:
    string password;
    vector<string> loadEventNames();
    void saveEventNames(vector<string> names);
    void deleteEventDescriptio(string name);
public:
    Head();
    vector<Good> loadGoods();
    void buyGood(Good good);
    void makeEvent(Event event);
    void deleteEvent(Event event);
    vector<Event> loadEvents();
    Event getEventByName(string name);

    const string &getPassword() const;

    void setPassword(const string &password);
};


#endif //OSBB_HEAD_H
