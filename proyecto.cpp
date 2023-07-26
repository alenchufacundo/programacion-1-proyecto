#include <iostream>
#include <stdlib.h>
#include <time.h>
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

void crear_usuario(Usuario &usuario)
{
    srand(time(NULL));
    int num;
    ofstream archivo("clientes.csv");

    if(!archivo)
    {
        cout << "Error al crear el archivo 'clientes.csv'" << endl;
    }
    else
    {
        string nombre, apellido, cbu, pin, balance;
        cout << "Ingrese su nombre: ";
        getline (cin,nombre);
        cout << "Ingrese su apellido: ";
        getline (cin,apellido);
        cout << "Ingrese un pin de 4 numeros: ";
        getline (cin, pin);
        num = 1 + rand() % (10000000000 - 1);
        if(num < 10)
        {
            std::to_string(num);
            num = '000000000' + num;
        }
        else if(num < 100)
        {
            std::to_string(num);
            num = '00000000' + num;
        }
        else if(num < 1000)
        {
            std::to_string(num);
            num = '0000000' + num;
        }
        else if(num < 10000)
        {
            std::to_string(num);
            num = '000000' + num;
        }
        else if(num < 100000)
        {
            std::to_string(num);
            num = '00000' + num;
        }
        else if(num < 1000000)
        {
            std::to_string(num);
            num = '0000' + num;
        }
        else if(num < 10000000)
        {
            std::to_string(num);
            num = '000' + num;
        }
        else if(num < 100000000)
        {
            std::to_string(num);
            num = '00' + num;
        }
        else if(num < 1000000000)
        {
            std::to_string(num);
            num = '0' + num;
        }
        cbu = num;
        cout << "Se ha generado su CBU... Este es: " << cbu << endl;
        cout << "Ingrese el importe que tendra su cuenta: ";
        getline(cin, balance);
        archivo << cbu + ',' + nombre + ',' + apellido + ',' + pin + ',' + balance;
        archivo.close();

        cout << "Se a creado su cuenta exitosamente." << endl;
    }
}
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
void actualizarBalanceEnArchivoDeposito(const Usuario &usuario)
{
    fstream archivo(NOMBRE_ARCHIVO);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string linea;
    string cbuBuscado = usuario.cbu;
    char delimitador = ',';
    string nuevoContenido;

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string cbu, nombre, apellido, pin, balanceStr;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balanceStr, delimitador);

        if (cbu == cbuBuscado)
        {
            nuevoContenido += cbu + ',' + nombre + ',' + apellido + ',' + pin + ',' + to_string(usuario.balance) + '\n';
        }
        else
        {
            nuevoContenido += linea + '\n';
        }
    }

    archivo.close();

    //LO GOOGLE para hacer esto 
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

// depositar
void depositar(Usuario &usuario)
{
    double deposito;
    cout << "Ingrese el monto a depositar: ";
    cin >> deposito;

    usuario.balance += deposito;
    cout << "Su nuevo balance es: " << usuario.balance << endl;

    actualizarBalanceEnArchivoDeposito(usuario);
}

void actualizarBalanceEnArchivoRetiro(const Usuario &usuario)
{
    fstream archivo(NOMBRE_ARCHIVO);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string linea;
    string cbuBuscado = usuario.cbu;
    char delimitador = ',';
    string nuevoContenido;

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string cbu, nombre, apellido, pin, balanceStr;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balanceStr, delimitador);

        if (cbu == cbuBuscado)
        {
            nuevoContenido += cbu + ',' + nombre + ',' + apellido + ',' + pin + ',' + to_string(usuario.balance) + '\n';
        }
        else
        {
            nuevoContenido += linea + '\n';
        }
    }

    archivo.close();

    //LO GOOGLE para hacer esto 
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

void retirar(Usuario &usuario)
{
    double retiro;
    cout << "Ingrese el monto a depositar: ";
    cin >> retiro;

    usuario.balance -= retiro;
    cout << "Su nuevo balance es: " << usuario.balance << endl;

    actualizarBalanceEnArchivoRetiro(usuario);
}

void actualizarBalanceEnArchivoTransferencia(const Usuario &usuario)
{
    fstream archivo(NOMBRE_ARCHIVO);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string linea;
    string cbuBuscado = usuario.cbu;
    char delimitador = ',';
    string nuevoContenido;

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string cbu, nombre, apellido, pin, balanceStr;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balanceStr, delimitador);

        if (cbu == cbuBuscado)
        {
            nuevoContenido += cbu + ',' + nombre + ',' + apellido + ',' + pin + ',' + to_string(usuario.balance) + '\n';
        }
        else
        {
            nuevoContenido += linea + '\n';
        }
    }

    archivo.close();

    //LO GOOGLE para hacer esto 
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

void transferir(Usuario &usuario)
{
    ifstream archivo = leerArchivo();
    string linea;
    string cbuPedido;
    char delimitador = ',';
    bool usuarioEncontrado = false;
    double transferir;

    cout << "Ingrese el cbu de la cuenta que quiera tranferir: ";
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

        cbuPedido = pedirCbu();

        if (cbu == cbuPedido)
        {
            usuario.nombre = nombre;
            usuario.apellido = apellido;
            cout << "Usuario a tranferir" << endl;
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;

            usuarioEncontrado = true;
        }
    }
    if(usuarioEncontrado != true)
    {
        cout << "No se a encontrado el ususario que busca." << endl;
    }
    else
    {
    cout << "Ingrese el monto a depositar: ";
    cin >> transferir;

    usuario.balance -= transferir;
    cout << "Su nuevo balance es: " << usuario.balance << endl;
    //FALTA como actualizar el balance del otro usuario al tranferir
    actualizarBalanceEnArchivoTransferencia(usuario);
    }
}

// devuelve objeto/struct usuario.
Usuario leerUsuario()
{
    ifstream archivo = leerArchivo();
    string linea;
    char delimitador = ',';
    bool usuarioEncontrado = false;
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

            usuarioEncontrado = true;
            return usuario;
        }
    }
    if(usuarioEncontrado != true)
    {
        cout << "No se encontro un usuario con ese cbu o el pin es incorrecto" << endl;
    }

    archivo.close();
    // devuelve vacio
    return Usuario{};
}

int main()
{
    Usuario nuevoUsuario = leerUsuario();
    int opcion;
    bool salida = false;

    while (!salida)
    {

        mostrarMenu();
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
        case 4:
            transferir(nuevoUsuario);
            break;
        case 5:
            cout << "Cerrando seccion" << endl;
            salida = true;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }

    return 0;
}