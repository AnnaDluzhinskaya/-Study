//
// Created by Anna Dluzhinskaya on 06.04.2021.
//

#include "DriverGateway.h"

void DriverGateway::login(Driver& driver) {
    if(driver.getLoggedIn()){
        cout<<"You are already logged in!"<<"\n";
        cout << "\n";
    }else{
        driver.setLoggedIn(true);
        this->drivers.push_back(&driver);
        cout<<"You are logged in!"<<"\n";
        cout << "\n";
        gateway->saveDrivers();
    }
}

void DriverGateway::showOrderHistory(Driver& driver) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            cout << "Order history:" << "\n";
            for (int i = 0; i < driver.getOrderHistory().size(); ++i) {
                Order temp = driver.getOrderHistory()[i];
                cout << i + 1 << ": " << temp.getFrom() << " -> " << temp.getTo() << " (" << temp.getTime() << " min) "
                     << temp.getPrice() << "$" << "\n";
            }
            cout << "\n";
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

DriverGateway::DriverGateway(Gateway &gateway) {
    this->gateway = &gateway;
    this->gateway->addDrivers(drivers);
}

void DriverGateway::showCar(Driver& driver) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            Car *car = driver.getOfficialCar();
            cout << "Car:" << "\n";
            cout << car->getModel() << " " << car->getColor() << " " << car->getNumber() << " " << car->getCarType()
                 << "\n";
            cout << "Coordinates: " << car->getCoordinateX() << "; " << car->getCoordinateY() << "\n";
            if (car->getCarType() >= 1) {
                cout << "Number of bottle of water: " << car->getNumberBottleOfWater() << "\n";
            }
            cout << "\n";
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::setStatusWork(Driver &driver, bool status) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.setStatusWork(status);
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::setStatusRide(Driver &driver, bool status) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.setStatusRide(status);
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

pair<Passenger*,Order> DriverGateway::checkAvailableOrder(Driver &driver) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            if (!driver.getStatusRide() && driver.getStatusWork()) {
                pair<Passenger *, Order> order = this->gateway->checkAvailableOrder(driver);
                return order;
            } else {
                cout << "This driver is not working now\n";
                cout << "\n";
                pair<Passenger *, Order> temp;
                Passenger passenger = Passenger();
                temp.first = &passenger;
                temp.second = Order();
                return temp;
            }
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
            pair<Passenger *, Order> temp;
            Passenger passenger = Passenger();
            temp.first = &passenger;
            temp.second = Order();
            return temp;
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::acceptOrder(Driver &driver, pair<Passenger*,Order> order) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.setStatusRide(true);
            driver.addOrderHistory(order.second);
            gateway->removeOrder(order.second);
            order.first->setInRide(true);
            cout << "Ride condition accepted!" << "\n";
            cout << "\n";
            gateway->saveDrivers();
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::declineOrder(Driver &driver) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.countOfDeclineOrders = +1;
            cout << "You decline this order!" << "\n";
            cout << "\n";
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::endOrder(Driver &driver, pair<Passenger*, Order> order) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.setStatusRide(false);
            order.first->setInRide(false);
            order.first->addOrderHistory(order.second);
            gateway->savePassangers();
            cout << "Ride is ended!" << "\n";
            cout << "\n";
        } else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::addCar(Driver &driver, Car car) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.getCar()->push_back(car);
            cout << "Car was added!" << "\n";
            cout << "\n";
            gateway->saveDrivers();
        }else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}

void DriverGateway::changeOfficialCar(Driver &driver, int index) {
    try {
        if(driver.getBanned()) throw "You are banned!";
        if (driver.getLoggedIn()) {
            driver.setOfficialCar(index);
            cout << "Car was changed!" << "\n";
            cout << "\n";
            gateway->saveDrivers();
        }else {
            cout << "You are not logged in!" << "\n";
            cout << "\n";
        }
    }catch (const char* exception) {
        cerr<<"Error: "<< exception<<"\n";
    }
}




