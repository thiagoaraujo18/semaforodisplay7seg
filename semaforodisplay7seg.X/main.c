/*
 * File:   main.c
 * Author: 20185210
 *
 * Created on 5 de Fevereiro de 2021, 16:37
 */


#include <xc.h>
#include "config.h"
#include "inicializacao.h"
#include "delay.h"


void main(void) 
{   
    semafaro_init();
    display7seg_init();
    char estado = 0;
    int cont = 0;
    
    while (1)
    {
       switch(estado) 
       {
            case 0: 
                        desligatudo()
                        verde();
                        vermelho_ped();
                        if (botao_ped() == 1)
                            estado = 1;     
                        break;
            case 1: 
                        cont = 3;
                        if(botao_ped() == 0)
                            estado = 2;
                        break;
            case 2:
                        display7seg(cont);
                        delay(1000);
                        --cont;
                        if( cont == 0)
                        {
                            cont = 6;
                            estado = 3;
                        }
                        else
                            estado = 2;
                        break; 
            case 3:
                        amarelo();
                        display7seg(cont);
                        delay(1000);
                        --cont;
                        if( cont == 0)
                        {
                            cont = 8;
                            estado = 4;
                        }
                        else
                            estado = 3;
                        break;
            case 4:
                        vermelho();
                        verde_ped();
                        display7seg(cont);
                        delay(1000);
                        --cont;
                        if( cont == 0)
                        {
                            estado = 0;
                        }
                        else
                            estado = 4;  
                        break;
       }
    } 
  }



