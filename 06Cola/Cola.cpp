/*
Ejemplo de una cola
primeras entradas
primeras salidas

*/

#include<iostream>

using namespace std;

//estructura
struct nodo{
	int nro; 
	struct nodo *siguiente;
};


//estrucutra cola
struct cola{
	nodo *delante;
	nodo *atras;
};


//encolar
void encolar(struct cola &q, int valor){
	//lo que hay adentro de la cola
	struct nodo * aux = new(struct nodo);
	
	aux->nro = valor;
	aux->siguiente = NULL;
	
	if(q.delante == NULL){
		q.delante = aux; //encolar el primer elemento
	}else{
		(q.atras)->siguiente = aux;
	}
	//el puntero siempre apunta al ultimo
	q.atras = aux;
}

//desencolar
int desencolar(struct cola &q){
	int num;
	struct nodo *aux;
	
	//aux apunte al inicio de la cola
	aux = q.delante;
	num = aux->nro;
	//dale delete a aux
	delete(aux);
	
	return num;
}


//mostrar colita
void muestraCola(struct cola q){
	//nodo auxiliar
	struct nodo *aux;
	
	//siempre el nodo hasta adelante
	aux = q.delante;
	////cola vacia?
	while(aux!=NULL){
		cout<<" "<<aux->nro;
		//recorrer 
		aux = aux->siguiente;
	}
}

//vaciar la cola, eliminar todos
void vaciarCola(struct cola &q){
	//auxiliar para eliminar cada elemento
	struct nodo * aux;
	//si esta vacia?
	while(q.delante!=NULL){
		aux = q.delante;
		q.delante = aux->siguiente;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;
}

void menu(){
	cout<<"\nEjemplo de una colita kawaii\n";
	cout<<"1.- Encolar\n";
	cout<<"2.- Desncolar\n";
	cout<<"3.- Mostrar cola\n";
	cout<<"4.- Vaciar cola\n";
	cout<<"5.- Salir\n";
}

int main(){
	//primero declaramos la cola
	struct cola q;
	
	//defino la cola con sus apuntadores
	q.delante = NULL;
	q.atras = NULL;
	
	//datos
	int dato;
	int op;
	int x; //funcion de pop a la cola
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a Encolar: \n";
				cin>>dato;
				encolar(q, dato);
				cout<<"\n Numero : "<<dato<<" encolado...\n";
				break;
			
			case 2:
				x = desencolar(q);
				cout<<"\n Numero: "<<x<<" desencolado..\n";
				break;
				
			case 3:
				cout<<"\n Mostrar cola: \n";
				//saber que no este null
				if(q.delante != NULL) muestraCola(q);
				else cout<<"\n Cola Vacia..\n";	
				break;
			
			case 4: 
				vaciarCola(q);
				cout<<"\n Colita se vacio..\n";
				break;
		}
	}while(op!=5);
	
	return 0;
	
}


