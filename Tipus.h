#include <stdio.h>
#ifndef _TIPUS_H_
#define _TIPUS_H_

typedef struct{
        
        int iden;
        char numero;
        int valor;
        
        }Carta; 

typedef struct{
        
        char nomOponent[100];
        int diners;
        char tipusOponent[20];
        int cartaMaxima;
        Carta cartes[11];
        int aposta;
        int jugada_acabada;
        
        }Oponent;
        
typedef struct{
        
        char nomJugador[100];
        int diners;
        int p_guanyades;
        int p_perdudes;
        int *progresio_diners;
        Carta cartes[11];
        int aposta;
        
        }Jugador;

typedef struct{
        
        Carta cartes[11];
        
        }Crupier;
        


#endif
