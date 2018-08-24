#include "cpu.hpp"
#include "clock.hpp"
#include "memory.hpp"
#include "instr.hpp"
#include <cstdint>
#include <iostream>

Cpu::Cpu(Memory *_memPtr, Display *_displayPtr) : memPtr(_memPtr), displayPtr(_displayPtr) {}

void Cpu::emulateCycle() {
    std::cout << "CPU | Starting cycle... \n";
    if (inte && checkInte()) {
        std::cout << "CPU | Interrupt detected!\n";
        inte = false;
        execInte();
    }
    fetch();
    exec();
}

bool Cpu::checkInte() {
    if (inteInstr == 0) return false;
    else return true;
}

void Cpu::execInte() {
    std::cout << "CPU | Executing interrupt!\n";
    if (inteInstr = 0xcf) rst_1();
    if (inteInstr = 0x10) rst_2();
    inteInstr = 0;
}

void Cpu::fetch() {
    currOp = memPtr->getByte(regPC.getFull());
}

void Cpu::exec() {
    std::cout << "CPU | REGISTERS | H value: " << (int)regHL.getFull() << "\n";
    //std::cout << "MEMORY | VRAM | VRAM state: ";
    //for (auto i = 0x2400; i < 0x3fff; ++i) std::cout << std::hex << unsigned(memPtr->getByte(i)) << " ";
    std::cout << "\n";
    switch (instructions[currOp].length) {
        case 1 : {
            std::cout << "CPU | Executing instr: " << std::hex << (int)currOp << "\n";
            ((void (*)())instructions[currOp].functionPtr)();
            regPC.setFull(regPC.getFull() + 1);
            break;
        }
        case 2 : {
            std::cout << "CPU | Executing instr: " << std::hex << (int)currOp << (int)(memPtr->getByte(regPC.getFull() + 1)) << "\n";
            ((void (*)(std::uint8_t))instructions[currOp].functionPtr)(memPtr->getByte(regPC.getFull() + 1));
            regPC.setFull(regPC.getFull() + 2);
            break;
        }
        case 3 : {
            std::cout << "CPU | Executing instr: " << std::hex << (int)currOp << (int)(memPtr->getByte(regPC.getFull() + 1)) << (int)(memPtr->getByte(regPC.getFull() + 2)) << "\n";
            ((void (*)(std::uint8_t, std::uint8_t))instructions[currOp].functionPtr)(memPtr->getByte(regPC.getFull() + 1), memPtr->getByte(regPC.getFull() + 2));
            regPC.setFull(regPC.getFull() + 3);
            break;
        }
    };
    std::cout << "CLOCK | Waiting...\n";
    clock.wait(instructions[currOp].duration);
}