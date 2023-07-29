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
    const int N = 10;
    srand(time(NULL));
    typedef int tAnum[N];
    tAnum num;
    int numX = 0, numZ;
    ofstream archivo("clientes.csv");

    if(!archivo)
    {
        cout << "Error al crear el archivo 'clientes.csv'" << endl;
    }
    else
    {
        int cantidadCaracteres;
        string nombre, apellido, cbu, pin, balance;
        cout << "Ingrese su nombre: ";
        getline (cin,nombre);
        cout << "Ingrese su apellido: ";
        getline (cin,apellido);
        cout << "Ingrese un pin de 4 numeros: ";
        getline (cin, pin);

        for(int i = 0; i < N; i++)
        {
            numX = 1 + rand() % (10 - 1);
            num[i] = numX;
        }

        for(int i = 8; i > 0 ; i--)
        {
            if(i == 8)
            {
                numX = num[i];
                numX = numX * 10; 
            }
            else if(i == 7)
            {
                numX = num[i];
                numX = numX * 100;
            }
            else if(i == 6)
            {
                numX = num[i];
                numX = numX * 1000;
            }
            else if(i == 5)
            {
                numX = num[i];
                numX = numX * 10000;
            }
            else if(i == 4)
            {
                numX = num[i];
                numX = numX * 100000;
            }
            else if(i == 3)
            {
                numX = num[i];
                numX = numX * 1000000;
            }
            else if(i == 2)
            {
                numX = num[i];
                numX = numX * 10000000;
            }
            else if(i == 1)
            {
                numX = num[i];
                numX = numX * 100000000;
            }
            else
            {
                numX = num[i];
                numX = numX * 1000000000;
            }
            numX += numX;
        }
        numZ = num[9] + numX;
        
        cbu = to_string(numZ);
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

    // LO GOOGLE para hacer esto
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

    // LO GOOGLE para hacer esto
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

void retirar(Usuario &usuario)
{
    double retiro;
    cout << "Ingrese el monto a retirar: ";
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

    // LO GOOGLE para hacer esto
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

void transferir(Usuario &usuario)
{
    ifstream archivo = leerArchivo();
    string linea;
    string cbuPedido;
    string cbuDestino;
    char delimitador = ',';
    bool usuarioEncontrado = false;
    double transferir;

    cout << "Ingrese el cbu de la cuenta que quiera tranferir: ";
    cin >> cbuDestino;
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

        if ((cbu == cbuPedido) && (cbu != cbuDestino))
        {
            
            usuario.nombre = nombre;
            usuario.apellido = apellido;
            usuario.cbu = cbu;
            stringstream balanceStream(balance);
            balanceStream >> usuario.balance;
            cout << "Usuario actual: " << endl;
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;

            usuarioEncontrado = true;
            break;
        }
    }

    archivo.close();

    if (usuarioEncontrado != true)
    {
        cout << "No se a encontrado el usuario que busca." << endl;
    }
    else
    {
        cout << "Ingrese el monto a depositar: ";
        cin >> transferir;

        if (transferir > usuario.balance)
        {
            cout << "No tiene suficiente balance en la cuenta para realizar la trasnferencia" << endl;
            return;
        }

        usuario.balance -= transferir;
        cout << "Su nuevo balance es: " << usuario.balance << endl;
        actualizarBalanceEnArchivoTransferencia(usuario);
    }

    // Buscar al destinatario de la transferencia
    archivo.open(NOMBRE_ARCHIVO);
    Usuario destinatario;
    usuarioEncontrado = false;

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

        if (cbu == cbuDestino)
        {
            destinatario.nombre = nombre;
            destinatario.apellido = apellido;
            destinatario.cbu = cbu;
            // convierte el string balance a double.
            stringstream balanceStream(balance);
            balanceStream >> destinatario.balance;

            cout << "Usuario de destino de la transferencia: " << endl;
            cout << "Nombre: " << destinatario.nombre << endl;
            cout << "Apellido: " << destinatario.apellido << endl;

            destinatario.balance += transferir;
            cout << "Nuevo balance del destinatario: " << destinatario.balance << endl;

            usuarioEncontrado = true;
            break;
        }
    }
    archivo.close();

    if (!usuarioEncontrado)
    {
        cout << "No se encontró el destinatario de la transferencia" << endl;
        return;
    }

    // Actualizar balance del destinatario en el archivo
    actualizarBalanceEnArchivoTransferencia(destinatario);
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
    if (usuarioEncontrado != true)
    {
        cout << "No se encontro un usuario con ese cbu o el pin es incorrecto" << endl;
    }

    archivo.close();
    // devuelve vacio
    return Usuario{};
}

int main()
{
    Usuario nuevoUsuario; // = leerUsuario(); Anterior Funcion
    int opcion;
    bool salida = false;

    while(!salida)
    {
        cout << "1- Ingresar mi usuario" << endl;
        cout << "2- Crear un usuario" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingresando usuario" << endl;
            nuevoUsuario = leerUsuario();
            salida = true;
            break;
        case 2:
            cout << "Creando usuario" << endl;
            crear_usuario(nuevoUsuario);
            break;
        default:
            cout << "Error, no se ingreso una de las opciones" << endl;
            break;
        }
    }

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