//
// Created by Anna Dluzhinskaya on 10.04.2021.
//

#include "Gateway.h"

void Gateway::createOrder(Passenger &passenger, Order order) {
    this->orders.push_back(pair<Passenger*, Order>(&passenger, order));
}

pair<Passenger*,Order> Gateway::checkAvailableOrder(Driver &driver) {
    int k = 0;
    if (driver.getOfficialCar()->getValidated()) {
        for (int i = 0; i < orders.size(); ++i) {
            if (k == driver.countOfDeclineOrders &&
                driver.getOfficialCar()->getCarType() == orders[i].second.getCarType()) {
                cout << "Available order:" << "\n";
                cout << "From: " << orders[i].second.getFrom() << "\n";
                cout << "To: " << orders[i].second.getTo() << "\n";
                cout << "(" << orders[i].second.getTime() << " min) " << orders[i].second.getPrice() << " $" << "\n";
                cout << "\n";
                return orders[i];
            } else if (driver.getOfficialCar()->getCarType() == orders[i].second.getCarType()) {
                k++;
            }
        }
        cout << "No available orders for this driver\n";
        cout << "\n";
        pair<Passenger *, Order> temp;
        Passenger passenger = Passenger();
        temp.first = &passenger;
        temp.second = Order();
        return temp;
    }else{
        cout <<"Car is not validating by admin!"<<"\n";
        cout << "\n";
        pair<Passenger *, Order> temp;
        Passenger passenger = Passenger();
        temp.first = &passenger;
        temp.second = Order();
        return temp;
    }
}

void Gateway::removeOrder(Order order) {
    int index = 0;
    for (int i = 0; i < this->orders.size(); ++i) {
        if (order==this->orders[i].second){
            index = i;
        }
    }
    this->orders.erase(this->orders.begin()+index);
}

void Gateway::addPassengers(vector<Passenger *> &passengers) {
    this->passengers = &passengers;
}

void Gateway::addDrivers(vector<Driver *> &drivers) {
    this->drivers = &drivers;
}

void Gateway::saveDrivers() {
    vector<Order> ord;
    vector<Car>* cars;
    fstream ofs;
    ofs.open("drivers.txt", ios::out | ios::trunc);
    ofs << this->drivers->size()<< "\n";

    for (auto & i : *this->drivers) {
        ofs << "Name:\n" << i->getName() << "\n";
        ofs << "Orders:\n";
        ord = i->getOrderHistory();
        for (auto & j : ord) {
            ofs << j.getFrom() << "\n";
            ofs << j.getTo() << "\n";
            ofs << j.getCarType() << "\n";
            ofs << j.getTime() << "\n";
            ofs << j.getPrice() << "\n";
        }
        cars = i->getCar();
        for (int j = 0;j<cars->size();j++) {
            ofs << "Car:\n" << cars->at(j).getModel() << "\n";
            if (cars->at(j).getCarType() == Economy) {
                ofs << "Economy\n";
            } else if (cars->at(j).getCarType() == Comfort) {
                ofs << "Comfort\n";
            } else if (cars->at(j).getCarType() == ComfortPlus) {
                ofs << "ComfortPlus\n";
            } else if (cars->at(j).getCarType() == Business) {
                ofs << "Business\n";
            }
            ofs << cars->at(j).getColor() << "\n" << cars->at(j).getNumber() << "\n";
            if(cars->at(j).getValidated()){
                ofs<<"1" << "\n";
            }else{
                ofs<<"0" << "\n";
            }
        }
        ofs << "Rating:\n";
        ofs << i->getRating() << "\n";

        ofs << "Banned:\n";
        if(i->getBanned()){
            ofs<<"1" << "\n";
        }else{
            ofs<<"0" << "\n";
        }
    }
    ofs.close();
}

void Gateway::savePassangers() {
    vector<Order> ord;
    vector<string> pin_adr;
    fstream ofs;
    ofs.open("passengers.txt", ios::out | ios::trunc);
    ofs << this->passengers->size() << "\n";

    for (auto & i : *this->passengers) {
        ofs << "Name:\n" << i->getName() << "\n";
        ofs << "Orders:\n";
        ord = i->getOrderHistory();
        for (auto & j : ord) {
            ofs << j.getFrom() << "\n";
            ofs << j.getTo() << "\n";
            ofs << j.getCarType() << "\n";
            ofs << j.getTime() << "\n";
            ofs << j.getPrice() << "\n";
        }
        ofs << "Pinned:\n";
        pin_adr = i->getPinnedAddresses();
        for (auto & j : pin_adr) {
            ofs << j << "\n";
        }
        ofs << "Payment:\n";
        if (i->getPaymentSystem() == Card) {
            ofs << "Card\n";
        } else {
            ofs << "Cash\n";
        }
        ofs << "Rating:\n";
        ofs << i->getRating() << "\n";

        ofs << "Banned:\n";
        if(i->getBanned()){
            ofs<<"1" << "\n";
        }else{
            ofs<<"0" << "\n";
        }
    }
    ofs.close();
}

