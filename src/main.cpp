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

    std::mt19937 mt_engine(std::random_device{}());
    std::uniform_int_distribution<int> ran(1, 100);

    while(day < 1000000){
        if(station.getPassangersWaiting() < 10){
            station.refill(ran(mt_engine));
        }
        std::cout << "Day: " << day << std::endl;
        bus.collectPassengers(station);

        //TODO: Make the program stop the loop when the station has been empty for more than 8 days
        //TODO: Add slight colors using termcolor to improve readability
        day++;
        //sleep(1);
    }

    std::cout << "Bus ran for " << day << " days and transported " << bus.peopleTransported << " people" << std::endl;

    return 0;
}