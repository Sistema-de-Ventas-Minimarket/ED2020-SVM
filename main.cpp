//
// Created by h4ns3L on 26/11/2020.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "conio.h"
#include <iomanip>
#include <ctime>
#include <fstream>
#include <afxres.h>
#include "string"

using namespace std;

#define USER "admin"
#define PASS "admin"

struct Nodo {
    string nombre;
    int edad;
    string DNI;
    string apellido;
    Nodo *der;
    Nodo *izq;
    Nodo *Daddy;
};

Nodo *arbol = NULL;
Nodo *bus = NULL;

struct Item {
    int codeItem;
    char nameItem[20];
    int priceItem;
    int qualityItem;
    Item *sgte;
} *a, *i, *p;

char nombre[20];
int codigo;
int precio;
int cantArticulo;


typedef struct Item *TItem;

typedef struct Item DATO;

void menuMain();

/*----*/

void insertarArticulo(TItem &lista, int codigo, char nombre[], int precio, int cantArticulo);

void imprimirMemory(TItem lista);

void cargarArticulo();

//void buscar(TItem lista, char codigo[]);

int buscar(int codigo);

void eliminar(TItem lista, char codigo[]);

void borrar(int codigo);

void login(string username, string password);

void banners();

void menuItems();

void gotoxy(int x,int y);

COORD coord={0,0};

/*-----*/
void menuCustomers();

Nodo *crearNodo(int, string, string, string, string, Nodo *);

void insertarNodo(Nodo *&, int, string, string, string, Nodo *);

void mostrarArbol(Nodo *, int);

bool busqueda(Nodo *, int);

int busquedaiterativa(Nodo *, int);

void preOrden(Nodo *);

void inOrden(Nodo *);

void postOrden(Nodo *);

void eliminar(Nodo *, int);

void eliminarNodo(Nodo *);

Nodo *minimo(Nodo *);

void reemplazar(Nodo *, Nodo *);

void destNodo(Nodo *);

/*----*/

int main() {
    string username, password;
    login(username, password);
    menuItems();
    menuCustomers();
    return 0;
}


void insertarArticulo(TItem &lista, int codigo, char nombre[], int precio, int cantidad) {

    ofstream outArticulo;
    ifstream consultaArticulo;
    bool repetido = false;
    Item item;  //creando objeto de estructura
    consultaArticulo.open("Items.txt", ios::in);
    outArticulo.open("Items.txt", ios::out | ios::app);  //abriendo archivo

    if (outArticulo.is_open() && consultaArticulo.is_open()) {

        consultaArticulo >> item.codeItem;

        //verificando que no exista un rgistro con el codigo
//        while (!consultaArticulo.eof())
//        {
//            consultaArticulo >> item.nameItem >> item.priceItem >> item.qualityItem;
//
//            if (item.codeItem == codigo) {
//                cout << "Ya existe un producto con el codigo " << codigo << endl;
//                system("pause");
//            }
//            consultaArticulo >> item.codeItem;
//        }
        if (repetido == false) {

            TItem nuevo = new(struct Item);
            outArticulo << (nuevo->codeItem, codigo) << " " << strcpy(nuevo->nameItem, nombre) << " "
                        << (nuevo->priceItem, precio) << " " << (nuevo->qualityItem, cantidad) << endl;
            nuevo->sgte = lista;
            lista = nuevo;

            //outArticulo << codigo << " " << item.nameItem << " " << item.priceItem << " " << item.qualityItem << endl;

            system("cls");
        }
    } else {
        cout << "No es posible abrir el archivo";
    }
    outArticulo.close();
    consultaArticulo.close();
    system("pause");
}

