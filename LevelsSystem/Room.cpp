//
// Created by Anna Dluzhinskaya on 06.03.2021.
//

#include "Room.h"
using namespace std;

string Room::getID() {
    return this->id;
}

string Room::getAccessLevel() {
    return this->accessLevel;
}

bool Room::getEmergencySituation() {
    return this->emergency_situation;
}

void Room::setEmergencySituation(bool state) {
    this->emergency_situation = state;
}

Room::Room(string id, string name) {
    this->id = id;
    if (name=="special"){
        this->accessLevel = "special";
    }else if(name=="class_room"){
        this->accessLevel ="no_level";
    }else if(name=="lecture_room"){
        this->accessLevel ="green";
    }else if(name=="conference_room"){
        this->accessLevel ="yellow";
    }
    this->emergency_situation = false;

}


