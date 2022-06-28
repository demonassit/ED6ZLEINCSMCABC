/*
vamos a ver una cola que se aitende 
por prioridades
*/


#include <iostream>
#include<stdlib.h>

using namespace std;

//definir el nodo

struct nodo{
	char dato;
	int priori;
	struct nodo *siguiente;
};

//la cola

struct cola{
	nodo *delante;
	nodo *atras;
};

//crear nodo

struct nodo*crearNodo(char x, int pri){
	struct nodo *nuevoNodo = new(struct nodo);
	nuevoNodo->dato = x;
	nuevoNodo->priori = pri;
	return nuevoNodo;
}

void encolar(struct cola &q, char valor, int priori){
	//auxiliar para mover el nodo
	struct nodo *aux = crearNodo(valor, priori);
	aux->siguiente = NULL;
	
	if(q.delante == NULL){
		//el primero en encolar
		q.delante = aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//siempre debe apuntar al ultimo
	q.atras = aux;
}


//mostrar la cola
void muestraCola(struct cola q){
	struct nodo *aux;
	
	aux = q.delante;
	
	cout<<"\n Caracter de Prioridad\n";
	
	while(aux"=NULL"){
		cout<<" "<<aux->dato<<" | "<<aux->priori<<endl;
		aux = aux->siguiente;
	}
}

//definri una prioridad 
//criterio 0

void ordenarPrioridad(strcut cola &q){
	//metodo de burbuja
	
	//necesito dos aux
	struct nodo *aux1, *aux2;
	int p_aux;
	char c_aux;
	
	//aux1 va a ser mi colita con los datos
	aux1 = q.delante;
	
	while(aux1->siguiente !=NULL){
		//comparar aux1 vs aux2
		aux2 = aux1->siguiente;
		while(aux2 !=NULL){
			
			if(aux1->priori > aux2->priori){
				p_aux = aux1->priori;
				c_aux = aux1->dato;
				
				aux1->priori = aux2->priori;
				aux1->dato = aux2->dato;
				
				aux2->priori = p_aux;
				aux2->dato =  c_aux;
			}
		}
	}
}


