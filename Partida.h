#include <stdio.h>
#ifndef _PARTIDA_H_
#define _PARTIDA_H_
#include "Tipus.h"
#include "Llista.h"

LlistaPDI Inicialitza_oponents(LlistaPDI O);
Jugador Inicialitza_jugador(Jugador J);
Crupier Inicialitza_crupier(Crupier C);
LlistaPDI Aposta_oponents(LlistaPDI O);
Carta crea_carta(int iden);
void mostra_Cartes(Oponent o);
int Carta_max(LlistaPDI O, Jugador J);
int Carta_min(LlistaPDI O);

#endif
