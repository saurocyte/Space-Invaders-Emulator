#ifndef CPU
#define CPU

#include "register.hpp"
#include <cstdint>
#include "instr.hpp"
#include "clock.hpp"
#include <cmath>
#include "memory.hpp"
#include "display.hpp"

class Cpu {
    public:
		friend void nop();
		friend void lxi_b_d16(std::uint8_t o1, std::uint8_t o2);
		friend void stax_b();
		friend void inx_b();
		friend void inr_b();
		friend void dcr_b();
		friend void mvi_b_d8(std::uint8_t o1);
		friend void rlc();
		friend void dad_b();
		friend void ldax_b();
		friend void dcx_b();
		friend void inr_c();
		friend void dcr_c();
		friend void mvi_c_d8(std::uint8_t o1);
		friend void rrc();
		friend void lxi_d_d16(std::uint8_t o1, std::uint8_t o2);
		friend void stax_d();
		friend void inx_d();
		friend void inr_d();
		friend void dcr_d();
		friend void mvi_d_d8(std::uint8_t o1);
		friend void ral();
		friend void dad_d();
		friend void ldax_d();
		friend void dcx_d();
		friend void inr_e();
		friend void dcr_e();
		friend void mvi_e_d8(std::uint8_t o1);
		friend void rar();
		friend void rim();
		friend void lxi_h_d16(std::uint8_t o1, std::uint8_t o2);
		friend void shld_adr(std::uint8_t o1, std::uint8_t o2);
		friend void inx_h();
		friend void inr_h();
		friend void dcr_h();
		friend void mvi_h_d8(std::uint8_t o1);
		friend void daa();
		friend void dad_h();
		friend void lhld_adr(std::uint8_t o1, std::uint8_t o2);
		friend void dcx_h();
		friend void inr_l();
		friend void dcr_l();
		friend void mvi_l_d8(std::uint8_t o1);
		friend void cma();
		friend void sim();
		friend void lxi_sp_d16(std::uint8_t o1, std::uint8_t o2);
		friend void sta_adr(std::uint8_t o1, std::uint8_t o2);
		friend void inx_sp();
		friend void inr_m();
		friend void dcr_m();
		friend void mvi_m_d8(std::uint8_t o1);
		friend void stc();
		friend void dad_sp();
		friend void lda_adr(std::uint8_t o1, std::uint8_t o2);
		friend void dcx_sp();
		friend void inr_a();
		friend void dcr_a();
		friend void mvi_a_d8(std::uint8_t o1);
		friend void cmc();
		friend void mov_b_b();
		friend void mov_b_c();
		friend void mov_b_d();
		friend void mov_b_e();
		friend void mov_b_h();
		friend void mov_b_l();
		friend void mov_b_m();
		friend void mov_b_a();
		friend void mov_c_b();
		friend void mov_c_c();
		friend void mov_c_d();
		friend void mov_c_e();
		friend void mov_c_h();
		friend void mov_c_l();
		friend void mov_c_m();
		friend void mov_c_a();
		friend void mov_d_b();
		friend void mov_d_c();
		friend void mov_d_d();
		friend void mov_d_e();
		friend void mov_d_h();
		friend void mov_d_l();
		friend void mov_d_m();
		friend void mov_d_a();
		friend void mov_e_b();
		friend void mov_e_c();
		friend void mov_e_d();
		friend void mov_e_e();
		friend void mov_e_h();
		friend void mov_e_l();
		friend void mov_e_m();
		friend void mov_e_a();
		friend void mov_h_b();
		friend void mov_h_c();
		friend void mov_h_d();
		friend void mov_h_e();
		friend void mov_h_h();
		friend void mov_h_l();
		friend void mov_h_m();
		friend void mov_h_a();
		friend void mov_l_b();
		friend void mov_l_c();
		friend void mov_l_d();
		friend void mov_l_e();
		friend void mov_l_h();
		friend void mov_l_l();
		friend void mov_l_m();
		friend void mov_l_a();
		friend void mov_m_b();
		friend void mov_m_c();
		friend void mov_m_d();
		friend void mov_m_e();
		friend void mov_m_h();
		friend void mov_m_l();
		friend void hlt();
		friend void mov_m_a();
		friend void mov_a_b();
		friend void mov_a_c();
		friend void mov_a_d();
		friend void mov_a_e();
		friend void mov_a_h();
		friend void mov_a_l();
		friend void mov_a_m();
		friend void mov_a_a();
		friend void add_b();
		friend void add_c();
		friend void add_d();
		friend void add_e();
		friend void add_h();
		friend void add_l();
		friend void add_m();
		friend void add_a();
		friend void adc_b();
		friend void adc_c();
		friend void adc_d();
		friend void adc_e();
		friend void adc_h();
		friend void adc_l();
		friend void adc_m();
		friend void adc_a();
		friend void sub_b();
		friend void sub_c();
		friend void sub_d();
		friend void sub_e();
		friend void sub_h();
		friend void sub_l();
		friend void sub_m();
		friend void sub_a();
		friend void sbb_b();
		friend void sbb_c();
		friend void sbb_d();
		friend void sbb_e();
		friend void sbb_h();
		friend void sbb_l();
		friend void sbb_m();
		friend void sbb_a();
		friend void ana_b();
		friend void ana_c();
		friend void ana_d();
		friend void ana_e();
		friend void ana_h();
		friend void ana_l();
		friend void ana_m();
		friend void ana_a();
		friend void xra_b();
		friend void xra_c();
		friend void xra_d();
		friend void xra_e();
		friend void xra_h();
		friend void xra_l();
		friend void xra_m();
		friend void xra_a();
		friend void ora_b();
		friend void ora_c();
		friend void ora_d();
		friend void ora_e();
		friend void ora_h();
		friend void ora_l();
		friend void ora_m();
		friend void ora_a();
		friend void cmp_b();
		friend void cmp_c();
		friend void cmp_d();
		friend void cmp_e();
		friend void cmp_h();
		friend void cmp_l();
		friend void cmp_m();
		friend void cmp_a();
		friend void rnz();
		friend void pop_b();
		friend void jnz_adr(std::uint8_t o1, std::uint8_t o2);
		friend void jmp_adr(std::uint8_t o1, std::uint8_t o2);
		friend void cnz_adr(std::uint8_t o1, std::uint8_t o2);
		friend void push_b();
		friend void adi_d8(std::uint8_t o1);
		friend void rst_0();
		friend void rz();
		friend void ret();
		friend void jz_adr(std::uint8_t o1, std::uint8_t o2);
		friend void cz_adr(std::uint8_t o1, std::uint8_t o2);
		friend void call_adr(std::uint8_t o1, std::uint8_t o2);
		friend void aci_d8(std::uint8_t o1);
		friend void rst_1();
		friend void rnc();
		friend void pop_d();
		friend void jnc_adr(std::uint8_t o1, std::uint8_t o2);
		friend void out_d8(std::uint8_t o1);
		friend void cnc_adr(std::uint8_t o1, std::uint8_t o2);
		friend void push_d();
		friend void sui_d8(std::uint8_t o1);
		friend void rst_2();
		friend void rc();
		friend void jc_adr(std::uint8_t o1, std::uint8_t o2);
		friend void in_d8(std::uint8_t o1);
		friend void cc_adr(std::uint8_t o1, std::uint8_t o2);
		friend void sbi_d8(std::uint8_t o1);
		friend void rst_3();
		friend void rpo();
		friend void pop_h();
		friend void jpo_adr(std::uint8_t o1, std::uint8_t o2);
		friend void xthl();
		friend void cpo_adr(std::uint8_t o1, std::uint8_t o2);
		friend void push_h();
		friend void ani_d8(std::uint8_t o1);
		friend void rst_4();
		friend void rpe();
		friend void pchl();
		friend void jpe_adr(std::uint8_t o1, std::uint8_t o2);
		friend void xchg();
		friend void cpe_adr(std::uint8_t o1, std::uint8_t o2);
		friend void xri_d8(std::uint8_t o1);
		friend void rst_5();
		friend void rp();
		friend void pop_psw();
		friend void jp_adr(std::uint8_t o1, std::uint8_t o2);
		friend void di();
		friend void cp_adr(std::uint8_t o1, std::uint8_t o2);
		friend void push_psw();
		friend void ori_d8(std::uint8_t o1);
		friend void rst_6();
		friend void rm();
		friend void sphl();
		friend void jm_adr(std::uint8_t o1, std::uint8_t o2);
		friend void ei();
		friend void cm_adr(std::uint8_t o1, std::uint8_t o2);
		friend void cpi_d8(std::uint8_t o1);
		friend void rst_7();

