#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"
#include "display.hpp"

Memory mem;
Display display;
Cpu cpu(&mem, &display);

int main() {
    mem.loadGame();

    while (display.isOpen()) {
        sf::Event event;
        while (display.pollEvent(event)) {
        
        }
        cpu.emulateCycle();
        //display.update();
    }

    return 0;
}