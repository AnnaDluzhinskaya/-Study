//
// Created by Anna Dluzhinskaya on 26.04.2021.
//

#include "Admin.h"

Admin::Admin(string name) {
    this->name = name;
}

string Admin::getName() {
    return this->name;
}

bool Admin::getLoggedIn() {
    return this->loggedIn;
}

void Admin::setLoggedIn(bool temp) {
    this->loggedIn = temp;
}

