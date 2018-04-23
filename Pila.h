#include <stdio.h>
#ifndef _PILA_H_
#define _PILA_H_
#include "Tipus.h"

typedef struct N{
        
        int iden;
        struct N *seg;
        
        }Node1;
        
typedef Node1 *Pila;

Pila Pila_crea();
void Pila_push(Pila *p, int valor);
void Pila_pop(Pila *p);
int Pila_top(Pila p);
int Pila_buida(Pila p);
void Pila_destrueix(Pila *p);
Pila Barallar(Pila *p);

#endif

