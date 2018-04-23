#include "Pila.h"
#include <time.h>
#include <stdio.h>
#include "Tipus.h"

Pila Pila_crea(){
     
     return NULL;
     
}

void Pila_push(Pila *p, int iden){
     
     Node1 *aux;
     aux = (Node1*) malloc (sizeof(Node1));
     
     if(aux == NULL){
     
           printf("Error al fer el push\n");
            
     }else{
           
           aux->iden = iden;
           aux->seg = *p;
           *p = aux;
           
     }
}

void Pila_pop(Pila *p){
     
     Node1 *aux;
     
     if(*p == NULL){
     
           printf("Error, pila buida\n");
     
     }else{

           aux = *p;
           *p = (*p)->seg;
           free(aux);

     }
}

int Pila_top(Pila p){
    int aux;
    
    if(p != NULL){

         aux = p->iden;

    }
    
    return aux;

}

int Pila_buida(Pila p){
    
    return p == NULL;
    
}

void Pila_destrueix(Pila *p){
     
     Node1 *aux;
     
     while(*p != NULL){

           aux = *p;
           *p = (*p)->seg;
           free(aux);

     }
}

Pila Barallar(Pila *p){
     
     int b[13], i, no_buida, casella, acabada, iden, num_baralles;
   
     
     do{

        printf("Quantes baralles vols barrejar?\n");
        scanf("%d", &num_baralles);
        if(num_baralles < 0 || num_baralles > 4){
                     
            printf("\nError, nombre de baralles incorrecte [1-4].\n\n");
                       
        }else{
        
            for(i = 0; i <=12; i++){
           
                b[i] = (4 * num_baralles);
           
            }
         
            printf("Baralleeeeemmm\n"); 
            do{
           
                no_buida = 0;
                do{
                  
                  acabada = 0;
                  casella = rand() % 13;
                  
                  if(b[casella] == 0){
                  
                      acabada = 1;
    
                  
                  }else{
                        
                      printf("------------casella = %d---------\n", casella);
                      iden = casella;
                      acabada = 0;
                      Pila_push(p, iden);
                      b[casella] --;
                      
                  }
                  
               }while(acabada != 0);
               
         
               for(i = 0; i <=12; i++){
               
                     if(b[i] != 0){
                     
                             no_buida = 1;
                     
                     }
                     
               }
     
           }while(no_buida == 1);
     
         }
                    
      }while(num_baralles < 0 || num_baralles > 4);
       
     
}   











