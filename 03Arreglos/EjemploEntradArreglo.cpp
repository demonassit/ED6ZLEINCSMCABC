#include <iostream>

using namespace std;

int main(){
	/*
	Ejemplo de arreglo introducir datos
	*/
	
	float vector1[3];
	float vector2[3];
	float vectorSuma[3];
	
	int i = 0;
	
	//introducir los elementos del primer vector
	
	for(i=0; i<3; i++){
		cout<<"\n Introduce el primer componente "<<i<<" del primer vector \n";
		cin>>vector1[i]; 
	}
	
	for(i=0; i<3; i++){
		cout<<"\n Introduce el primer componente "<<i<<" del ssegundo vector \n";
		cin>>vector2[i]; 
	}
	
	//calculo de la suma
	for(i=0; i<3; i++){
		vectorSuma[i] = vector1[i] + vector2[i];
	}
	
	cout<<"\nLa suma de los vectores es: \n";
	
	for(i=0; i<3; i++){
		cout<<vectorSuma[i] << " ";
	}
	
}
