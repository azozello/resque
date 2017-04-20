#ifndef GASSTATION_OIL_H
#define GASSTATION_OIL_H

class Oil {
public:
    virtual ~Oil();
    Oil();
    Oil(float price);
    /**
     * @return price for 1 barrel
     * 1 barrel is  158,987 liters
     */
    virtual float getPrice() const;
private:
    float price;
};

#endif //GASSTATION_OIL_H
