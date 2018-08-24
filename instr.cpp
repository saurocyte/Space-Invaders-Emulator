#include <cstdint>
#include "cpu.hpp"
#include "memory.hpp"

extern Cpu cpu;

bool toSetP(std::uint16_t x){
    unsigned int count = 0, i, b = 1;
    for(i = 0; i < 16; i++)
        if (x & (b << i)) count++;
    if (count % 2) return false;
    return true;
}

bool isNegative(std::uint16_t x) {
	if ((x >> 7) & 1) return true;
	else return false;
}

void nop() {

}

void lxi_b_d16(std::uint8_t o1, std::uint8_t o2) {
    cpu.regBC.setHi(o2);
    cpu.regBC.setLo(o1);    
}

void stax_b() {
	cpu.memPtr->setByte(cpu.regBC.getFull(), cpu.regAF.getHi());
}

void inx_b() {
	cpu.regBC.setFull(cpu.regBC.getFull() + 1);
}

void inr_b() {
	cpu.regBC.setHi(cpu.regBC.getHi() + 1);
    if (isNegative(cpu.regBC.getHi() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regBC.getHi() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regBC.getHi() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_b() {
	cpu.regBC.setHi(cpu.regBC.getHi() - 1);
	if (isNegative(cpu.regBC.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regBC.getHi()== 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regBC.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_b_d8(std::uint8_t o1) {
	cpu.regBC.setHi(o1);
}

void rlc() {
	std::uint8_t bit7 = (cpu.regAF.getHi() >> 7) & 1;
	cpu.flags.C = bit7;
	cpu.regAF.setHi(cpu.regAF.getHi() << 1);
	if (bit7) cpu.regAF.setHi(cpu.regAF.getHi() | 1 << 0);
	else cpu.regAF.setHi(cpu.regAF.getHi() & ~(1 << 0));
}

void dad_b() {
	cpu.regHL.setFull(cpu.regHL.getFull() + cpu.regBC.getFull());
	if (cpu.regHL.getFull() + cpu.regBC.getFull() > 65535) cpu.flags.C = true;
	else cpu.flags.C = false;
}

void ldax_b() {
	cpu.regAF.setHi(cpu.memPtr->getByte(cpu.regBC.getFull()));
}

void dcx_b() {
	cpu.regBC.setFull(cpu.regBC.getFull() - 1);
}

void inr_c() {
	cpu.regBC.setLo(cpu.regBC.getLo() + 1);
    if (isNegative(cpu.regBC.getLo() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regBC.getLo() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regBC.getLo() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_c() {
	cpu.regBC.setLo(cpu.regBC.getLo() - 1);
    if (isNegative(cpu.regBC.getLo())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regBC.getLo() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regBC.getLo())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_c_d8(std::uint8_t o1) {
	cpu.regBC.setLo(o1);
}

void rrc() {
	std::uint8_t bit0 = (cpu.regAF.getHi() >> 0) & 1;
	cpu.flags.C = bit0;
	cpu.regAF.setHi(cpu.regAF.getHi() >> 1);
	if (bit0) cpu.regAF.setHi(cpu.regAF.getHi() | 1 << 7);
	else cpu.regAF.setHi(cpu.regAF.getHi() & ~(1 << 7));
}

void lxi_d_d16(std::uint8_t o1, std::uint8_t o2) {
    cpu.regDE.setHi(o2);
    cpu.regDE.setLo(o1);    
}

void stax_d() {
	cpu.memPtr->setByte(cpu.regDE.getFull(), cpu.regAF.getHi());
}

void inx_d() {
	cpu.regDE.setFull(cpu.regDE.getFull() + 1);
}

void inr_d() {
	cpu.regDE.setHi(cpu.regDE.getHi() + 1);
    if (isNegative(cpu.regDE.getHi() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regDE.getHi() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regDE.getHi() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_d() {
	cpu.regDE.setHi(cpu.regDE.getHi() - 1);
    if (isNegative(cpu.regDE.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regDE.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regDE.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_d_d8(std::uint8_t o1) {
	cpu.regDE.setHi(o1);
}

void ral() {
	std::uint8_t bit7 = (cpu.regAF.getHi() >> 7) & 1;
	cpu.regAF.setHi(cpu.regAF.getHi() << 1);
	if (cpu.flags.C) cpu.regAF.setHi(cpu.regAF.getHi() | 1 << 0);
	else cpu.regAF.setHi(cpu.regAF.getHi() & ~(1 << 0));
	cpu.flags.C = bit7;
}

void dad_d() {
	cpu.regHL.setFull(cpu.regHL.getFull() + cpu.regDE.getFull());
	if (cpu.regHL.getFull() + cpu.regDE.getFull() > 65535) cpu.flags.C = true;
	else cpu.flags.C = false;
}

void ldax_d() {
	cpu.regAF.setHi(cpu.memPtr->getByte(cpu.regDE.getFull()));
}

void dcx_d() {
	cpu.regDE.setFull(cpu.regDE.getFull() - 1);
}

void inr_e() {
	cpu.regDE.setLo(cpu.regDE.getLo() + 1);
    if (isNegative(cpu.regDE.getLo() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regDE.getLo() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regDE.getLo() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_e() {
	cpu.regDE.setLo(cpu.regDE.getLo() - 1);
    if (isNegative(cpu.regDE.getLo())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regDE.getLo() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regDE.getLo())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_e_d8(std::uint8_t o1) {
	cpu.regDE.setLo(o1);
}

void rar() {
	std::uint8_t bit0 = (cpu.regAF.getHi() >> 0) & 1;
	std::uint8_t bit7 = (cpu.regAF.getHi() >> 7) & 1;
	cpu.regAF.setHi(cpu.regAF.getHi() >> 1);
	if (bit7) cpu.regAF.setHi(cpu.regAF.getHi() | 7 << 0);
	else cpu.regAF.setHi(cpu.regAF.getHi() & ~(7 << 0));
	cpu.flags.C = bit0;
}

void lxi_h_d16(std::uint8_t o1, std::uint8_t o2) {
    cpu.regHL.setHi(o2);
    cpu.regHL.setLo(o1);    
}

void shld_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	cpu.memPtr->setByte(addr, cpu.regHL.getLo());
	cpu.memPtr->setByte(addr + 1, cpu.regHL.getHi());
}

void inx_h() {
	cpu.regHL.setFull(cpu.regHL.getFull() + 1);
}

void inr_h() {
	cpu.regHL.setHi(cpu.regHL.getHi() + 1);
    if (isNegative(cpu.regHL.getHi() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regHL.getHi() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regHL.getHi() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_h() {
	cpu.regHL.setHi(cpu.regHL.getHi() - 1);
    if (isNegative(cpu.regHL.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regHL.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regHL.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_h_d8(std::uint8_t o1) {
	cpu.regHL.setHi(o1);
}
//todo
void daa() {
	
}

void dad_h() {
	cpu.regHL.setFull(cpu.regHL.getFull() + cpu.regHL.getFull());
	if (cpu.regHL.getFull() + cpu.regHL.getFull() > 65535) cpu.flags.C = true;
	else cpu.flags.C = false;
}

void lhld_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	cpu.regHL.setLo(cpu.memPtr->getByte(addr));
	cpu.regHL.setHi(cpu.memPtr->getByte(addr + 1));
}

void dcx_h() {
	cpu.regHL.setFull(cpu.regHL.getFull() - 1);
}

void inr_l() {
	cpu.regHL.setLo(cpu.regHL.getLo() + 1);
    if (isNegative(cpu.regHL.getLo() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regHL.getLo() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regHL.getLo() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
	
}

void dcr_l() {
	cpu.regHL.setLo(cpu.regHL.getLo() - 1);
    if (isNegative(cpu.regHL.getLo())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regHL.getLo() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regHL.getLo())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_l_d8(std::uint8_t o1) {
	cpu.regHL.setLo(o1);
}

void cma() {
	cpu.regAF.setHi(~(cpu.regAF.getHi()));
}

void lxi_sp_d16(std::uint8_t o1, std::uint8_t o2) {
    cpu.regSP.setHi(o2);
    cpu.regSP.setLo(o1);    
}

void sta_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	cpu.memPtr->setByte(addr, cpu.regAF.getHi());
}

void inx_sp() {
	cpu.regSP.setFull(cpu.regSP.getFull() + 1);
}
//to fix
void inr_m() {
	cpu.memPtr->setByte(cpu.memPtr->getByte(cpu.regHL.getFull()) + 1, cpu.regHL.getFull());
    if (isNegative(cpu.memPtr->getByte(cpu.regHL.getFull()) + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.memPtr->getByte(cpu.regHL.getFull()) + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.memPtr->getByte(cpu.regHL.getFull()) + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_m() {
	cpu.memPtr->setByte(cpu.memPtr->getByte(cpu.regHL.getFull()) - 1, cpu.regHL.getFull());
    if (isNegative(cpu.memPtr->getByte(cpu.regHL.getFull()))) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.memPtr->getByte(cpu.regHL.getFull()) == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.memPtr->getByte(cpu.regHL.getFull()))) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_m_d8(std::uint8_t o1) {
	cpu.memPtr->setByte(cpu.regHL.getFull(), o1);
}

void stc() {
	cpu.flags.C = true;
}

void dad_sp() {
	cpu.regHL.setFull(cpu.regHL.getFull() + cpu.regSP.getFull());
	if (cpu.regHL.getFull() + cpu.regSP.getFull() > 65535) cpu.flags.C = true;
	else cpu.flags.C = false;
}

void lda_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	cpu.regAF.setHi(cpu.memPtr->getByte(addr));
}

void dcx_sp() {
	cpu.regSP.setFull(cpu.regSP.getFull() - 1);
}

void inr_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() + 1);
    if (isNegative(cpu.regAF.getHi() + 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regAF.getHi() + 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void dcr_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() - 1);
    if (isNegative(cpu.regAF.getHi() - 1)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() - 1 == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (toSetP(cpu.regAF.getHi() - 1)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void mvi_a_d8(std::uint8_t o1) {
	cpu.regAF.setHi(o1);
}

void cmc() {
	cpu.flags.C = !cpu.flags.C;
}

void mov_b_b() {
	cpu.regBC.setHi(cpu.regBC.getHi());
}

void mov_b_c() {
	cpu.regBC.setHi(cpu.regBC.getLo());
}

void mov_b_d() {
	cpu.regBC.setHi(cpu.regDE.getHi());
}

void mov_b_e() {
	cpu.regBC.setHi(cpu.regDE.getLo());
}

void mov_b_h() {
	cpu.regBC.setHi(cpu.regHL.getHi());
}

void mov_b_l() {
	cpu.regBC.setHi(cpu.regHL.getLo());
}

void mov_b_m() {
	cpu.regBC.setHi(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_b_a() {
	cpu.regBC.setHi(cpu.regAF.getHi());
}

void mov_c_b() {
	cpu.regBC.setLo(cpu.regBC.getHi());
}

void mov_c_c() {
	cpu.regBC.setLo(cpu.regBC.getLo());
}

void mov_c_d() {
	cpu.regBC.setLo(cpu.regDE.getHi());
}

void mov_c_e() {
	cpu.regBC.setLo(cpu.regDE.getLo());
}

void mov_c_h() {
	cpu.regBC.setLo(cpu.regHL.getHi());
}

void mov_c_l() {
	cpu.regBC.setLo(cpu.regHL.getLo());
}

void mov_c_m() {
	cpu.regBC.setLo(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_c_a() {
	cpu.regBC.setLo(cpu.regAF.getHi());
}

void mov_d_b() {
	cpu.regDE.setHi(cpu.regBC.getHi());
}

void mov_d_c() {
	cpu.regDE.setHi(cpu.regBC.getLo());
}

void mov_d_d() {
	cpu.regDE.setHi(cpu.regDE.getHi());
}

void mov_d_e() {
	cpu.regDE.setHi(cpu.regDE.getLo());
}

void mov_d_h() {
	cpu.regDE.setHi(cpu.regHL.getHi());
}

void mov_d_l() {
	cpu.regDE.setHi(cpu.regHL.getLo());
}

void mov_d_m() {
	cpu.regDE.setHi(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_d_a() {
	cpu.regDE.setHi(cpu.regAF.getHi());
}

void mov_e_b() {
	cpu.regDE.setLo(cpu.regBC.getHi());
}

void mov_e_c() {
	cpu.regDE.setLo(cpu.regBC.getLo());
}

void mov_e_d() {
	cpu.regDE.setLo(cpu.regDE.getHi());
}

void mov_e_e() {
	cpu.regDE.setLo(cpu.regDE.getLo());
}

void mov_e_h() {
	cpu.regDE.setLo(cpu.regHL.getHi());
}

void mov_e_l() {
	cpu.regDE.setLo(cpu.regHL.getLo());
}

void mov_e_m() {
	cpu.regDE.setLo(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_e_a() {
	cpu.regDE.setLo(cpu.regAF.getHi());
}

void mov_h_b() {
	cpu.regHL.setHi(cpu.regBC.getHi());	
}

void mov_h_c() {
	cpu.regHL.setHi(cpu.regBC.getLo());
}

void mov_h_d() {
	cpu.regHL.setHi(cpu.regDE.getHi());
}

void mov_h_e() {
	cpu.regHL.setHi(cpu.regDE.getLo());
}

void mov_h_h() {
	cpu.regHL.setHi(cpu.regHL.getHi());
}

void mov_h_l() {
	cpu.regHL.setHi(cpu.regHL.getLo());
}

void mov_h_m() {
	cpu.regHL.setHi(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_h_a() {
	cpu.regHL.setHi(cpu.regAF.getHi());
}

void mov_l_b() {
	cpu.regHL.setLo(cpu.regBC.getHi());
}

void mov_l_c() {
	cpu.regHL.setLo(cpu.regBC.getLo());
}

void mov_l_d() {
	cpu.regHL.setLo(cpu.regDE.getHi());
}

void mov_l_e() {
	cpu.regHL.setLo(cpu.regDE.getLo());
}

void mov_l_h() {
	cpu.regHL.setLo(cpu.regHL.getHi());
}

void mov_l_l() {
	cpu.regHL.setLo(cpu.regHL.getLo());
}

void mov_l_m() {
	cpu.regHL.setLo(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_l_a() {
	cpu.regHL.setLo(cpu.regAF.getHi());
}

void mov_m_b() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regBC.getHi());
}

void mov_m_c() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regBC.getLo());
}

void mov_m_d() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regDE.getHi());
}

void mov_m_e() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regDE.getLo());
}

void mov_m_h() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regHL.getHi());
}

void mov_m_l() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regHL.getLo());
}
//todo
void hlt() {
	
}

void mov_m_a() {
	cpu.memPtr->setByte(cpu.regHL.getFull(), cpu.regAF.getHi());
}

void mov_a_b() {
	cpu.regAF.setHi(cpu.regBC.getHi());
}

void mov_a_c() {
	cpu.regAF.setHi(cpu.regBC.getLo());
}

void mov_a_d() {
	cpu.regAF.setHi(cpu.regDE.getHi());
}

void mov_a_e() {
	cpu.regAF.setHi(cpu.regDE.getLo());
}

void mov_a_h() {
	cpu.regAF.setHi(cpu.regHL.getHi());
}

void mov_a_l() {
	cpu.regAF.setHi(cpu.regHL.getLo());
}

void mov_a_m() {
	cpu.regAF.setHi(cpu.memPtr->getByte(cpu.regHL.getFull()));
}

void mov_a_a() {
	cpu.regAF.setHi(cpu.regAF.getHi());
}

void add_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regBC.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regBC.getHi() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regBC.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regBC.getLo() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regDE.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regDE.getHi() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regDE.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regDE.getLo() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regHL.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regHL.getHi() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regHL.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regHL.getLo() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.memPtr->getByte(cpu.regHL.getFull()));
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.memPtr->getByte(cpu.regHL.getFull()) > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void add_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regAF.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regAF.getHi() > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regBC.getHi() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regBC.getHi() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regBC.getLo() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regBC.getLo() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regDE.getHi() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regDE.getHi() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regDE.getLo() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regDE.getLo() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regHL.getHi() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regHL.getHi() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regHL.getLo() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regHL.getLo() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.memPtr->getByte(cpu.regHL.getFull()) + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.memPtr->getByte(cpu.regHL.getFull()) + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void adc_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() + cpu.regAF.getHi() + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + cpu.regAF.getHi() + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regBC.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regBC.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regDE.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regDE.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regHL.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regHL.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.memPtr->getByte(cpu.regHL.getFull()));
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.memPtr->getByte(cpu.regHL.getFull())) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sub_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regAF.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regAF.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regBC.getHi() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() - cpu.regBC.getHi() - cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regBC.getLo() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regBC.getLo() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regDE.getHi() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regDE.getHi() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regDE.getLo() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regDE.getLo() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regHL.getHi() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regHL.getHi() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regHL.getLo() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regHL.getLo() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.memPtr->getByte(cpu.regHL.getFull()) - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.memPtr->getByte(cpu.regHL.getFull()) + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void sbb_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() - cpu.regAF.getHi() - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < (cpu.regAF.getHi() + cpu.flags.C)) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regBC.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regBC.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regDE.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regDE.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regHL.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regHL.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.memPtr->getByte(cpu.regHL.getFull()));
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.memPtr->getByte(cpu.regHL.getFull())) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ana_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() & cpu.regAF.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regAF.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regBC.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regBC.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regDE.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regDE.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regHL.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regHL.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.memPtr->getByte(cpu.regHL.getFull()));
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.memPtr->getByte(cpu.regHL.getFull())) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void xra_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ cpu.regAF.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regAF.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_b() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regBC.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_c() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regBC.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_d() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regDE.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_e() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regDE.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_h() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regHL.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_l() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regHL.getLo());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_m() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.memPtr->getByte(cpu.regHL.getFull()));
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.memPtr->getByte(cpu.regHL.getFull())) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void ora_a() {
	cpu.regAF.setHi(cpu.regAF.getHi() | cpu.regAF.getHi());
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regAF.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_b() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regBC.getHi();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_c() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regBC.getLo();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regBC.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_d() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regDE.getHi();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_e() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regDE.getLo();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regDE.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_h() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regHL.getHi();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_l() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regHL.getLo();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regHL.getLo()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_m() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.memPtr->getByte(cpu.regHL.getFull());
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.memPtr->getByte(cpu.regHL.getFull())) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void cmp_a() {
	std::uint8_t temp = cpu.regAF.getHi() - cpu.regAF.getHi();
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < cpu.regAF.getHi()) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void rnz() {
	if (!cpu.flags.Z) ret();
}

void pop_b() {
	cpu.regBC.setLo(cpu.memPtr->getByte(cpu.regSP.getFull()));
	cpu.regBC.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.regSP.setFull(cpu.regSP.getFull() + 2);
}

void jnz_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (!cpu.flags.Z) cpu.regPC.setFull(addr - 3);
}

void jmp_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	cpu.regPC.setFull(addr - 3);
}

void cnz_adr(std::uint8_t o1, std::uint8_t o2) {
	if (!cpu.flags.Z) call_adr(o1, o2);
}

void push_b() {
	cpu.memPtr->setByte(cpu.regSP.getFull() - 2, cpu.regBC.getLo());
	cpu.memPtr->setByte(cpu.regSP.getFull() - 1, cpu.regBC.getHi());
	cpu.regSP.setFull(cpu.regSP.getFull() - 2);
}

void adi_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() + o1);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + o1 > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}
//to fix
void rst_0() {
	call_adr(0, 0);
}

void rz() {
	if (cpu.flags.Z) ret();
}

void ret() {
	cpu.regPC.setLo(cpu.memPtr->getByte(cpu.regSP.getFull()));
	cpu.regPC.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.regSP.setFull(cpu.regSP.getFull() + 1);
}

void jz_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (cpu.flags.Z) cpu.regPC.setFull(addr - 3);
}

void cz_adr(std::uint8_t o1, std::uint8_t o2) {
	if (cpu.flags.Z) call_adr(o1, o2);
}

void call_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	//After executing subroutine, we will return to instruction AFTER call, so we'll push pc+2 (idk why +2) to stack
	cpu.regPC.setFull(cpu.regPC.getFull() + 2);
	cpu.memPtr->setByte(cpu.regSP.getFull() - 1, cpu.regPC.getHi());
	cpu.memPtr->setByte(cpu.regSP.getFull() - 2, cpu.regPC.getLo());
	cpu.regSP.setFull(cpu.regSP.getFull() - 2);
	cpu.regPC.setFull(addr - 3);
}

void aci_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() + o1 + cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() + o1 + cpu.flags.C > 255) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void rst_1() {
	call_adr(8, 0);
}

void rnc() {
	if (!cpu.flags.C) ret();
}

void pop_d() {
	cpu.regDE.setLo(cpu.memPtr->getByte(cpu.regSP.getFull()));
	cpu.regDE.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.regSP.setFull(cpu.regSP.getFull() + 2);
}

void jnc_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (cpu.flags.C) cpu.regPC.setFull(addr - 3);
}

void out_d8(std::uint8_t o1) {
	cpu.outputPorts[o1] = cpu.regAF.getHi();	
}

void cnc_adr(std::uint8_t o1, std::uint8_t o2) {
	if (!cpu.flags.C) call_adr(o1, o2);
}

void push_d() {
	cpu.memPtr->setByte(cpu.regSP.getFull() - 2, cpu.regDE.getLo());
	cpu.memPtr->setByte(cpu.regSP.getFull() - 1, cpu.regDE.getHi());
	cpu.regSP.setFull(cpu.regSP.getFull() - 2);
}

void sui_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() - o1);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void rst_2() {
	call_adr(0b0000, 0b0001);
}

void rc() {
	if (cpu.flags.C) ret();
}

void jc_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (cpu.flags.C) cpu.regPC.setFull(addr - 3);
}

void in_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.inputPorts[o1]);	
}

void cc_adr(std::uint8_t o1, std::uint8_t o2) {
	if (cpu.flags.C) call_adr(o1, o2);
}

void sbi_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() - o1 - cpu.flags.C);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1 + cpu.flags.C) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
	
}

void rst_3() {
	call_adr(0b1000, 0b0001);
}

void rpo() {
	if (!cpu.flags.P) ret();
}

void pop_h() {
	cpu.regHL.setLo(cpu.memPtr->getByte(cpu.regSP.getFull()));
	cpu.regHL.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.regSP.setFull(cpu.regSP.getFull() + 2);
}

void jpo_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (!cpu.flags.P) cpu.regPC.setFull(addr - 3);
}

void xthl() {
	std::uint8_t prevL = cpu.regHL.getLo();
	std::uint8_t prevH = cpu.regHL.getHi();
	cpu.regHL.setLo(cpu.memPtr->getByte(cpu.regSP.getFull()));
	cpu.regHL.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.memPtr->setByte(cpu.regSP.getFull(), prevL);
	cpu.memPtr->setByte(cpu.regSP.getFull() + 1, prevH);
}

void cpo_adr(std::uint8_t o1, std::uint8_t o2) {
	if (!cpu.flags.P) call_adr(o1, o2);
}

void push_h() {
	cpu.memPtr->setByte(cpu.regSP.getFull() - 2, cpu.regHL.getLo());
	cpu.memPtr->setByte(cpu.regSP.getFull() - 1, cpu.regHL.getHi());
	cpu.regSP.setFull(cpu.regSP.getFull() - 2);
}

void ani_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() & o1);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void rst_4() {
	call_adr(0b0000, 0b0010);
}

void rpe() {
	if (cpu.flags.P) ret();
}

void pchl() {
	cpu.regPC.setHi(cpu.regHL.getHi());
	cpu.regPC.setLo(cpu.regHL.getLo());
}

void jpe_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (cpu.flags.P) cpu.regPC.setFull(addr - 3);
}

