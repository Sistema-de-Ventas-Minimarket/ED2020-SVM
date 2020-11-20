//
// Created by h4ns3L on 29/10/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "conio.h"
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

#define USER ""
#define PASS ""

struct Item {
    char codeItem[20];
    char nameItem[20];
    //int priceItem;
    char priceItem[20];
    //int qualityItem;
    char qualityItem[20];
    Item *sgte;
} *a, *i;

char nombre[20];
char codigo[20];
char precio[20];
char cantArticulo[20];


typedef struct Item *TItem;

typedef struct Item DATO;

void insertarArticulo(TItem &lista, char codigo[], char nombre[], char precio[], char cantArticulo[]);

void imprimirMemory(TItem lista);

void cargarArticulo();

void buscar(TItem lista, char codigo[]);

void eliminar(TItem lista, char codigo[]);

void login(string username, string password);

void menu();

int main() {
    string username, password;
    login(username, password);
    menu();
    return 0;
}

void insertarBinario(TItem &lista, char codigo[], char nombre[], char precio[], char cantidad[]) {

    TItem nuevo = new(struct Item);
    strcpy(nuevo->codeItem, codigo);
    strcpy(nuevo->nameItem, nombre);
    strcpy(nuevo->priceItem, precio);
    strcpy(nuevo->qualityItem, cantidad);
    nuevo->sgte = lista;
    lista = nuevo;

    FILE *fichero;
    //TItem it; //variable dato

    if ((fichero = fopen("Items.dat", "ab")) == NULL) {
        cout << "Fichero no encontrado" << endl;
    } else {
        // obtenemos datos
        fwrite(&nuevo, sizeof(nuevo), 1, fichero);
        fclose(fichero);
    }
}

void insertarArticulo(TItem &lista, char codigo[], char nombre[], char precio[], char cantidad[]) {

    ofstream outArticulo("Items.txt");

    if (outArticulo.is_open()) {
        TItem nuevo = new(struct Item);
        outArticulo << strcpy(nuevo->codeItem, codigo) << " " << strcpy(nuevo->nameItem, nombre) << " "
                    << strcpy(nuevo->priceItem, precio) << " " << strcpy(nuevo->qualityItem, cantidad);
        nuevo->sgte = lista;
        lista = nuevo;
        outArticulo.close();
    } else {
        cout << "No es posible abrir el archivo";
    }
}

void cargarFile() {

    FILE *fichero;
    DATO e;         //variable dato
    //abriendo archivo
    //if ((fichero = fopen("Items", "rb")) == NULL) {
    fichero = fopen("Items.dat", "r+b");
    // printf("\n Items no existe");
    //} else {
    //leyendo el primer caracter
    fread(&e, sizeof(DATO), 1, fichero);
    while (!feof(fichero)) {
        printf("\n________________________");
        /*cout << "Codigo Articulo. " << e->codeItem << endl;
        cout << "Nombre Articulo. " << e->nameItem << endl;
        cout << "Precio Articulo. " << e->priceItem << endl;
        cout << "Cantidad Articulo. " << e->qualityItem << endl;
        cout << "----------------------------- " << endl;*/
        printf("\nCodigo Articulo.________________________%s", e.codeItem);
        printf("\nNombre Articulo.________________________%s", e.nameItem);
        printf("\nPrecio Articulo.________________________%s", e.priceItem);
        printf("\nCantidad Articulo.______________________%s", e.qualityItem);
        printf("\n________________________");
        //leo el sgte caracter
        fread(&e, sizeof(e), 1, fichero);
        //e = e.sgte;
        //e.sgte;
    }
    // }
    //cerramos archivo
    fclose(fichero);

    /* while (tmp) {
         cout << "Codigo Articulo. " << tmp->codeItem << endl;
         cout << "Nombre Articulo. " << tmp->nameItem << endl;
         cout << "Precio Articulo. " << tmp->priceItem << endl;
         cout << "Cantidad Articulo. " << tmp->qualityItem << endl;
         cout << "----------------------------- " << endl;

         tmp = tmp->sgte;
     }*/
}

//outArticulo <<"Cod.Articulo "<<"Nom.Articulo "<<"Prec.Articulo "<<"Cant.Articulo"<<endl;
void cargarArticulo() {
    DATO e;
    string line;
    ifstream myArticulo("Items.txt");
    if (myArticulo.is_open()) {
        cout << "\t\t   ----------------------------------------------------------------------------" << endl;
        cout << "   " << setw(30) << "| Cod.Articulo";
        cout << setw(26) << "| Nom.Articulo";
        cout << setw(20) << "| Prec.Articulo";
        cout << setw(15) << "| Cant.Articulo" << endl;


        while (!myArticulo.eof()) {
            //cout << line << '\n';
            myArticulo >> e.codeItem;
            myArticulo >> e.nameItem;
            myArticulo >> e.priceItem;
            myArticulo >> e.qualityItem;
            cout << "   " << setw(30) << e.codeItem << setw(26) << e.nameItem << setw(20) << e.priceItem << setw(15)
                 << e.qualityItem << endl;
        }
        myArticulo.close();
    } else {
        cout << "No se pudo abrir el documento";
    }
    system("pause");

}

