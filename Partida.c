#include "Partida.h"
#include "Tipus.h"
#include "Llista.h"

LlistaPDI Inicialitza_oponents(LlistaPDI O){
     int i;
     Oponent Oponent;
     O = LlistaPDI_vesInici(O);
     
     while (!LlistaPDI_fi(O)){
                         
         Oponent = LlistaPDI_consulta(O);
         O = LlistaPDI_esborra(O);
         Oponent.jugada_acabada = 0;
         Oponent.aposta = 0;
                         
         for(i = 0; i < 11; i++){
               
                               
              Oponent.cartes[i].iden = 13;

              //printf("%d  ", Oponent.cartes[i].iden);
              
                         
         }
        // printf("------------->%d", Oponent.jugada_acabada);
                         
         O = LlistaPDI_insereix(O, Oponent);                
                           
         
                         
     }
                   
     O = LlistaPDI_vesInici(O);
     
     return O;
}     


Jugador Inicialitza_jugador(Jugador J){
        int i;
        
        //printf("Comensa el jugadooor \n");
        for(i = 0; i < 11; i++){
                               
              J.cartes[i].iden = 13;
              //printf("%d  ", J.cartes[i].iden);
                     
         }
        
        return J;
        
}

Crupier Inicialitza_crupier(Crupier C){
        
        int i;
        //printf("Comensa el crupieer \n");
        for(i = 0; i < 11; i++){
               
                               
              C.cartes[i].iden = 13;
              //printf("%d  ", C.cartes[i].iden);
              
                         
         }
        
        return C;
        
}
        
LlistaPDI Aposta_oponents(LlistaPDI O){
     
     Oponent o;
     while (!LlistaPDI_fi(O)){
                     
         
          o = LlistaPDI_consulta(O);
          O = LlistaPDI_esborra(O);
     
          if(strcmp(o.tipusOponent,"Fort") == 0){
               
               o.aposta = 900 + o.cartaMaxima;
               o.diners = o.diners - o.aposta;
               
          
          }else{
           
               if(strcmp(o.tipusOponent,"Normal") == 0){
                                             
                    o.aposta = 500 + o.cartaMaxima;
                    o.diners = o.diners - o.aposta;
          
               }else{
          
                    o.aposta = 100 + o.cartaMaxima;
                    o.diners = o.diners - o.aposta;
               
               }
          
          }
          
          O = LlistaPDI_insereix(O, o);
          
     }
     O = LlistaPDI_vesInici(O);
     
     return O;
}
     

Carta crea_carta(int iden){
      Carta c;

      switch(iden){
          
          case 0:
               
               c.iden = iden;
               c.numero = 'A';
               c.valor = 11;
               
               
          break;
          
          case 1:
               
               c.iden = iden;
               c.numero = '2';
               c.valor = 2;
               
          break;

          case 2:
               
               c.iden = iden;
               c.numero = '3';
               c.valor = 3;
               
          break;
          
          case 3:
               
               c.iden = iden;
               c.numero = '4';
               c.valor = 4;
               
          break;
          
          case 4:
               
               c.iden = iden;
               c.numero = '5';
               c.valor = 5;
               
          break;
          
          case 5:
               
               c.iden = iden;
               c.numero = '6';
               c.valor = 6;
               
          break;
          
          case 6:
               
               c.iden = iden;
               c.numero = '7';
               c.valor = 7;
               
          break;
          
          case 7:
               
               c.iden = iden;
               c.numero = '8';
               c.valor = 8;
               
          break;
          
          case 8:
               
               c.iden = iden;
               c.numero = '9';
               c.valor = 9;
               
          break;
          
          case 9:
               
               c.iden = iden;
               c.numero = '0';
               c.valor = 10;
               
          break;
          
          case 10:
               
               c.iden = iden;
               c.numero = 'J';
               c.valor = 10;
               
          break;
          
          case 11:
               
               c.iden = iden;
               c.numero = 'Q';
               c.valor = 10;
               
          break;
          
          case 12:
               
               c.iden = iden;
               c.numero = 'K';
               c.valor = 10;
               
          break;
     }
    
     
     return c;
}

