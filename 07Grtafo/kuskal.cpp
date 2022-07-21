/*
algoritmo kruskal

ejemplo a la entrada
9 14 n v
1 2 4
1 8 9 
2 3 9
2 8 11
3 4 7
3 9 2
3 6 4
4 5 10
4 6 15
5 6 11
6 7 2
7 8 1
7 9 6
8 9 7

*/

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX 1005 //numero max de vertices

//meter un arreglo que contiene el padre del i-esimo nodo
int padre[MAX];

//inicializamos el algoritmo
void inicializar(int n){
	for(int i = 1; i<=n; ++i){
		padre[i] = i;
	}
}

//metodo para encontrar la raiz del vertice
int encontrar(int x){
	return (x == padre[x])? x : padre[x] = encontrar(padre[x]);
}

//unir los vertices conexos
void Union(int x, int y){
	padre[encontrar(x)] = encontrar(y);
}

//metodo que me determine si 2 vertices
//estan o no en el mismo componente
bool mismocomponente(int x, int y){
	if(encontrar(x) == encontrar(y)) return true;
	return false;
}

//variables globales

int V, E;

//crear una estructura de la arista v_origen, v_destino, peso

struct Arista{
	int origen;
	int destino;
	int peso;
	//comparador que me sirva para ordenar el ascenso o descenso
	//inicializador
	Arista(){
	}
	bool operador<(const Arista &e) const{
		return peso < e.peso;
	}
}arista[MAX];  //necesito un arreglo de aristras para el uso del algoritmo

//arreglo de aristas del MST para encontrar 
Arista MST[MAX]; //aristas mas cortas


//algoritmo
void Kruskal(){
	int origen, destino, peso;
	int total = 0;   //peso total del MST
	int numAristas = 0;  //numero de aristas del MST
	
	//inicializamos cada componente
	inicializar(V);
	//ordenamos las aristas por su comparador
	std::sort(arista, arista + E);
	
	//recorrer las aristas ya ordenadas por su peso
	for(int i = 0; i < E; ++i){
		origen = arista[i].origen;
		destino = arista[i].destino;
		peso = arista[i].peso;
		
		//verificar si estan o no en la misma componente conexa
		if(!mismocomponente(origen, destino)){
			//evitar los ciclos o bucles
			//incrementar el peso total del MST
			total += peso;
			//agregar al M ST la arista actual
			MST[numAristas++] = arista[i];
			//unir ambos componentes en uno solo
			Union(origen, destino);
		}
	}
	
	/*
	si el MST no posee todos los vertices, entonces
	mostramos un mensaje de error
	porque debemos saber si contiene o no todos los vestices 
	con el numero de aristas que sea igual
	al numero de vertices -1
	
	*/
}




