//
// Created by Anna Dluzhinskaya on 06.04.2021.
//

#include <istream>
#include <vector>
#include "Passenger.h"

string Passenger::getName() {
    return this->name;
}

double Passenger::getRating() {
    return this->rating;
}

string Passenger::getPassword() {
    return this->password;
}

vector<Order> Passenger::getOrderHistory() {
    return this->order_history;
}

Payment_System Passenger::getPaymentSystem() {
    return this->paymentSystem;
}

Passenger::Passenger(string name, string password) {
    this->name = name;
    this->password = password;
    this->rating = 5.0;
    this->paymentSystem = Cash;
    this->loggedIn = false;
    this->inRide = false;
    this->banned = false;
}

void Passenger::setPaymentSystem(Payment_System paymentSystem1) {
    this->paymentSystem = paymentSystem1;
}

bool Passenger::getLoggedIn() {
    return this->loggedIn;
}

void Passenger::setLoggedIn(bool temp) {
    this->loggedIn = temp;
}

vector<string> Passenger::getPinnedAddresses() {
    return this->pinned_addresses;
}

void Passenger::addOrderHistory(Order order) {
    this->order_history.push_back(order);
}

void Passenger::addPinnedAddress(string address) {
    this->pinned_addresses.push_back(address);
}

void Passenger::deletePinnedAddress(int index) {
    this->pinned_addresses.erase(this->pinned_addresses.begin() + (index - 1));
}

bool Passenger::getInRide() {
    return this->inRide;
}

void Passenger::setInRide(bool temp) {
    this->inRide = temp;
}

Passenger::Passenger(string name, double rating, vector<Order> orders, Payment_System p, vector<string> pin, bool banned) {
    this->name = name;
    this->rating  = rating;
    this->order_history = orders;
    this->paymentSystem = p;
    this->pinned_addresses = pin;
    this->banned = banned;
}

bool Passenger::getBanned() {
    return this->banned;
}

void Passenger::setBanned(bool temp) {
    this->banned = temp;
}
