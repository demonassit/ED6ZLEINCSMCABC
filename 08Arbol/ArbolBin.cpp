/*
Ejemplo de un arbol binario
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


//vamos a crear la estructura de la base de un arbol
struct nodo{
	//primero el dato
	char dato;
	//nodo derecho 
	struct nodo *der;
	//nodo izquierdo
	struct nodo *izq;
};
//poder operar con las ramas izq y der
typedef struct nodo _nodo;

//vamos a crear una definicion de la 
//operacion de las ramas izq y der

_nodo *crear(char dato){
	_nodo *nuevo;
	//necesitamos solicitar
	//el tamaño de la estructura
	//cuando se reserva de memoria
	//sizeof
	nuevo = (_nodo*)malloc(sizeof(_nodo));
	nuevo -> dato = dato;
	nuevo -> der = NULL;
	nuevo -> izq = NULL;
	
	return nuevo;
}


//metodo para agregar derecha

_nodo *agregarDerecha(_nodo *nuevo, _nodo *raiz){
	raiz -> der = nuevo;
	return raiz;
}

//metodo para agregar izq

_nodo *agregarIzquierda(_nodo *nuevo, _nodo *raiz){
	raiz -> izq = nuevo;
	return raiz;
}

//vamos a imprimir el arbol
void imprimir(_nodo *nodo){
	//tenemos que saber si esta vacio
	if(nodo != NULL){
		printf(" %c ", nodo->dato);
	}
}

//preorden

void preOrden(_nodo *raiz){
	//nodo actual, rama izq, rama der
	if(raiz != NULL){
		imprimir(raiz);
		//recursividad
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

//in orden

void inOrden(_nodo *raiz){
	//nodo izq, raiz, rama der
	if(raiz != NULL){
		
		//recursividad
		inOrden(raiz->izq);
		imprimir(raiz);
		inOrden(raiz->der);
	}
}

//post orden

void posOrden(_nodo *raiz){
	//nodo izq, der, raiz
	if(raiz != NULL){
		
		//recursividad
		posOrden(raiz->izq);
		posOrden(raiz->der);
		imprimir(raiz);
		
	}
}

int main(){
	_nodo *raiz;
	raiz = crear('+');
	raiz -> izq = crear('*');
	raiz -> der = crear('=');
	
	raiz -> izq -> izq = crear('A');
	raiz -> izq -> der = crear('B');
	
	raiz -> der -> izq = crear('/');
	
	raiz -> der -> izq -> izq = crear('C');
	raiz -> der -> izq -> der = crear('D');
	
	raiz -> der-> der = crear('2');
	
	//imprimimos arbolito de navidad
	printf("Preorden (RID): \n ");
	preOrden(raiz);
	
	printf("\n Inorden (IRD): \n ");
	inOrden(raiz);
	
	printf("\nPosorden (IDR): \n ");
	posOrden(raiz);
	
	return 0;
}



