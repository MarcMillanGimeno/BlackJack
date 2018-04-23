#include "Fitxers.h"
#include "Tipus.h"
#include "Llista.h"

LlistaPDI Llegeix_oponents(LlistaPDI I){
          
          FILE* f_o;
          Oponent o;
          int n_o, salt_linea, aux;
          char aux_nom[100], aux_caracter[20];
          
          f_o = fopen("oponents.txt", "r");
          I = LlistaPDI_vesInici(I);
          
          if (f_o == NULL){
             
             printf("Error al obrir el fitxer d'oponents");
           
          }else{

                fscanf(f_o, "%d", &n_o);
                for(n_o; n_o > 0; n_o--){
                    
                    fscanf(f_o, "%d", &salt_linea);
                    fgets(aux_nom, 100, f_o);
                    aux_nom[strlen(aux_nom)-1] = '\0';
                    strcpy(o.nomOponent,aux_nom);
                    //printf("---%s\n", aux_nom);
                    
                    
                    fscanf(f_o, "%d", &aux);
                    o.diners = aux;
                    //printf("---%d\n", aux);
                    
                    fscanf(f_o, "%d", &salt_linea);
                    fgets(aux_caracter, 20, f_o);
                    aux_caracter[strlen(aux_caracter)-1] = '\0';
                    strcpy(o.tipusOponent,aux_caracter);
                    //printf("---%s\n", aux_caracter);
                    
                    
                    fscanf(f_o, "%d", &aux);
                    o.cartaMaxima = aux;
                    //printf("---%d\n", aux);
                    
                    I = LlistaPDI_insereix(I, o);
                    
                }
           }
           fclose(f_o);
           return I;
}
                    
Jugador Llegeix_jugador(Jugador j){
    FILE* f_u;
    char aux_nom[100];
    int aux, index;
     
    f_u = fopen("usuari.txt", "r");
          
    if (f_u == NULL){
             
        printf("Error al obrir el fitxer d'usuari");
           
    }else{
    
        fgets(aux_nom, 100, f_u);
        aux_nom[strlen(aux_nom)-1] = '\0';
        strcpy(j.nomJugador,aux_nom); 
        
        fscanf(f_u, "%d", &aux);
        j.diners = aux;
        
        fscanf(f_u, "%d", &aux);
        j.p_guanyades = aux;
        
        fscanf(f_u, "%d", &aux);
        j.p_perdudes = aux;
        index = 0;
        /*
        while(!feof(f_u)){
                         
             fscanf(f_u, "%d", &aux);
             j.progresio_diners[index] = aux;
             
             index ++;
             
        }
    */
    }
    fclose(f_u);
    return j;   
}  
                    
                   
void Fitxer_actualitza(Jugador j){
  
     FILE* f_u;
     char aux_nom[100];
     int aux, index;
     
     f_u = fopen("usuari.txt", "w");
          
     if (f_u == NULL){
             
        printf("Error al obrir el fitxer d'usuari");
           
     }else{
     
     
         fprintf(f_u, "%s\n", j.nomJugador);
         fprintf(f_u,"%d\n", j.diners);
         fprintf(f_u, "%d\n", j.p_guanyades);
         fprintf(f_u, "%d\n", j.p_perdudes);
     
     }
     fclose(f_u);
     
}
   
                   
                    
                    
                    
                    
                    
                    
                    
                    
                    
