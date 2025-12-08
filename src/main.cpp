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

    while(true){
        std::cout << "Day: " << day << std::endl;
        bus.collectPassengers(station);

        //TODO: Make the program stop the loop when the station has been empty for more than 8 days
        //TODO: Add slight colors using termcolor to improve readability
        day++;
        sleep(1);
    }

    return 0;
}