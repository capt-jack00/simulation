#pragma once
#include <random>
#include <iostream>

class Station {

public:
    int passangers_waiting;

    Station(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> ran(0, 50);

        passangers_waiting = ran(gen);

        std::cout << "New station created!" << std::endl;
        std::cout << "Waiting passangers: " << passangers_waiting << std::endl;
        std::cout << std::endl;
    }

    void shrinkPassangersByAmnt(int amnt);
    void shrinkPassangersToAmnt(int amnt);
    bool canBeShrinked();
    int getPassangersWaiting();
};
