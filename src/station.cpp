#include "../headers/station.h"
#include <random>
#include <iostream>

//TODO: Make station be able to refill with passangers
void Station::shrinkPassangersByAmnt(int amnt){
    passangers_waiting -= amnt;
}

void Station::shrinkPassangersToAmnt(int amnt){
    passangers_waiting = amnt;
}

bool Station::canBeShrinked(){
    if(passangers_waiting == 0){
        return false;
    }
    else{
        return true;
    }
}

int Station::getPassangersWaiting() {
    return passangers_waiting;
}


