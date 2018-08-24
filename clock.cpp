#include "clock.hpp"
#include <cstdint>
#include <iostream>
#include <SFML/System.hpp>

Clock::Clock(unsigned int _rate) : rate(_rate) {
    std::cout << "Clock creted!\n";
}

void Clock::wait(std::uint8_t cyclesToWait) {
    sfClock.restart();
    double timeToWait = cyclesToWait / rate; 
    while (true) {
        if (sfClock.getElapsedTime().asMicroseconds() >= timeToWait) break;
    }
}