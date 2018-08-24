#include "register.hpp" 

void Register::setFull(std::uint16_t val) {
    full = val; 
    hi = full >> 8; 
    lo = full << 8 >> 8;
}

void Register::setHi(std::uint8_t val) {
    hi = val; 
    full = (std::uint16_t)(hi << 8) | lo;
}

void Register::setLo(std::uint8_t val) {
    lo = val; 
    full = ((std::uint16_t)lo) | ((std::uint16_t)hi << 8); 
}