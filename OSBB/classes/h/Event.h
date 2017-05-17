//
// Created by azozello on 17.05.17.
//

#ifndef OSBB_EVENT_H
#define OSBB_EVENT_H

#include <array>

using namespace std;

class Event {
private:
    string description, name;
public:
    Event();

    const string &getDescription() const;

    void setDescription(const string &description);

    const string &getName() const;

    void setName(const string &name);
};


#endif //OSBB_EVENT_H
