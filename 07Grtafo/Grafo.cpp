/*
Vamos a crear un grafo que tiene los siguientes nodos

5 3
1 2
2 3
4 5  FUERA DE LA MATRIZ

*/

#include<stdio.h>
#include<vector>
#include<cstring>

//sirve para poder hacer operaciones con cadenas
//para manipular elementos de caracteres bajo matriz


//debemos asignar un espacio de memoria para
//las operaciones, de ahi el vector

using namespace std;

#define MAX 10001

vector<int> ady[MAX];

/*
tenemos que tener una variable que se encargue de
detectar el recorrido de los nodos y del camino que ya se
visito
*/


bool visitado[MAX];

bool visitado_componente[MAX];


//debemos realizar un algoritmo para el recorrido

void dfs(int u){
	//saber si ya visite el camino (arista)
	visitado[u] = true;
	//saber si ya visite el nodo
	visitado_componente[u]= true;
	//ciclo de recorrido
	for(int v=0; v<ady[u].size(); v++){
		if(!visitado[ady[u][v]]){
			dfs(ady[u][v]);
		}
	}
}


int main(){
	//variables para el grafo
	int V, E, u, v;
	
	printf("Hola escribe algo\n");
	//elementos para la memoria
	scanf("%d, %d", &V, &E);
	
	//ahor avamos a crear un bucle
	//que se encargue de entrar
	//y salir meter y sacar
	
	while(E--){
		scanf("%d, %d", &u, &v);
		ady[u].push_back(v);
		ady[u].push_back(u);
	}
	
	printf("Cantidad de componentes conexos\n");
	int total = 0;
	
	/*
	con esto puedo saber cuanto pesa cada uno
	de los caminos de mi grafo
	primero el camino, el inicio, su peso
	o tamaño
	*/
	
	memset(visitado, 0, sizeof(visitado));
	
	//tenemos que recorrer todos los caminos
	//posibles de cada nodo
	
	for(int i = 1; i<=V; ++ i){
		if(!visitado[i]){
			memset(visitado_componente, 0, sizeof(visitado_componente));
			dfs(i);
			/*
			recorrer cada nodo y con ello
			saber como se forma el grafo
			al imprimir cada componente del vertice
			*/
			printf("Componente: %d", total+1);
			//recorrer los valores de cada vertice
			for(int j = 1; j<=V; ++j){
				if(!visitado_componente[j]){
					printf("%d", j);
				}
			}
			printf("\n");
			total++;
			
		}
	}
	printf("%d\n", total);
	return 0;
	
	
}




