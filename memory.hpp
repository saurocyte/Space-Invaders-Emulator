#ifndef MEMORY
#define MEMORY

#include <cstdint>
#include <string>

void getByte();
void setByte();

class Memory {
    public:
        Memory() = default;
        std::uint8_t getByte(unsigned int addr);
        std::string getByteStr(unsigned int addr);
        std::uint8_t setByte(unsigned int addr, std::uint8_t val);
        
        void loadGame();
    private:
        std::uint8_t mem[32766];
};

#endif