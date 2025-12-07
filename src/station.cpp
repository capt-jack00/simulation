#include "../headers/station.h"
#include <random>
#include <iostream>

bool Station::shrinkPassangersByAmnt(int amnt){
    if(passangers_waiting == 0){
        return false;
    }
    else{
        passangers_waiting -= amnt;
        std::cout << "Passanger amnt shrinked by: " << amnt << std::endl;
        return true;
    }
}

bool Station::shrinkPassangersToAmnt(int amnt){
    if(passangers_waiting == 0){
        return false;
    }
    else{
        passangers_waiting = amnt;
        std::cout << "Passanger amnt shrinked to: " << amnt << std::endl;
        return true;
    }
}

int Station::getPassangersWaiting() {
    return passangers_waiting;
}


