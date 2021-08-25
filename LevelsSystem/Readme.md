#Language standard: C++14
#Compiler: GCC
#OS: MacOS

#How to run code:
    1) Open folder LevelSystem as CLion project (in CLion)
    2) Run main.cpp in CLion
    3) Results and all comands will appear in console

#Description:
    My programm has 2 external classes: Person and Room
        Person - Include implementation of all classes: Students, Admins and etc.
        Room - Include implementation of rooms
    
    Access levels:
        Student - No level - Class room
        Employee - Green - Class room, Lecture room, own Lab
        Professor, Director - Yellow - Class room, Lecture room, own Cabinet
        Admin - Red - All rooms
        Guest - blue
        

    When you run main.cpp, you will see in console some examples of output:
        1) List of rooms (This rooms are added in our program at start)
        2) List of students (Added at the begging)
        3) List of lab employees (Added at the begging)
        4) List of professors (Added at the begging)
        5) List of admins (Added at the begging)
        6) List of directors (Added at the begging)
        7) Examples of adding person (Adding student and director)
        7) Examples of changing level (Student trie to change his level ,Admin change access level of Student)
        8) Examples of opening (Persons try to open some cabinets)
        9) Examples of printinf info about persons.
        10) Examples of adding person (Adding guest)
        11) List of guests
        12) Examples of opening (Guest try to open some room 421) - he can't do it
        13) Emergency situation mood - On
        14) Examples of opening (Guest try to open some room 421) - he can do it
        15) Emergency situation mood - Off
        16) Examples of opening (Guest try to open some room 421) - he can't do it

    Also, after examples programm ask you to write a command/commands (write all command like here - all letters are upper (without space and comma))