void mostra_Cartes(Oponent o){
     int i, stop = 0, index, carta_jug;
     
     i = 1;
     printf("\n%s\t\t\t", o.nomOponent);
     printf("%d btc\n\n", o.aposta);
     //printf("\n\njugada_acabada en mostra cartes------->%d\n\n", o.jugada_acabada );
     if(o.jugada_acabada == 0){
                            
            i = 1;
            printf("X ");
            
        }else{
            
            i = 0;
            
        }
     
     do{
           
           if(o.cartes[i].iden != 13 && i <= 11){
                
                if(o.cartes[i].iden != 9){
                                     
                    printf("%c ", o.cartes[i].numero);
                
                }else{
                
                    printf("10 ");
                
                }
                
                i++;
                
           }else{
                 
                stop = 1;
                
           }
           
     }while (stop == 0);
     
     if ( o.jugada_acabada == 1 ){
          
          index = 0;
          carta_jug = 0;
          //printf("--> %d  ", Oponent.cartes[2].iden);
          while(o.cartes[index].iden != 13){
                                    
              carta_jug = carta_jug + o.cartes[index].valor;                                 
              index++;
                                        
          }
          
          if(index > 4){
                   
              printf("\t\t(%d", carta_jug);
              
          }else{
                
              printf("\t\t\t(%d", carta_jug);
              
          }
          index = 0;
          carta_jug = 0;
             
          while(o.cartes[index].iden != 13){
                                        
              carta_jug = carta_jug + o.cartes[index].valor;                                 
              index++;
                                            
          }
          if((index == 2 && carta_jug == 21) && (o.cartes[0].iden != 9 && o.cartes[1].iden != 9)){
                       
              printf("B)");
                       
          }else{
                
                printf(")");
          
          }
     }       
           
     if(o.jugada_acabada == 0){
                         
         printf("\n\n");
     
     }
         
}     


int Carta_max(LlistaPDI O, Jugador J){
    
    Oponent oponent;
    int carta_jug, carta_max, index;
    
    carta_max = 0;
    O = LlistaPDI_vesInici(O);
    
    while(!LlistaPDI_fi(O)){
    
        carta_jug = 0;
        oponent = LlistaPDI_consulta(O);
        //printf("\njugada acabada: %d\n\n", oponent.jugada_acabada);
        
        if(oponent.jugada_acabada == 0){
                                  
            index = 1;
            
        }else{
              
            index = 0;
            
        }
        
        while(oponent.cartes[index].iden != 13){
                                         
            carta_jug = carta_jug + oponent.cartes[index].valor;
            index ++;
            
        }
        
        if(carta_max < carta_jug && carta_jug <= 21){
                     //printf("\n\ncarta maxima: %d\n\n", carta_max);             
            carta_max = carta_jug;
            
        }
        
        O = LlistaPDI_avansa(O);
        
    }
    index = 1;
    
    while(J.cartes[index].iden != 13){
                                         
            carta_jug = carta_jug + J.cartes[index].valor;
            index ++;
            
    }
    if(carta_max < carta_jug && carta_jug <= 21){
                 //printf("\n\ncarta maxima: %d\n\n", carta_max);             
         carta_max = carta_jug;
            
    }
    
    return carta_max;
    
}

int Carta_min(LlistaPDI O){
    
    Oponent oponent;
    int carta_jug, carta_min, index;
    
    carta_min = 1000;
    O = LlistaPDI_vesInici(O);
    //printf("entra carta minima");
    
    while(!LlistaPDI_fi(O)){
    
        carta_jug = 0;
        index = 0;
        
        oponent = LlistaPDI_consulta(O);
        
        while(oponent.cartes[index].iden != 13){
                                         
            carta_jug = carta_jug + oponent.cartes[index].valor;
            index ++;
            //printf("Carta minima ----->%d \n", carta_jug);
            
        }
        
        if(carta_min > carta_jug && carta_jug <= 21){
                     
            carta_min = carta_jug;
            //printf("Carta minima ----->%d \n", carta_min);
            
        }
        
        O = LlistaPDI_avansa(O);
        
    }
    
    //printf("Carta minima ----->%d \n", carta_min);    
    return carta_min;
    
}


    
    
    
    
    
    
    
    
    
    
    
    
    
    



