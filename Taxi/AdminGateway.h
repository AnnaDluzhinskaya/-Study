//
// Created by Anna Dluzhinskaya on 26.04.2021.
//

#ifndef TAXI_ADMINGATEWAY_H
#define TAXI_ADMINGATEWAY_H


#include "Admin.h"
#include "Gateway.h"

class AdminGateway {
protected:
    vector<Admin*> admins;
    Gateway* gateway;
public:
    AdminGateway(Gateway& gateway);
    void login(Admin& admin);
    void validateCar(Driver& driver);
    void showPassenger(Passenger& passenger);
    void showDriver(Driver& driver);
    void bannedPassenger(Passenger& passenger,bool temp);
    void bannedDriver(Driver& driver, bool temp);
};


#endif //TAXI_ADMINGATEWAY_H
