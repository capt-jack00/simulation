#include "../headers/bus.h"
#include "../headers/station.h"
#include <iostream>

// if ammount of passengers waiting > bus capacity then board up to capacity
// if ammount of passengers waiting <= bus capacity then board all passengers
void Bus::collectPassengers(Station &station) {
    std::cout << "Collecting passengers..." << std::endl;
    if(station.getPassangersWaiting() >= Bus::capacity){
        station.shrinkPassangersByAmnt(Bus::capacity);
        std::cout << "Bus took " << Bus::capacity << " passangers from station" << std::endl;
    }
    else if(station.getPassangersWaiting() < Bus::capacity){
        station.shrinkPassangersToAmnt(0);
        std::cout << "Bus took " << station.getPassangersWaiting() << " passangers from station" << std::endl;
    }
}