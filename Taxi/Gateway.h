//
// Created by Anna Dluzhinskaya on 10.04.2021.
//

#ifndef TAXI_GATEWAY_H
#define TAXI_GATEWAY_H
#include "Passenger.h"
#include "Driver.h"
#include "Admin.h"
#include <fstream>


class Gateway {
protected:
    vector<pair<Passenger*, Order>> orders;
    vector<Passenger*> *passengers;
    vector<Driver*> *drivers;
    vector<Admin*> *admins;
public:
    Gateway() = default;
    void createOrder(Passenger &passenger, Order order);
    void removeOrder(Order order);
    pair<Passenger*,Order> checkAvailableOrder(Driver& driver);
    void addPassengers(vector<Passenger*> &passengers);
    void addDrivers(vector<Driver*> &drivers);
    void addAdmins(vector<Admin*> &admins);
    void savePassangers();
    void saveDrivers();
    void saveAdmins();
    vector<Passenger> getPassangers();
    vector<Driver> getDriver();
    vector<Admin> getAdmins();

};


#endif //TAXI_GATEWAY_H