#List of commands:
        1) END - ends code execution
           Example (It will looks like that):
               Which type of action do you what to do?
               END
               
               Process finished with exit code 0
               
        2) ADD - add new person
            a) Write class of person: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                *Write class like here - all letters are upper (without space and comma)
            b) Write Name and Surname of person.
            c) Write Date of birth. Format: dd.mm.yyyy
            d) Write Lab's Name if person is lab employee
            e) If perons is Employee/Professor, Admin, Director - write his own Lab/Cabinet
            f) Programm print: added if person added
             
            Example (It will looks like that):
                Which type of action do you what to do?
                ADD
                Which type of users do you want to add?
                ADMINS
                Name: Misha
                Surname: Ivanov
                Date of birth: 01.05.1999
                Cabinets ID: 123
                Admin Misha Ivanov was added.
                
        3) INFO - give info about person
            a) Write class of person: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                *Write class like here - all letters are upper (without space and comma)
            b) Choose the number of person from given list (number only from the list)
            c) Program print: Name, Surname, Date of birth, Access Level and Cabinet.
                
            Example (It will looks like that):
                Which type of action do you what to do?
                INFO
                Which type of users do you want to see?
                ADMINS
                Admins:
                1: Victor Lester 
                2: Elizabeth Ford 
                3: Misha Ivanov 
                What is the number of user in this list you need?
                3
                Name: Misha 
                Surname: Ivanov 
                Date of birth: 01.05.1999 
                Access level: red 
                Cabinet: 123

        4) SHOW_ALL_MEMBERS - print all members of one class
            a) Write class of person: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                  *Write class like here - all letters are upper (without space and comma)
            b) Program print: list of all members of the chosen class
            
             Example (It will looks like that):
             Which type of action do you what to do?
             SHOW_ALL_MEMBERS
             Which type of users do you want to see?
             PROFESSORS
             Professors:
             1: Giancarlo Succi 
             2: Vladimir Ivanov 
             3: Eugene Zuev 
             4: Artem Burmyakov 
                            
                            
        5) CHANGE_LEVEL - admin changes access level for given person
            
            a) Write class of person which try to change level: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                  *Write class like here - all letters are upper (without space and comma)
            b) If class is equal to ADMINS we choose which admint try to change level (number only from the list), else program write that you can not chamge level
            c) Write class of person whom we try to change level
            d) Chose the person (number only from the list)
            e) Write new access level (We replace our access level on this): 
                no_level, green, yellow, red
            e) Programm print:  Class's ( Name Surname ) access level was changed on new_level.

            Example (It will looks like that):
                Which type of action do you what to do?
                CHANGE_LEVEL
                What type of users are you ?
                ADMINS
                Admins:
                1: Victor Lester 
                2: Elizabeth Ford 
                3: Misha Ivanov 
                What is your number in this list?
                2
                Which type of user you want to change access level?
                STUDENTS
                Students:
                1: Anna Dluzhinskaya 
                2: Damir Nabiullin 
                3: Tasha Sakovets 
                4: Lev Kozlov 
                5: Renata Shakirova 
                6: Mark Esaian 
                7: Ruslan Gilvanov 
                8: Artem Voronov 
                9: Roman Voronov 
                10: Artem Sacharov 
                11: Artem Rozhdestvenskiy 
                12: Sofia Milutenkova 
                13: Fedor Ivanov 
                14: Anna Kopeiykina 
                15: Maya Dluzhinskaya 
                16: Elena Shulina 
                17: Elena Krasnova 
                What is your number of student?
                1
                New access level: green
                Student's ( Anna Dluzhinskaya ) access level was changed on green

        6) OPEN_DOOR - print is room opened by person or no
            a) Write class of person: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                                *Write class like here - all letters are upper (without space and comma)
            b) Write the number of person from the list (number only from the list)
            c) Write the number of room from the list (number only from the list)
            d) Programm print: is room opened or no.

            Example (It will looks like that):
                Which type of action do you what to do?
                OPEN_DOOR
                What type of users are you?
                LAB_EMPLOYEES
                Lab Employees:
                1: Hugh Tyler (Software)
                2: Jonas Booker (Software)
                3: Amie Francis (Software)
                4: Liliana Short (Software)
                5: Collin Peters (Game Development)
                6: Christine Warner (Game Development)
                7: Randall Flynn (Game Development)
                8: Winifred Simon (Game Development)
                What is your number in this list?
                2
                Room:
                1: 11
                2: 23
                3: 421
                4: 425
                5: 435
                6: 422
                7: A_124
                8: A_122
                9: 400
                10: 312
                11: 108
                12: 101
                What is your number of room you want to open?
                1
                Jonas Booker tries to open room number 11:
                Open
        7)ADD_ROOM - add access to aditional rooms
            a) Write class of person: STUDENTS,LAB_EMPLOYEES, PROFESSORS, ADMINS, DIRECTORS, GUESTS
                 *Write class like here - all letters are upper (without space and comma)
            b) If class is equal to ADMINS we choose which admint try to add room (number only from the list), else program write that you can not add room
            c) Write class of person whom we try to add room
            d) Chose the person (number only from the list)
            e) Chose the number of room (number only from the list)
            e) Programm print:  Room №.. was added
            
            Example (It will looks like that):
            Which type of action do you what to do?
            ADD_ROOM
            What type of users are you ?
            ADMINS
            Admins:
            1: Victor Lester 
            2: Elizabeth Ford 
            What is your number in this list?
            2
            Which type of user you want to add room?
            GUESTS
            Guests:
            1: Sasha Petrov 
            What is your number of guest?
            1
            Room:
            1: 11
            2: 23
            3: 421
            4: 425
            5: 435
            6: 422
            7: A_124
            8: A_122
            9: 400
            10: 312
            11: 108
            12: 101
            Access to which room do you want to add?
            9
            Room №400 was added!
                
        8)EMERGENCY_SITUATION - make posible open all doors for each person
            a) Change rooms's bool variables (energency_stuation) to true
            
             Example (It will looks like that):
             Which type of action do you what to do?
             EMERGENCY_SITUATION
             Emergency situation!
             
        9)STOP_EMERGENCY_SITUATION - off emergency situation mood
            a) Change rooms's bool variables (energency_stuation) to false
            
            Example (It will looks like that):
            Which type of action do you what to do?
            STOP_EMERGENCY_SITUATION
            Stop emergency situation!