void imprimirMemory(TItem lista) {

    TItem tmp = lista;

    while (tmp) {
        printf("\n________________________");
        printf("\nCodigo Articulo.________________________%s", tmp->codeItem);
        printf("\nNombre Articulo.________________________%s", tmp->nameItem);
        printf("\nPrecio Articulo.________________________%s", tmp->priceItem);
        printf("\nCantidad Articulo.______________________%s", tmp->qualityItem);
        printf("\n________________________");

        tmp = tmp->sgte;
    }

    /* while (tmp) {
         cout << "Codigo Articulo. " << tmp->codeItem << endl;
         cout << "Nombre Articulo. " << tmp->nameItem << endl;
         cout << "Precio Articulo. " << tmp->priceItem << endl;
         cout << "Cantidad Articulo. " << tmp->qualityItem << endl;
         cout << "----------------------------- " << endl;

         tmp = tmp->sgte;
     }*/
}

void buscar(TItem lista, char codigo[]) {
    TItem tmp = lista;
    while (tmp) {
        if (!strcmp(tmp->codeItem, codigo));
        cout << "Nro°  Cod. " << tmp->codeItem << endl;
        cout << "Nombre Del Producto : " << tmp->nameItem << endl;
        cout << "Precio Del Producto : " << tmp->priceItem << endl;
        cout << "Stock Del Producto : " << tmp->qualityItem << endl;

        tmp = tmp->sgte;
        break;
    }
    if (tmp == NULL) {
        cout << "No se encontro el Producto " << codigo << endl;
    }
}

void liberar(Item **p) {
    while (*p != NULL) {
        Item *prox = (*p)->sgte;
        free(*p);
        *p = prox;
    }
}


void eliminar(TItem listaT, char codigo[]) {
    if (listaT != NULL) {
        TItem auxborrar;
        TItem anterior = NULL;
        auxborrar = listaT;

        while ((auxborrar != NULL) && (auxborrar->codeItem != codigo)) {
            anterior = auxborrar;
            auxborrar = auxborrar->sgte;
        }
        if (auxborrar == NULL) {
            cout << "El elemento no existe";
        } else if (anterior == NULL) {
            listaT = listaT->sgte;
            delete auxborrar;
        } else {
            anterior->sgte = auxborrar->sgte;
            delete auxborrar;
        }
    }
}

void dateTime() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream fecha;
    fecha << put_time(&tm, "%d/%m/%Y %H:%M:%S");
    auto str = fecha.str();
    cout << str;
}

void login(string username, string password) {
    bool entry = false;
    int attempts = 0;
    do {
        system("cls");
        cout << "\n"
                "                                          _    _____ _     _                       \n"
                "     /\\                                  | |  / ____(_)   | |                      \n"
                "    /  \\   ___ ___ ___  ___  ___     __ _| | | (___  _ ___| |_ ___ _ __ ___   __ _ \n"
                "   / /\\ \\ / __/ __/ _ \\/ __|/ _ \\   / _` | |  \\___ \\| / __| __/ _ \\ '_ ` _ \\ / _` |\n"
                "  / ____ \\ (_| (_|  __/\\__ \\ (_) | | (_| | |  ____) | \\__ \\ ||  __/ | | | | | (_| |\n"
                " /_/    \\_\\___\\___\\___||___/\\___/   \\__,_|_| |_____/|_|___/\\__\\___|_| |_| |_|\\__,_|\n"
                "                                                                                   \n"
                "                                                                                   ";

        printf("\t\t\t\n"
               "\t\t   _   _   _   _   _   _   _   _   _   _  \n"
               "\t\t  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n"
               "\t\t ( E ( D ( 2 ( 0 ( 2 ( 0 ( - ( S ( V ( M )\n"
               "\t\t  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n");
        cout << "\n";
        //printf("        *********************************************\n");
        cout << "\t\t * Usuario : ", cin >> username;
        //cout<<"\t\t  * Contrase+a : ", cin >> password;
        cout << "\t\t  * Contrase+a : ";
        char caracter;
        caracter = getch();
        while (caracter != 13) {
            password.push_back(caracter);
            cout << "*";
            caracter = getch();
        }

        if (username == "admin" && password == "admin") {
            printf("\t\t\nVALICACI+N Y CLAVE CONFORME\n");
            entry = true;
            getchar();
            system("pause");
            system("cls");
            cout << "\n" << endl;
        } else {
            printf("Usuario o Contraseña incorrecta\n");
            attempts++;
            getchar();
            //system("pause");
        }
    } while (entry == false && attempts < 3);

    if (entry == true) {

        system("Color 0B");
        cout << "\t\nBIENVENIDO AL SISTEMA DE VENTA 'ED2020-SVM' ";
        menu();
    } else {
        cout << "\tHa sobrepasado el numero permitido de intentos ";
    }
}

