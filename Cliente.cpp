#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string nombre;
    int edad;
    string DNI;
    string apellido;
    Nodo* der;
    Nodo* izq;
    Nodo* Daddy;
};

void menu();
Nodo* crearNodo(int, string, string,string, string, Nodo*);
void insertarNodo(Nodo*&, int, string,string, string, Nodo*);
void mostrarArbol(Nodo*, int);
bool busqueda(Nodo*, int);
int busquedaiterativa(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destNodo(Nodo*);


Nodo* arbol = NULL;
Nodo* bus = NULL;

int main() {
    menu();
}

void menu() {
    int dato, opcion, contador = 0;
    string nombre,ap, codigo, dni;
    do {
        cout << "\t...:::|MINI MARKET|:::...\n\n"<< endl;
        cout << "\t############## MENU ##############\n" <<endl;
        cout << "\t1. Registrar nuevo Cliente" << endl;
        cout << "\t2. Mostrar codigos de los Cliente" << endl;
        cout << "\t3. Buscar Clientes " << endl;
        //cout << "4. Buscar un elemento en los registros (Iterativa)" << endl;
        cout << "\t5. Recorrer en PreOrden" << endl;
        cout << "\t6. Recorrer en InOrden" << endl;
        cout << "\t7. Recorrer en PostOrden" << endl;
        cout << "\t8. Eliminar un Cliente" << endl;
        cout << "\t9. Salir" << endl;
        cout << "\t##################################\n" <<endl;
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

                insertarNodo(arbol, dato, nombre,ap, dni, NULL);
                cout << "\n";
                system("pause");
                break;

            case 2: cout << "\n...:::|Mostrando Registro del MINI MARKET|:::...\n\n";
                mostrarArbol(arbol, contador);
                cout << "\n";
                system("pause");
                break;


            case 3:
                cout << "\n..:::|Ingrese el DNI del Cliente que desea buscar|:::.. ";
                cin >> dato;
                if (busqueda(arbol, dato) == true) {
                    cout << "\nEl DNI " << dato << " a sido encontrado en los registros\n";
                    cout << "\nPertenece a: \n";
                    cout << "\t##################################\n" <<endl;
                    cout << "\tNOMBRE.......: " << bus->nombre << endl;
                    cout << "\tAPELLIDO.....: " << bus->apellido << endl;
                    cout << "\tDNI..........: " << bus->edad << endl;
                    cout << "\tEDAD.........: " << bus->DNI << endl;
                    cout << "\t##################################\n" <<endl;
                }
                else {
                    cout << "\nElemento no encontrado\n";
                }
                cout << "\n";
                system("pause");
                break;

            case 4:
                cout << "\n...:::|Ingrese el DNI del Cliente que desea buscar|:::... ";
                cin >> dato;
                if (busquedaiterativa(arbol, dato) == 1) {
                    cout << "\nLa edad" << dato << " a sido encontrado en los registros\n";
                    cout << "\nPertenece a: \n";
                    cout << "NOMBRE: " << bus->nombre << endl;
                    cout << "APELLIDO: " << bus->apellido << endl;
                    cout << "DNI: " << bus->edad << endl;
                    cout << "EDAD: " << bus->DNI << endl;
                }
                else {
                    cout << "\nElemento no encontrado\n";
                }
                cout << "\n";
                system("pause");
                break;


            case 5: cout << "\nRecorrido en PreOrden: ";
                preOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 6: cout << "\nRecorrido en InOrden: ";
                inOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 7: cout << "\nRecorrido en PostOrden: ";
                postOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;


            case 8: cout << "\n...:::|Ingrese el DNI del Cliente que desea eliminar del registro|:::...\n\n";
                cin >> dato;
                eliminar(arbol, dato);
                cout << "\n";
                system("pause");
                break;
        }
        system("cls");

    } while (opcion != 9);
}

Nodo* crearNodo(int n, string nombre,string ap, string dni, Nodo* Daddy) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->nombre = nombre;
    nuevo_nodo->apellido = ap;
    nuevo_nodo->edad = n;
    nuevo_nodo->DNI = dni;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->Daddy = Daddy;
    return nuevo_nodo;
}

void insertarNodo(Nodo*& arbol, int n, string nombre,string ap, string dni, Nodo* Daddy)
{
    if (arbol == NULL) {
        Nodo* nuevo_nodo = crearNodo(n, nombre,ap, dni, Daddy);
        arbol = nuevo_nodo;
    }
    else {
        int valorRaiz = arbol->edad;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n, nombre,ap, dni, arbol);
        }
        else if (n > valorRaiz) {
            insertarNodo(arbol->der, n, nombre,ap, dni, arbol);
        }
    }
}

void mostrarArbol(Nodo* arbol, int cont)
{
    string p1[1],p2[1];
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "        ";
        }
        p1[0] = toupper(arbol->nombre[0]);
        p2[0] = toupper(arbol->apellido[0]);
        cout << p1[0]<<p2[0]<< "-" << arbol->edad << "-" << arbol->DNI[0] << endl;

        mostrarArbol(arbol->izq, cont + 1);
    }
}


bool busqueda(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->edad == n) {
        bus = arbol;
        return true;
    }
    else if (n < arbol->edad) {
        return busqueda(arbol->izq, n);
    }
    else {
        return busqueda(arbol->der, n);
    }
}

int busquedaiterativa(Nodo* arbol, int dato) {
    while (arbol != NULL) {
        if (dato < arbol->edad) {
            arbol = arbol->izq;
        }
        else if (dato > arbol->edad) {
            arbol = arbol->der;
        }
        else {
            bus = arbol;
            return 1;
        }
    }
    return 0;
}

void preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        ;
        return;
    }
    else {
        cout << arbol->edad << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        ;
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->edad << " - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        ;
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->edad << " - ";
    }
}

void eliminar(Nodo* arbol, int n) {
    if (arbol == NULL) {
        ;
        return;
    }
    else if (n < arbol->edad) {
        eliminar(arbol->izq, n);
    }
    else if (n > arbol->edad) {
        eliminar(arbol->der, n);
    }
    else {
        eliminarNodo(arbol);
    }

}

Nodo* minimo(Nodo* arbol) {
    if (arbol == NULL) {
        ;
        return NULL;
    }
    if (arbol->izq) {
        return minimo(arbol->izq);
    }
    else {
        return arbol;

    }
}

void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->Daddy) {

        if (arbol->edad == arbol->Daddy->izq->edad) {
            arbol->Daddy->izq = nuevoNodo;
        }
        else if (arbol->edad == arbol->Daddy->der->edad) {
            arbol->Daddy->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {

        nuevoNodo->Daddy = arbol->Daddy;
    }

}

void destNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

void eliminarNodo(Nodo* nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo* menor = minimo(nodoEliminar->der);
        nodoEliminar->edad = menor->edad;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destNodo(nodoEliminar);
    }
    else {
        reemplazar(nodoEliminar, NULL);
        destNodo(nodoEliminar);
    }
}