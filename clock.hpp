#ifndef CLOCK
#define CLOCK

#include <cstdint>
#include <SFML/System.hpp>

class Clock {
    public:
        Clock(unsigned int _rate);
        void wait(std::uint8_t cyclesToWait);
    private:
        unsigned int rate;
        sf::Clock sfClock;
};

#endif