//--------------------utilitarios---------------------
int ramdonCode(){
        int valor = 0;
        valor = rand() % (99999 - 11111) + 11111;
    return valor;
}

void messageError(int n){
    switch (n) {
        case 1:
            cout<<"Usuario o Contrase+a Errada";
        case 2:
            cout<<"No se grabo el archivo";
        case 3:
            cout<<"No se abrio el archivo";
        default:
            cout<<"Error generico";
    }
}

void optionItems() {
    int opcion;
    std::ostringstream o;
    string l = "201";  //201-xxxxx->limpieza
    string a = "301";  //301-xxxxx->alimentos
    string g = "401";  //401-xxxxx->licores & gaseosas
    string d = "501";  //501-xxxxx->dulces

    //do {
        cout << "\nG E N E R A N D O | C O D I G O";
        cout << "";
        cout << "\n\t1 - L I M P I E Z A";
        cout << "\n\t2 - A L I M E N T O S";
        cout << "\n\t3 - L I C O R E S & G A S E O S A S";
        cout << "\n\t4 - D U L C E S";
        cout << "\nSeleccione opcion [~]: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                //printf("201%d", ramdonCode());
                o <<l<<ramdonCode();
                std::cout<<o.str();
                break;
            case 2:
                printf("301%d", ramdonCode());
                break;
            case 3:
                printf("401%d", ramdonCode());
                break;
            case 4:
                printf("501%d", ramdonCode());
                break;
            default:
                cout << "\n\nOpcion no valida !!!";
                getch();
        }
    //} while (opc);

}

void menu() {
    int opc;
    TItem listarItem = NULL;
    do {

        cout << "\n\n";
        cout << "\t#########";
        cout << "# Menu de Productos #";
        cout << "#########   Fecha y Hora: ", dateTime();
        cout << "\n\t1 - Insertar datos";
        cout << "\n\t2 - Mostrar todos los datos de Memoria";
        cout << "\n\t3 - Buscar un Producto";
        cout << "\n\t4 - Borrar un Producto";
        cout << "\n\t5 - Mostrar todos los datos del archivo";
        cout << "\n\t0 - Finalizar\n";
        cout << "\t#########";
        cout << "#####################";
        cout << "#########\n";
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
                    //cout << "Ingresar 'codigo' del articulo " << i << "): ";
                    cout << "Ingrese el tipo de Articulo ";
                    int opcion;
                    std::ostringstream o;
                    string l = "201";  //201-xxxxx->limpieza
                    string a = "301";  //301-xxxxx->alimentos
                    string g = "401";  //401-xxxxx->licores & gaseosas
                    string d = "501";  //501-xxxxx->dulces

                    cout << "\n\t1 - L I M P I E Z A";
                    cout << "\n\t2 - A L I M E N T O S";
                    cout << "\n\t3 - L I C O R E S & G A S E O S A S";
                    cout << "\n\t4 - D U L C E S";
                    cout << "\nSeleccione opcion [~]: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            o <<l<<ramdonCode();
                            //std::cout<<o.str();
                            break;
                        case 2:
                            o <<a<<ramdonCode();
                            break;
                        case 3:
                            o <<g<<ramdonCode();
                            break;
                        case 4:
                            o <<d<<ramdonCode();
                            break;
                        default:
                            cout << "\n\nOpcion no valida !!!";
                            getch();
                    }
                    //convert string to char
                    strcpy(codigo,o.str().c_str());
                    cout<<"Codigo generado : "<<codigo;
                    cout << "\nIngresar el nombre del articulo " << i << "): ";
                    cin >> nombre;
                    cout << "Ingresar el" << " precio del articulo [S/.] " << i << "): ";
                    cin >> precio;
                    cout << "Ingresar la cantidad del articulo " << i << "): ";
                    cin >> cantArticulo;
                    insertarArticulo(listarItem, codigo, nombre, precio, cantArticulo);
                }
                cout << endl << "==================" << endl;
                cout << "Se ingreso correctamente los pedidos" << endl;
                cout << "==================" << endl;
                break;
            case 2:
                cout << "Mostrando todos los productos que recien se ingresaron ...\n\n";
                imprimirMemory(listarItem);
                liberar(&listarItem);
                break;
            case 3:
                cout << "\nIngrese codigo del Producto : ";
                cin >> codigo;
                buscar(listarItem, codigo);
                liberar(&listarItem);
                break;
            case 4:
                cout << "\nIngrese el codigo para eleminar el Producto : ";
                cin >> codigo;
                eliminar(listarItem, codigo);
                break;
            case 5:
                cout << "Mostrando el historial de productos  guardados\n\n";
                cargarArticulo();
                liberar(&listarItem);
                break;
            default:
                cout << "\n\nOpcion no valida !!!";
                getch();
        }
    } while (opc);
}