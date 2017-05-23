#include "calculator.h"
#include <iostream>

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}

Product Calculator::count(Product prod, int weight)
{
    Product *result = new Product();

    float proteins, fat, carbons;
    int ccal;

    proteins = prod.getProteins() * weight;
    fat = prod.getFat() * weight;
    carbons = prod.getCarbons() * weight;
    ccal = prod.getCcal() * weight;

    result->setCarbons(carbons);
    result->setCcal(ccal);
    result->setFat(fat);
    result->setProteins(proteins);
    result->setName("Total: ");

    return *result;
}

Product Calculator::count(vector<Product> prod, vector<int> weight)
{
    Product *result = new Product();

    float proteins = 0, fat = 0, carbons = 0;
    int ccal = 0;

    for (int i=0; i<prod.size() ;i++)
    {
        proteins += prod[i].getProteins() * weight[i];
        fat += prod[i].getFat() * weight[i];
        carbons += prod[i].getCarbons() * weight[i];
        ccal += prod[i].getCcal() * weight[i];
    }

    result->setCarbons(carbons);
    result->setCcal(ccal);
    result->setFat(fat);
    result->setProteins(proteins);
    result->setName("Total: ");

    return *result;
}


