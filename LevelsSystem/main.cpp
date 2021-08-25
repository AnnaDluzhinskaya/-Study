#include <iostream>
#include "Person.h"
#include "Room.h"
using namespace std;

void showAllStudents(vector<Student> &students){
    cout<<"Students:"<<"\n";
    for (int i = 0; i <students.size(); ++i) {
        cout<<i+1<<": ";
        students[i].getName();
        students[i].getSurname();
        cout<<"\n";
    }
}

void showAllGuests(vector<Guest> &guests){
    cout<<"Guests:"<<"\n";
    for (int i = 0; i <guests.size(); ++i) {
        cout<<i+1<<": ";
        guests[i].getName();
        guests[i].getSurname();
        cout<<"\n";
    }
}

void showAllLabs(vector<LabEmployees> &labs){
    cout<<"Lab Employees:"<<"\n";
    for (int i = 0; i <labs.size(); ++i) {
        cout<<i+1<<": ";
        labs[i].getName();
        labs[i].getSurname();
        cout<<"(";
        labs[i].getLabName();
        cout<<")";
        cout<<"\n";
    }
}

void showAllProfessors(vector<Professor> &professors){
    cout<<"Professors:"<<"\n";
    for (int i = 0; i <professors.size(); ++i) {
        cout<<i+1<<": ";
        professors[i].getName();
        professors[i].getSurname();
        cout<<"\n";
    }
}

void showAllAdmins(vector<Admin> &admins){
    cout<<"Admins:"<<"\n";
    for (int i = 0; i <admins.size(); ++i) {
        cout<<i+1<<": ";
        admins[i].getName();
        admins[i].getSurname();
        cout<<"\n";
    }
}

void showAllDirectors(vector<Director> &directors){
    cout<<"Directors:"<<"\n";
    for (int i = 0; i <directors.size(); ++i) {
        cout<<i+1<<": ";
        directors[i].getName();
        directors[i].getSurname();
        cout<<"\n";
    }
}

void showAllRooms(vector<Room> &rooms){
    cout<<"Room:"<<"\n";
    for (int i = 0; i <rooms.size(); ++i) {
        cout<<i+1<<": ";
        cout<<rooms[i].getID();
        cout<<"\n";
    }
}

template <typename T>
void printInfo(vector<T> &persons, int number){
    cout<<"Name: ";
    persons[number-1].getName();
    cout<<"\n";
    cout<<"Surname: ";
    persons[number-1].getSurname();
    cout<<"\n";
    cout<<"Date of birth: ";
    persons[number-1].getDateOfBirth();
    cout<<"\n";
    cout<<"Access level: ";
    persons[number-1].getAccessLevel();
    cout<<"\n";
    cout<<"Cabinet: ";
    persons[number-1].getIdCabinet();
    cout<<"\n";
}

