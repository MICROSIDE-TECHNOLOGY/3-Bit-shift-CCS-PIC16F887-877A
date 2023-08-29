/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
Corrimiento de bits.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
Implementar corrimiento de 8 bits y desplegar el resultado en 8 LEDs
---------------------------------------------------------------------------
*/

#include <16F887.h>                     //Incluye el microcontrolador con el que se va a trabajar 
#use delay ( clock=20Mhz, crystal )     //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

byte LEDS;                              //Variable de 8 bits(1 byte)

int i;

void main ( void ) {
   set_tris_b ( 0x00 );                   //Configura puerto B como salidas
   LEDS = 0x0D;                         //Se inicia cargando los bits deseados

   while ( 1 ) {
      LEDS = ((LEDS << 1)|(LEDS >> 7)); //Inicia corrimiento
      output_b ( LEDS );                //Pasa el valor al puerto B
      delay_ms ( 500 );
   }
}
