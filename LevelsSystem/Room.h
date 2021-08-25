//
// Created by Anna Dluzhinskaya on 06.03.2021.
//

#ifndef LEVELSSYSTEM_ROOM_H
#define LEVELSSYSTEM_ROOM_H
#include <iostream>
using namespace std;

class Room {
protected:
    string id;
    string accessLevel;
    bool emergency_situation;
public:
    Room(string id, string name);
    string getID();
    string getAccessLevel();
    bool getEmergencySituation();
    void setEmergencySituation(bool state);
};


#endif //LEVELSSYSTEM_ROOM_H
