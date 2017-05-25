//
// Created by azozello on 25.05.17.
//

#ifndef BUILDINGCOMPANY_FLAT_H
#define BUILDINGCOMPANY_FLAT_H


class Flat {
private:
    int square, price, building, number;
public:
    Flat();

    int getSquare() const;

    void setSquare(int square);

    int getPrice() const;

    void setPrice(int price);

    int getBuilding() const;

    void setBuilding(int building);

    int getNumber() const;

    void setNumber(int number);
};


#endif //BUILDINGCOMPANY_FLAT_H
