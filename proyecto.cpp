#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO
using namespace std;

// encontrar cbu dentro de archivo
bool cbuEncontrado(string cbu, bool& cbuExiste){

}

// inicio de seccion
void inicioSeccion(){
    bool cbuExiste = false;
    string cbu;
    string pin;
    
    do{
        cout << "Ingrese el CBU del usuario";
        cin >> cbu;
        cbuEncontrado(archivo,cbu,cbuExiste); //archivo a agregar
    } while(cbuExiste =! false);

    cout << " " << endl;
    cout << "Ingrese el PIN del usuario";
    cin >> pin;

}
// menu
void mostrarMenu(){

    cout << "OPCIONES" << endl;
    cout << " " << endl;
    cout << "1- Balance" << endl;
    cout << "2- Deposito" << endl;
    cout << "3- Retiro" << endl;
    cout << "4- Tranferir" << endl;
    cout << "5- Salir" << endl;
    cout << "----------------" << endl;
    
}

// funciones archivo

void leerArchivo(){
    //abrirarchivo

}

void escribirArchivo(){

}

void guardarArchivo(){


    //no olvidar cerrararchivo
}

//funcion global que se le pase x parametro loq ue se quiere mostrar.
void mostrarDatos(){

}

void leerUsuario(){
    leerArchivo();
    mostrarDatos();
}

void ingresoPin(){


}


int main()
{
    mostrarMenu();

    return 0;
}