		friend Display;

        Cpu(Memory *_memPtr, Display *_displayPtr);
        void emulateCycle();

		std::uint8_t inputPorts[4];
		std::uint8_t outputPorts[7];
		//In actual CPU can be varied length, but in Space Invaders this works
		std::uint8_t inteInstr;

    private:
        void fetch();
        void exec(); 
		void execInte();
		bool checkInte();

        Memory *memPtr;
		Display *displayPtr;
        Clock clock{(int)(2 * std::pow(10, 6))};
		//Or true?
		bool inte = false;

        Register regAF;
        Register regBC;
        Register regDE;
        Register regHL;
		Register regPC;
		Register regSP;

		struct {
			bool S;
			bool Z;
			bool P;
			bool C;
			bool AC;
		} flags;

        std::uint8_t currOp;

		const instruction instructions[256] = {
/*0x0*/			{1, 4, (void (*)())&nop},
/*0x1*/			{3, 10, (void (*)())&lxi_b_d16},
/*0x2*/			{1, 7, (void (*)())&stax_b},
/*0x3*/			{1, 5, (void (*)())&inx_b},
/*0x4*/			{1, 5, (void (*)())&inr_b},
/*0x5*/			{1, 5, (void (*)())&dcr_b},
/*0x6*/			{2, 7, (void (*)())&mvi_b_d8},
/*0x7*/			{1, 4, (void (*)())&rlc},
/*0x8*/			{1, 4, (void (*)())&nop},
/*0x9*/			{1, 10, (void (*)())&dad_b},
/*0xa*/			{1, 7, (void (*)())&ldax_b},
/*0xb*/			{1, 5, (void (*)())&dcx_b},
/*0xc*/			{1, 5, (void (*)())&inr_c},
/*0xd*/			{1, 5, (void (*)())&dcr_c},
/*0xe*/			{2, 7, (void (*)())&mvi_c_d8},
/*0xf*/			{1, 4, (void (*)())&rrc},
/*0x10*/		{1, 4, (void (*)())&nop},
/*0x11*/		{3, 10, (void (*)())&lxi_d_d16},
/*0x12*/		{1, 7, (void (*)())&stax_d},
/*0x13*/		{1, 5, (void (*)())&inx_d},
/*0x14*/		{1, 5, (void (*)())&inr_d},
/*0x15*/		{1, 5, (void (*)())&dcr_d},
/*0x16*/		{2, 7, (void (*)())&mvi_d_d8},
/*0x17*/		{1, 4, (void (*)())&ral},
/*0x18*/		{1, 4, (void (*)())&nop},
/*0x19*/		{1, 10, (void (*)())&dad_d},
/*0x1a*/		{1, 7, (void (*)())&ldax_d},
/*0x1b*/		{1, 5, (void (*)())&dcx_d},
/*0x1c*/		{1, 5, (void (*)())&inr_e},
/*0x1d*/		{1, 5, (void (*)())&dcr_e},
/*0x1e*/		{2, 7, (void (*)())&mvi_e_d8},
/*0x1f*/		{1, 4, (void (*)())&rar},
/*0x20*/		{1, 4, (void (*)())&nop},
/*0x21*/		{3, 10, (void (*)())&lxi_h_d16},
/*0x22*/		{3, 16, (void (*)())&shld_adr},
/*0x23*/		{1, 5, (void (*)())&inx_h},
/*0x24*/		{1, 5, (void (*)())&inr_h},
/*0x25*/		{1, 5, (void (*)())&dcr_h},
/*0x26*/		{2, 7, (void (*)())&mvi_h_d8},
/*0x27*/		{1, 4, (void (*)())&daa},
/*0x28*/		{1, 4, (void (*)())&nop},
/*0x29*/		{1, 10, (void (*)())&dad_h},
/*0x2a*/		{3, 16, (void (*)())&lhld_adr},
/*0x2b*/		{1, 5, (void (*)())&dcx_h},
/*0x2c*/		{1, 5, (void (*)())&inr_l},
/*0x2d*/		{1, 5, (void (*)())&dcr_l},
/*0x2e*/		{2, 7, (void (*)())&mvi_l_d8},
/*0x2f*/		{1, 4, (void (*)())&cma},
/*0x30*/		{1, 4, (void (*)())&nop},
/*0x31*/		{3, 10, (void (*)())&lxi_sp_d16},
/*0x32*/		{3, 13, (void (*)())&sta_adr},
/*0x33*/		{1, 5, (void (*)())&inx_sp},
/*0x34*/		{1, 10, (void (*)())&inr_m},
/*0x35*/		{1, 10, (void (*)())&dcr_m},
/*0x36*/		{2, 10, (void (*)())&mvi_m_d8},
/*0x37*/		{1, 4, (void (*)())&stc},
/*0x38*/		{1, 4, (void (*)())&nop},
/*0x39*/		{1, 10, (void (*)())&dad_sp},
/*0x3a*/		{3, 13, (void (*)())&lda_adr},
/*0x3b*/		{1, 5, (void (*)())&dcx_sp},
/*0x3c*/		{1, 5, (void (*)())&inr_a},
/*0x3d*/		{1, 5, (void (*)())&dcr_a},
/*0x3e*/		{2, 7, (void (*)())&mvi_a_d8},
/*0x3f*/		{1, 4, (void (*)())&cmc},
/*0x40*/		{1, 5, (void (*)())&mov_b_b},
/*0x41*/		{1, 5, (void (*)())&mov_b_c},
/*0x42*/		{1, 5, (void (*)())&mov_b_d},
/*0x43*/		{1, 5, (void (*)())&mov_b_e},
/*0x44*/		{1, 5, (void (*)())&mov_b_h},
/*0x45*/		{1, 5, (void (*)())&mov_b_l},
/*0x46*/		{1, 7, (void (*)())&mov_b_m},
/*0x47*/		{1, 5, (void (*)())&mov_b_a},
/*0x48*/		{1, 5, (void (*)())&mov_c_b},
/*0x49*/		{1, 5, (void (*)())&mov_c_c},
/*0x4a*/		{1, 5, (void (*)())&mov_c_d},
/*0x4b*/		{1, 5, (void (*)())&mov_c_e},
/*0x4c*/		{1, 5, (void (*)())&mov_c_h},
/*0x4d*/		{1, 5, (void (*)())&mov_c_l},
/*0x4e*/		{1, 7, (void (*)())&mov_c_m},
/*0x4f*/		{1, 5, (void (*)())&mov_c_a},
/*0x50*/		{1, 5, (void (*)())&mov_d_b},
/*0x51*/		{1, 5, (void (*)())&mov_d_c},
/*0x52*/		{1, 5, (void (*)())&mov_d_d},
/*0x53*/		{1, 5, (void (*)())&mov_d_e},
/*0x54*/		{1, 5, (void (*)())&mov_d_h},
/*0x55*/		{1, 5, (void (*)())&mov_d_l},
/*0x56*/		{1, 7, (void (*)())&mov_d_m},
/*0x57*/		{1, 5, (void (*)())&mov_d_a},
/*0x58*/		{1, 5, (void (*)())&mov_e_b},
/*0x59*/		{1, 5, (void (*)())&mov_e_c},
/*0x5a*/		{1, 5, (void (*)())&mov_e_d},
/*0x5b*/		{1, 5, (void (*)())&mov_e_e},
/*0x5c*/		{1, 5, (void (*)())&mov_e_h},
/*0x5d*/		{1, 5, (void (*)())&mov_e_l},
/*0x5e*/		{1, 7, (void (*)())&mov_e_m},
/*0x5f*/		{1, 5, (void (*)())&mov_e_a},
/*0x60*/		{1, 5, (void (*)())&mov_h_b},
/*0x61*/		{1, 5, (void (*)())&mov_h_c},
/*0x62*/		{1, 5, (void (*)())&mov_h_d},
/*0x63*/		{1, 5, (void (*)())&mov_h_e},
/*0x64*/		{1, 5, (void (*)())&mov_h_h},
/*0x65*/		{1, 5, (void (*)())&mov_h_l},
/*0x66*/		{1, 7, (void (*)())&mov_h_m},
/*0x67*/		{1, 5, (void (*)())&mov_h_a},
/*0x68*/		{1, 5, (void (*)())&mov_l_b},
/*0x69*/		{1, 5, (void (*)())&mov_l_c},
/*0x6a*/		{1, 5, (void (*)())&mov_l_d},
/*0x6b*/		{1, 5, (void (*)())&mov_l_e},
/*0x6c*/		{1, 5, (void (*)())&mov_l_h},
/*0x6d*/		{1, 5, (void (*)())&mov_l_l},
/*0x6e*/		{1, 7, (void (*)())&mov_l_m},
/*0x6f*/		{1, 5, (void (*)())&mov_l_a},
/*0x70*/		{1, 7, (void (*)())&mov_m_b},
/*0x71*/		{1, 7, (void (*)())&mov_m_c},
/*0x72*/		{1, 7, (void (*)())&mov_m_d},
/*0x73*/		{1, 7, (void (*)())&mov_m_e},
/*0x74*/		{1, 7, (void (*)())&mov_m_h},
/*0x75*/		{1, 7, (void (*)())&mov_m_l},
/*0x76*/		{1, 7, (void (*)())&hlt},
/*0x77*/		{1, 7, (void (*)())&mov_m_a},
/*0x78*/		{1, 5, (void (*)())&mov_a_b},
/*0x79*/		{1, 5, (void (*)())&mov_a_c},
/*0x7a*/		{1, 5, (void (*)())&mov_a_d},
/*0x7b*/		{1, 5, (void (*)())&mov_a_e},
/*0x7c*/		{1, 5, (void (*)())&mov_a_h},
/*0x7d*/		{1, 5, (void (*)())&mov_a_l},
/*0x7e*/		{1, 7, (void (*)())&mov_a_m},
/*0x7f*/		{1, 5, (void (*)())&mov_a_a},
/*0x80*/		{1, 4, (void (*)())&add_b},
/*0x81*/		{1, 4, (void (*)())&add_c},
/*0x82*/		{1, 4, (void (*)())&add_d},
/*0x83*/		{1, 4, (void (*)())&add_e},
/*0x84*/		{1, 4, (void (*)())&add_h},
/*0x85*/		{1, 4, (void (*)())&add_l},
/*0x86*/		{1, 7, (void (*)())&add_m},
/*0x87*/		{1, 4, (void (*)())&add_a},
/*0x88*/		{1, 4, (void (*)())&adc_b},
/*0x89*/		{1, 4, (void (*)())&adc_c},
/*0x8a*/		{1, 4, (void (*)())&adc_d},
/*0x8b*/		{1, 4, (void (*)())&adc_e},
/*0x8c*/		{1, 4, (void (*)())&adc_h},
/*0x8d*/		{1, 4, (void (*)())&adc_l},
/*0x8e*/		{1, 7, (void (*)())&adc_m},
/*0x8f*/		{1, 4, (void (*)())&adc_a},
/*0x90*/		{1, 4, (void (*)())&sub_b},
/*0x91*/		{1, 4, (void (*)())&sub_c},
/*0x92*/		{1, 4, (void (*)())&sub_d},
/*0x93*/		{1, 4, (void (*)())&sub_e},
/*0x94*/		{1, 4, (void (*)())&sub_h},
/*0x95*/		{1, 4, (void (*)())&sub_l},
/*0x96*/		{1, 7, (void (*)())&sub_m},
/*0x97*/		{1, 4, (void (*)())&sub_a},
/*0x98*/		{1, 4, (void (*)())&sbb_b},
/*0x99*/		{1, 4, (void (*)())&sbb_c},
/*0x9a*/		{1, 4, (void (*)())&sbb_d},
/*0x9b*/		{1, 4, (void (*)())&sbb_e},
/*0x9c*/		{1, 4, (void (*)())&sbb_h},
/*0x9d*/		{1, 4, (void (*)())&sbb_l},
/*0x9e*/		{1, 7, (void (*)())&sbb_m},
/*0x9f*/		{1, 4, (void (*)())&sbb_a},
/*0xa0*/		{1, 4, (void (*)())&ana_b},
/*0xa1*/		{1, 4, (void (*)())&ana_c},
/*0xa2*/		{1, 4, (void (*)())&ana_d},
/*0xa3*/		{1, 4, (void (*)())&ana_e},
/*0xa4*/		{1, 4, (void (*)())&ana_h},
/*0xa5*/		{1, 4, (void (*)())&ana_l},
/*0xa6*/		{1, 7, (void (*)())&ana_m},
/*0xa7*/		{1, 4, (void (*)())&ana_a},
/*0xa8*/		{1, 4, (void (*)())&xra_b},
/*0xa9*/		{1, 4, (void (*)())&xra_c},
/*0xaa*/		{1, 4, (void (*)())&xra_d},
/*0xab*/		{1, 4, (void (*)())&xra_e},
/*0xac*/		{1, 4, (void (*)())&xra_h},
/*0xad*/		{1, 4, (void (*)())&xra_l},
/*0xae*/		{1, 7, (void (*)())&xra_m},
/*0xaf*/		{1, 4, (void (*)())&xra_a},
/*0xb0*/		{1, 4, (void (*)())&ora_b},
/*0xb1*/		{1, 4, (void (*)())&ora_c},
/*0xb2*/		{1, 4, (void (*)())&ora_d},
/*0xb3*/		{1, 4, (void (*)())&ora_e},
/*0xb4*/		{1, 4, (void (*)())&ora_h},
/*0xb5*/		{1, 4, (void (*)())&ora_l},
/*0xb6*/		{1, 7, (void (*)())&ora_m},
/*0xb7*/		{1, 4, (void (*)())&ora_a},
/*0xb8*/		{1, 4, (void (*)())&cmp_b},
/*0xb9*/		{1, 4, (void (*)())&cmp_c},
/*0xba*/		{1, 4, (void (*)())&cmp_d},
/*0xbb*/		{1, 4, (void (*)())&cmp_e},
/*0xbc*/		{1, 4, (void (*)())&cmp_h},
/*0xbd*/		{1, 4, (void (*)())&cmp_l},
/*0xbe*/		{1, 7, (void (*)())&cmp_m},
/*0xbf*/		{1, 4, (void (*)())&cmp_a},
/*0xc0*/		{1, 11, (void (*)())&rnz},
/*0xc1*/		{1, 10, (void (*)())&pop_b},
/*0xc2*/		{3, 10, (void (*)())&jnz_adr},
/*0xc3*/		{3, 10, (void (*)())&jmp_adr},
/*0xc4*/		{3, 17, (void (*)())&cnz_adr},
/*0xc5*/		{1, 11, (void (*)())&push_b},
/*0xc6*/		{2, 7, (void (*)())&adi_d8},
/*0xc7*/		{1, 11, (void (*)())&rst_0},
/*0xc8*/		{1, 11, (void (*)())&rz},
/*0xc9*/		{1, 10, (void (*)())&ret},
/*0xca*/		{3, 10, (void (*)())&jz_adr},
/*0xcb*/		{3, 10, (void (*)())&nop},
/*0xcc*/		{3, 17, (void (*)())&cz_adr},
/*0xcd*/		{3, 17, (void (*)())&call_adr},
/*0xce*/		{2, 7, (void (*)())&aci_d8},
/*0xcf*/		{1, 11, (void (*)())&rst_1},
/*0xd0*/		{1, 11, (void (*)())&rnc},
/*0xd1*/		{1, 10, (void (*)())&pop_d},
/*0xd2*/		{3, 10, (void (*)())&jnc_adr},
/*0xd3*/		{2, 10, (void (*)())&out_d8},
/*0xd4*/		{3, 17, (void (*)())&cnc_adr},
/*0xd5*/		{1, 11, (void (*)())&push_d},
/*0xd6*/		{2, 7, (void (*)())&sui_d8},
/*0xd7*/		{1, 11, (void (*)())&rst_2},
/*0xd8*/		{1, 11, (void (*)())&rc},
/*0xd9*/		{1, 10, (void (*)())&nop},
/*0xda*/		{3, 10, (void (*)())&jc_adr},
/*0xdb*/		{2, 10, (void (*)())&in_d8},
/*0xdc*/		{3, 17, (void (*)())&cc_adr},
/*0xdd*/		{3, 17, (void (*)())&nop},
/*0xde*/		{2, 7, (void (*)())&sbi_d8},
/*0xdf*/		{1, 11, (void (*)())&rst_3},
/*0xe0*/		{1, 11, (void (*)())&rpo},
/*0xe1*/		{1, 10, (void (*)())&pop_h},
/*0xe2*/		{3, 10, (void (*)())&jpo_adr},
/*0xe3*/		{1, 18, (void (*)())&xthl},
/*0xe4*/		{3, 17, (void (*)())&cpo_adr},
/*0xe5*/		{1, 11, (void (*)())&push_h},
/*0xe6*/		{2, 7, (void (*)())&ani_d8},
/*0xe7*/		{1, 11, (void (*)())&rst_4},
/*0xe8*/		{1, 11, (void (*)())&rpe},
/*0xe9*/		{1, 5, (void (*)())&pchl},
/*0xea*/		{3, 10, (void (*)())&jpe_adr},
/*0xeb*/		{1, 5, (void (*)())&xchg},
/*0xec*/		{3, 17, (void (*)())&cpe_adr},
/*0xed*/		{3, 17, (void (*)())&nop},
/*0xee*/		{2, 7, (void (*)())&xri_d8},
/*0xef*/		{1, 11, (void (*)())&rst_5},
/*0xf0*/		{1, 11, (void (*)())&rp},
/*0xf1*/		{1, 10, (void (*)())&pop_psw},
/*0xf2*/		{3, 10, (void (*)())&jp_adr},
/*0xf3*/		{1, 4, (void (*)())&di},
/*0xf4*/		{3, 17, (void (*)())&cp_adr},
/*0xf5*/		{1, 11, (void (*)())&push_psw},
/*0xf6*/		{2, 7, (void (*)())&ori_d8},
/*0xf7*/		{1, 11, (void (*)())&rst_6},
/*0xf8*/		{1, 11, (void (*)())&rm},
/*0xf9*/		{1, 5, (void (*)())&sphl},
/*0xfa*/		{3, 10, (void (*)())&jm_adr},
/*0xfb*/		{1, 4, (void (*)())&ei},
/*0xfc*/		{3, 17, (void (*)())&cm_adr},
/*0xfd*/		{3, 17, (void (*)())&nop},
/*0xfe*/		{2, 7, (void (*)())&cpi_d8},
/*0xff*/		{1, 11, (void (*)())&rst_7},
    	 };
	};

#endif
