#include<xc.h>
#include"Display7seg.h"

void ConmutarDigito(){ //ESTA FUNCION MUESTRA LOS NUMEROS EN LOS DIGITOS Y PRENDE Y APAGA LOS TRANSISTORES.
 unsigned char i; 
 unsigned int load;
 switch(DigitoOn) 
 { 
  case 0: 
   load=D1; //En load se guarda el numero a mostrar por el digito encendido.
   BJT1=1; 
   BJT2=0;  //Enciende un digito y apaga los demas.
   BJT3=0; 
   DigitoOn=1; //Se cambia la variable para que la siguiente vez pase por otro case del switch, encendiendo otro digito.
   break; 
  case 1: 
   load=D2; 
   BJT1=0; 
   BJT2=1; 
   BJT3=0; 
   DigitoOn=2; 
   break; 
  case 2: 
   load=D3;
   BJT1=0; 
   BJT2=0; 
   BJT3=1; 
   DigitoOn=0; 
   break; 
 } 
 PORTB=load;
}

void MostrarDisplay(unsigned int valor) //ESTA FUNCION DIVIDE EN CEN, DEC Y UNI VALOR ASIGNADO POR EL USUARIO Y LO CONVIERTE EN CODIGOS PARA USAR EN EL REGISTRO DE DESPLAZAMIENTO.
{ 
 unsigned int cen, dec, uni; 
 cen=(valor/100); 
 dec=((valor/10)%10); //Separacion entre centena, descena y unidad.
 uni=(valor%10); 
 D1=Codificar(cen); 
 D2=Codificar(dec);  //Codificacion de numero a codigo para el registro.
 D3=Codificar(uni); 
} 
unsigned int Codificar(int x) 
{ 
  unsigned int caca; //En esta variable se guarda el codigo.
 
 switch(x) 
 { 
  case 0: 
   caca=0b0111111; 
   break; 
  case 1: 
   caca=0b0000110; //00000110
   break; 
  case 2: 
   caca=0b1011011;
   break; 
  case 3: 
   caca=0b1001111; 
   break; 
  case 4: 
   caca=0b1100110; 
   break; 
  case 5: 
   caca=0b1101101;
   break; 
  case 6: 
   caca=0b1111101; 
   break; 
  case 7: 
   caca=0b0000111; 
   break; 
  case 8: 
   caca=0b1111111; 
   break; 
  case 9: 
   caca=0b1100111; 
   break; 
 } 
 return caca; 
}
