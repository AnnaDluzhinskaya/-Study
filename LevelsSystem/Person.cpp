//
// Created by Anna Dluzhinskaya on 06.03.2021.
//

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

void Person::openDoor(Room room) {
    bool flag = false;
    for (int i = 0; i < this->additional_rooms.size() ; ++i) {
        if (room.getID() == additional_rooms[i].getID()){
            flag = true;
        }
    }
    if (flag||room.getEmergencySituation()) {
        cout << "Open" << "\n";
    }else if(this->accessLevel=="blue"){
        string r = room.getID();
        if(r.at(0)=='1'){
            cout << "Open" << "\n";
        }else{
            cout<<"Sorry, you can't open the door!"<<"\n";
        }
    }else if(room.getAccessLevel()=="special"){
        if(room.getID()==this->ID_cabinet||this->accessLevel=="red"){
            cout<<"Open"<<"\n";
        }else{
            cout<<"Sorry, you can't open the door!"<<"\n";
        }
    }else{
        if (this->accessLevel=="red"||this->accessLevel=="yellow"){
            cout<<"Open"<<"\n";
        }else if(this->accessLevel=="green"){
            if(room.getAccessLevel()!="yellow"){
                cout<<"Open"<<"\n";
            }else{
                cout<<"Sorry, you can't open the door!"<<"\n";
            }
        }else if(this->accessLevel=="no_level") {
            if (room.getAccessLevel() == "no_level") {
                cout << "Open" << "\n";
            } else {
                cout << "Sorry, you can't open the door!" << "\n";
            }
        }
    }
}

void Person::getAccessLevel() {
    cout << this->accessLevel<< " ";
}

void Person::getName() {
    cout << this->name << " ";
}

void Person::getSurname() {
    cout << this->surname << " ";
}

void Person::getDateOfBirth() {
    cout << this->dateOfBirth << " ";
}


void Person::setAccessLevel(string new_level) {
    this->accessLevel = new_level;
}

void Person::getIdCabinet() {
    cout<<this->ID_cabinet<<"\n";
}

void Person::addAdditionalRoom(Room room) {
    this->additional_rooms.push_back(room);
    cout <<"Room №"<<room.getID()<<" was added!"<<"\n";
}

Student::Student(string name, string surname, string dateOfBirth) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "no_level";
    this->ID_cabinet = "no_cabinet";

}



Professor::Professor(string name, string surname, string dateOfBirth, string id_cabinet) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "yellow";
    this->ID_cabinet = id_cabinet;
}



LabEmployees::LabEmployees(string name, string surname, string dateOfBirth,string lab_name, string id_cabinet) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "green";
    this->lab_name = lab_name;
    this->ID_cabinet = id_cabinet;
}


void LabEmployees::getLabName(){
    cout << this->lab_name;
}

Director::Director(string name, string surname, string dateOfBirth, string id_cabinet) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "yellow";
    this->ID_cabinet = id_cabinet;
}


Admin::Admin(string name, string surname, string dateOfBirth, string id_cabinet) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "red";
    this->ID_cabinet = id_cabinet;
}

void Admin::changeAccessLevel(Person &person, string new_level) {
    person.setAccessLevel(new_level);
}

void Admin::addRoom(Person &person, Room room) {
    person.addAdditionalRoom(room);
}

Guest::Guest(string name, string surname, string dateOfBirth) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->accessLevel = "blue";
    this->ID_cabinet = "no_cabinet";
}


