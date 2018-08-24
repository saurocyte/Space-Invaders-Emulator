#include "cpu.hpp"
#include "display.hpp"
#include "memory.hpp"
#include <string>
#include <iostream>

extern Cpu cpu;

RGBPix::RGBPix(std::uint8_t _R, std::uint8_t _G, std::uint8_t _B, std::uint8_t _A) : R(_R), G(_G), B(_B), A(_A) {} 

Display::Display() : window(sf::VideoMode(256, 224), "SpaceIemu") {
    
}

void Display::update() {
    std::cout << "DISPLAY | Updating window...\n";
    window.clear(sf::Color::Black);
    std::cout << "DISPLAY | Window cleared!\n";
    for (auto row = 0; row < 255; ++row) {
        for (auto col = 0; col < 30; col++) {
            int bitPos = 0;
            for (auto bit : cpu.memPtr->getByteStr(32 * row + col)) {
                if (bit == '1') {
                    RGBPix pix(255, 255, 255, 0);
                    pixVec.push_back(pix.R);
                    pixVec.push_back(pix.G);
                    pixVec.push_back(pix.B);
                    pixVec.push_back(pix.A);
                } else {
                    RGBPix pix(0, 0, 0, 0);
                    pixVec.push_back(pix.R);
                    pixVec.push_back(pix.G);
                    pixVec.push_back(pix.B);
                    pixVec.push_back(pix.A);
                }
                ++bitPos;
            }
            if (row == 112 && col == 0) { cpu.inteInstr = 0xcf;
            std::cout << "DISPLAY | Half updated, interrupt sent!\n"; }
        }
    }
    cpu.inteInstr = 0xd7;
    std::cout << "DISPLAY | Image constructed, interrupt sent!\n";

    image.create(256, 224, &pixVec[0]);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setRotation(270);
    window.draw(sprite);
    std::cout << "DISPLAY | Displaying...\n";
    window.display(); 
}

bool Display::isOpen() {
    return window.isOpen();
}

bool Display::pollEvent(sf::Event event) {
    return window.pollEvent(event);
}

