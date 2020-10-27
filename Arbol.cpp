//Arbol binario de numeros enteros

//Librerias

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#define ARRIBA 72
#define ABAJO 80
#define SALIR 27
#define ENTER 13

using namespace std;

//Estructura de un arbol binario

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//Prototipos de los metodos a utilizar

bool buscarNodo(Nodo *,int);
void mostrarArbol(Nodo *,int,int,int);
void menu();
Nodo *CrearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void PreOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);
void EliminarNodo(Nodo *,int);
void Eliminar(Nodo *);
Nodo* Minimo(Nodo*);
void Reemplazar(Nodo *,Nodo *);
void DestruirNodo(Nodo *);
void gotoxy(int, int);
void menu2();

//Variable tipo Nodo

Nodo *arbol=NULL;

/*Metodo Main. No es necesario  que tenga muchas lineas 
  de codigo*/

int main(){
	menu2();
	
	system("pause");
	return 0;
}

/*Metodo para elegir las acciones posibles con un arbol 
  binario*/

void menu2(){
	char tecla;
	bool retorno,muestra;
	int px=50,py=0,dato,opcion,contador=0;
	while(!retorno){
		if(!muestra){
			px=50;py=0;
			gotoxy(px,py);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(px,py+1);printf("%cElige y presiona Enter   %c",186,186);
			gotoxy(px,py+2);printf("%cPresiona ESC para salir  %c",186,186);
			gotoxy(px,py+3);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
			gotoxy(px,py+4);printf("%c A%cadir un numero.       %c",186,164,186);
			gotoxy(px,py+5);printf("%c Buscar un elemento.     %c",186,186);
			gotoxy(px,py+6);printf("%c Ordenamiento PreOrden.  %c",186,186);
			gotoxy(px,py+7);printf("%c Ordenamiento InOrden.   %c",186,186);
			gotoxy(px,py+8);printf("%c Ordenamiento PostOrden. %c",186,186);
			gotoxy(px,py+9);printf("%c Eliminar un nodo        %c",186,186);
			gotoxy(px,py+10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			mostrarArbol(arbol,contador,px,py+20);//x50 y22
			muestra=true;
			py=4;
		}
		gotoxy(px+1,py);printf("%c",175);
		tecla=getch();
		gotoxy(px+1,py);printf(" ");
		if(tecla==ARRIBA){
			py--;
		}
		if(tecla==ABAJO){
			py++;
		}
		if(py==10){
			py=4;
		}
		if(py==3){
			py=9;
		}
		if(tecla==ENTER){
			system("cls");
			muestra=false;
			if(py==4){
				gotoxy(px,py);cout<<"Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato,NULL);
				cout<<"\n";
				system("pause");
			}
			if(py==5){
				gotoxy(px,py);cout<<"\nDigite el elemento a buscar: \n";
				cin>>dato;
				if(buscarNodo(arbol,dato)==true){
				gotoxy(px,py);cout<<"\nElemento "<<dato<<" ha sido encontrado en el arbol\n";
				}else{
					gotoxy(px,py);cout<<"\nElemento no encontrado\n";
				}
				cout<<"\n";
				system("pause");
			}
			if(py==6){
				cout<<"Mostrando ordenamiento PreOrden\n\n";
				PreOrden(arbol);
				cout<<"\n";
				system("pause");
			}
			if(py==7){
				cout<<"Mostrando ordenamiento InOrden\n\n";
				InOrden(arbol);
				cout<<"\n";
				system("pause");
			}
			if(py==8){
				cout<<"Mostrando ordenamiento PostOrden\n\n";
				PostOrden(arbol);
				cout<<"\n";
				system("pause");
			}
			if(py==9){
				gotoxy(px,py);cout<<"\nDigite el numero a eliminar: ";
				cin>>dato;
				EliminarNodo(arbol,dato);
				cout<<"\n";
				system("pause");
			}
			system("cls");
		}
		if(tecla==SALIR){
			system("cls");
			retorno=true;
		}
	}
}

//Metodo para crear un nodo del arbol

Nodo *CrearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo=new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre;
	
	return nuevo_nodo;
}

//Metodo para insertar un nodo a el arbol

void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevo_nodo=CrearNodo(n,padre);
		arbol=nuevo_nodo;
	}else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n,arbol);
		}else{
			insertarNodo(arbol->der,n,arbol);
		}
	}
}

//Metodo para imprimir el arbol creado completamente

void mostrarArbol(Nodo *arbol,int contador,int px,int py){
	if(arbol==NULL){
		return;
	}else{
		mostrarArbol(arbol->der,contador+1,px+3,py+3);
		gotoxy(px,py);cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,contador+1,px+3,py-3);
	}
}

//Metodo para buscar un nodo en concreto 

bool buscarNodo(Nodo *arbol,int n){
	if(arbol==NULL){
		return false;;
	}else if(arbol->dato==n){
		return true;
	}else if(n<arbol->dato){
		return buscarNodo(arbol->izq,n);
	}else{
		return buscarNodo(arbol->der,n);
	}
}

/*Metodo para ordenar el arbol de la forma Raiz-Parte 
  Izquierda-Parte Derecha*/

void PreOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato<<"-";
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
}

/*Metodo para ordenar el arbol de la forma Parte 
  Izquierda-Raiz-Parte Derecha*/

void InOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		InOrden(arbol->izq);
		cout<<arbol->dato<<"-";
		InOrden(arbol->der);	
	}
}

/*Metodo para ordenar el arbol de la forma Parte 
  Izquierda-Parte Derecha-Raiz*/

void PostOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}

//Metodo para encontrar el nodo a eliminar

void EliminarNodo(Nodo *arbol,int n){
	if(arbol==NULL){
		return;
	}else if(n<arbol->dato){
		EliminarNodo(arbol->izq,n);
	}
	if(n>arbol->dato){
		EliminarNodo(arbol->der,n);
	}else{
		Eliminar(arbol);
	}
}

//Metodo para saber cual es el nodo mas izquierdo del arbol

Nodo *Minimo(Nodo *arbol){
	if(arbol==NULL){
		return NULL;
	}else if(arbol->izq){
		return Minimo(arbol->izq);
	}else{
		return arbol;
	}
}

/*Metodo para remplazar el nodo a eliminar con el 
mas izquierdo del derecho a eliminar*/

void Reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq=nuevoNodo;
		}else if(arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre=arbol->padre;
	}
}

//Metodo para destruir un nodo

void DestruirNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	
	delete nodo;
}

//Metodo para eliminar un nodo

void Eliminar(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=Minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		Eliminar(menor);
	}else if(nodoEliminar->izq){
		Reemplazar(nodoEliminar,nodoEliminar->izq);
		DestruirNodo(nodoEliminar);
	}else if(nodoEliminar->der){
		Reemplazar(nodoEliminar,nodoEliminar->der);
		DestruirNodo(nodoEliminar);
	}else{
		Reemplazar(nodoEliminar,NULL);
		DestruirNodo(nodoEliminar);
	}
}

// Metodo gotoxy para elegir la posicion de caracteres

void gotoxy(int x,int y){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}

