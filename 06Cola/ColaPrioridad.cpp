/*
Ejemplo de cola con prioridades
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//vamos con la estructura nodo

struct nodo{
	char dato;
	int prioridad;
	struct nodo * siguiente;
};


//estructura de la cola
struct cola{
	nodo *delante;
	nodo *atras;
};

//funcion para crear un nodo nuevo

struct nodo *crearNodo(char x, int pri){
	//vamos a crear ese nuevo nodo
	struct nodo *nuevoNodo = new (struct nodo);
	nuevoNodo->dato=x;
	nuevoNodo->prioridad=pri;
	return nuevoNodo;
}


void encolar(struct cola &q, char valor, int priori){
	//necesito mi auxiliar
	struct nodo *aux = crearNodo(valor, priori);
	aux->siguiente=NULL;
	
	if(q.delante == NULL){
		//es el primero en encolar
		q.delante=aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//siempre el aux debe apuntar al final
	q.atras = aux;
}


void mostrarCola(struct cola q){
	//auxliar
	struct nodo *aux;
	
	aux = q.delante;
	
	cout<<"\n Caracter de Prioridad\n";
	
	while(aux!=NULL){
		//hay datos
		cout<<" "<<aux->dato<<" | "<<aux->prioridad<<endl;
		aux = aux->siguiente;
	} 
}


void ordenarPrioridad(struct cola &q){
	//criterio de 0 como prioridad
	//el numero mayor es la mas alta
	
	struct nodo *aux1, *aux2;
	int p_aux;
	char c_aux;
	
	aux1 = q.delante;
	
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		while(aux2!=NULL){
			if(aux1->prioridad > aux2->prioridad){
				p_aux = aux1->prioridad;
				c_aux = aux1->dato;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				
				aux2->prioridad = p_aux;
				aux2->dato = c_aux;
			}
			aux2=aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}


void insertar(struct cola &q, char c, int pri){
	
	//encolar
	encolar(q, c, pri);
	
	//ordeno
	ordenarPrioridad(q);
	//nuevo comentario
}


void menu(){
	cout<<"\n Colas de Prioridad\n";
	cout<<"1.- Encolar\n";
	cout<<"2.- Mostrar Cola\n";
	cout<<"3.- Salir\n";
	
}

/*
Supongamos que quiero 
guardar la cola en archivo
txt

void guardar(){
	//primero es crear el archivo
	FILE *archivo;
	archivo = fopen("guardar.txt", "w");//aqui va el nombre
	//se le conoce como la serializacion del archivo
	int i = 0;
	if(!i){
		cout<<"no hay nada que guaradar";
		getchar();
		return;
		
	}
	q = i;
	while(q){
	fprint(archivo, "%i\n", q->dato);  //%i enteros   %c caracter 
	q = q->siguiente;
	}
	cout<<"archivo guardado";
	//es importante cerrar el flujo del archivo
	fclose(archivo);
	getchar();
}

para cargar es lo mismo
cargar

fscanf(archivo, "%i\n", &q)


*/



int main(){
	
	struct cola q;
	
	q.delante = NULL;
	q.atras = NULL;
	
	//variables
	char c; //caracter a encolar
	int priori; //prioridad
	int op; //opcion del menu
	int x;  //para la funcion pop
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Ingrese caracter:\n";
				cin>>c;
				cout<<"\nIngrese la prioridad:\n";
				cin>>priori;
				
				insertar(q, c, priori);
				
				cout<<"\n Caracter: "<<c<<" encolado\n";
				break;
			case 2:
				cout<<"\n Mostrar la cola  \n";
				if(q.delante !=NULL){
					mostrarCola(q);
				}else{
					cout<<"\n Cola vacia\n";
				}
				break;
			default:
				cout<<"\n Opcion no valida\n";
				system("pause");
				exit(0);
		}
		system("pause");
		system("cls");
	}while(op!=3);
	return 0;
}
