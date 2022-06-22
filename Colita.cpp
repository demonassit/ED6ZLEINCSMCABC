#include <iostream>
#include <conio.h>
#include <stdlib.h>//Libreria para poder usar new y delete 

using namespace std;

struct ICO{
	char clave[20];
	char nombre[30];
	float calificacion;
};

struct Nodo{
	ICO alumnos;
	Nodo *siguiente;
};
//Insertar elementos a l cola 
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&,Nodo *&,ICO);
bool c_vacia(Nodo *);

int main(){
	ICO alumnos;
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	char opcion;
	
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		Nodo *aux=frente;
		switch(opcion){
			case '1':
				agregarDatos(alumnos);
				insertarDatos(frente,fin,alumnos);
				break;
			case '2':
				cout<<"CLAVE"<<"\tNOMBRE\t\t\t"<<"CALIFICACION "<<endl;
				while(aux !=NULL){
					cout<<aux->alumnos.clave<<"\t"<<aux->alumnos.nombre<<"\t\t\t"<<aux->alumnos.calificacion<<endl;
					aux=aux->siguiente;
				}
				break;
			case '3':
				cout<<"\nSalio del programa..."<<endl;
				break;
			default:
				cout<<"\nOpcion invalida "<<endl;
				break;
		}
		cout<<"Presionar una tecla para continuar"<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
	return 0;
}

void menu(){
	cout<<"MENU"<<endl
	    <<"1.Agregar datos del alumno"<<endl
	    <<"2.Mostrar datos de los alumnos"<<endl
	    <<"3.Salir del programa"<<endl
	    <<"Ingresar el numero de opcion que desea: ";
}

void agregarDatos(ICO &alumnos){
	cout<<"Ingresar clave del alumno: "; cin.getline(alumnos.clave,20,'\n');
	cout<<"Ingresar nombre del alumno: "; cin.getline(alumnos.nombre,30,'\n');
	cout<<"Ingresar calificacion: "; cin>>alumnos.calificacion;
}

//Insertando elementos a ala cola
void insertarDatos(Nodo *&frente, Nodo *&fin,ICO alumnos){
	Nodo *n_nodo=new Nodo();//declarando un nuevo nodo 
	
	n_nodo->alumnos=alumnos;//asignando al nuevo nodo el dato a insertar en la cola
	//siguiente apunta directamente hacia null
	n_nodo->siguiente=NULL;
	
	if(c_vacia(frente)){
		frente = n_nodo;//si la cola esta vacia frente = nuevo nodo
	}
	else{
		fin->siguiente=n_nodo;//si la cola no esta vacia 
	}
	
	fin=n_nodo;
}
//determina si la cola esta vacia 
bool c_vacia(Nodo *frente){
	//si frente igual a null cola vacia retornar true
	return (frente==NULL)? true : false;
}

