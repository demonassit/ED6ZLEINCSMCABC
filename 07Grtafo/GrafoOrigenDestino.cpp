/*
Ejemplo de un grafo que se encarga de todos los caminos o las
conexiones que tendra un grafo que se encargue de la
busqueda de la anchura dde sus nodos
*/

#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 500

//vector
vector<int> ady[MAX];
//pasa saber si el nodo ya fue visitado
bool visitado[MAX];

void bfs(){
	int ini, fin;
	
	printf("Nodo raiz: \n");
	scanf("%d", &ini);
	//%d es enteros %f es flotantes %s cadenas %c caracteres
	
	printf("Nodo final: ");
	scanf("%d", &fin);
	
	//creamos una cola para almancenar los nodos del grafo
	queue<int> Q;
	
	//contar los pasos del recorrido del grafo
	Q.push(ini);
	
	//mientras exista otro nodo
	//mientras la cola no este vacia
	
	int pasos = 0, maxi = 0;
	
	while(!Q.empty()){
		//saber si la memora de la cola la estoy usando respecto
		//del tamaño
		
		maxi = max(maxi, (int)Q.size());
		
		int actual = Q.front(); Q.back();
		
		pasos++;
		
		if(actual == fin) break;
		
		
		//tengo que saber donde estoy
		visitado[actual] = true;
		//contador para saber donde he estado
		for(int i = 0; i < ady[actual].size(); ++i){
			
			//saber si tiene nodos adyacente
			if(!visitado[ady[actual][i]]){
		
			
				//si obtengo i nos va a decir la posicion de donde
				//se encuentra el nodo
				printf("%d  -->   %d", actual, ady[actual][i]);
				//se mete a la cola
				Q.push(ady[actual][i]);
			}
		}
	}
	
	printf("Memoria Maxima de uso: %d\n ", maxi);
	printf("Numero de pasos que ha dado: %d\n ", pasos);
}

int main(){
	
	//variables del grafo
	int V, E, x, y;
	
	printf("Ingresa el numero de vertice y arista: \n");
	scanf("%d %d", &V, &E);
	
	//recorremos su origin y fin
	
	for(int i = 1; i <= E; ++i){
		//necesitamos su origen y destino
		printf("Ingresa el nodo de origin y destino:\n");
		scanf("%d %d", &x, &y);
	}
	bfs();
	
	return 0;
	
}