void xchg() {
	std::uint8_t prevL = cpu.regHL.getLo();
	std::uint8_t prevH = cpu.regHL.getHi();
	cpu.regHL.setLo(cpu.regDE.getLo());
	cpu.regHL.setHi(cpu.regDE.getHi());
	cpu.regDE.setLo(prevL);
	cpu.regDE.setHi(prevH);
}

void cpe_adr(std::uint8_t o1, std::uint8_t o2) {
	if (cpu.flags.P) call_adr(o1, o2);
}

void xri_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() ^ o1);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;	
}

void rst_5() {
	call_adr(0b1000, 0b0010);
}

void rp() {
	if (!cpu.flags.S) ret();
}
//to fix
void pop_psw() {
	cpu.flags.S = (cpu.memPtr->getByte(cpu.regSP.getFull()) >> 7) & 1;
	cpu.flags.Z = (cpu.memPtr->getByte(cpu.regSP.getFull()) >> 6) & 1;
	cpu.flags.AC = (cpu.memPtr->getByte(cpu.regSP.getFull()) >> 4) & 1;
	cpu.flags.P = (cpu.memPtr->getByte(cpu.regSP.getFull()) >> 2) & 1;
	cpu.flags.C = (cpu.memPtr->getByte(cpu.regSP.getFull()) >> 0) & 1;
	cpu.regAF.setHi(cpu.memPtr->getByte(cpu.regSP.getFull() + 1));
	cpu.regSP.setFull(cpu.regSP.getFull() + 2);
}

