#ifndef REGISTER
#define REGISTER

#include <cstdint>

class Register {
    public:
        void setFull(std::uint16_t val);
        void setHi(std::uint8_t val);
        void setLo(std::uint8_t val);
        std::uint16_t getFull() {return full;}
        std::uint8_t getHi() {return hi;}
        std::uint8_t getLo() {return lo;}
    private:
        std::uint16_t full;
        std::uint8_t hi;
        std::uint8_t lo;
};

#endif