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

string comprobarBalance()
{
    string balance;
    int contador, contErrores, contNumCorrectos = 0;
    bool numCorrecto = true;

    do
    {
        cout << "Ingrese el importe: ";
        cin >> balance;
        contErrores = 0;
        contador = balance.length();
        for (int i = 0; i < contador; i++)
        {
            numCorrecto = false;
            for (int j = 0; j < 10; j++)
            {
                switch (j)
                {
                case 0:
                    if (balance[i] == '0')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 1:
                    if (balance[i] == '1')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 2:
                    if (balance[i] == '2')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 3:
                    if (balance[i] == '3')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 4:
                    if (balance[i] == '4')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 5:
                    if (balance[i] == '5')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 6:
                    if (balance[i] == '6')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 7:
                    if (balance[i] == '7')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 8:
                    if (balance[i] == '8')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 9:
                    if (balance[i] == '9')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                }
            }
            if (numCorrecto == false)
            {
                cout << i + 1 << ". ERROR: Caracter invalido" << endl;
                contErrores += 1;
            }
        }
        if (contErrores == 0)
        {
            cout << "Verificacion de balance: correcto" << endl;
            return balance;
        }
        else
        {
            cout << "Verificacion de balance: incorrecto" << endl;
            cout << "Cantidad de Errores: " << contErrores << endl;
            numCorrecto = false;
        }
    } while (numCorrecto == false);

    return "0.00";
}

double comprobarBalanceOperaciones()
{
    string balance;
    int contador, contErrores, contNumCorrectos = 0;
    bool numCorrecto = true;

    do
    {
        cout << "Ingrese el importe: ";
        cin >> balance;
        contErrores = 0;
        contador = balance.length();
        for (int i = 0; i < contador; i++)
        {
            numCorrecto = false;
            for (int j = 0; j < 10; j++)
            {
                switch (j)
                {
                case 0:
                    if (balance[i] == '0')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 1:
                    if (balance[i] == '1')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 2:
                    if (balance[i] == '2')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 3:
                    if (balance[i] == '3')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 4:
                    if (balance[i] == '4')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 5:
                    if (balance[i] == '5')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 6:
                    if (balance[i] == '6')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 7:
                    if (balance[i] == '7')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 8:
                    if (balance[i] == '8')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                case 9:
                    if (balance[i] == '9')
                    {
                        contNumCorrectos += 1;
                        numCorrecto = true;
                    }
                    break;
                }
            }
            if (numCorrecto == false)
            {
                cout << i + 1 << ". ERROR: Caracter invalido" << endl;
                contErrores += 1;
            }
        }
        if (contErrores == 0)
        {
            cout << "Verificacion de balance: correcto" << endl;
            //convierte string a double
            return stod(balance);
        }
        else
        {
            cout << "Verificacion de balance: incorrecto" << endl;
            cout << "Cantidad de Errores: " << contErrores << endl;
            numCorrecto = false;
        }
    } while (numCorrecto == false);

    return 0.0;
}

int comprobarOpcion()
{
    string datoEntrada;
    while (true)
    {
        cout << "Ingrese una opcion: ";
        cin >> datoEntrada;

        bool esEntero = true;
        int opcion = 0;

        // foreach bucle
        for (char c : datoEntrada)
        {
            if (c >= '0' && c <= '9')
            {
                opcion = opcion * 10 + (c - '0');
            }
            else
            {
                esEntero = false;
                break;
            }
        }

        if (esEntero && opcion >= 1 && opcion <= 2)
        {
            return opcion;
        }
        cout << "Error: La opcion ingresada no es una opcion valida." << endl;
    }
}

int comprobarOpcionSubMenu()
{
    string datoEntrada;
    while (true)
    {
        cout << "Ingrese una opcion: ";
        cin >> datoEntrada;

        bool esEntero = true;
        int opcion = 0;

        // foreach bucle
        for (char c : datoEntrada)
        {
            if (c >= '0' && c <= '9')
            {
                opcion = opcion * 10 + (c - '0');
            }
            else
            {
                esEntero = false;
                break;
            }
        }

        if (esEntero && opcion >= 1 && opcion <= 5)
        {
            return opcion;
        }
        cout << "Error: La opcion ingresada no es una opcion valida." << endl;
    }
}


