/*

Es una estructura de datos que deriva de una secuencia 
conectada de nodos, y cada uno de los cuales
contiene un dato

Hay un nodo al comienzo llamado la cabeza o frente
Hay un nodo de termino llamada la cola o atras

La lista solo puede ser recorrida en secuencia atras 
o hacia adelante



Operaciones de la estructura

Añadir o insertar elemento
eliminar o Borrar elemento
moverme eatraves de la lista desde el primero al ultimo
Buscar elementos
&
**
*elemento   apuntador memoria(direccion de memoria / el peso)
.elemento 

list    es una clase templete que nos permite
crear listas que contengan cualquier tipo de objeto

incluye las operaciones

push  meter

pop   sacar

begin()
end()

size()   tamaño

empty()  vacio




*/


#include<iostream>

using namespace std;

//definir la estructura de la lista
struct Nodo{
	//los datos de la lista
	int valor;
	Nodo *siguiente;
};

//metodo para insertar
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);

int main(){
	//declarar mi variable de la lista
	Nodo *lista = NULL;
	
	//variables
	int op = 1, c, i = 0, valores;
	
	cout<<"Trabajando con listas (simples, doblemente enlazadas, circulares y circulares dobles"<<endl;
	while(op!=3){
		cout<<"Ejemplo de lista simple"<<endl;
		cout<<"1.- Insertar nuevo valor en la lista"<<endl;
		cout<<"2.- Ver la lista"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Indica el numero de valores a introducir\n";
				cin>>valores;
				while lores){
					cout<<"Valor["<<i<<"]\n";
					cin>>c;
					//mando a llmar al metodo para insertarlo
					insertarLista(lista, c);
					i++;
				}
				break;
			case 2:
				cout<<"Ver elementos de la lista\n";
				cout<<"Pendienten";
				break;
			default:
				cout<<"Gracias por estar aqui uwu";
			
		}
		
	}
	return 0;
		
}

void insertarLista(Nodo *&lista, int c){
		Nodo *inslista = new Nodo();
		inslista->valor = c;
		//necesito un auxiliar para encadenar los valores de la lista
		Nodo *aux = lista;
		Nodo *aux2;
		
		//se meten ordenados los datos
		while((aux!=NULL)&&(aux->valor<c)){
			aux2=aux;
			aux = aux->siguiente;
		}
		
		if(inslista == aux){
			lista = inslista;
		}else{
			aux2->siguiente = inslista;
		}
		
		inslista->siguiente=aux; 
		cout<<"Elemento: "<<c<<" insertado"<<endl;
	}
	
	
	void mostrarLista(Nodo *lista){
		Nodo * recurso = new Nodo();
		recurso = lista;
		
		//imprimir los valores
		while(recurso!=NULL){
			cout<<recurso->valor<<endl;
			recurso=recurso->siguiente;
		}
	}
	
	//tarea 
	/*
	imprimir la lsita y hacer que se borre un elemento 
	de la lsita que sea el ultimo
	*/