void cargarArticulo() {
    DATO e;
    string line;
    ifstream myArticulo("Items.txt");
    if (myArticulo.is_open()) {
        cout << "\t\t   ----------------------------------------------------------------------------" << endl;
        cout << "   " << setw(25) << "| Cod.Articulo";
        cout << setw(26) << "| Nom.Articulo";
        cout << setw(20) << "| Prec.Articulo";
        cout << setw(15) << "| Cant.Articulo" << endl;


        while (!myArticulo.eof()) {
            //cout << line << '\n';
            myArticulo >> e.codeItem;
            myArticulo >> e.nameItem;
            myArticulo >> e.priceItem;
            myArticulo >> e.qualityItem;
            cout << "   " << setw(30) << e.codeItem << setw(26) << e.nameItem << setw(15) << e.priceItem << setw(15)
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
        printf("\nCodigo Articulo.________________________%d", tmp->codeItem);
        printf("\nNombre Articulo.________________________%s", tmp->nameItem);
        printf("\nPrecio Articulo.________________________%d", tmp->priceItem);
        printf("\nCantidad Articulo.______________________%d", tmp->qualityItem);
        printf("\n________________________");

        tmp = tmp->sgte;
    }

}

int buscar(int codigo) {
    Item item;
    ifstream lectura;
    bool encontrado = false;
    lectura.open("Items.txt", ios::out | ios::in);

    if (lectura.is_open()) {
        lectura >> item.codeItem;
        while (!lectura.eof()) {
            lectura >> item.nameItem >> item.priceItem >> item.qualityItem;

            if (codigo == item.codeItem) {
                encontrado = true;

                cout << "\t\t   ----------------------------------------------------------------------------" << endl;
                cout << "   " << setw(25) << "| Cod.Articulo";
                cout << setw(26) << "| Nom.Articulo";
                cout << setw(20) << "| Prec.Articulo";
                cout << setw(15) << "| Cant.Articulo" << endl;

                cout << "   " << setw(30) << item.codeItem << setw(26) << item.nameItem << setw(15) << item.priceItem
                     << setw(15)
                     << item.qualityItem << endl;
            }
            lectura >> item.codeItem;
        }
        if (!encontrado) {
            cout << "Producto no encontado" << endl;
            getch();
            return (0);
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    system("pause");
    return 1;
}

int buscarItem(int codigo) {
    if (!codigo) {
        cout << "No hay datos en la lista!!!";
        getch();
        return (0);
    }
    p = i;
    a = NULL;
    while (p->sgte && p->codeItem < codigo) {
        a = p;
        p = p->sgte;
    }
    return (p->codeItem == codigo ? 1 : 0);
}

void liberar(Item **p) {
    while (*p != NULL) {
        Item *prox = (*p)->sgte;
        free(*p);
        *p = prox;
    }
}

void eliminar(TItem listaT, int codigo) {
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

void borrar(int codigo) {
    //TItem lista;
    if (buscar(codigo)) {
        if (a)
            a->sgte = p->sgte;
        else
            i = p->sgte;
        delete (p);
        cout << "\n\nCodigo eliminado";
    } else
        cout << "\n\nCodigo no se encuentra";
    getch();
}

/*
 *
 * Revisar unico
void eliminar()
{
    Item item;
    ofstream aux;
    ifstream lectura;
    int i= 0;
    bool encontrado = false;
    int auxCodigo = 0;
    aux.open("Items.txt",ios::out);
    lectura.open("Items.txt",ios::in);

    if(aux.is_open() && lectura.is_open()){

        cout<<"Ingresa el codigo: ";
        cin>>auxCodigo;
        lectura >> item.codeItem;
        while(!lectura.eof())
        {
            lectura >> item.nameItem >> item.priceItem >> item.qualityItem;
            if(auxCodigo == item.codeItem){
                encontrado = true;
                cout << "Registro Eliminado!" << endl;
            }else{
                aux << item.codeItem << " " << item.nameItem << " " << item.priceItem << " "
                    << item.qualityItem << endl;
            }
            lectura>>item.codeItem;
        }
        if(encontrado==false){
            cout<<"No se encontro ningun registro con clave "<<auxCodigo<<endl;
        }
        aux.close();
        lectura.close();
        //remove("inventario.txt");
        //rename("auxiliar2.txt","inventario.txt");
    }
    else{
        cout<<"No se pudo abrir el Archivo o aun no ha sido Creado"<<endl;

    }
    system("pause");
}
*/

/*-----------------------Facturacion--------------------------*/

void agregarFactura(){

}

void facturarse(){

}

void menufactura()
{
    SetConsoleTitle("F A C T U R A C I O N");
    system("cls");
    char op;
    do
    {
        gotoxy(40,9);
        cout << "F a c t u r a c i o n" << endl;
        gotoxy(27,11);
        cout << "[1] Agregar Venta" << endl;
        gotoxy(27,12);
        cout << "[2] Imprimir" << endl;
        gotoxy(27,13);
        cout <<"[0] Retornar"<<endl;

        gotoxy(25,16);
        cout << "Ingrese opcion: "; cin >> op;

        switch(op)
        {
            case '1':
            {
                system("cls");
                agregarFactura();
                system("cls");
                break;
            }
            case '2':
            {
                system("cls");
                facturarse();
                system("cls");
                break;
            }
            case '0':
            {
                system("cls");
                break;
            }
            default:
            {
                system("cls");
                cout << "Error, opcion desconocida" << endl;
                Sleep(500);
                system("cls");
                break;
            }
        }
    }while(op!='0');

}

/*--------------------Cliente-------------------------------*/

void menuCustomers() {
    system("cls");
    int dato, opcion, contador = 0;
    string nombre, ap, codigo, dni;
    do {

        cout << "\t############## MENU  CLIENTES ##############\n" << endl;
        cout << "\t1. Registrar nuevo Cliente" << endl;
        cout << "\t2. Mostrar codigos de los Cliente" << endl;
        cout << "\t3. Buscar Clientes " << endl;
        //cout << "\t5. Recorrer en PreOrden" << endl;
        //cout << "\t6. Recorrer en InOrden" << endl;
        //cout << "\t7. Recorrer en PostOrden" << endl;
        cout << "\t4. Eliminar un Cliente" << endl;
        cout << "\t0. Retornar" << endl;
        cout << "\t##################################\n" << endl;
        cout << "\nIngrese Opcion: ";
        cin >> opcion;


        switch (opcion) {
            case 1:
                cout << "\n...:::|Datos de Registro de un nuevo Cliente|:::...\n\n";
                cout << "\nIngrese Nombre: ";
                cin >> nombre;
                cout << "\nIngrese Apellido: ";
                cin >> ap;


                cout << "\nIngrese Edad: ";
                cin >> dni;

                cout << "\nIngrese DNI: ";
                cin >> dato;

                insertarNodo(arbol, dato, nombre, ap, dni, NULL);
                cout << "\n";
                system("pause");
                break;

            case 2:
                cout << "\n...:::|Mostrando Registro del MINI MARKET|:::...\n\n";
                mostrarArbol(arbol, contador);
                cout << "\n";
                system("pause");
                break;

            case 3:
                cout << "\n...:::|Ingrese el DNI del Cliente que desea buscar|:::... ";
                cin >> dato;
                if (busqueda(arbol, dato) == true) {
                    cout << "\nEl DNI " << dato << " a sido encontrado en los registros\n";
                    cout << "\nPertenece a: \n";
                    cout << "\t##################################\n" << endl;
                    cout << "\tNOMBRE.......: " << bus->nombre << endl;
                    cout << "\tAPELLIDO.....: " << bus->apellido << endl;
                    cout << "\tDNI..........: " << bus->edad << endl;
                    cout << "\tEDAD.........: " << bus->DNI << endl;
                    cout << "\t##################################\n" << endl;
                } else {
                    cout << "\nElemento no encontrado\n";
                }
                cout << "\n";
                system("pause");
                break;

            case 8:
                cout << "\n...:::|Ingrese el DNI del Cliente que desea buscar|:::... ";
                cin >> dato;
                if (busquedaiterativa(arbol, dato) == 1) {
                    cout << "\nLa edad" << dato << " a sido encontrado en los registros\n";
                    cout << "\nPertenece a: \n";
                    cout << "NOMBRE: " << bus->nombre << endl;
                    cout << "APELLIDO: " << bus->apellido << endl;
                    cout << "EDAD: " << bus->edad << endl;
                    cout << "DNI: " << bus->DNI << endl;
                } else {
                    cout << "\nElemento no encontrado\n";
                }
                cout << "\n";
                system("pause");
                break;


            case 5:
                cout << "\nRecorrido en PreOrden: ";
                preOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 6:
                cout << "\nRecorrido en InOrden: ";
                inOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 7:
                cout << "\nRecorrido en PostOrden: ";
                postOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 4:
                cout << "\n...:::|Ingrese el DNI del Cliente que desea eliminar del registro|:::...\n\n";
                cin >> dato;
                eliminar(arbol, dato);
                cout << "\n";
                system("pause");
                break;
        }
        system("cls");

    } while (opcion != 0);
}

Nodo *crearNodo(int n, string nombre, string ap, string dni, Nodo *Daddy) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->nombre = nombre;
    nuevo_nodo->apellido = ap;
    nuevo_nodo->edad = n;
    nuevo_nodo->DNI = dni;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->Daddy = Daddy;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, string nombre, string ap, string dni, Nodo *Daddy) {
    if (arbol == NULL) {
        Nodo *nuevo_nodo = crearNodo(n, nombre, ap, dni, Daddy);
        arbol = nuevo_nodo;
    } else {
        int valorRaiz = arbol->edad;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n, nombre, ap, dni, arbol);
        } else if (n > valorRaiz) {
            insertarNodo(arbol->der, n, nombre, ap, dni, arbol);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont) {
    string p1[1], p2[1];
    if (arbol == NULL) {
        return;
    } else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "        ";
        }
        p1[0] = toupper(arbol->nombre[0]);
        p2[0] = toupper(arbol->apellido[0]);
        cout << p1[0] << p2[0] << "-" << arbol->edad << "-" << arbol->DNI[0] << endl;

        mostrarArbol(arbol->izq, cont + 1);
    }
}


bool busqueda(Nodo *arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->edad == n) {
        bus = arbol;
        return true;
    } else if (n < arbol->edad) {
        return busqueda(arbol->izq, n);
    } else {
        return busqueda(arbol->der, n);
    }
}

