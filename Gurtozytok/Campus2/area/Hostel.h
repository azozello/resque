
#ifndef CAMPUS2_HOSTEL_H
#define CAMPUS2_HOSTEL_H

#include <array>

using namespace std;

class Hostel {
private:
    string name;
public:
    Hostel(const string &name);
    Hostel();

    const string &getName() const;

    void setName(const string &name);
};


#endif //CAMPUS2_HOSTEL_H
