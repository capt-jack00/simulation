#include "../headers/bus.h"
#include "../headers/station.h"
#include "../headers/main.h"
#include <iostream>
#include <unistd.h>
#include <thread>

bool Bus::isBusBusy(){
    return isBusy;
}

void Bus::collectPassengers(Station &station) {
    int cooldown = 3;
    if(isBusy){
        std::cout << "Cannot take any passangers! The bus is busy at the moment." << std::endl;
        if(collectDay + cooldown == day){
            isBusy = false;
            collectDay = 0;
        }
    }
    else{
        std::cout << "Collecting passengers..." << std::endl;
        if(station.getPassangersWaiting() >= Bus::capacity){
            if(station.canBeShrinked()){
                std::cout << "Bus took " << Bus::capacity << " passangers from station" << std::endl;
                station.shrinkPassangersByAmnt(Bus::capacity);
                std::cout << "Remaining passangers: " << station.getPassangersWaiting() << std::endl;
                isBusy = true;
                collectDay = day;
            }
            else{
                std::cout << "Cannot take any passangers, the station is empty" << std::endl;
                isBusy == false;
            }
            

        }
        else if(station.getPassangersWaiting() < Bus::capacity){
            if(station.canBeShrinked()){
                std::cout << "Bus took " << station.getPassangersWaiting() << " passangers from station" << std::endl;
                station.shrinkPassangersToAmnt(0);
                std::cout << "Remaining passangers: " << station.getPassangersWaiting() << std::endl;
                isBusy = true;
                collectDay = day;
            }
            else{
                std::cout << "Cannot take any passangers, the station is empty" << std::endl;
                isBusy == false;
            }
                  
        }
    }
}
