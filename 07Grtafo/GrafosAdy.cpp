#include <iostream>
#include <queue> //cola
#include <stack> //pila

/*
vamos a crear un grafo que pueda determinar la 
busqueda de nodos para su recorrido
*/

using namespace std;

class Grafo{
	private:
		int vertice, arista;
		int **adyMatriz; 
		int *visitado;
		
		/*Cuando tenemos un doble apuntador
		este esta obteniendo tanto
		el dato como el espacio de memoria*/
		
	public :
		//constructor
		Grafo(int ver, int arc):vertice(ver), arista(arc){
			//estos son los constructores del metodo
			adyMatriz = new int *[ver];
			for(int i = 0; i < vertice; i++){
				adyMatriz[i] = new int [vertice];
				for(int j = 0; j < vertice; j++){
					adyMatriz[i][j] = 0;
				}
				
			}
			visitado = new int[vertice];
		}
		
		void visitados(){
			for(int i = 0; i < vertice; i++){
				visitado[i] = 0;
			}
		}
		
		//destructor
		~Grafo(){
			for(int i = 0; i < vertice; i++){
				delete[] adyMatriz[i];
				
			}
			
			delete[] adyMatriz;
				
		}	
		
		void crear_grafo(){
			for(int i = 0; i <vertice; i++){
				for(int j = 0; j < vertice; j++){
					cin>>adyMatriz[i][j];
					//meto coordenadas
				}
			}
		}
		
		void agregarArista(int i, int j){
			if(i >= 0 && i < vertice && j > 0 && j < vertice){
				adyMatriz[i][j] = 1;
			}
		}
		
		void removerArista(int i, int j){
			if(i >= 0 && i < vertice && j > 0 && j < vertice){
				adyMatriz[i][j] = 0;
			}
		}
		
		//saber si pase por la arista
		bool esArista(int i, int j){
			if(i >= 0 && i < vertice && j > 0 && j < vertice){
				return adyMatriz[i][j];
			}else{
				return false; 
			}
		}
		
		void profundidad(int nodo){
			visitado[nodo] = 1;
			cout<<nodo<<"  ";
			//recorrer los nodos visitados
			for(int i = 0; i < vertice; i++){
				if(adyMatriz[nodo][i] && !visitado[i]){
					profundidad(i);
				}
			}
		}
		
		void profundidadI(int nodo){
			visitados();
			//ahora necesito mi pila
			stack<int> pila;
			pila.push(nodo);
			visitado[nodo] = 1;
			
			//mientras la pila no este vacia debo 
			//recorrer los elementos
			while(!pila.empty()){
				int elemento = pila.top();
				//lo saco
				pila.pop();
				cout<<elemento<<" ";
				
				for(int i = 0; i < vertice; i++){
					if(adyMatriz[elemento][i]){
						if(!visitado[i]){
							pila.push(i);
						}
						visitado[i] = 1;
					}
				}
			}
			
		}
		
		void anchura(int nodo){
			visitados();
			visitado[nodo] = 1;
			
			//necesito a la cola
			queue<int> cola;
			cola.push(nodo);
			
			while(!cola.empty()){
				int elemento = cola.front();
				cola.pop();
				cout<<elemento<<" ";
				for(int i = 0; i < vertice; i++){
					if(adyMatriz[elemento][i] && !visitado[i]){
						cola.push(i);
					}
					visitado[i] = 1;
				}
			}
		}
};

int main(){
	int ver, arc;
	cout<<"Numero de vertices: \n";
	cin>>ver;
	cout<<"Numero de aristas: \n";
	cin>>arc;
	
	//al grafo
	Grafo gh(ver, arc);
	
	cout<<"Creacion del grafo \n";
	gh.crear_grafo();
	
	cout<<"Busqueda en anchura \n";
	gh.anchura(0);
	cout<<endl;
	
	cout<<"busqueda en profundidad: \n";
	gh.visitados();
	cout<<endl;
	gh.profundidad(0);
	cout<<endl;
	gh.profundidadI(0);
	cout<<endl;
	
	
}
