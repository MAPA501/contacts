
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datos
{   char cname[30];
    unsigned long cphone;
}datos;

typedef struct tnode
{    datos cnt; 
    struct tnode *link;
}tnode;

tnode *head = NULL;
tnode *footer = NULL;

tnode* creanode(){ //estructura de creacion de nodo
    tnode *Nnode =(tnode*)malloc(sizeof(tnode)); //alocacion de memoria del nuevo nodo y casting 
    if(Nnode==NULL) printf("memoria insuficiente\r\n");
    return(Nnode); 
}

// crea un nuevo nodo,lo modifica y lo agrega a  la lista como el nodo final.
void nuevocontacto(){
    tnode *nvnode=creaNode();
     unsigned long num;
    if (nvnode!=NULL){
        fflush(stdin);
        printf("Ingrese nombre: ");
        gets(nvnode->cnt.cname);
        fflush(stdin);
        printf("Ingrese numero: ");
        scanf("%ld", &num);
        nvnode->cnt.cphone=num;

        
        if(head==NULL){ 
            nvnode->link=NULL; 
            head=nvnode; 
            footer=nvnode;
            return; 
        }
        nvnode->link = NULL;
        footer->link=nvnode;     
        footer=nvnode;
    }
}


void walkList(){ // recorre la lista y muestra los valores guardados en los nodos.
    tnode *nodoact =head; 
while(nodoact != NULL){

    printf("Nombre: %s\r\n",nodoact->cnt.cname);
    printf("Telefono: %ld\r\n\r\n",nodoact->cnt.cphone);
    nodoact=nodoact->link; 
    }
printf("No hay contactos para mostrar.\r\n");
}
 


 
void freeList(){  // al salir del programa tambien es liberada la memoria usando esat funcion.
    tnode* aux = head;
    if(aux == NULL){
        printf("No hay contactos.r\n");
        return;
    }

while(aux!=NULL){
    head=aux->link;
    free(aux); 
    aux=head; 
    }
    head = NULL;
    footer = NULL;
    printf("Memoria Liberada\r\n");
}



int main(){
    char x;
    printf("            |||agenda telefónica|||         \r\n");
    


    while (1)
    {
        printf("\r\n\tseleccione una opción:\r\n");
        printf("1. añadir un contacto \r\n2. ver todos los contactos\r\n3. eliminar lista de contactos\r\n4. eliminar un numero\r\n5. salir\r\n");
        scanf("%d", &x);
        getchar();
        switch (x)
        {
        case 1:
            nuevocontacto();
            break;
        
        case 2:
            walkList();
            break;
        case 3:
            freeList();
            break;
        case 4:
            deleteNumber();
            break;
            
        case 5:
            freeList();
            return -1;
            break;
        default:
            printf("opción invalida, intente nuevamente.");
            break;
        }
    }
    return 0;
}