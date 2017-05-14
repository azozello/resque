#ifndef AUTOSTATION_HUMAN_H
#define AUTOSTATION_HUMAN_H

#include <array>

using namespace std;

class Human {
private:
    string name;
public:
    Human(const string &name);

    Human();

    const string &getName() const;

    void setName(const string &name);
};


#endif //AUTOSTATION_HUMAN_H
