#include "memory.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <string>

void Memory::loadGame() {
    //Game parts + merged thing for reading
    std::ifstream p1, p2, p3, p4, mergedI;
    //Merged thing for writing
    std::ofstream mergedO("./rom/merged.txt", std::ios::binary);
    
    //Open files
    p1.open("./rom/invaders.h", std::ios::binary);
    p2.open("./rom/invaders.g", std::ios::binary);
    p3.open("./rom/invaders.f", std::ios::binary);
    p4.open("./rom/invaders.e", std::ios::binary);

    //Merge them
    mergedO << p1.rdbuf() << p2.rdbuf() << p3.rdbuf() << p4.rdbuf();
    //Close
    p1.close(), p2.close(), p3.close(), p4.close();

    //Open thing
    mergedI.open("./rom/merged.txt", std::ios::binary);
    //Write bytes to vector
    std::vector<char> mergedContents((std::istreambuf_iterator<char>(mergedI)), (std::istreambuf_iterator<char>()));
    //Store everything in memory
    for (int i = 0; i < mergedContents.size(); ++i) {
        mem[i] = mergedContents[i];
    }
}

std::uint8_t Memory::getByte(unsigned int addr) {
    return mem[addr];
} 

std::uint8_t Memory::setByte(unsigned int addr, std::uint8_t val) {
    if (addr > 32765) std::cout << "Invalid memory address!";
    else if (addr < 8191) std::cout << "Writing into rom!";
    else { 
        mem[addr] = val;
        return mem[addr];
    }
    return 0;
}

std::string Memory::getByteStr(unsigned int addr) {
    return std::bitset<8>(mem[addr]).to_string();
}