int busquedaiterativa(Nodo *arbol, int dato) {
    while (arbol != NULL) {
        if (dato < arbol->edad) {
            arbol = arbol->izq;
        } else if (dato > arbol->edad) {
            arbol = arbol->der;
        } else {
            bus = arbol;
            return 1;
        }
    }
    return 0;
}

void preOrden(Nodo *arbol) {
    if (arbol == NULL) { ;
        return;
    } else {
        cout << arbol->edad << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Nodo *arbol) {
    if (arbol == NULL) { ;
        return;
    } else {
        inOrden(arbol->izq);
        cout << arbol->edad << " - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol) {
    if (arbol == NULL) { ;
        return;
    } else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->edad << " - ";
    }
}

void eliminar(Nodo *arbol, int n) {
    if (arbol == NULL) { ;
        return;
    } else if (n < arbol->edad) {
        eliminar(arbol->izq, n);
    } else if (n > arbol->edad) {
        eliminar(arbol->der, n);
    } else {
        eliminarNodo(arbol);
    }

}

Nodo *minimo(Nodo *arbol) {
    if (arbol == NULL) { ;
        return NULL;
    }
    if (arbol->izq) {
        return minimo(arbol->izq);
    } else {
        return arbol;

    }
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
    if (arbol->Daddy) {

        if (arbol->edad == arbol->Daddy->izq->edad) {
            arbol->Daddy->izq = nuevoNodo;
        } else if (arbol->edad == arbol->Daddy->der->edad) {
            arbol->Daddy->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {

        nuevoNodo->Daddy = arbol->Daddy;
    }

}

void destNodo(Nodo *nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->edad = menor->edad;
        eliminarNodo(menor);
    } else if (nodoEliminar->izq) {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destNodo(nodoEliminar);
    } else if (nodoEliminar->der) {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destNodo(nodoEliminar);
    } else {
        reemplazar(nodoEliminar, NULL);
        destNodo(nodoEliminar);
    }
}


/*---------------------Fin Customer--------------------------------------*/


void login(string username, string password) {
    SetConsoleTitle("LOGIN");
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

        if (username == USER && password == PASS) {
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
        cout << "\t\t", banners();
        menuMain();
    } else {
        cout << "\tHa sobrepasado el numero permitido de intentos ";
        exit(1);
    }
}

//--------------------utilitarios---------------------

string Fecha()
{
    time_t t;
    struct tm *tm;
    char fecha[100];
    t=time(NULL);
    tm=localtime(&t);
    strftime(fecha, 100, "%d/%m/%y", tm);
    return  fecha;
}

string Hora()
{
    time_t t;
    struct tm *tm;
    char hora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(hora, 100, "%I:%M:%S", tm);
    return  hora;
}

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int ramdonCode() {
    int valor = 0;
    valor = rand() % (99999 - 11111) + 11111;
    return valor;
}

void banners() {
    string banner = "B I E N V E N I D O  A L  S I S T E M A  D E  V E N T A  'ED2020-SVM' ";
    for (int j = 0; j < banner.length(); ++j) {
        cout << banner[j];
        Sleep(80);
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

void messageError(int n) {
    switch (n) {
        case 1:
            cout << "Usuario o Contrase+a Errada";
        case 2:
            cout << "No se grabo el archivo";
        case 3:
            cout << "No se abrio el archivo";
        default:
            cout << "Error generico";
    }
}

void menuItems() {
    SetConsoleTitle("MENU PRODUCTOS");
    system("cls");
    int opc;
    TItem listarItem = NULL;
    do {

        cout << "\n\n";
        cout << "\t#########";
        cout << "# Menu de Productos #";
        cout << "#########   Fecha y Hora: ", dateTime();
        cout << "\n\t1 - Insertar datos";
        cout << "\n\t2 - Mostrar datos recien ingresados";
        cout << "\n\t3 - Buscar un Producto";
        cout << "\n\t4 - Borrar un Producto";
        cout << "\n\t5 - Mostrar todos los datos del archivo";
        cout << "\n\t0 - Retornar\n";
        cout << "\t#########";
        cout << "#####################";
        cout << "#########\n";
        cout << "\nSeleccione opcion [~]: ";
        cin >> opc;

        switch (opc) {

            //case 0:
            //    cout << "\nFinaliza el programa";
            //    getch();
            //    exit(0);
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
                    cout << "\n\t3 - L I C O R E S  &  G A S E O S A S";
                    cout << "\n\t4 - D U L C E S";
                    cout << "\nSeleccione opcion [~]: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            o << l << ramdonCode();
                            //std::cout<<o.str();
                            break;
                        case 2:
                            o << a << ramdonCode();
                            break;
                        case 3:
                            o << g << ramdonCode();
                            break;
                        case 4:
                            o << d << ramdonCode();
                            break;
                        default:
                            cout << "\n\nOpcion no valida !!!";
                            getch();
                    }
                    int codigo = std::stoi(o.str());
                    cout << "Codigo generado : " << codigo;
                    fflush(stdin);
                    cout << "\nIngresar el nombre del articulo " << i << "): ";
                    cin >> nombre;
                    fflush(stdin);
                    cout << "Ingresar el" << " precio del articulo [S/.] " << i << "): ";
                    cin >> precio;
                    fflush(stdin);
                    cout << "Ingresar la cantidad del articulo " << i << "): ";
                    cin >> cantArticulo;
                    fflush(stdin);
                    insertarArticulo(listarItem, codigo, nombre, precio, cantArticulo);
                }
                cout << endl << "==================" << endl;
                cout << "Se ingreso correctamente los pedidos" << endl;
                cout << "==================" << endl;
                system("pause");
                break;
            case 2:
                cout << "Mostrando todos los productos que recien se ingresaron ...\n\n";
                imprimirMemory(listarItem);
                liberar(&listarItem);
                system("pause");
                break;
            case 3:
                cout << "\nIngrese codigo del Producto : ";
                cin >> codigo;
                //buscar(listarItem, codigo);
                buscar(codigo);
                liberar(&listarItem);
                break;
            case 4:
                cout << "\nIngrese el codigo para eliminar el Producto : ";
                cin >> codigo;
                //eliminar(listarItem, codigo);
                borrar(codigo);
                cout << endl << "==================" << endl;
                cout << "Se elimino correctamente el producto del codigo -> " << codigo << endl;
                cout << "==================" << endl;
                system("pause");
                break;
            case 5:
                cout << "Mostrando el historial de productos  guardados\n\n";
                cargarArticulo();
                liberar(&listarItem);
                break;
                //default:
                //    cout << "\n\nOpcion no valida !!!";
                //    getch();
        }
        system("cls");
    } while (opc != 0);
}

void menuMain() {
    SetConsoleTitle("MENU PRINCIPAL");
    int opc;
    do {

        cout << "\n\n";
        cout << "\t#########";
        cout << "# M E N U  P R I N C I P A L #";
        cout << "#########   Fecha y Hora: ", dateTime();
        cout << "\n\t1 - Productos";
        cout << "\n\t2 - Clientes";
        cout << "\n\t3 - Transacciones";
        cout << "\n\t4 - Configuraciones";
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
                menuItems();
                break;
            case 2:
                menuCustomers();
                break;
            case 3:
                //cout << "\nTransacciones en Mantenimiento :-( ";
                menufactura();
                break;
            case 4:
                cout << "\nConfiguraciones en Mantenimiento :-(  ";
                break;
            default:
                cout << "\n\nOpcion no valida !!!";
                getch();
        }
    } while (opc);
}