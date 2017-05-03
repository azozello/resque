//
// Created by azozello on 02.05.17.
//

#include <iostream>
#include "../h/Cash.h"

void Cash::changeCash(float cash) {
    ofstream file("/home/azozello/CLionProjects/OutSource/Shop/files/cash.txt");
    file<<cash<<endl;
    file.close();
}

float Cash::getCash() {
    float result = 0;
    ifstream file("/home/azozello/CLionProjects/OutSource/Shop/files/cash.txt");
    string buff;
    file>>buff;
    result = stof(buff);
    file.close();
    return result;
}
