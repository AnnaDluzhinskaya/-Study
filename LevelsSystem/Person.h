//
// Created by Anna Dluzhinskaya on 06.03.2021.
//

#ifndef LEVELSSYSTEM_PERSON_H
#define LEVELSSYSTEM_PERSON_H

#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

class Person {
protected:
     string accessLevel;
     string name;
     string surname;
     string dateOfBirth;
     string ID_cabinet;
     vector<Room> additional_rooms;

public:

    void setAccessLevel (string new_level);
    void openDoor (Room room) ;
    void getAccessLevel ();
    void getName();
    void getSurname ();
    void getIdCabinet();
    void getDateOfBirth ();
    void addAdditionalRoom(Room room);

};

class Student : public Person{
public:
    Student(string name, string surname, string dateOfBirth);

};

class Professor : public Person{
public:
    Professor(string name, string surname, string dateOfBirth, string id_cabinet);

};

class LabEmployees : public Person{
protected:
    string lab_name;
public:
    LabEmployees(string name, string surname, string dateOfBirth,string lab_name,string id_cabinet);
    void getLabName();
};

class Director : public Person{
public:
    Director(string name, string surname, string dateOfBirth, string id_cabinet);

};

class Admin : public Person{
public:
    Admin(string name, string surname, string dateOfBirth, string id_cabinet);
    void changeAccessLevel(Person &person, string new_level);
    void addRoom(Person &person, Room room);

};

class Guest : public Person{
public:
    Guest(string name, string surname, string dateOfBirth);
};

#endif //LEVELSSYSTEM_PERSON_H
