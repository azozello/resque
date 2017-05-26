#ifndef LOADER_H
#define LOADER_H

#include "product.h"
#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <QString>

using namespace std;

//Loads products from file and finds product by name
class Loader
{
private:
    vector<Product> products;
    void loadProducts();
public:
    Loader();
    virtual ~Loader();
    Product getProductByName(QString name);
    vector<Product> getAllProducts();
};

#endif // LOADER_H
