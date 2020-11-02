//
// Created by h4ns3L on 29/10/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "conio.h"

using namespace std;

struct Item {
    char codeItem[20];
    char nameItem[20];
    //int priceItem;
    char priceItem[20];
    //int qualityItem;
    char qualityItem[20];
    Item *sgte;
}*a,*i;

char nombre[20];
char codigo[20];
char precio[20];
char cantArticulo[20];


typedef struct Item *TItem;

void insertar(TItem &lista, char codigo[], char nombre[], char precio[], char cantArticulo[]);

void imprimir(TItem lista);

void buscar(TItem lista, char codigo[]);

void eliminar(TItem lista, char codigo[]);

void menu();

int main() {

    system("Color 0B");
    cout << "\tBIENVENIDO AL SISTEMA DE VENTA 'ED2020-SVM' ";
    menu();
    return 0;
}

void insertar(TItem &lista, char codigo[], char nombre[], char precio[], char cantidad[]) {

    TItem nuevo = new(struct Item);
    strcpy(nuevo->codeItem, codigo);
    strcpy(nuevo->nameItem, nombre);
    strcpy(nuevo->priceItem, precio);
    strcpy(nuevo->qualityItem, cantidad);
    nuevo->sgte = lista;
    lista = nuevo;
}

void imprimir(TItem lista) {

    TItem tmp = lista;

    while (tmp) {
        cout << "Codigo Articulo. " << tmp->codeItem << endl;
        cout << "Nombre Articulo. " << tmp->nameItem << endl;
        cout << "Precio Articulo. " << tmp->priceItem << endl;
        cout << "Cantidad Articulo. " << tmp->qualityItem << endl;
        cout << "----------------------------- " << endl;

        tmp = tmp->sgte;
    }
}

void buscar(TItem lista, char codigo[]){
    TItem tmp = lista;
    while (tmp)
    {
        if (!strcmp(tmp->codeItem,codigo));
        cout<<"Nro°  Cod. "<<tmp->codeItem<<endl;
        cout<<"Nombre Del Producto : "<<tmp->nameItem<<endl;
        cout<<"Precio Del Producto : "<<tmp->priceItem<<endl;
        cout<<"Stock Del Producto : "<<tmp->qualityItem<<endl;

        tmp = tmp->sgte;
        break;
    }
    if (tmp==NULL){
        cout<<"No se encontro el Producto "<<codigo<<endl;
    }
}

void liberar(Item** p)
{
    while( *p!=NULL )
    {
        Item* prox=(*p)->sgte;
        free(*p);
        *p=prox;
    }
}


void eliminar(TItem lista, char codigo[]){
    /*cout<<"\n\nIngrese dato a eliminar: ";
    TItem tmp = lista;
    cin>>codigo;
    if(buscar(codigo))
    {
        if(a)
            a->codeItem=tmp->codeItem;
        else
            i=tmp->codeItem;
        delete(tmp);
        cout<<"\n\nDato eliminado";
    }
    else
        cout<<"\n\nDato no se encuentra";
    getch();*/
}

void menu() {
    int opc;
    TItem listarItem = NULL;
    do {
        cout<<"\n\n";
        cout<<"\t#########";
        cout<<"# Menu de Productos #";
        cout<<"#########\n";
        cout << "1 - Insertar datos";
        cout << "\t2 - Mostrar todos los datos";
        cout << "\t3 - Buscar un Producto";
        cout << "\t4 - Borrar un Producto";
        cout << "\t0 - Finalizar";
        cout << "\nSeleccione opcion [~]: ";
        cin >> opc;

        switch (opc) {

            case 0:
                cout << "\nFinaliza el programa";
                getch();
                exit(0);
            case 1:
                cout << "\nIngrese la cantidad de productos [~n]: ";
                int cant;
                cin >> cant;
                for (int i = 0; i < cant; ++i) {
                    cout << "Ingresar 'codigo' del articulo " << i << "): ";
                    cin >> codigo;
                    cout << "Ingresar el nombre del articulo " << i << "): ";
                    cin >> nombre;
                    cout << "Ingresar el" << " precio del articulo [S/.] " << i << "): ";
                    cin >> precio;
                    cout << "Ingresar la cantidad del articulo " << i << "): ";
                    cin >> cantArticulo;
                    insertar(listarItem, codigo, nombre, precio, cantArticulo);
                }
                cout << endl << "==================" << endl;
                cout << "Se ingreso correctamente los pedidos" << endl;
                cout << "==================" << endl;
                break;
            case 2:
                cout << "Mostrando todos los productos que se ingresaron ahora\n\n";
                imprimir(listarItem);
                liberar(&listarItem);
                break;
            case 3: cout << "\nIngrese codigo del Producto : ";
                cin >> codigo;
                buscar(listarItem,codigo);
                liberar(&listarItem);
                break;
            case 4:
                cout << "\nIngrese el codigo para eleminar el Producto";
                cin >> codigo;
                eliminar(listarItem, codigo);
                break;
            default:
                cout << "\n\nOpcion no valida !!!";
                getch();
        }
    } while (opc);
}









/* int number=33;
 stringstream strs;
 strs << number;
 string temp_str = strs.str();
 char* char_type = (char*) temp_str.c_str();*/