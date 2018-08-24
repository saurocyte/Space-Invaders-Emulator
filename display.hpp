#ifndef DISPLAY
#define DISPLAY

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdint>
#include <vector>

struct RGBPix {
    RGBPix(std::uint8_t _R, std::uint8_t _G, std::uint8_t _B, std::uint8_t A);

    std::uint8_t R;
    std::uint8_t G;
    std::uint8_t B;
    std::uint8_t A;
};

class Display {
    public:
        Display();
        void update();
        bool isOpen();
        bool pollEvent(sf::Event event);
    private:
        sf::RenderWindow window;
        std::vector<std::uint8_t> pixVec;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif