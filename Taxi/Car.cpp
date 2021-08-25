//
// Created by Anna Dluzhinskaya on 06.04.2021.
//
#include <istream>
#include <vector>
#include "Car.h"

using namespace std;

string Car::getModel() {
    return model;
}

CarType Car::getCarType() {
    return carType;
}

double Car::getCoordinateX() {
    coordinateX = rand()%100/1.005;
    return coordinateX;
}

double Car::getCoordinateY() {
    coordinateY = rand()%100/1.005;
    return coordinateY;
}

string Car::getColor() {
    return color;
}

string Car::getNumber() {
    return number;
}

Car::Car(string model, CarType carType1, string color, string number, bool temp) {
    this->model=model;
    this->color=color;
    this->carType = carType1;
    this->number = number;
    if (carType1>=1){
        this->freeBottleOfWater = (rand()%10)+1;
    }else{
        this->freeBottleOfWater = 0;
    }
    this->validated = temp;
}

int Car::getNumberBottleOfWater() {
    return this->freeBottleOfWater;
}

void Car::setNumberBottleOfWater(int number) {
    this->freeBottleOfWater = number;
}

bool Car::getValidated() {
    return this->validated;
}

void Car::setValidated(bool temp) {
    this->validated = temp;
}

