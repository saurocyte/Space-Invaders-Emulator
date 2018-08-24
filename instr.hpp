#ifndef INSTR
#define INSTR

#include <cstdlib>
#include "cpu.hpp"

struct instruction {
    const std::uint8_t length;
    const std::uint8_t duration;
    void (*functionPtr)();
};

void nop();
void lxi_b_d16(std::uint8_t o1, std::uint8_t o2);
void stax_b();
void inx_b();
void inr_b();
void dcr_b();
void mvi_b_d8(std::uint8_t o1);
void rlc();
void dad_b();
void ldax_b();
void dcx_b();
void inr_c();
void dcr_c();
void mvi_c_d8(std::uint8_t o1);
void rrc();
void lxi_d_d16(std::uint8_t o1, std::uint8_t o2);
void stax_d();
void inx_d();
void inr_d();
void dcr_d();
void mvi_d_d8(std::uint8_t o1);
void ral();
void dad_d();
void ldax_d();
void dcx_d();
void inr_e();
void dcr_e();
void mvi_e_d8(std::uint8_t o1);
void rar();
void rim();
void lxi_h_d16(std::uint8_t o1, std::uint8_t o2);
void shld_adr(std::uint8_t o1, std::uint8_t o2);
void inx_h();
void inr_h();
void dcr_h();
void mvi_h_d8(std::uint8_t o1);
void daa();
void dad_h();
void lhld_adr(std::uint8_t o1, std::uint8_t o2);
void dcx_h();
void inr_l();
void dcr_l();
void mvi_l_d8(std::uint8_t o1);
void cma();
void sim();
void lxi_sp_d16(std::uint8_t o1, std::uint8_t o2);
void sta_adr(std::uint8_t o1, std::uint8_t o2);
void inx_sp();
void inr_m();
void dcr_m();
void mvi_m_d8(std::uint8_t o1);
void stc();
void dad_sp();
void lda_adr(std::uint8_t o1, std::uint8_t o2);
void dcx_sp();
void inr_a();
void dcr_a();
void mvi_a_d8(std::uint8_t o1);
void cmc();
void mov_b_b();
void mov_b_c();
void mov_b_d();
void mov_b_e();
void mov_b_h();
void mov_b_l();
void mov_b_m();
void mov_b_a();
void mov_c_b();
void mov_c_c();
void mov_c_d();
void mov_c_e();
void mov_c_h();
void mov_c_l();
void mov_c_m();
void mov_c_a();
void mov_d_b();
void mov_d_c();
void mov_d_d();
void mov_d_e();
void mov_d_h();
void mov_d_l();
void mov_d_m();
void mov_d_a();
void mov_e_b();
void mov_e_c();
void mov_e_d();
void mov_e_e();
void mov_e_h();
void mov_e_l();
void mov_e_m();
void mov_e_a();
void mov_h_b();
void mov_h_c();
void mov_h_d();
void mov_h_e();
void mov_h_h();
void mov_h_l();
void mov_h_m();
void mov_h_a();
void mov_l_b();
void mov_l_c();
void mov_l_d();
void mov_l_e();
void mov_l_h();
void mov_l_l();
void mov_l_m();
void mov_l_a();
void mov_m_b();
void mov_m_c();
void mov_m_d();
void mov_m_e();
void mov_m_h();
void mov_m_l();
void hlt();
void mov_m_a();
void mov_a_b();
void mov_a_c();
void mov_a_d();
void mov_a_e();
void mov_a_h();
void mov_a_l();
void mov_a_m();
void mov_a_a();
void add_b();
void add_c();
void add_d();
void add_e();
void add_h();
void add_l();
void add_m();
void add_a();
void adc_b();
void adc_c();
void adc_d();
void adc_e();
void adc_h();
void adc_l();
void adc_m();
void adc_a();
void sub_b();
void sub_c();
void sub_d();
void sub_e();
void sub_h();
void sub_l();
void sub_m();
void sub_a();
void sbb_b();
void sbb_c();
void sbb_d();
void sbb_e();
void sbb_h();
void sbb_l();
void sbb_m();
void sbb_a();
void ana_b();
void ana_c();
void ana_d();
void ana_e();
void ana_h();
void ana_l();
void ana_m();
void ana_a();
void xra_b();
void xra_c();
void xra_d();
void xra_e();
void xra_h();
void xra_l();
void xra_m();
void xra_a();
void ora_b();
void ora_c();
void ora_d();
void ora_e();
void ora_h();
void ora_l();
void ora_m();
void ora_a();
void cmp_b();
void cmp_c();
void cmp_d();
void cmp_e();
void cmp_h();
void cmp_l();
void cmp_m();
void cmp_a();
void rnz();
void pop_b();
void jnz_adr(std::uint8_t o1, std::uint8_t o2);
void jmp_adr(std::uint8_t o1, std::uint8_t o2);
void cnz_adr(std::uint8_t o1, std::uint8_t o2);
void push_b();
void adi_d8(std::uint8_t o1);
void rst_0();
void rz();
void ret();
void jz_adr(std::uint8_t o1, std::uint8_t o2);
void cz_adr(std::uint8_t o1, std::uint8_t o2);
void call_adr(std::uint8_t o1, std::uint8_t o2);
void aci_d8(std::uint8_t o1);
void rst_1();
void rnc();
void pop_d();
void jnc_adr(std::uint8_t o1, std::uint8_t o2);
void out_d8(std::uint8_t o1);
void cnc_adr(std::uint8_t o1, std::uint8_t o2);
void push_d();
void sui_d8(std::uint8_t o1);
void rst_2();
void rc();
void jc_adr(std::uint8_t o1, std::uint8_t o2);
void in_d8(std::uint8_t o1);
void cc_adr(std::uint8_t o1, std::uint8_t o2);
void sbi_d8(std::uint8_t o1);
void rst_3();
void rpo();
void pop_h();
void jpo_adr(std::uint8_t o1, std::uint8_t o2);
void xthl();
void cpo_adr(std::uint8_t o1, std::uint8_t o2);
void push_h();
void ani_d8(std::uint8_t o1);
void rst_4();
void rpe();
void pchl();
void jpe_adr(std::uint8_t o1, std::uint8_t o2);
void xchg();
void cpe_adr(std::uint8_t o1, std::uint8_t o2);
void xri_d8(std::uint8_t o1);
void rst_5();
void rp();
void pop_psw();
void jp_adr(std::uint8_t o1, std::uint8_t o2);
void di();
void cp_adr(std::uint8_t o1, std::uint8_t o2);
void push_psw();
void ori_d8(std::uint8_t o1);
void rst_6();
void rm();
void sphl();
void jm_adr(std::uint8_t o1, std::uint8_t o2);
void ei();
void cm_adr(std::uint8_t o1, std::uint8_t o2);
void cpi_d8(std::uint8_t o1);
void rst_7();

#endif