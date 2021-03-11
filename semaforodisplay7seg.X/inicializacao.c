


#include <xc.h>
#include "config.h"
#include "delay.h"



void semafaro_init ( void)
{
    //configuração de entradas e saidas 
    TRISDbits.TRISD1 = 1; 
    TRISDbits.TRISD2 = 0;  
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
}
void verde (void) 
{
    PORTDbits.RD5 = 1;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;        
}             
void amarelo (void)
{
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 1;
    PORTDbits.RD7 = 0;        
}   
void vermelho (void)
{
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 1;
}    
void vermelho_ped ( void)
{
    PORTDbits.RD3 = 1;
    PORTDbits.RD2 = 0;  
} 
void verde_ped ( void)  
{
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 1;  
}
int botao_ped ( void )
{
  return(PORTDbits.RD1);     
}
