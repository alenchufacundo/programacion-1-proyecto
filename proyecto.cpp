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

// encontrar cbu dentro de archivo
bool cbuEncontrado(string cbu, bool &cbuExiste)
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

void escribirArchivo(string parametros)
{
    leerArchivo();
    ofstream archivo(NOMBRE_ARCHIVO);

    archivo << parametros << endl;

    archivo.close();
}


// se le pasa el cbu
void leerUsuario()
{
    ifstream archivo = leerArchivo();
    string linea;
    char delimitador = ',';
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string nombre, apellido, cbu, pin;
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, cbu, delimitador);
        getline(stream, pin, delimitador);

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

            // mostrar info
            cout << "Nombre: " << usuario.nombre << endl;
            cout << "Apellido: " << usuario.apellido << endl;
            cout << "CBU: " << usuario.cbu << endl;

            return;
        }
    }

    cout << "No se encontro un usuario con ese cbu o el pin es incorrecto" << endl;

    archivo.close();
}

int main()
{
    leerUsuario();
    mostrarMenu();

    return 0;
}