//
// Created by h4ns3L on 29/10/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "string.h"

using namespace std;

struct Item{
    char codeItem[20];
    char nameItem[20];
    int priceItem;
    int qualityItem;
    Item* sgte;
};

typedef struct Item *TItem;

void insertar(TItem &lista,char codigo[], char nombre[], int precio, int cantArticulo);
void imprimir(TItem lista);

int main(){
    TItem listarItem = NULL;
    int cant;
    char nombre[20];
    char codigo[20];
    int precio;
    int cantArticulo;
    cout<<"Cantidad de productos: ";cin>>cant;
    for (int i = 0;  i < cant; ++i) {
        cout<<"Ingresar codigo del articulo "<<i<<"): ";cin>>codigo;
        cout<<"Ingresar el nombre del articulo "<<i<<"): ";cin>>nombre;
        cout<<"Ingresar el precio del articulo "<<i<<"): ";cin>>precio;
        cout<<"Ingresar la cantidad articulo "<<i<<"): ";cin>>cantArticulo;
        insertar(listarItem,codigo,nombre,precio,cantArticulo);
    }
    cout<<endl<<"=================="<<endl;
    imprimir(listarItem);
    cout<<"=================="<<endl;
    return 0;
}
void insertar(TItem &lista, char codigo[], char nombre[], int precio, int cantidad ){

    std::string pitem = std::to_string(precio);
    char const *pitems = pitem.c_str();

    TItem  obj1 = new(struct Item);
    std::string objpitem = std::to_string(obj1->priceItem);
    char const *tpriceItem = objpitem.c_str();

    std::string pquality = std::to_string(cantidad);
    char const *pqualitys = pitem.c_str();

    int number=33;
    stringstream strs;
    strs << number;
    string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();

    TItem  nuevo = new(struct Item);
    strcpy(nuevo->codeItem,codigo);
    strcpy(nuevo->nameItem,nombre);
    //strcpy(nuevo->priceItem, pitems);
    //strcpy(nuevo->qualityItem, pqualitys);
    nuevo->sgte = lista;
    lista = nuevo;
}

void imprimir(TItem lista)
{
    TItem tmp = lista;
    //TPaciente tmpPaciente=NULL;
    while(tmp)
    {
        cout<<"Codigo Articulo. "<<tmp->codeItem<<endl;
        cout<<"Nombre Articulo. "<<tmp->nameItem<<endl;
        cout<<"Precio Articulo. "<<tmp->priceItem<<endl;
        cout<<"Cantidad Articulo. "<<tmp->qualityItem<<endl;
        //tmpPaciente = tmp->proximo;
        /*while(tmpPaciente)
        {
            cout<<"  [+] "<<tmpPaciente->nombre<<endl;
            tmpPaciente = tmpPaciente->sgte;
        }*/
        tmp = tmp->sgte;
    }
}
