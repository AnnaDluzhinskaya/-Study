//
// Created by Anna Dluzhinskaya on 06.04.2021.
//

#include <istream>
using namespace std;

#ifndef TAXI_CAR_H
#define TAXI_CAR_H

enum CarType{
    Economy, Comfort, ComfortPlus, Business
};

class Car {
protected:
    string model;
    CarType carType;
    double coordinateX, coordinateY;
    string color;
    string number;
    int freeBottleOfWater;
    bool validated;
public:
    Car(string model,CarType carType1, string color, string number,bool temp);
    Car() = default;
    string getModel();
    CarType getCarType();
    double getCoordinateX();
    double getCoordinateY();
    string getColor();
    string getNumber();
    int getNumberBottleOfWater();
    void setNumberBottleOfWater(int number);
    bool getValidated();
    void setValidated(bool temp);
};


#endif //TAXI_CAR_H
