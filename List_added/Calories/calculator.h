#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "product.h"
#include <vector>

using namespace std;

class Calculator
{
public:
    Calculator();
    virtual ~Calculator();
    Product count(Product prod, int weight);
    Product count(vector<Product> prod, vector<int> weight);
};

#endif // CALCULATOR_H
