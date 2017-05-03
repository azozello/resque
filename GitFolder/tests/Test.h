//
// Created by azozello on 03.05.17.
//

#ifndef SHOP_TEST_H
#define SHOP_TEST_H

#include <gtest/gtest.h>
#include <vector>
#include <array>
#include "../classes/h/Cash.h"
#include "../classes/h/Stock.h"
#include "../classes/h/Item.h"
#include "../classes/h/Manager.h"

class Test : public ::testing::Test {
protected:
    void SetUp() {
        stock = new Stock();
        cash = new Cash();
        manager = new Manager();
    }
    void TearDown() {
        delete stock;
        delete cash;
        delete manager;
    }
    Cash *cash;
    Stock *stock;
    Manager *manager;
};

#endif //SHOP_TEST_H
