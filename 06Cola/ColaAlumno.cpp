/*
Ejemplo de una cola de matriculacion de estudiante
*/

#include<iostream>
#include<conio.h>
#include <stdlib.h>

using namespace std;

//estructura de la cola

struct ICO{
	char clave[20];
	char nombre[30];
	float calificacion;
};

struct Nodo{
	ICO alumnos;
	Nodo *siguiente;
};

//metodos
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&,Nodo *&,ICO);
bool c_vacia(Nodo *);

int main(){
	//vamos a crear y colocar los apuntadores
	ICO alumnos;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	char opcion;
	
	
	
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		
		Nodo *aux = frente;
		
		switch(opcion){
			case '1':
				agregarDatos(alumnos);
				insertarDatos(frente, fin, alumnos);
				break;
			case '2':
				cout<<"\n CLAVE "<<" \t Nombre \t"<<" Calificacion \n";
				while(aux!=NULL){
					cout<<aux->alumnos.clave<<"\t"<<aux->alumnos.nombre<<"\t"<<aux->alumnos.calificacion<<endl;
					aux = aux->siguiente;
				}
				break;
			case '3':
				cout<<"\n Ayos nwn/ \n";
				break;
			default:
				cout<<"Opcion no valida T_T \n";
				break;
		}
		getch();
		cout<<"\n Presione una tecla para continuar\n";
		system("cls");
		
	}while(opcion != '3');
	return 0;
}

void menu(){
	cout<<"\nMenu\n";
	cout<<"1.- Agregar datos del alumno\n";
	cout<<"2.- Mostrar datos del alumno\n";
	cout<<"3.- Salir\n";
}

void agregarDatos(ICO &alumnos){
	cout<<"\n Ingresa la clave del alumno: \n";
	cin.getline(alumnos.clave, 20, '\n');
	cout<<"\n Ingresa el nombre del alumno: \n";
	cin.getline(alumnos.nombre, 30, '\n');
	cout<<"\n Ingresa la calificacion del alumno: \n";
	cin>>alumnos.calificacion;
}

void insertarDatos(Nodo *&frente, Nodo *&fin,ICO alumnos){
	//declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//asignar los valores de los datos
	n_nodo -> alumnos = alumnos;
	
	//el siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo; 
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo; //si la cola esta vacia
	}
	fin = n_nodo;
}

bool c_vacia(Nodo *frente){
	//operar ternario para saber si esta vacia
	return (frente == NULL)? true:false;
}
