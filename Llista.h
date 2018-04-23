#include <stdio.h>
#ifndef _LLISTA_H_
#define _LLISTA_H_
#include "Tipus.h"

typedef struct N2{
        
        Oponent oponent;
        struct N2 *seg;
        
        }Node2;
        
typedef struct{
        
        Node2 *pri;
        Node2 *ant;

        }LlistaPDI;
        
LlistaPDI LlistaPDI_crea();
LlistaPDI LlistaPDI_insereix(LlistaPDI I, Oponent o);
LlistaPDI LlistaPDI_esborra(LlistaPDI I);
Oponent   LlistaPDI_consulta(LlistaPDI I);
int       LlistaPDI_buida(LlistaPDI I);
LlistaPDI LlistaPDI_vesInici(LlistaPDI I);
LlistaPDI LlistaPDI_avansa(LlistaPDI I);
int       LlistaPDI_fi(LlistaPDI I);
void      LlistaPDI_destrueix(LlistaPDI *I);
Oponent   Fantasma();



#endif
