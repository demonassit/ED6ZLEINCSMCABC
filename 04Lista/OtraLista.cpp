/*
vamos a crear un ejemplo de una liata que puede
contener un dato y manejo de apuntadores


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>

/*
Conio es una libreria que da una extension
a stdio, como libreria standar, para el
manejo de consola usando comando como
getch(), clrscr(), gotoxy(), textcolor(), 
y otras

stdlib es una libreria standar para el manejo
de funciones de busqueda, ordenamiento,
arboles, pilas, colas, listas nos sirve
para las estructuras de datos
*/

using namespace std;

//definimos la lista acorde a
//un nodo, el acceso, el dato, el apuntador y sig

struct dato{//lista
	int i;
	dato *s;//siguiente
}*a, *i, *p, *e;

//meter los metodos de acceso a la lista

int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);

//void guardar(void);
//void cargar(void);

main(){
	menu();
}

//metodo del menu
void menu(void){
	//vamos a ser un menu de 6 opciones
	int opc, da;
	do{
		//imprimir el menu
		cout<<"Ejemplo para una lista completa que carga datos";
		cout<<"\n 1.- Buscar Datos: ";
		cout<<"\n 2.- Insertar Datos: ";
		cout<<"\n 3.- Mostrar Datos: ";
		cout<<"\n 4.- Borrar Dato: ";
		cout<<"\n 5.- Guardar Datos en Archivo: ";
		cout<<"\n 6.- Cargar Datos en Archivo: ";
		cout<<"\n 7.- Salir: ";	
		cout<<"\n Seleccione la opcion deseada ";
		cin>>opc;
		//menu
		switch(opc){
			case 1:
				//buscar
				cout<<"\n\n Ingresa el dato a buscar";
				cin>>da;
				if(buscar(da)){
					cout<<"Dato si existe wiii";
				}else{
					cout<<"Dato no existe, solo juguito";
					getch();
				}
				break;
			case 2:
				cout<<"Ingresa el dato: ";
				cin>>da;
				insertar(da);
				break;
			case 3:
				mostrar();
				break;
			case 4:
				borrar();
				break;
			case 5:
				//guardar();
				break;
			case 6:
				//cargar();
				break;
			case 7:
				cout<<"\n\n Ayos uwu :3";
				getch();
				//borrar todos los datos de la lista
				p=i;
				while(p){
					a=p;
					p=p->s;
					delete(a); //metodo de la lista
				}
				exit(0);//se cierra
			default:
				cout<<"Aprenda a leer ¬¬";
				getch();
		}	
	}while(opc);
}

//mostrar

void mostrar(void){
	int cont = 1;
	if(!i){
		//no hay lista que mostrar
		cout<<"No hay lista que mostrar.";
		getch();
		return;
	}
	//si hay datos
	p=i;
	cout<<"\n\n";
	while(p){
		//como si existe la lista la recorremos
		cout<<cont++<<"\nValor = "<<p->i<<endl;
		p = p->s;
	}
	cout<<"\n Fin de la lista";
	getch();
}

//buscar
int buscar(int d){
	//si esta vacia
	if(!i){
		cout<<"\n No hay datos en la lista";
		getch();
		return(0);
	}
	
	//cuando si hay datos
	p = i;
	a = NULL;
	//recorrer los valores de lista;
	while(p->s && p->i < d){
		a=p;
		p=p->s;
	}
	return(p->i==d?1:0);
}


//insertar
void insertar(int dat){
	//si esta vacio
	if(!i){
		//hay que crear un nuevo nodo
		//porque se ingresa por primera vez
		i = new(dato);
		i->s = NULL;
		i->i = dat;
		return;
	}
	//saber si existe o no el dato
	if(buscar(dat)){
		cout<<"\El dato Existe llegale T_T";
		getch();
		return;
	}
	/*
	Imaginemos que existen varios valores
	
	nodo 1 = -2,  nodo 2 = 0, nodo 3 = 4  nodo 4 = 8
	
	insertar 4
	
	*/
	
	//rpimero creamos el nodo
	e = new(dato);
	
	e->i=dat;
	
	if(p==i && p->s){
		if(p->i < e->i){
			//el ultimo dato
			p->s =e;
			e->i = NULL;
		}else{
			//enmedio
			e->s =p;
			i=e;
		}
		return;
	}
	if(p->s){ 
		a->s = e;
		e->s = p; 
		return;
		
	}
	
	if(e->i > p->i){
		e->s = NULL;
		p->s = e;
	}else{
		a->s = e;
		e->s = p;
	}
}









