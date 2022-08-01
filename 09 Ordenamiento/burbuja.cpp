/*
Vamos a ocupar un arreglo que se encargue de ordenar
los elementos a traves del metodo burbuja

*/

#include <iostream>
#include <conio.h>
#include <string.h>

#define MAX 50

struct ordenamiento{
	int elem;
};


using namespace std;

//metodos

void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);

int main(){
	int n;
	struct ordenamiento orden[MAX];
	
	cout<<"Ingresa el limite del arreglo: \n";
	cin>>n;
	
	leerarray(n, orden);
	burbuja(n, orden);
	
	cout<<"\n El arreglo ordenado es: \n";
	
	mostrar(n, orden);
	
	getch();
}


void leerarray(int n, struct ordenamiento a[]){
	//ingresar los valores del arreglo
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento:\n";
		cin>>a[i].elem;
	}
}

void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	//aqui guardo los datos ordenados
	struct ordenamiento temp;
	
	//aplico burbuja
	for(i = 1; i < n; i++){
		for(j = n-1; j>=i; j--){
			//realizo la comparacion
			if(a[j-1].elem > a[j].elem){
				//aqui hacemos el intercambio de posiciones
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
	
}

void mostrar(int n, struct ordenamiento a[]){
	//imprimir elemento por elemento
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].elem;
	}
}






