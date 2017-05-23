#include "loader.h"
#include <iostream>

using namespace std;

inline bool space(char c)
{
    return isspace(c);
}

inline bool notspace(char c)
{
    return !isspace(c);
}

vector<string> split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i!=s.end())
    {
        i = find_if(i, s.end(), notspace);
        iter j = find_if(i, s.end(), space);
        if(i!=s.end())
        {
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

Loader::~Loader()
{

}

Loader::Loader()
{
    loadProducts();
}

void Loader::loadProducts()
{
    vector<Product> result;
        ifstream file("/home/azozello/Sasha/files/products.txt");
        while(file)
        {
            Product *tempProduct = new Product();
            string str;
            getline(file, str);
            vector<string> temp = split(str);
            for (int i = 0; i < temp.size(); i++)
            {
                if (i==0)
                {
                    tempProduct->setName(QString::fromStdString(temp[i]));
                }
                else if(i==1)
                {
                    tempProduct->setProteins(stof(temp[i]));
                }
                else if(i==2)
                {
                    tempProduct->setFat(stof(temp[i]));
                }
                else if(i==3)
                {
                    tempProduct->setCarbons(stof(temp[i]));
                }
                else if(i==4)
                {
                    tempProduct->setCcal(stoi(temp[i]));
                }
            }
            if (tempProduct->getName()!="")
            {
                result.insert(result.end(), *tempProduct);
                delete tempProduct;
            }
        }
        file.close();
        Loader::products = result;
}

Product Loader::getProductByName(QString name)
{
    Product notFound;

    for (int i=0; i<products.size(); i++)
    {
        if(products[i].getName() == name)
        {
            notFound = products[i];
        }
    }
    notFound.setName("Product not found");
    return notFound;
}