void crear_usuario(Usuario &usuario)
{
    srand(time(NULL));
    int num;
    fstream archivo(NOMBRE_ARCHIVO, ios::app); // esto es para que lo abre en forma de escritura y que el nuevo contenido se agrege al final.
    if (!archivo)
    {
        cout << "Error al abrir el archivo 'clientes.csv'" << endl;
    }
    else
    {
        int contador, contNumCorrectos = 0, contErrores = 0;
        char cambio;
        bool numCorrecto, pinCorrecto = false;
        string nombre, apellido, cbu, pin, balance;
        cin.ignore();
        cout << "Ingrese su nombre: ";
        getline(cin, nombre);
        "\n";
        cout << "Ingrese su apellido: ";
        getline(cin, apellido);
        do
        {
            contErrores = 0;
            numCorrecto = false;
            cout << "Ingrese un pin de 4 numeros: ";
            cin >> pin;
            contador = pin.length();
            if (pin.length() == 4)
            {
                for (int i = 0; i < contador; i++)
                {
                    numCorrecto = false;
                    for (int j = 0; j < 10; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            if (pin[i] == '0')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 1:
                            if (pin[i] == '1')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 2:
                            if (pin[i] == '2')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 3:
                            if (pin[i] == '3')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 4:
                            if (pin[i] == '4')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 5:
                            if (pin[i] == '5')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 6:
                            if (pin[i] == '6')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 7:
                            if (pin[i] == '7')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 8:
                            if (pin[i] == '8')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        case 9:
                            if (pin[i] == '9')
                            {
                                contNumCorrectos += 1;
                                numCorrecto = true;
                            }
                            break;
                        }
                    }
                    if (numCorrecto == false)
                    {
                        cout << i + 1 << ". ERROR: Caracter invalido" << endl;
                        contErrores += 1;
                    }
                }
                if (contErrores == 0)
                {
                    cout << "Verificacion de pin: correcto" << endl;
                }
                else
                {
                    cout << "Verificacion de pin: incorrecto" << endl;
                    cout << "Cantidad de Errores: " << contErrores << endl;
                    numCorrecto = false;
                }
            }
            else
            {
                cout << "Por favor, ingresar un numero de 4 cifras" << endl;
            }

            if ((pin.length() == 4) && (numCorrecto == true))
            {
                pinCorrecto = true;
            }
        } while (pinCorrecto != true);

        num = rand() % 10000000000;
        // funcion que convierte el numero aleatorio en string.
        cbu = to_string(num);

        // al 10 se le resta la longitud del cbu y se le agregan 0 a la izquierda.
        cbu = string(10 - cbu.length(), '0') + cbu;
        cout << "Se ha generado su CBU: " << cbu << endl;

        balance = comprobarBalance();

        archivo << cbu + ',' + nombre + ',' + apellido + ',' + pin + ',' + balance << endl;

        archivo.close();

        cout << "Se ha creado su cuenta exitosamente." << endl;
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
    cout << "Ingrese su CBU: ";
    cin >> cbu;

    return cbu;
}

string pedirPin()
{
    string pin;
    cout << "Ingrese su PIN: ";
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
void actualizarBalanceEnArchivoDeposito(Usuario &usuario)
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

    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

// depositar
void depositar(Usuario &usuario)
{
    double deposito;
    deposito = comprobarBalanceOperaciones();

    usuario.balance += deposito;
    cout << "Su nuevo balance es: " << usuario.balance << endl;

    actualizarBalanceEnArchivoDeposito(usuario);
}

void actualizarBalanceEnArchivoRetiro(Usuario &usuario)
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

    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::trunc);
    archivo << nuevoContenido;
    archivo.close();
}

void retirar(Usuario &usuario)
{
    double retiro;
    retiro = comprobarBalanceOperaciones();

    usuario.balance -= retiro;
    cout << "Su nuevo balance es: " << usuario.balance << endl;

    actualizarBalanceEnArchivoRetiro(usuario);
}

void actualizarBalanceEnArchivoTransferencia(Usuario &usuario)
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
    bool cbuDestinoEncontrado = false;
    double transferir;

    cout << "Ingrese el CBU de la cuenta de destino: ";
    cin >> cbuDestino;

    cbuPedido = pedirCbu();

    // Verificar si el CBU destino existe
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string cbu, nombre, apellido, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

        if (cbu == cbuDestino)
        {
            cbuDestinoEncontrado = true;
            break;
        }
    }
    archivo.close();

    if (!cbuDestinoEncontrado)
    {
        cout << "El CBU destino no se encuentra en el archivo" << endl;
        return;
    }

    archivo.open(NOMBRE_ARCHIVO);

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

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

    if (!usuarioEncontrado)
    {
        cout << "No se encontró el usuario que busca." << endl;
        return;
    }
    else
    {
        cout << "Su balance es: " << usuario.balance << endl;
        transferir = comprobarBalanceOperaciones();

        if (transferir > usuario.balance)
        {
            cout << "No tiene suficiente balance en la cuenta para realizar la transferencia" << endl;
            return;
        }

        usuario.balance -= transferir;
        cout << "Su nuevo balance es: " << usuario.balance << endl;
        actualizarBalanceEnArchivoTransferencia(usuario);
    }

    // Continuar con la transferencia
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
            cout << "Nuevo balance del destinatario: "
                 << "****" << endl;

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
    Usuario usuario;

    string cbuPedido = pedirCbu();
    string pinPedido = pedirPin();

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string cbu, nombre, apellido, pin, balance;
        getline(stream, cbu, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, pin, delimitador);
        getline(stream, balance, delimitador);

        if (cbu == cbuPedido && pin == pinPedido)
        {
            usuario.nombre = nombre;
            usuario.apellido = apellido;
            usuario.cbu = cbu;
            stringstream balanceStream(balance);
            balanceStream >> usuario.balance;
            cout << "Bienvenido" << endl;
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;
            cout << "CBU: " << usuario.cbu << endl;
            usuarioEncontrado = true;
            break;
        }
    }

    if (!usuarioEncontrado)
    {
        cout << "No se encontró un usuario con ese CBU o PIN incorrecto" << endl;
        cout << "Vuelva a iniciarlo nuevamente" << endl;
        exit(EXIT_FAILURE);
    }

    archivo.close();
    return usuario;
}


int main()
{
    Usuario nuevoUsuario;
    int opcion;
    bool salida = false;
    bool usuarioIngresado = false;

    while (!usuarioIngresado)
    {
        cout << "Bienvenido al cajero virtual automatico" << endl;
        cout << "Opciones" << endl;
        cout << "1- Ingresar mi usuario" << endl;
        cout << "2- Crear un usuario" << endl;
        opcion = comprobarOpcion();

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingresando usuario ..." << endl;
            nuevoUsuario = leerUsuario();
            usuarioIngresado = true;
            break;
        }
        case 2:
            cout << "Creando usuario ..." << endl;
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
        opcion = comprobarOpcionSubMenu();

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