//
// Created by azozello on 17.05.17.
//

#ifndef OSBB_MEMBER_H
#define OSBB_MEMBER_H


#include "Human.h"

class Member : public Human{
private:
    int id;
public:
    Member();

    int getId() const;

    void setId(int id);
};


#endif //OSBB_MEMBER_H
