#include "product.h"

Product::Product()
{

}

Product::~Product()
{

}

void Product::setCarbons(float carbons)
{
    Product::carbons = carbons;
}

void Product::setProteins(float proteins)
{
    Product::proteins = proteins;
}

void Product::setCcal(int ccal)
{
    Product::ccal = ccal;
}

void Product::setFat(float fat)
{
    Product::fat = fat;
}

void Product::setName(QString name)
{
    Product::name = name;
}

float Product::getCarbons()
{
    return Product::carbons;
}

float Product::getProteins()
{
    return Product::proteins;
}

float Product::getFat()
{
    return Product::fat;
}

int Product::getCcal()
{
    return Product::ccal;
}

QString Product::getName()
{
    return Product::name;
}


