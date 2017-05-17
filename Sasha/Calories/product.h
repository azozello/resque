#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
private:
    QString name;
    float proteins, fat, carbons;
    int ccal;
public:
    Product();
    virtual ~Product();

    void setName(QString name);
    void setProteins(float proteins);
    void setFat(float fat);
    void setCarbons(float carbons);
    void setCcal(int ccal);

    QString getName();
    float getProteins();
    float getFat();
    float getCarbons();
    int getCcal();
};

#endif // PRODUCT_H
