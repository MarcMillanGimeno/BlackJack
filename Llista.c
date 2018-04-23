#include "Llista.h"
#include "Tipus.h"

LlistaPDI   LlistaPDI_crea(){
    
    LlistaPDI I;
    
    I.pri = (Node2*) malloc (sizeof(Node2));
    if(I.pri == NULL){
    
        printf("Error al crear llista\n");
        
    }else{
    
        I.pri->oponent = Fantasma();
        I.pri->seg = NULL;
        I.ant = I.pri;
        
    }
    return I;
    
}
LlistaPDI    LlistaPDI_insereix(LlistaPDI I, Oponent o){
             
    Node2 *aux;
    aux = (Node2*) malloc(sizeof(Node2));
    
    if(aux == NULL){
           
           printf("Error al inserir a la llista\n");
           
    }else{
          
           aux->oponent = o;
           aux->seg = I.ant->seg;
           I.ant->seg = aux;
           I.ant = aux;
           
    }
    
    return I;
    
}
 
LlistaPDI LlistaPDI_esborra(LlistaPDI I){
          
    Node2 *aux;
    
    if(I.ant->seg == NULL){
    
        printf("Error al esborrar\n");
        
    }else{
          
          aux = I.ant->seg;
          I.ant->seg = aux->seg;
          free(aux);
          
    }
    return I;

}

Oponent LlistaPDI_consulta(LlistaPDI I){
        
        Oponent o = Fantasma();
        if(I.ant->seg != NULL){
            //printf("consulta");           
            o = I.ant->seg->oponent;
            
        }
        return o;

}

int   LlistaPDI_buida(LlistaPDI I){
      
      return I.pri->seg == NULL;
      
}

LlistaPDI LlistaPDI_vesInici(LlistaPDI I){
          
    I.ant = I.pri;
    return I;
    
}

LlistaPDI LlistaPDI_avansa(LlistaPDI I){
          
    if(I.pri->seg != NULL){
    
       I.ant = I.ant->seg;
       
    }
       
    return I;
       
}

int   LlistaPDI_fi(LlistaPDI I){   
      
      return I.ant->seg == NULL;
      
}

void   LlistaPDI_destrueix(LlistaPDI *I){
          
    Node2 *aux;
    
    while(I->pri != NULL){
          
          aux = I->pri;
          I->pri = I->pri->seg;
          free(aux);
          
    }
    I->ant = NULL;  
}

Oponent Fantasma(){

    Oponent o;
    
    strcpy(o.nomOponent, "Fantasma");
    o.diners = -1;
    strcpy(o.tipusOponent, "Fantasma");
    o.cartaMaxima = -1;
    
    return o;
    
}
    
    
    
    
    
    
    
    
    
    
    
    
    
