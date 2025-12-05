#include "../headers/bus.h"
#include "../headers/station.h"
#include <iostream>

bool Bus::isBusBusy(){
    return isBusy;
}

void Bus::collectPassengers(Station &station) {
    //TODO: Add a cooldown for bus being busy. For example: after a specified time the bus is no longer busy.
    if(isBusy){
        std::cout << "Cannot take any passangers! The bus is busy at the moment." << std::endl;
    }
    else{
        std::cout << "Collecting passengers..." << std::endl;
        if(station.getPassangersWaiting() >= Bus::capacity){
            station.shrinkPassangersByAmnt(Bus::capacity);
            std::cout << "Bus took " << Bus::capacity << " passangers from station" << std::endl;
            isBusy = true;
        }
        else if(station.getPassangersWaiting() < Bus::capacity){
            station.shrinkPassangersToAmnt(0);
            std::cout << "Bus took " << station.getPassangersWaiting() << " passangers from station" << std::endl;
            isBusy = true;
        }
    }
}
