//
// Created by Anna Dluzhinskaya on 06.04.2021.
//

#include "Gateway.h"
#include "Car.h"

#ifndef TAXI_PASSENGERGATEWAY_H
#define TAXI_PASSENGERGATEWAY_H


class PassengerGateway {
protected:
    vector<Passenger*> passengers;
    Gateway* gateway;
public:
    PassengerGateway(Gateway &gateway);
    void login(Passenger& passenger);
    void showOrderHistory(Passenger& passenger);
    void changePaymentMethod(Passenger& passenger, Payment_System paymentSystem);
    void showPinnedAddresses(Passenger& passenger);
    void addPinnedAddress(Passenger& passenger, string address);
    void deletePinnedAddress(Passenger& passenger, int index);
    Order printOrder(Passenger& passenger,string from, string to, CarType carType);
    void acceptOrder(Passenger& passenger, Order order, bool accept);
    void acceptOrderAndChangePS(Passenger& passenger, Order order, bool accept, Payment_System paymentSystem);
    void getCoordinatesOfCar(Passenger& passenger);
};


#endif //TAXI_PASSENGERGATEWAY_H