vector<Passenger> Gateway::getPassangers() {
    fstream ofs;
    ofs.open("passengers.txt", ios::in);
    int k = 0;
    double price, time, rating;
    CarType carT;
    Payment_System p;
    string s, from, to, carType, name, ban;
    bool val;
    vector<Passenger> tempPassengers;
    vector<string> pinedAddresses;
    ofs >> k;
    getline(ofs, s);
    for (int i = 0; i < k; i++) {
        getline(ofs, s);
        getline(ofs, name);
        getline(ofs, s);
        vector<Order> tempOrds;
        getline(ofs, from);
        while (from != "Pinned:") {
            getline(ofs, to);
            getline(ofs, carType);
            ofs >> time;
            ofs >> price;

            if (carType == "Economy") {
                carT = Economy;
            }
            else if (carType == "Comfort") {
                carT = Comfort;
            }
            else if (carType == "ComfortPlus") {
                carT = ComfortPlus;
            }
            else if (carType == "Business") {
                carT = Business;
            }
            Order tempOrd(from, to, carT);
            tempOrd.setPrice(price);
            tempOrd.setTime(time);
            tempOrds.push_back(tempOrd);
            getline(ofs, s);
            getline(ofs, from);
        }
        getline(ofs, from);
        while (from != "Payment:") {
            pinedAddresses.push_back(from);
            getline(ofs, from);
        }
        getline(ofs, s);
        if (s == "Card") {
            p = Card;
        } else {
            p = Cash;
        }
        getline(ofs, s);
        ofs >> rating;
        getline(ofs, s);
        getline(ofs,ban);
        if(ban=="1"){
            val = true;
        }else{
            val = false;
        }
        getline(ofs, s);
        Passenger pas(name, rating, tempOrds, p, pinedAddresses, val);
        tempPassengers.push_back(pas);
    }
    ofs.close();
    return tempPassengers;
}

vector<Driver> Gateway::getDriver() {
    fstream ofs;
    ofs.open("drivers.txt", ios::in);
    int k = 0;
    double price, time, rating;
    string f, t;
    CarType carT;
    Payment_System p;
    string s, from, to, carType, name, model, color, number, validated, ban;
    bool val, val1;
    vector<Driver> tempDriver;
    ofs >> k;
    getline(ofs, s);
    for (int i = 0; i < k; i++) {
        getline(ofs, s);
        getline(ofs, name);
        getline(ofs, s);
        vector<Order> tempOrds;
        getline(ofs, from);
        while (from != "Car:") {
            getline(ofs, to);
            getline(ofs, carType);
            ofs >> time;
            ofs >> price;


            if (carType == "Economy") {
                carT = Economy;
            } else if (carType == "Comfort") {
                carT = Comfort;
            } else if (carType == "ComfortPlus") {
                carT = ComfortPlus;
            } else if (carType == "Business") {
                carT = Business;
            }
            Order tempOrd(from, to, carT);
            tempOrd.setPrice(price);
            tempOrd.setTime(time);
            tempOrds.push_back(tempOrd);
            getline(ofs, s);
            getline(ofs, from);
        }
        vector<Car> cars;
        while (from != "Rating:") {
            getline(ofs, model);
            getline(ofs, carType);
            if (carType == "Economy") {
                carT = Economy;
            } else if (carType == "Comfort") {
                carT = Comfort;
            } else if (carType == "ComfortPlus") {
                carT = ComfortPlus;
            } else if (carType == "Business") {
                carT = Business;
            }
            getline(ofs, color);
            getline(ofs, number);
            getline(ofs,validated);
            if(validated=="1"){
                val = true;
            }else{
                val = false;
            }
            Car tempCar(model, carT, color, number,val);
            cars.push_back(tempCar);
            getline(ofs, from);
        }
        ofs >> rating;
        getline(ofs, s);
        getline(ofs,ban);
        if(ban=="1"){
            val1 = true;
        }else{
            val1 = false;
        }
        getline(ofs, s);
        Driver newD(name, rating, tempOrds, cars,val1);
        tempDriver.push_back(newD);
    }
    ofs.close();
    return tempDriver;
}

void Gateway::addAdmins(vector<Admin *> &admins) {
    this->admins = &admins;
}

vector<Admin> Gateway::getAdmins() {
    fstream ofs;
    ofs.open("admins.txt", ios::in);
    int k = 0;
    string s, name;
    vector<Admin> tempAdmins;
    ofs >> k;
    getline(ofs, s);
    for (int i = 0; i < k; i++) {
        getline(ofs, s);
        getline(ofs, name);

        Admin newA(name);
        tempAdmins.push_back(newA);
    }
    ofs.close();
    return tempAdmins;
}

void Gateway::saveAdmins() {
    fstream ofs;
    ofs.open("admins.txt", ios::out | ios::trunc);
    ofs << this->admins->size()<< "\n";

    for (auto & i : *this->admins) {
        ofs << "Name:\n" << i->getName() << "\n";
    }
    ofs.close();
}
