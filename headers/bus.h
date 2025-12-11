#pragma once
#include "station.h"

class Bus{
    private:
        int capacity;
        bool isBusy = false;

    public:
        long peopleTransported = 0;
        int collectDay;
        Bus(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> ran(0, 30);

            Bus::capacity = ran(gen);
            std::cout << "New bus created with capacity for: " << Bus::capacity << " passangers" << std::endl;
        }
        void collectPassengers(Station &station);
        bool isBusBusy();
};