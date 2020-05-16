#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

void ConmutarDigito(void);
void MostrarDisplay(unsigned int valor);
unsigned int Codificar(int x);
unsigned int D1=0b0111111, D2=0b0111111, D3=0b0111111, DigitoOn=0;
#define BJT1 PORTCbits.RC7
#define BJT2 PORTCbits.RC6
#define BJT3 PORTCbits.RC5
#endif