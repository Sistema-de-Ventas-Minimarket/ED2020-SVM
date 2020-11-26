#include <iostream>
#include <string> 
#include <stdio.h>
//system ("color 05");
using namespace std;

struct nodo{
	int nrOrden;
	string cliente;
	string dni;
	string apellido;
	string telefono;
	struct nodo *siguiente;
};


typedef nodo *ptrPila;
void push(ptrPila &p, int nrOrden, string cliente, string dni,string apellido, string telefono);
void mostrarPila(ptrPila p);
int pop(ptrPila &p);
void buscarPila(ptrPila p);

int main(int argc, char *argv[]) {
	int op, no=0, x;
	string cli;
	string dni;
	string ape; 
	string tele;
	ptrPila p = NULL;
	
	do{
		cout<<"\n***** CLIENTES *****\n"<<endl;
		cout<<"    1. Agregar Cliente ---------------"<<endl;
		cout<<"    2. Quitar Cliente ----------------"<<endl;
		cout<<"    3. Mostrar Clientes --------------"<<endl;
		cout<<"    4. Buscar ------------------------"<<endl;
		cout<<"    5. Salir -------------------------"<<endl<<endl;
		cout<<"\n**** ***** *****"<<endl;
		
		cout<<"    Seleccione una opcion: ";
		cin>>op;
		switch(op){
		case 1:
			no = no + 1;
			//cout<<"Numero Orden: ";
			//cin>>no;
			fflush(stdin);
			cout<<"\nDNI : ";
			getline(cin, cli); 
			//fflush(stdin);
			cout<<"NOMBRE : ";
			cin>>dni;
			//fflush(stdin);
			cout<<"APELLIDO: ";
			cin>>ape;
			//fflush(stdin);
			cout<<"TELEFONO: ";
			cin>>tele;
			push(p, no, cli, dni, ape, tele);
			cout<<"\nDATOS GUARDADOS CORRECTAMENTE: "<<no<<" ,"<<cli<<" ,"<<dni<<","<<ape<<","<<tele<<endl;
			break;
		case 2:
			if(p != NULL){
				x = pop(p);
				cout<<"Numero "<<x<<" ELIMINADO..."<<endl;
			}else{
				cout<<"NO HAY CLIENTES..."<<endl;
			}
			break;
		case 3:
			cout<<"\nMostrando Lista Clientes \n"<<endl;
			if(p != NULL){
				mostrarPila(p);
			}else{
				cout<<"La Lista de Clientes esta Vacia..."<<endl;
			}
			break;
		case 4:
			cout<<"Buscar cliente\n"<<endl;
			if(p != NULL){
				buscarPila(p);
			}else{
				cout<<"NO HAY CLIENTES..."<<endl;
			}
			break;	
	
		}
		cout<<endl;
		system("pause");
		system("cls");
	} while(op != 5);
	return 0;
}

void push(ptrPila &p,int no, string cli, string dni, string ape, string tele){
	ptrPila aux = new nodo();
	aux->nrOrden = no;
	aux->cliente = cli;
	aux->dni = dni;
	aux->apellido=ape;
	aux->telefono =tele;
	aux->siguiente = p;
	p = aux;
}
	
int pop(ptrPila &p){
	int num;
	string cli, dni;
	ptrPila aux;
	aux = p;
	num = aux->nrOrden;
	cli = aux->cliente;
	dni = aux->dni;
	p = aux->siguiente;
	delete(aux);
	return num;
}
		
void mostrarPila(ptrPila p){
	ptrPila aux;
	aux = p;
	while(aux != NULL){
		cout<<aux->nrOrden<<endl;
		cout<<aux->cliente<<endl;
		cout<<aux->dni<<endl;
		cout<<aux->apellido <<endl;
		cout<<aux->telefono<<endl;
		cout<<"------------------\n";
		aux = aux->siguiente;
	}
}
	
void buscarPila(ptrPila p){
	ptrPila aux;
	aux = p;
	string buscar;
	bool enc = false;
	fflush(stdin);
	cout<<"Ingrese DNI del Cliente: "<<endl;
	getline(cin, buscar);
	//cin>>buscar;
	//fflush(stdin);
	
	while(aux != NULL){
		if(buscar == aux->cliente){
			cout<<"\nEncontrado, el cliente es: "<<endl;
			cout<<"DNI: "<<aux->cliente<<endl;
			cout<<"CLIENTE: "<<aux->dni<<endl;
			cout<<"Nro de Cliente es : "<<aux->nrOrden<<endl;
			enc = true;			
		}
		aux = aux->siguiente;		
	}
	if( enc == false){
		cout<<"\nel cliente "<<buscar<<" no existe"<<endl;
	}
}
