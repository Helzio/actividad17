
#include "videogame.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Videogame videogame;
    Civilizacion c;

    int opcion;
    bool repetir = true;

    while (repetir)
    {
        cout << endl
             << "*** VIDEOJUEGO ***" << endl;
        cout << "1) Añadir nombre del jugador" << endl;
        cout << "2) Agregar civilización" << endl;
        cout << "3) Insertar civilización" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Obtener la primer civilización" << endl;
        cout << "6) Obtener la última civilización" << endl;
        cout << "7) Ordenar civilizaciones" << endl;
        cout << "8) Eliminar civilización" << endl;
        cout << "9) Buscar civilización por nombre" << endl;
        cout << "10) Modificar civilización" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Guardar" << endl;
        cout << "13) Cargar" << endl;
        cout << "0) Salir" << endl;
        cout << "Introduce una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << endl
                 << "*** Añadir nombre del jugador ***" << endl;
                 videogame.agregarNombreUsuario();
            break;
        case 2:
            cout << endl
                 << "*** Agregar civilización ***" << endl;
                 videogame.agregarCivilizacion();
            break;
        case 3:
            cout << endl
                 << "*** Insertar civilización ***" << endl;
                 videogame.insertarCivilizacion();
            break;
        case 4:
            cout << endl
                 << "*** Crear civilizaciones ***" << endl;
                 videogame.crearCivilizaciones();
            break;
        case 5:
            cout << endl
                 << "*** Obtener la primera civilización ***" << endl;
                 videogame.primeraCivilizacion();
            break;
        case 6:
            cout << endl
                 << "*** Obtener la última civilización ***" << endl;
                 videogame.ultimaCivilizacion();
            break;
        case 7:
                 videogame.ordenarCivilizaciones();
            break;
        case 8:
            cout << endl
                 << "*** Eliminar civilización ***" << endl;
                 videogame.eliminarCivilizacion();
            break;
        case 9:
            cout << endl
                 << "*** Buscar civilización por nombre ***" << endl;
                 videogame.buscarCivilizacion();
            break;
        case 10:
            cout << endl
                 << "*** Modificar civilización ***" << endl;
                 videogame.modificarCivilizacion();
            break;
        case 11:
            cout << endl
                 << "*** Resumen ***" << endl;
                 videogame.resumen();
            break;
        case 12:
            cout << endl
                 << "*** Guardar ***" << endl;
                 videogame.guardar();
            break;
        case 13:
            cout << endl
                 << "*** Cargar ***" << endl;
                 videogame.cargar();
            break;
        default:
            repetir = false;
            break;
        }
    }

    return 0;
}