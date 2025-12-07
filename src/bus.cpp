#include "../headers/bus.h"
#include "../headers/station.h"
#include "../headers/main.h"
#include <iostream>
#include <unistd.h>
#include <thread>

bool Bus::isBusBusy(){
    return isBusy;
}

//TODO: Fix bus displaying info about taken passangers. Issue is described below 
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
            // Here the passangers waiting number is getting shrinked by amount BEFORE it will even display
            //the information about taken passangers
            if(station.shrinkPassangersByAmnt(Bus::capacity)){
                std::cout << "Bus took " << Bus::capacity << " passangers from station" << std::endl;
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
            // Here applies the same issue as above
            if(station.shrinkPassangersToAmnt(0)){
                //The passangers_waiting variable is already equal to 0 so the bus is telling us
                //that he took 0 passangers even if he for example took 10 of them
                std::cout << "Bus took " << station.getPassangersWaiting() << " passangers from station" << std::endl;
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