void jp_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (!cpu.flags.S) cpu.regPC.setFull(addr - 3);
}

void di() {
	cpu.inte = false;	
}

void cp_adr(std::uint8_t o1, std::uint8_t o2) {
	if (!cpu.flags.S) call_adr(o1, o2);
}

void push_psw() {
	std::uint8_t flags = (cpu.flags.S << 7) | (cpu.flags.Z << 6) | (0 << 5) | (cpu.flags.AC << 4) | (0 << 3) | (cpu.flags.P << 2) | (1 << 1) | (cpu.flags.C);
	cpu.memPtr->setByte(cpu.regSP.getFull(), flags);
	cpu.memPtr->setByte(cpu.regSP.getFull() - 1, cpu.regAF.getHi());
	cpu.regSP.setFull(cpu.regSP.getFull() - 2);
}

void ori_d8(std::uint8_t o1) {
	cpu.regAF.setHi(cpu.regAF.getHi() | o1);
	if (cpu.regAF.getHi() == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(cpu.regAF.getHi())) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(cpu.regAF.getHi())) cpu.flags.P = true;
	else cpu.flags.P = false;	
}

void rst_6() {
	call_adr(0b0000, 0b0011);	
}

void rm() {
	if (cpu.flags.S) ret();
}

void sphl() {
	cpu.regSP.setFull(cpu.regHL.getFull());
}

void jm_adr(std::uint8_t o1, std::uint8_t o2) {
	std::uint16_t addr = (std::uint16_t)o2 << 8 | o1;
	if (cpu.flags.S) cpu.regPC.setFull(addr - 3);
}

void ei() {
	cpu.inte = true;
}

void cm_adr(std::uint8_t o1, std::uint8_t o2) {
	if (cpu.flags.S) call_adr(o1, o2);
}

void cpi_d8(std::uint8_t o1) {
	std::uint8_t temp = cpu.regAF.getHi() - o1;
	if (temp == 0) cpu.flags.Z = true;
	else cpu.flags.Z = false;
	if (isNegative(temp)) cpu.flags.S = true;
	else cpu.flags.S = false;
	if (cpu.regAF.getHi() < o1) cpu.flags.C = true;
	else cpu.flags.C = false;
	if (toSetP(temp)) cpu.flags.P = true;
	else cpu.flags.P = false;
}

void rst_7() {
	call_adr(0b1000, 0b0011);
}