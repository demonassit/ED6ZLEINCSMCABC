#include <iostream>

using namespace std;

int main(){
	/*//vamos a crear un do while
	int i = 1;
	do{//haz
		//imprima cada elemento hasta el 10
		cout<<i<<endl;
		i++;
		
	}while(i<10);
	*/
	
	//while
	/*int cont = 1;
	while(cont <= 10){
		cout<<cont<<endl;
		cont++;
	}
	cout<<"Wiii se acabo";
	*/
	
	//otro while
	/*int contador = 1;
	while(contador <= 20){
		cout<<"Debo hacer la tarea T_T"<<" "<<contador<<endl;
		contador++;
	}
	cout<<"Wiii se acabo";
	*/
	
	//for
	/*for(int i =1; i<= 10; i++)
		cout<<i<<endl;
		*/
		
		
	//menu
	int seleccion, l;
	
	do{
		cout<<"\n Menu 1, 2, 3 otra opcion es salir \n";
		cout<<"1: Opcion\n";
		cout<<"2: Opcion\n";
		cout<<"3: Opcion\n";
		cout<<"Otra opcion Salir\n";
		cout<<"Ingrese la seleccion\n";
		
		cin>>seleccion;
		
		switch(seleccion){
			case 1:
				cout<<"opcion 1";
				break;
			case 2:
				cout<<"opcion 2";
				break;
			case 3:
				cout<<"opcion 3";
				break;
			default:	
				cout<<"ayos";
				break;
		}
	}while((seleccion > 0)&&(seleccion < 4));
}
