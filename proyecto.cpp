#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "clientes.csv"
using namespace std;

struct Usuario
{
    string nombre;
    string apellido;
    string cbu;
    string pin;
    double balance;
};

// menu
void mostrarMenu()
{

    cout << "OPCIONES" << endl;
    cout << " " << endl;
    cout << "1- Balance" << endl;
    cout << "2- Deposito" << endl;
    cout << "3- Retiro" << endl;
    cout << "4- Tranferir" << endl;
    cout << "5- Salir" << endl;
    cout << "----------------" << endl;
}

//--------------
// fijate si podes mirar lo que hice abajo, lo pense de estar forma con la funcion de leerUsuario, no se como lo habias pensado vos.
//  funciones archivo

string pedirCbu()
{
    string cbu;
    cout << "Ingrese su cbu: ";
    cin >> cbu;

    return cbu;
}

string pedirPin()
{
    string pin;
    cout << "Ingrese su pin: ";
    cin >> pin;

    return pin;
}

// devuelve objeto archivo.
ifstream leerArchivo()
{
    // abrirarchivo
    ifstream archivo(NOMBRE_ARCHIVO);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return archivo;
}

// depositar
void depositar(Usuario &usuario)
{
    double deposito;
    cout << "Ingrese el monto a depositar: ";
    cin >> deposito;

    usuario.balance += deposito;
    cout << "Su nuevo balance es: " << usuario.balance << endl;

    //FALTA reescribir el nuevo balance en el archivo.
    //lee el archivo
    ifstream archivo = leerArchivo();
    //hacete este vos y yo sigo con el de retiro y algun otro
}

void retirar(Usuario &usuario)
{
    double retiro;
    cout << "Ingrese el monto a retirar: ";
    cin >> retiro;

    usuario.balance -= retiro;

    cout << "Su nuevo balance es: " << usuario.balance << endl;

    //FALTA reescribir el nuevo balance en el archivo.
    //lee archivo
    ifstream archivo = leerArchivo();
}

// aun no implementada
void escribirArchivo(string parametros)
{
    leerArchivo();
    ofstream archivo(NOMBRE_ARCHIVO);

    archivo << parametros << endl;

    archivo.close();
}

// devuelve objeto/struct usuario.
Usuario leerUsuario()
{
    ifstream archivo = leerArchivo();
    string linea;
    char delimitador = ',';
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

        string cbuPedido = pedirCbu();
        string pinPedido = pedirPin();

        // se podria hacer una funcion que valide el cbu
        if ((cbu == cbuPedido) && (pin == pinPedido))
        {
            // crea objecto/struct usuario
            Usuario usuario;
            usuario.nombre = nombre;
            usuario.apellido = apellido;
            usuario.cbu = cbu;
            // convierte el string balance a double.
            stringstream balanceStream(balance);
            balanceStream >> usuario.balance;

            // mostrar info
            cout << "Bienvenido" << endl;
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;
            cout << "CBU: " << usuario.cbu << endl;

            return usuario;
        }
    }

    cout << "No se encontro un usuario con ese cbu o el pin es incorrecto" << endl;

    archivo.close();
    // devuelve vacio
    return Usuario{};
}

int main()
{
    Usuario nuevoUsuario = leerUsuario();
    mostrarMenu();
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "$ " << nuevoUsuario.balance << endl;
        break;
    case 2:
        depositar(nuevoUsuario);
        break;
    case 3:
        retirar(nuevoUsuario);
        break;
    default:
        cout << "Opcion incorrecta" << endl;
        break;
    }

    return 0;
}