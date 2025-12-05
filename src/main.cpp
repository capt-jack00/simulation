#include "../headers/station.h"
#include "../headers/bus.h"
#include <unistd.h>
#include <random>

int main(){
    int day = 0;
    //int population = 100;

    Station station;
    station.getPassangersWaiting();

    Bus bus;
    bus.collectPassengers(station);

    //TODO: Extend this loop in functionality. 
    // This loop below is only a barebone 
    while(true){
        std::cout << "Day: " << day << std::endl;

        //std::random_device dev;
        //std::mt19937 gen(dev());
        //std::uniform_int_distribution<> ran(0, 100);

        bus.collectPassengers(station);

        day++;
        sleep(1);
    }

    return 0;
}