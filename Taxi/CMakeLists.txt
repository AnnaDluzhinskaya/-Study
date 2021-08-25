cmake_minimum_required(VERSION 3.17)
project(Taxi)

set(CMAKE_CXX_STANDARD 14)

add_executable(Taxi main.cpp PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h Driver.cpp Driver.h Car.cpp Car.h Order.cpp Order.h Passenger.cpp Passenger.h Gateway.cpp Gateway.h Admin.cpp Admin.h AdminGateway.cpp AdminGateway.h)