#include "../headers/station.h"
#include "../headers/bus.h"

int main(){
    Station station;
    station.getPassangersWaiting();

    Bus bus;
    bus.collectPassengers(station);

    return 0;
}