int main() {
    vector<Student> students;
    vector<LabEmployees> labs;
    vector<Professor> professors;
    vector<Admin> admins;
    vector<Director> directors;
    vector<Room> rooms;
    vector<Guest> guests;

    Student student1 = Student("Anna","Dluzhinskaya","22.09.2002");
    students.push_back(student1);
    Student student2 = Student("Damir","Nabiullin","02.09.2002");
    students.push_back(student2);
    Student student3 = Student("Tasha","Sakovets","16.08.1999");
    students.push_back(student3);
    Student student4 = Student("Lev","Kozlov","23.10.2002");
    students.push_back(student4);
    Student student5 = Student("Renata","Shakirova","21.12.2001");
    students.push_back(student5);
    Student student6 = Student("Mark","Esaian","23.01.2003");
    students.push_back(student6);
    Student student7 = Student("Ruslan","Gilvanov","12.11.2002");
    students.push_back(student7);
    Student student8 = Student("Artem","Voronov","20.09.2002");
    students.push_back(student8);
    Student student9 = Student("Roman","Voronov","20.09.2002");
    students.push_back(student9);
    Student student10 = Student("Artem","Sacharov","11.09.2001");
    students.push_back(student10);
    Student student11 = Student("Artem","Rozhdestvenskiy","14.06.2002");
    students.push_back(student11);
    Student student12 = Student("Sofia","Milutenkova","11.11.2002");
    students.push_back(student12);
    Student student13 = Student("Fedor","Ivanov","20.09.2002");
    students.push_back(student13);
    Student student14 = Student("Anna","Kopeiykina","02.09.2002");
    students.push_back(student14);
    Student student15 = Student("Maya","Dluzhinskaya","22.09.2002");
    students.push_back(student15);
    Student student16 = Student("Elena","Shulina","17.05.1998");
    students.push_back(student16);

    LabEmployees labEmployees1 = LabEmployees ("Hugh","Tyler","01.03.1990","Software","11");
    labs.push_back(labEmployees1);
    LabEmployees labEmployees2 = LabEmployees ("Jonas","Booker","05.09.1992","Software","11");
    labs.push_back(labEmployees2);
    LabEmployees labEmployees3 = LabEmployees ("Amie","Francis","08.01.1987","Software","11");
    labs.push_back(labEmployees3);
    LabEmployees labEmployees4 = LabEmployees ("Liliana","Short","09.09.1988","Software","11");
    labs.push_back(labEmployees4);
    LabEmployees labEmployees5 = LabEmployees ("Collin","Peters","01.03.1990","Game Development","23");
    labs.push_back(labEmployees5);
    LabEmployees labEmployees6 = LabEmployees ("Christine","Warner","07.02.1982","Game Development","23");
    labs.push_back(labEmployees6);
    LabEmployees labEmployees7 = LabEmployees ("Randall","Flynn","19.01.1997","Game Development","23");
    labs.push_back(labEmployees7);
    LabEmployees labEmployees8 = LabEmployees ("Winifred","Simon","22.03.1980","Game Development","23");
    labs.push_back(labEmployees8);

    Professor professor1 = Professor("Giancarlo","Succi","13.06.1956","421");
    professors.push_back(professor1);
    Professor professor2 = Professor("Vladimir","Ivanov","11.05.1976","425");
    professors.push_back(professor2);
    Professor professor3 = Professor("Eugene","Zuev","11.10.1956","435");
    professors.push_back(professor3);
    Professor professor4 = Professor("Artem","Burmyakov","10.11.1982","422");
    professors.push_back(professor4);

    Admin admin1 = Admin("Victor","Lester","27.03.1978","A_124");
    admins.push_back(admin1);
    Admin admin2 = Admin("Elizabeth","Ford","16.04.1988","A_122");
    admins.push_back(admin2);

    Director director1 = Director("Alexsander","Tormasov","14.08.1965","400");
    directors.push_back(director1);

    Room room1 = Room ("11","special");
    rooms.push_back(room1);
    Room room2 = Room ("23","special");
    rooms.push_back(room2);
    Room room3 = Room ("421","special");
    rooms.push_back(room3);
    Room room4 = Room ("425","special");
    rooms.push_back(room4);
    Room room5 = Room ("435","special");
    rooms.push_back(room5);
    Room room6 = Room ("422","special");
    rooms.push_back(room6);
    Room room7 = Room ("A_124","special");
    rooms.push_back(room7);
    Room room8 = Room ("A_122","special");
    rooms.push_back(room8);
    Room room9 = Room ("400","special");
    rooms.push_back(room9);
    Room room10 = Room ("312","class_room");
    rooms.push_back(room10);
    Room room11 = Room ("108","lecture_room");
    rooms.push_back(room11);
    Room room12 = Room ("101","conference_room");
    rooms.push_back(room12);


    showAllRooms(rooms);
    cout<<"\n";
    showAllStudents(students);
    cout<<"\n";
    showAllLabs(labs);
    cout<<"\n";
    showAllProfessors(professors);
    cout<<"\n";
    showAllAdmins(admins);
    cout<<"\n";
    showAllDirectors(directors);
    cout<<"\n";

    string name = "Elena";
    string surname = "Krasnova";
    string dateOfBirth = "24.03.1973";
    Student student = Student(name,surname,dateOfBirth);
    students.push_back(student);
    cout<<"Student "<<name<<" "<<surname<<" was added."<<"\n"<<"\n";
    showAllStudents(students);

    cout<<"\n";
    name = "Masha";
    surname = "Ivanova";
    dateOfBirth = "24.03.1983";
    string id_cabinet = "402";
    Director director = Director(name,surname,dateOfBirth,id_cabinet);
    directors.push_back(director);
    cout<<"Director "<<name<<" "<<surname<<" was added."<<"\n"<<"\n";
    showAllDirectors(directors);

    cout<<"\n";
    string level = "green";

    cout<<"\n";
    admins[0].changeAccessLevel(students[0],level);
    cout<<"Student's ( ";
    students[0].getName();
    students[0].getSurname();
    cout<<") access level was changed on "<<level<<"\n";

    cout<<"\n";
    directors[0].getName();
    directors[0].getSurname();
    cout<<"tries to open room number "<<rooms[2].getID()<<":\n";
    directors[0].openDoor(rooms[2]);

    cout<<"\n";
    admins[1].getName();
    admins[1].getSurname();
    cout<<"tries to open room number "<<rooms[10].getID()<<":\n";
    admins[1].openDoor(rooms[10]);

    cout<<"\n";
    printInfo(students,1);
    printInfo(admins, 1);
    printInfo(professors, 4);

    cout<<"\n";
    name = "Sasha";
    surname = "Petrov";
    dateOfBirth = "24.03.1993";
    Guest guest = Guest(name,surname,dateOfBirth);
    guests.push_back(guest);
    cout<<"Guest "<<name<<" "<<surname<<" was added."<<"\n"<<"\n";
    showAllGuests(guests);

    cout<<"\n";
    guests[0].getName();
    guests[0].getSurname();
    cout<<"tries to open room number "<<rooms[2].getID()<<":\n";
    guests[0].openDoor(rooms[2]);

    cout<<"\n";
    cout<<"Emergency situation!"<<"\n";
    for (int i = 0; i < rooms.size(); ++i) {
        rooms[i].setEmergencySituation(true);
    }

    cout<<"\n";
    guests[0].getName();
    guests[0].getSurname();
    cout<<"tries to open room number "<<rooms[2].getID()<<":\n";
    guests[0].openDoor(rooms[2]);

    cout<<"\n";
    cout<<"Stop emergency situation!"<<"\n";
    for (int i = 0; i < rooms.size(); ++i) {
        rooms[i].setEmergencySituation(false);
    }

    cout<<"\n";
    guests[0].getName();
    guests[0].getSurname();
    cout<<"tries to open room number "<<rooms[2].getID()<<":\n";
    guests[0].openDoor(rooms[2]);


    // ADD, OPEN_DOOR, CHANGE_LEVEL, SHOW_ALL_MEMBERS, INFO, END, ADD_ROOM, EMERGENCY_SITUATION, STOP_EMERGENCY_SITUATION
    string action = "";
    string data = "";
    while (action!="END") {
        cout << "Which type of action do you what to do?" << "\n";
        cin >> action;
        if (action == "ADD") {
            cout << "Which type of users do you want to add?" << "\n";
            cin >> data;
            string name, surname, dateOfBirth, lab_name, id_cabinet;
            if (data == "STUDENTS") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                Student student = Student(name, surname, dateOfBirth);
                students.push_back(student);
                cout << "Student " << name << " " << surname << " was added." << "\n";
            } else if (data == "LAB_EMPLOYEES") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                cout << "Lab's name: ";
                cin >> lab_name;
                cout << "Cabinets ID: ";
                cin >> id_cabinet;
                LabEmployees labEmployee = LabEmployees(name, surname, dateOfBirth, lab_name, id_cabinet);
                labs.push_back(labEmployee);
                cout << "Lab employee " << name << " " << surname << " was added." << "\n";
            } else if (data == "PROFESSORS") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                cout << "Cabinets ID: ";
                cin >> id_cabinet;
                Professor professor = Professor(name, surname, dateOfBirth, id_cabinet);
                professors.push_back(professor);
                cout << "Professor " << name << " " << surname << " was added." << "\n";
            } else if (data == "ADMINS") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                cout << "Cabinets ID: ";
                cin >> id_cabinet;
                Admin admin = Admin(name, surname, dateOfBirth, id_cabinet);
                admins.push_back(admin);
                cout << "Admin " << name << " " << surname << " was added." << "\n";
            } else if (data == "DIRECTORS") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                cout << "Cabinets ID: ";
                cin >> id_cabinet;
                Director director = Director(name, surname, dateOfBirth, id_cabinet);
                directors.push_back(director);
                cout << "Director " << name << " " << surname << " was added." << "\n";
            } else if (data == "GUESTS") {
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Date of birth: ";
                cin >> dateOfBirth;
                Guest guest = Guest(name, surname, dateOfBirth);
                guests.push_back(guest);
                cout << "Guest " << name << " " << surname << " was added." << "\n";
            }else {
                cout << "There is no such type of users!" << "\n";
            }
        } else if (action == "CHANGE_LEVEL") {
            cout << "What type of users are you ?" << "\n";
            cin >> data;
            if (data == "STUDENTS") {
                cout << "Sorry, but you can't change access level!" << "\n";
            } else if (data == "LAB_EMPLOYEES") {
                cout << "Sorry, but you can't change access level!" << "\n";
            } else if (data == "PROFESSORS") {
                cout << "Sorry, but you can't change access level!" << "\n";
            } else if (data == "ADMINS") {
                showAllAdmins(admins);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                cout << "Which type of user you want to change access level?" << "\n";
                cin >> data;
                if (data == "STUDENTS") {
                    showAllStudents(students);
                    int number_1;
                    cout << "What is your number of student?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(students[number_1 - 1], level);
                    cout << "Student's ( ";
                    students[number_1 - 1].getName();
                    students[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                } else if (data == "LAB_EMPLOYEES") {
                    showAllLabs(labs);
                    int number_1;
                    cout << "What is your number of lab employee?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(labs[number_1 - 1], level);
                    cout << "Lab employee's ( ";
                    labs[number_1 - 1].getName();
                    labs[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                } else if (data == "PROFESSORS") {
                    showAllProfessors(professors);
                    int number_1;
                    cout << "What is your number of professor?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(professors[number_1 - 1], level);
                    cout << "Professor's ( ";
                    professors[number_1 - 1].getName();
                    professors[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                } else if (data == "ADMINS") {
                    int number_1;
                    cout << "What is your number of admin?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(admins[number_1 - 1], level);
                    cout << "Admin's ( ";
                    admins[number_1 - 1].getName();
                    admins[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                } else if (data == "DIRECTORS") {
                    showAllDirectors(directors);
                    int number_1;
                    cout << "What is your number of director?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(directors[number_1 - 1], level);
                    cout << "Director's ( ";
                    directors[number_1 - 1].getName();
                    directors[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                } else if (data == "GUESTS") {
                    showAllGuests(guests);
                    int number_1;
                    cout << "What is your number of guest?" << "\n";
                    cin >> number_1;
                    string level;
                    cout << "New access level: ";
                    cin >> level;
                    admins[number - 1].changeAccessLevel(guests[number_1 - 1], level);
                    cout << "Guest's ( ";
                    guests[number_1 - 1].getName();
                    guests[number_1 - 1].getSurname();
                    cout << ") access level was changed on " << level << "\n";
                }else {
                    cout << "There is no such type of users!" << "\n";
                }
            } else if (data == "DIRECTORS") {
                cout << "Sorry, but you can't change access level!" << "\n";
            }else if (data == "GUESTS") {
                    cout << "Sorry, but you can't change access level!" << "\n";
            } else {
                cout << "There is no such type of users!" << "\n";
            }
        } else if (action == "SHOW_ALL_MEMBERS") {
            cout << "Which type of users do you want to see?" << "\n";
            cin >> data;
            if (data == "STUDENTS") {
                showAllStudents(students);
            } else if (data == "LAB_EMPLOYEES") {
                showAllLabs(labs);
            } else if (data == "PROFESSORS") {
                showAllProfessors(professors);
            } else if (data == "ADMINS") {
                showAllAdmins(admins);
            } else if (data == "DIRECTORS") {
                showAllDirectors(directors);
            } else if (data == "GUESTS") {
                showAllGuests(guests);
            }else {
                cout << "There is no such type of users!" << "\n";
            }
        } else if (action == "OPEN_DOOR") {
            cout << "What type of users are you?" << "\n";
            cin >> data;
            if (data == "STUDENTS") {
                showAllStudents(students);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                students[number - 1].getName();
                students[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                students[number - 1].openDoor(rooms[number_1 - 1]);
            } else if (data == "LAB_EMPLOYEES") {
                showAllLabs(labs);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                labs[number - 1].getName();
                labs[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                labs[number - 1].openDoor(rooms[number_1 - 1]);
            } else if (data == "PROFESSORS") {
                showAllProfessors(professors);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                professors[number - 1].getName();
                professors[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                professors[number - 1].openDoor(rooms[number_1 - 1]);
            } else if (data == "ADMINS") {
                showAllAdmins(admins);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                admins[number - 1].getName();
                admins[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                admins[number - 1].openDoor(rooms[number_1 - 1]);
            } else if (data == "DIRECTORS") {
                showAllDirectors(directors);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                directors[number - 1].getName();
                directors[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                directors[number - 1].openDoor(rooms[number_1 - 1]);
            }else if (data == "GUESTS") {
                showAllGuests(guests);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                showAllRooms(rooms);
                int number_1;
                cout << "What is your number of room you want to open?" << "\n";
                cin >> number_1;
                guests[number - 1].getName();
                guests[number - 1].getSurname();
                cout << "tries to open room number " << rooms[number_1 - 1].getID() << ":\n";
                guests[number - 1].openDoor(rooms[number_1 - 1]);
            } else {
                cout << "There is no such type of users!" << "\n";
            }
        } else if (action == "INFO") {
            cout << "Which type of users do you want to see?" << "\n";
            cin >> data;
            if (data == "STUDENTS") {
                showAllStudents(students);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(students, number);
            } else if (data == "LAB_EMPLOYEES") {
                showAllLabs(labs);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(labs, number);
            } else if (data == "PROFESSORS") {
                showAllProfessors(professors);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(professors, number);
            } else if (data == "ADMINS") {
                showAllAdmins(admins);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(admins, number);
            } else if (data == "DIRECTORS") {
                showAllDirectors(directors);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(directors, number);
            } else if (data == "GUESTS") {
                showAllGuests(guests);
                int number;
                cout << "What is the number of user in this list you need?" << "\n";
                cin >> number;
                printInfo(guests, number);
            } else {
                cout << "There is no such type of users!" << "\n";
            }
        } else if (action == "ADD_ROOM") {
            cout << "What type of users are you ?" << "\n";
            cin >> data;
            if (data == "STUDENTS") {
                cout << "Sorry, but you can't add room!" << "\n";
            } else if (data == "LAB_EMPLOYEES") {
                cout << "Sorry, but you can't add room!" << "\n";
            } else if (data == "PROFESSORS") {
                cout << "Sorry, but you can't add room!" << "\n";
            } else if (data == "ADMINS") {
                showAllAdmins(admins);
                int number;
                cout << "What is your number in this list?" << "\n";
                cin >> number;
                cout << "Which type of user you want to add room?" << "\n";
                cin >> data;
                if (data == "STUDENTS") {
                    showAllStudents(students);
                    int number_1;
                    cout << "What is the number of student?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(students[number_1 - 1], rooms[room-1]);
                } else if (data == "LAB_EMPLOYEES") {
                    showAllLabs(labs);
                    int number_1;
                    cout << "What is the number of lab employee?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(labs[number_1 - 1], rooms[room-1]);
                } else if (data == "PROFESSORS") {
                    showAllProfessors(professors);
                    int number_1;
                    cout << "What is the number of professor?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(professors[number_1 - 1], rooms[room-1]);
                } else if (data == "ADMINS") {
                    int number_1;
                    cout << "What is the number of admin?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(admins[number_1 - 1], rooms[room-1]);
                } else if (data == "DIRECTORS") {
                    showAllDirectors(directors);
                    int number_1;
                    cout << "What is the number of director?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(directors[number_1 - 1], rooms[room-1]);
                } else if (data == "GUESTS") {
                    showAllGuests(guests);
                    int number_1;
                    cout << "What is your number of guest?" << "\n";
                    cin >> number_1;
                    int room;
                    showAllRooms(rooms);
                    cout << "Access to which room do you want to add?"<<"\n";
                    cin >> room;
                    admins[number - 1].addRoom(guests[number_1 - 1], rooms[room-1]);
                }else {
                    cout << "There is no such type of users!" << "\n";
                }
            } else if (data == "DIRECTORS") {
                cout << "Sorry, but you can't add room!" << "\n";
            }else if (data == "GUESTS") {
                cout << "Sorry, but you can't add room!" << "\n";
            } else {
                cout << "There is no such type of users!" << "\n";
            }
        }else if (action=="EMERGENCY_SITUATION") {
            for (int i = 0; i < rooms.size(); ++i) {
                rooms[i].setEmergencySituation(true);
            }
            cout<<"Emergency situation!"<<"\n";
        }else if (action=="STOP_EMERGENCY_SITUATION") {
            for (int i = 0; i < rooms.size(); ++i) {
                rooms[i].setEmergencySituation(false);
            }
            cout<<"Stop emergency situation!"<<"\n";
        }else if (action != "END") {
                cout << "There is no such type of action!" << "\n";
        }

        }

}




