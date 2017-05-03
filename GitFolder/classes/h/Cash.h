//
// Created by azozello on 02.05.17.
//

#ifndef SHOP_CASH_H
#define SHOP_CASH_H

#include <algorithm>
#include <fstream>

using namespace std;

class Cash {
public:
    static float getCash();
    static void changeCash(float cash);
};


#endif //SHOP_CASH_H
