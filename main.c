#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "Tipus.h"
#include "Llista.h"
#include "Partida.h"
#include "Fitxers.h"
#include <time.h>

int main(int argc, char *argv[]){

   int opcio, barrejades = 0, num_baralles, iden, index, aposta = 0, perd, pasa, carta_jug, carta_max, caracter, opcio_joc, cartes_crupier, carta_min, stop, aux_as, ma_max;
   char s_n;
   Pila Baralla;
   LlistaPDI Oponents;
   Oponent Oponent;
   Jugador Jugador;
   Crupier Crupier;
   Baralla = Pila_crea();
   ma_max = 0;
   do{
       
       system("cls");
       printf("\n1. Generar baralla de cartes\n");
       printf("2. Jugar\n");
       printf("3. Mirar estadistiques\n");
       printf("4. Sortir\n");
       printf("Quina opcio vols executar?\n\n");
       scanf("%d", &opcio);
       if(opcio == 2 && barrejades == 0){
       
             printf("\nError. Cal tenir una baralla de cartes abans de poder jugar!\n\n");
       
       }else{
             
             switch(opcio){
                      
             case 1: 
                      
                       Barallar(&Baralla);
                       barrejades = 1;
                            

              break;
           
              case 2:
                   
                   do{
                   
                       system("cls");
                       Oponents = LlistaPDI_crea();
                       Oponents = Llegeix_oponents(Oponents);
                       Oponents = LlistaPDI_vesInici(Oponents);
                       Oponents = Inicialitza_oponents(Oponents);
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       
                       while (!LlistaPDI_fi(Oponents)){
                             
                             Oponent = LlistaPDI_consulta(Oponents);
                             Oponents = LlistaPDI_esborra(Oponents);
                             Oponent.jugada_acabada = 0;
                             //printf("------------->%d", Oponent.jugada_acabada);
                             Oponents = LlistaPDI_insereix(Oponents, Oponent); 
                             
                             
                       }
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       Jugador = Llegeix_jugador(Jugador);
                       Jugador = Inicialitza_jugador(Jugador);
                       Crupier = Inicialitza_crupier(Crupier);
                       Oponents = Aposta_oponents(Oponents);
                       
                       while (!LlistaPDI_fi(Oponents)){
                                
                                Oponent = LlistaPDI_consulta(Oponents);
                                printf("\n%s\t\t\t", Oponent.nomOponent);
                                printf("%d btc\n\n", Oponent.aposta);                        
                                Oponents = LlistaPDI_avansa(Oponents);
                       }
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       do{
                          
                          
                          printf("\n%s , fes la teva aposta\n", Jugador.nomJugador);
                          scanf("%d", &Jugador.aposta);
                          Jugador.diners = Jugador.diners - Jugador.aposta;
                       
                          if(Jugador.aposta < 20 || Jugador.aposta > 1000){
                       
                              printf("Aposta no valida, l'aposta de la taula esta entre 20 i 1000 btc\n");
                              aposta = 0;
                           
                           }else{
                              
                              aposta = 1;
                              
                           }
                       
                       }while(aposta != 1);
                       
                       while (!LlistaPDI_fi(Oponents) && !Pila_buida(Baralla)){
                             
                             Oponent = LlistaPDI_consulta(Oponents);
                             Oponents = LlistaPDI_esborra(Oponents);
                       
                             if(Pila_buida(Baralla) == 1){
                             
                                 Barallar(&Baralla);
                                 
                             }
                             
                             iden = Pila_top(Baralla);
                             //printf("---->%d\n", iden);
                             Pila_pop(&Baralla);
                             
                             Oponent.cartes[0] = crea_carta(iden);
                             
                             if(Pila_buida(Baralla) == 1){
                             
                                 Barallar(&Baralla);
                                 
                             }
                             
                             iden = Pila_top(Baralla);
                             //printf("---->%d\n", iden);
                             Pila_pop(&Baralla);
                             
                             Oponent.cartes[1] = crea_carta(iden);
                             Oponents = LlistaPDI_insereix(Oponents, Oponent);
                             
                       }
                       
                       
                       if(Pila_buida(Baralla) == 1){
                             
                             Barallar(&Baralla);
                                 
                       }
                       
                       iden = Pila_top(Baralla);
                       //printf("---->%d\n", iden);
                       Pila_pop(&Baralla);
                       Jugador.cartes[0] = crea_carta(iden);
                       
                       if(Pila_buida(Baralla) == 1){
                             
                             Barallar(&Baralla);
                                 
                       }
                       
                       iden = Pila_top(Baralla);
                       //printf("---->%d\n", iden);
                       Pila_pop(&Baralla);
                       Jugador.cartes[1] = crea_carta(iden);
                       
                       if(Pila_buida(Baralla) == 1){
                             
                             Barallar(&Baralla);
                                 
                       }
                       
                       iden = Pila_top(Baralla);
                       //printf("---->%d\n", iden);
                       Pila_pop(&Baralla);
                       Crupier.cartes[0] = crea_carta(iden);
                       
                       if(Pila_buida(Baralla) == 1){
                             
                             Barallar(&Baralla);
                                 
                       }
                       
                       iden = Pila_top(Baralla);
                       //printf("---->%d\n", iden);
                       Pila_pop(&Baralla);
                       Crupier.cartes[1] = crea_carta(iden);
                       
                       system("cls");
                       //printf("Cartes Repartides\n\n");
                       printf("\nCrupier\n\n");
                       
                       index = 1;
                       printf("X ");
                       
                       while(Crupier.cartes[index].iden != 13 && index <= 11){
                               
                           if(Crupier.cartes[index].iden != 9){
                                                             
                               printf("%c ", Crupier.cartes[index].numero);
                                   
                           }else{
                               
                               printf("10 ");
                               
                           }
                           index++;
                       
                       }
                       printf("\n");
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       while (!LlistaPDI_fi(Oponents)){
                                
                                Oponent = LlistaPDI_consulta(Oponents);
                                mostra_Cartes(Oponent);                          
                                Oponents = LlistaPDI_avansa(Oponents);
                       }
                       
                       printf("%s\t\t\t %d btc \n\n", Jugador.nomJugador, Jugador.aposta);
                       
                       index = 0;
                       
                       while(Jugador.cartes[index].iden != 13 && index <= 11){
                               
                           if(Jugador.cartes[index].iden != 9){
                                                             
                               printf("%c ", Jugador.cartes[index].numero);
                                   
                           }else{
                               
                               printf("10 ");
                               
                           }
                           index++;
                       
                       }
                       printf("\n");
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       
                       
                       
                       
                       while (!LlistaPDI_fi(Oponents)){
                                
                                Oponent = LlistaPDI_consulta(Oponents);
                                Oponents = LlistaPDI_esborra(Oponents);
                                Oponent.jugada_acabada = 0;                          
                                Oponents = LlistaPDI_insereix(Oponents, Oponent);
                       }
                       
                       Oponents = LlistaPDI_vesInici(Oponents);
                       
                       
                       
                       fflush(stdin);
                       getchar();
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       system("cls");
                       
                       
                        printf("\nCrupier\n\n");
                       
                        index = 1;
                        printf("X ");
                       
                        while(Crupier.cartes[index].iden != 13 && index <= 11){
                               
                            if(Crupier.cartes[index].iden != 9){
                                                             
                                printf("%c ", Crupier.cartes[index].numero);
                                   
                            }else{
                               
                                printf("10 ");
                               
                            }
                            index++;
                       
                        }
                        printf("\n");
                  
                        
                        while (!LlistaPDI_fi(Oponents)){
                                //printf("entra principi   ");
                            Oponent = LlistaPDI_consulta(Oponents);
                            Oponents = LlistaPDI_esborra(Oponents);
                            Oponent.jugada_acabada = 0;
                            printf("nom: %s\n", Oponent.nomOponent);
                            //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                            if(strcmp(Oponent.tipusOponent,"Fort") == 0){
                                  //printf("entra caracter   ");
                                  //printf("%s\n", Oponent.nomOponent);
                                caracter = 1;
                                  
                            }else{
                                   
                                if(strcmp(Oponent.tipusOponent,"Normal") == 0){
                                                      //printf("%s\n", Oponent.nomOponent);               
                                    caracter = 2;
                                  
                                }else{
                                  //printf("%s\n", Oponent.nomOponent);
                                    caracter = 3;
                                       
                                }
                                  
                            }
                             
                            switch(caracter){
                                              
                                case 1:
                                    //printf("caracter fort   ");
                                    pasa = 0;
                                    perd = 0;
                                    
                                    carta_max = Carta_max(Oponents, Jugador);
                                    //carta_max = 15;
                                    printf("CARTA MAXIMA: %d\n", carta_max);
                                    while(pasa == 0 && perd == 0){
                                    
                                        index = 0;
                                        carta_jug = 0;
                                        //printf("--> %d  ", Oponent.cartes[2].iden);
                                        while(Oponent.cartes[index].iden != 13){
                                        
                                            carta_jug = carta_jug + Oponent.cartes[index].valor;
                                            //printf("valor: %d\n", Oponent.cartes[index].valor );
                                            //printf("total: %d\n", carta_jug );
                                            
                                            index++;
                                            
                                        }
                                        //printf("carta jugador: %d\n   ",  carta_jug);
                                        
                                        
                                        //printf("carta maxima %d\n   ",  carta_max);
                                        
                                        
                                        if((carta_jug < carta_max || carta_jug < Oponent.cartaMaxima) && carta_jug < 21){
                                            
                                            if(Pila_buida(Baralla) == 1){
                             
                                                 Barallar(&Baralla);
                                 
                                            }
                                                     
                                            iden = Pila_top(Baralla);
                                            //printf("iden nova carta: %d\n", iden);
                                            Pila_pop(&Baralla);
                                            index = 0;
                                            while(Oponent.cartes[index].iden != 13){
                                                
                                                index ++;
                                                
                                            }                                 
                                                                                                                
                                            Oponent.cartes[index] = crea_carta(iden);
                                        
                                        }else{
                                              
                                              if(carta_jug > 21){
                                                           
                                                  index = 0;
                                                  aux_as = 0;
                                                  
                                                  while((Oponent.cartes[index].iden != 13 && index <= 11) && aux_as == 0){
                                                      
                                                      if(Oponent.cartes[index].iden == 0){
                                                      
                                                          if(Oponent.cartes[index].valor == 11){               
                                           
                                                               Oponent.cartes[index].valor = 1;
                                                               aux_as = 1;
                                                           
                                                           }
                                                           index++;
                                                          
                                                      }else{
                                                            
                                                          index++;
                                                          
                                                      }
                                                  } 
                                                  if(aux_as == 0){
                                                  
                                                      perd = 1;
                                                      
                                                  }
                                              
                                              }else{
                                                    
                                                    pasa = 1;
                                                    
                                              }
                                              
                                        }
                                        
                                  }
                                  Oponent.jugada_acabada = 1;
                                  //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                                  Oponents = LlistaPDI_insereix(Oponents, Oponent);
                                  mostra_Cartes(Oponent); 
                                  
                                break;
                                     
                                     
                                     
                                     
                                     
                                              
                                case 2:
                                     
                                     
                                    pasa = 0;
                                    perd = 0;
                                    //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                                    carta_max = Carta_max(Oponents, Jugador);
                                    //carta_max = 15;
                                    
                                    while(pasa == 0 && perd == 0){
                                    
                                        index = 0;
                                        carta_jug = 0;
                                        //printf("--> %d  ", Oponent.cartes[2].iden);
                                        while(Oponent.cartes[index].iden != 13){
                                        
                                            carta_jug = carta_jug + Oponent.cartes[index].valor;
                                            //printf("valor: %d\n", Oponent.cartes[index].valor );
                                            //printf("total: %d\n", carta_jug );
                                            
                                            index++;
                                            
                                        }
                                        
                                        
                                        if(((carta_jug % 2 != 0) || carta_jug < Oponent.cartaMaxima) && carta_jug < 21){
                                            
                                            if(Pila_buida(Baralla) == 1){
                             
                                                Barallar(&Baralla);
                                 
                                            }
                                                     
                                            iden = Pila_top(Baralla);
                                            //printf("iden nova carta: %d\n", iden);
                                            Pila_pop(&Baralla);
                                            index = 0;
                                            while(Oponent.cartes[index].iden != 13){
                                                
                                                index ++;
                                                
                                            }                                 
                                                                                                                
                                            Oponent.cartes[index] = crea_carta(iden);
                                        
                                        }else{
                                              
                                              if(carta_jug > 21){
                                                           
                                                  index = 0;
                                                  aux_as = 0;
                                                  
                                                  while((Oponent.cartes[index].iden != 13 && index <= 11) && aux_as == 0){
                                                      
                                                      if(Oponent.cartes[index].iden == 0){
                                                      
                                                          if(Oponent.cartes[index].valor == 11){               
                                           
                                                               Oponent.cartes[index].valor = 1;
                                                               aux_as = 1;
                                                           
                                                           }
                                                           index++;
                                                          
                                                      }else{
                                                            
                                                          index++;
                                                          
                                                      }
                                                  } 
                                                  if(aux_as == 0){
                                                  
                                                      perd = 1;
                                                      
                                                  }
                                              
                                              }else{
                                                    
                                                    pasa = 1;
                                                    
                                              }
                                              
                                        }
                                        
                                  }
                                  Oponent.jugada_acabada = 1;
                                  //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                                  Oponents = LlistaPDI_insereix(Oponents, Oponent);
                                  mostra_Cartes(Oponent);
                                     
                                  
                                  
                                  
                                break;
                                
                                
                                case 3:
                                     
                                    pasa = 0;
                                    perd = 0;
                                    //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                                    carta_max = Carta_max(Oponents, Jugador);
                                    //carta_max = 15;
                                    printf("CARTA MAXIMA: %d\n", carta_max);
                                    while(pasa == 0 && perd == 0){
                                    
                                        index = 0;
                                        carta_jug = 0;
                                        //printf("--> %d  ", Oponent.cartes[2].iden);
                                        while(Oponent.cartes[index].iden != 13){
                                        
                                            carta_jug = carta_jug + Oponent.cartes[index].valor;
                                            //printf("valor: %d\n", Oponent.cartes[index].valor );
                                            //printf("total: %d\n", carta_jug );
                                            
                                            index++;
                                            
                                        }
                                        
                                        if((carta_jug < Oponent.cartaMaxima) && carta_jug < 21){
                                        
                                            if(Pila_buida(Baralla) == 1){
                             
                                                 Barallar(&Baralla);
                                 
                                            }
                                                     
                                            iden = Pila_top(Baralla);
                                            //printf("iden nova carta: %d\n", iden);
                                            Pila_pop(&Baralla);
                                            index = 0;
                                            while(Oponent.cartes[index].iden != 13){
                                                
                                                index ++;
                                                
                                            }                                 
                                                                                                                
                                            Oponent.cartes[index] = crea_carta(iden);
                                        
                                        }else{
                                              
                                              if(carta_jug > 21){
                                                           
                                                  index = 0;
                                                  aux_as = 0;
                                                  
                                                  while((Oponent.cartes[index].iden != 13 && index <= 11) && aux_as == 0){
                                                      
                                                      if(Oponent.cartes[index].iden == 0){
                                                      
                                                          if(Oponent.cartes[index].valor == 11){               
                                           
                                                               Oponent.cartes[index].valor = 1;
                                                               aux_as = 1;
                                                           
                                                           }
                                                           index++;
                                                          
                                                      }else{
                                                            
                                                          index++;
                                                          
                                                      }
                                                  } 
                                                  if(aux_as == 0){
                                                  
                                                      perd = 1;
                                                      
                                                  }
                                              
                                              }else{
                                                    
                                                    pasa = 1;
                                                    
                                              }
                                              
                                        }
                                        
                                  }
                                  Oponent.jugada_acabada = 1;
                                  //printf("jugada_acabada ---------->%d\n", Oponent.jugada_acabada );
                                  Oponents = LlistaPDI_insereix(Oponents, Oponent);
                                  mostra_Cartes(Oponent);
                                    
                                    
                                    
                                     
                                    
                                break;
                                
                               
                                   
                             }
                       
                       
                       }
                        
                        printf("%s\t\t\t %d btc \n\n", Jugador.nomJugador, Jugador.aposta);
                       
                       index = 0;
                       
                       while(Jugador.cartes[index].iden != 13 && index <= 11){
                               
                           if(Jugador.cartes[index].iden != 9){
                                                             
                               printf("%c ", Jugador.cartes[index].numero);
                                   
                           }else{
                               
                               printf("10 ");
                               
                           }
                           index++;
                       
                       }
                       printf("\n");
                       
                       do{
                           
                           system("cls");
                           printf("\nCrupier\n\n");
                       
                           index = 1;
                           printf("X ");
                           
                           while(Crupier.cartes[index].iden != 13 && index <= 11){
                                   
                               if(Crupier.cartes[index].iden != 9){
                                                             
                                   printf("%c ", Crupier.cartes[index].numero);
                                   
                               }else{
                               
                                   printf("10 ");
                               
                               }
                               
                               index++;
                           
                           }
                           printf("\n");
                           
                           Oponents = LlistaPDI_vesInici(Oponents);
         
                           while (!LlistaPDI_fi(Oponents)){
                                                 
                               Oponent = LlistaPDI_consulta(Oponents);
                               mostra_Cartes(Oponent);
                               printf("\n\n");
                               Oponents = LlistaPDI_avansa(Oponents);
                               
                           }
                               
                           printf("%s\t\t\t %d btc \n\n", Jugador.nomJugador, Jugador.aposta);
                           
                           index = 0;
                           
                           while(Jugador.cartes[index].iden != 13 && index <= 11){
                               
                               if(Jugador.cartes[index].iden != 9){
                                                             
                                   printf("%c ", Jugador.cartes[index].numero);
                                   
                               }else{
                               
                                   printf("10 ");
                               
                               }
                               
                               index++;
                           
                           }
                           printf("\n\n");
                           
                           
                           printf("Jugador que vols fer?\n");
                           printf("\t1.Demanar Cartes\n");
                           printf("\t2.Plantar-se\n");
                           printf("\t3.Rendir-se\n");
                           printf("\t4.Abandonar Partida\n");
                           scanf("%d", &opcio_joc);
                       
                           if(opcio_joc == 1){
                               
                               if(Pila_buida(Baralla) == 1){
                             
                                   Barallar(&Baralla);
                                 
                               }
                               
                               iden = Pila_top(Baralla);
                               //printf("---->%d\n", iden);
                               Pila_pop(&Baralla);
                               index = 0;
                               carta_jug = 0;
                               while(Jugador.cartes[index].iden != 13){
                                                                  
                                   
                                   carta_jug = carta_jug + Jugador.cartes[index].valor;
                                   printf("carta:%d\n", carta_jug);
                                   index++;
                                                            
                               }
                               Jugador.cartes[index] = crea_carta(iden);
                               
                           
                           }
                           
                           index = 0;
                           carta_jug = 0;
                           while(Jugador.cartes[index].iden != 13){
                                                                  
                                   
                                carta_jug = carta_jug + Jugador.cartes[index].valor;
                                printf("carta:%d\n", carta_jug);
                                index++;
                                                            
                           }
                           
                           if(carta_jug > 21){
                                        
                               index = 0;
                               aux_as = 0;
                                                  
                               while((Jugador.cartes[index].iden != 13 && index <= 11) && aux_as == 0){
                                                      
                                   if(Jugador.cartes[index].iden == 0){
                                       
                                       if(Jugador.cartes[index].valor == 11){               
                                           
                                           Jugador.cartes[index].valor = 1;
                                           aux_as = 1;
                                       
                                       }
                                       index++;
                                                          
                                   }else{
                                                            
                                       index++;
                                                          
                                   }
                               } 
                           }
                           
                           index = 0;
                           carta_jug = 0;
                           while(Jugador.cartes[index].iden != 13){
                                                                  
                                   
                                carta_jug = carta_jug + Jugador.cartes[index].valor;
                                printf("carta:%d\n", carta_jug);
                                index++;
                                                            
                           }
                       
                       }while(opcio_joc == 1 && carta_jug <= 21);  
                       
                       stop = 0;           
           
                       while(stop == 0){
                                                          
                           index = 0;
                           cartes_crupier = 0;
                           
                           while(Crupier.cartes[index].iden != 13){
                                                            
                               cartes_crupier = cartes_crupier + Crupier.cartes[index].valor;
                               index ++;
                               
                           }
                           //printf("\n\nentra\n");
                           carta_min = Carta_min(Oponents);
                           //printf("Cartes CRUPIER: %d\n", cartes_crupier);
                           //printf("\nCARTA MINIMAAAA: %d\n", carta_min);
                           
                           if(cartes_crupier < 17 || cartes_crupier < carta_min){
                               
                               if(Pila_buida(Baralla) == 1){
                             
                                   Barallar(&Baralla);
                                 
                               }
                               
                               iden = Pila_top(Baralla);
                               //printf("---->%d\n", iden);
                               Pila_pop(&Baralla);
                               Crupier.cartes[index] = crea_carta(iden);
                               
                           }else{
                            
                                 if(cartes_crupier > 21){
                                        
                                       index = 0;
                                       aux_as = 0;
                                                          
                                       while((Crupier.cartes[index].iden != 13 && index <= 11) && aux_as == 0){
                                                              
                                           if(Crupier.cartes[index].iden == 0){
                                                              
                                               if(Crupier.cartes[index].valor == 11){               
                                           
                                                   Crupier.cartes[index].valor = 1;
                                                   
                                                   
                                               
                                               }
                                               index++;
                                                                  
                                           }else{
                                                                    
                                               index++;
                                                                  
                                           }
                                       }
                                       
                                 }
                                      
                                     stop = 1;
                                 
                           }
                           
                       }
                               
                           
                           system("cls");
                           printf("Crupier\n\n");
                       
                           index = 0;
                           cartes_crupier = 0;
                           
                           while(Crupier.cartes[index].iden != 13 && index <= 11){
                               
                               cartes_crupier = cartes_crupier + Crupier.cartes[index].valor;    
                               if(Crupier.cartes[index].iden != 9){
                                                             
                                   printf("%c ", Crupier.cartes[index].numero);
                                   
                               }else{
                               
                                   printf("10 ");
                               
                               }
                               index++;
                           
                           }
                           
                           printf("\t\t\t(%d", cartes_crupier);
                           
                           if((index == 2 && cartes_crupier == 21) && (Crupier.cartes[0].iden != 9 && Crupier.cartes[1].iden != 9)){
                   
                                  printf("B)");
                                       
                           }else{
                                 
                                 printf(")");
                           
                           }
                           
                           printf("\n");
                           
                           
                           Oponents = LlistaPDI_vesInici(Oponents);
         
                           while (!LlistaPDI_fi(Oponents)){
                                                 
                               Oponent = LlistaPDI_consulta(Oponents);
                               carta_jug = 0;
                               index = 0;
                               
                               while(Oponent.cartes[index].iden != 13 && index <= 11){
                               
                               carta_jug = carta_jug + Oponent.cartes[index].valor;    
                               index++;
                           
                               }
                               
                               mostra_Cartes(Oponent);
                               
                               if((carta_jug > cartes_crupier && carta_jug <= 21) || (cartes_crupier > 21 && carta_jug <= 21)){
                                    
                                    printf(" Guanya!\n\n");
                               
                               }else{
                                     
                                    printf(" Perd!\n\n");
                               
                               }
                               
                               Oponents = LlistaPDI_avansa(Oponents);
                              
                           }
                           
                           
                               
                           printf("%s\t\t\t %d btc \n\n", Jugador.nomJugador, Jugador.aposta);
                           
                           index = 0;
                           carta_jug = 0; 
                           
                           while(Jugador.cartes[index].iden != 13 && index <= 11){
                               
                               carta_jug = carta_jug + Jugador.cartes[index].valor;
                               if(Jugador.cartes[index].iden != 9){
                                                             
                                   printf("%c ", Jugador.cartes[index].numero);
                                   
                               }else{
                               
                                   printf("10 ");
                               
                               }
                               index++;
                           
                           }
                               
                           if(((carta_jug > cartes_crupier && carta_jug <= 21) || (cartes_crupier > 21 && carta_jug <= 21)) && opcio_joc == 2){
                               
                               printf("\t\t\t (%d", carta_jug);
                               
                               if((index == 2 && carta_jug == 21) && (Jugador.cartes[0].iden != 9 && Jugador.cartes[1].iden != 9)){
                   
                                      printf("B)");
                                           
                               }else{
                                     
                                     printf(")");
                                     
                               }
                               
                               printf("Guanya!\n\n");
                               
                               
                               perd = 0;
                               Jugador.diners = Jugador.diners + (Jugador.aposta*2);
                               Jugador.p_guanyades = Jugador.p_guanyades + 1;              
                               
                           }else{
                               
                               
                               printf("\t\t\t (%d)", carta_jug);
                               printf("Perd!\n\n");
                               
                               perd = 1;
                               Jugador.p_perdudes = Jugador.p_perdudes + 1;
                               
                           }
                           if(ma_max < carta_jug && carta_jug <= 21){
                                     
                                ma_max = carta_jug;
                                
                           }
                           
                                //Jugador.progresio_diners + 1 = Jugador.diners;
                           
                           if(opcio_joc != 4){
                                        
                               Fitxer_actualitza(Jugador);
                                        
                               do{
                                  if(perd == 0){
                                      
                                      printf("%s ha guanyat!\n", Jugador.nomJugador);      
                                      printf("Beneficis = %d\n", Jugador.aposta * 2);
                                      printf("Total = %d\n", Jugador.diners);
                                      printf("Mans guanyades = %d\n", Jugador.p_guanyades);
                                      printf("Mans perdudes = %d\n", Jugador.p_perdudes);
                                  
                                  }else{
                                  
                                      printf("%s ha perdut!\n", Jugador.nomJugador);      
                                      printf("Perdues = %d\n", Jugador.aposta);
                                      printf("Total = %d\n", Jugador.diners);
                                      printf("Mans guanyades = %d\n", Jugador.p_guanyades);
                                      printf("Mans perdudes = %d\n", Jugador.p_perdudes);
                                      
                                  }   
                                   
                                  fflush(stdin);
                                  printf("Vols tornar a jugar (S/N)?\n");
                                  scanf("%c", &s_n);
                                  
                                  if(s_n != 'n' && s_n != 'N' && s_n != 's' && s_n != 'S'){
                                         
                                         printf("Opcio incorrecta");
                                         
                                         
                                  }
                                  
                               }while(s_n != 'n' && s_n != 'N' && s_n != 's' && s_n != 'S');
                           
                           }else{
                                 
                                 s_n = 'n';
                                 
                           }
         
                    }while(s_n != 'n' && s_n != 'N');                 
                       
             
                   
              break;
              
              case 3:
                   
                   Jugador = Llegeix_jugador(Jugador);
                   system("cls");
                   
                   do{
                   
                      printf("\nInformacio de l'usuari\n");
                      printf("-----------------------------\n");
                      printf("Nom: %s\n", Jugador.nomJugador);
                      printf("Partides Jugades: %d\n", Jugador.p_guanyades + Jugador.p_perdudes);
                      printf("Partides guanyades: %d\n", Jugador.p_guanyades);
                      printf("Partides perdudes: %d\n", Jugador.p_perdudes);
                      printf("Millor jugada: %d", ma_max);
                               
                      fflush(stdin);
                      printf("\n\nMostrar l'evolucio de diners?\n");
                      scanf("%c", s_n);
                                  
                      if(s_n != 'n' && s_n != 'N' && s_n != 's' && s_n != 'S'){
                                         
                          printf("Opcio incorrecta");
                                                        
                      }
                                  
                   }while(s_n != 'n' && s_n != 'N' && s_n != 's' && s_n != 'S');     
                   
                   
              break;
              
              case 4:
                   
                   printf("YEEEEE CHAO PESCAOOO\n");
                   LlistaPDI_destrueix(&Oponents);
                   Pila_destrueix(&Baralla);
              
              break;
              
              default:
                      
                      printf("\nPutu monguer, tant dificil es triar una opcio entre l'1 i el 4? \n\n");
                      
              break;              
              
              }
     
        }

   }while(opcio != 4);


  
  system("PAUSE");	
  return 0;
}
