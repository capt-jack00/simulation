#include "../headers/station.h"
#include <random>
#include <iostream>

void Station::shrinkPassangersByAmnt(int amnt){
    passangers_waiting =- amnt;
}

void Station::shrinkPassangersToAmnt(int amnt){
    passangers_waiting == amnt;
}

int Station::getPassangersWaiting() {
    return passangers_waiting;
}


