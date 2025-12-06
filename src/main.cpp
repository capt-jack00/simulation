#include "../headers/station.h"
#include "../headers/bus.h"
#include "../headers/main.h"
#include <unistd.h>
#include <random>

int day = 0;

int main(){
    //int population = 100;

    Station station;
    station.getPassangersWaiting();

    Bus bus;

    //TODO: Extend this loop in functionality. 
    // This loop below is only a barebone 
    while(true){
        std::cout << "Day: " << day << std::endl;
        bus.collectPassengers(station);

        //std::random_device dev;
        //std::mt19937 gen(dev());
        //std::uniform_int_distribution<> ran(0, 100);
        day++;
        sleep(1);
    }

    return 0;
}