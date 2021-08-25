//
// Created by Anna Dluzhinskaya on 06.04.2021.
//
#include <istream>
#include <vector>
#include "Car.h"
#include "Order.h"

using namespace std;

#ifndef TAXI_DRIVER_H
#define TAXI_DRIVER_H


class Driver {
protected:
    string name;
    double rating;
    string password;
    vector <Order> order_history;
    bool status_work;
    bool status_ride;
    vector<Car> cars;
    bool loggedIn;
    Car officialCar;
    bool banned;
public:
    Driver(string name, string password, Car car);
    Driver(string name, double rating, vector<Order> vector1, vector<Car> car, bool banned);
    string getName();
    double getRating();
    string getPassword();
    vector<Order> getOrderHistory();
    bool getStatusWork();
    bool getStatusRide();
    void setStatusWork(bool status);
    void setStatusRide(bool status);
    bool getLoggedIn();
    void setLoggedIn(bool temp);
    vector<Car>* getCar();
    Car* getOfficialCar();
    void setOfficialCar(int index);
    int countOfDeclineOrders;
    void addOrderHistory(Order order);
    bool getBanned();
    void setBanned(bool temp);
};


#endif //TAXI_DRIVER_H
