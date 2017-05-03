//
// Created by azozello on 03.05.17.
//

#include "Test.h"

TEST_F(Test, cashTest){
    float startValue = cash->getCash();
    float finishValue = startValue*1.5f;
    cash->changeCash(finishValue);
    ASSERT_EQ(cash->getCash(),finishValue);
}

TEST_F(Test, stockCashTest){
    float startValue = cash->getCash();
    int quantity = 3;
    float price = 2.0;
    Item *testItem = new Item("testFruit",3.0,price);
    stock->orderItem(*testItem,quantity);
    ASSERT_EQ(cash->getCash(),startValue-(quantity*price));
}

TEST_F(Test, stockOrderTest){
    int quantity = 3;
    float price = 2.0;
    Item *testItem = new Item("testFruit",3.0,price);
    vector<Item> result = stock->orderItem(*testItem,quantity);
    ASSERT_EQ(result[0].getName(),testItem->getName());
}

TEST_F(Test, managerTest){
    Item *itemToAdd = new Item("testApple",5.5,4.4);
    Item *resultItem = new Item();
    manager->addItem(*itemToAdd);
    vector<Item> result = manager->loadItems();
    for (int i = 0; i < result.size(); ++i) {
        resultItem = new Item(result[i].getName(),result[i].getSellPrice(),result[i].getBuyPrice());
    }
    ASSERT_EQ(itemToAdd->getName(),resultItem->getName());
}