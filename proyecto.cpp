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
    double balance;
}

// encontrar cbu dentro de archivo
bool
cbuEncontrado(string cbu, bool &cbuExiste)
{
}

// inicio de seccion
void inicioSeccion()
{
    bool cbuExiste = false;
    string cbu;
    string pin;

    do
    {
        cout << "Ingrese el CBU del usuario";
        cin >> cbu;
        cbuEncontrado(archivo, cbu, cbuExiste); // archivo a agregar
    } while (cbuExiste = !false);

    cout << " " << endl;
    cout << "Ingrese el PIN del usuario";
    cin >> pin;
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

// funciones archivo

ifstream leerArchivo()
{
    // abrirarchivo
    ifstream archivo(NOMBRE_ARCHIVO);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    return archivo;
}



void escribirArchivo(string parametros)
{
    leerArchivo();
    ofstream archivo(NOMBRE_ARCHIVO);

    archivo << parametros << endl;

    archivo.close();
}

// se le pasa el cbu
void leerUsuario(string &cbu)
{
    ifstream archivo = leerArchivo();
    string linea;
    char delimitador = ',';
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, balance;
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, cbu, delimitador);
        getline(stream, balance, delimitador);

        if (cbu == cbu)
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
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;
            cout << "CBU: " << usuario.cbu << endl;
            cout << "Balance  : " << usuario.balance << endl;

            return;
        }
    }
    cout << "No se encontro un usuario con ese cbu" << endl;

   archivo.close();
}

void ingresoPin()
{
}

int main()
{
    mostrarMenu();

    return 0;
}