#include "videogame.h"
using namespace std;

Videogame::Videogame()
{
}

void Videogame::agregarNombreUsuario()
{
    if (nombreUsuario.size() == 0)
    {
        string st;
        cout << "Nombre del jugador: ";
        getline(cin, st);
        nombreUsuario = st;
        cout << "Usuario registrado correctamente." << endl;
    }
    else
    {
        while (true)
        {
            cout << "Ya hay un jugador registrado quieres reemplazarlo" << endl
                 << "S/N: ";
            string seleccion;
            cin >> seleccion;
            cin.ignore();

            if (seleccion == "s" || seleccion == "S")
            {
                nombreUsuario = "";
                agregarNombreUsuario();
                break;
            }
            else if (seleccion == "n" || seleccion == "N")
            {
                return;
            }
        }
    }
}

void Videogame::agregarCivilizacion()
{

    cout << "Civilización: " << endl;
    Civilizacion c;
    cin >> c;
    civilizaciones.push_back(c);
    cout << "Civilizacion agregada correctamente." << endl;
}

void Videogame::insertarCivilizacion()
{

    cout << "Posición: ";
    int p;
    cin >> p;
    cin.ignore();

    if (p >= 0 && p <= civilizaciones.size())
    {
        cout << "Civilización: " << endl;
        Civilizacion c;
        cin >> c;
        civilizaciones.insert(civilizaciones.begin() + p, c);

        cout << "Civilizacion insertada correctamente." << endl;
    }
    else
    {
        cout << "La posición en la que se desea insertar la civilización es incorrecta." << endl;
    }
}

void Videogame::crearCivilizaciones()
{

    cout << "Número de civilizaciones: ";
    int p;
    cin >> p;
    cin.ignore();

    cout << "Civilización: " << endl;
    Civilizacion c;
    cin >> c;
    civilizaciones = vector<Civilizacion>(p, c);

    cout << "Civilizaciones creadas correctamente." << endl;
}

void Videogame::primeraCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
        cout << "Primera civilización: " << endl;
        // encabezado
        cout << left;
        cout << setw(17) << "Nombre:";
        cout << setw(17) << "Pos X:";
        cout << setw(17) << "Pos Y:";
        cout << setw(17) << "Score:" << endl;
        cout << civilizaciones.front() << endl;
    }
    else
    {
        cout << "No hay ninguna civilización para mostrar." << endl;
    }
}

void Videogame::ultimaCivilizacion()
{

    if (civilizaciones.size() > 0)
    {
        cout << "Última civilización: " << endl;
        // encabezado
        cout << left;
        cout << setw(17) << "Nombre:";
        cout << setw(17) << "Pos X:";
        cout << setw(17) << "Pos Y:";
        cout << setw(17) << "Score:" << endl;
        cout << civilizaciones.back() << endl;
    }
    else
    {
        cout << "No hay civilizaciones agregadas al juego." << endl;
    }
}

void Videogame::ordenarCivilizaciones()
{
    if (civilizaciones.size() > 0)
    {
        int opcion;
        bool repetir = true;

        while (repetir)
        {
            cout << endl
                 << "*** Ordenar civilizaciones ***" << endl;
            cout << "1) Por nombre" << endl;
            cout << "2) Por ubicación en X" << endl;
            cout << "3) Por ubicación en Y" << endl;
            cout << "4) Por puntuación" << endl;
            cout << "Introduce una opción: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion)
            {
            case 1:
                cout << endl
                     << "*** Ordenar civilizaciones por nombre ***" << endl;
                ordenarCivilizacionesPorNombre();
                repetir = false;
                break;
            case 2:
                cout << endl
                     << "*** Ordenar civilizaciones por ubicación en X ***" << endl;
                ordenarCivilizacionesPorX();
                repetir = false;
                break;
            case 3:
                cout << endl
                     << "*** Ordenar civilizaciones por ubicación en Y ***" << endl;
                ordenarCivilizacionesPorY();
                repetir = false;
                break;
            case 4:
                cout << endl
                     << "*** Ordenar civilizaciones por puntuación ***" << endl;
                ordenarCivilizacionesPorPuntuacion();
                repetir = false;
                break;
            default:
                cout << endl
                     << "La opción ingresada es incorrecta." << endl;
                break;
            }
        }
    }
    else
    {
        cout << "No hay ninguna civilización para mostrar." << endl;
    }
}

void Videogame::ordenarCivilizacionesPorNombre()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getNombre() < c2.getNombre();
    });
    resumen();
}

void Videogame::ordenarCivilizacionesPorX()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getX() < c2.getX();
    });
    resumen();
}

void Videogame::ordenarCivilizacionesPorY()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getY() < c2.getY();
    });
    resumen();
}

void Videogame::ordenarCivilizacionesPorPuntuacion()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getPuntuacion() > c2.getPuntuacion();
    });
    resumen();
}

void Videogame::eliminarCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
        string nombre;
        cout << endl
             << "Introduce el nombre de la civilización que deseas eliminar:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);

        auto resultado = find(civilizaciones.begin(), civilizaciones.end(), nombre);
        if (resultado != civilizaciones.end())
        {
            civilizaciones.erase(resultado);
            cout << endl
                 << "Se ha eliminado la civilización: " << nombre << endl;
            resumen();
        }

        else
        {
            cout << "No se encontro ninguna civilización con el nombre: " << nombre << "." << endl;
        }
    }
    else
    {
        cout << "La lista de civilizaciones esta vacía." << endl;
    }
}

void Videogame::buscarCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
        string nombre;
        cout << endl
             << "Introduce el nombre de la civilización que deseas encontrar:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);

        auto resultado = find(civilizaciones.begin(), civilizaciones.end(), nombre);
        if (resultado != civilizaciones.end())
        {

            Civilizacion &c = *resultado;
            int opcion;
            bool repetir = true;

            cout << endl
                 << "*** Civilización encontrada ***" << endl;
            // encabezado
            cout << left;
            cout << setw(17) << "Nombre:";
            cout << setw(17) << "Pos X:";
            cout << setw(17) << "Pos Y:";
            cout << setw(17) << "Score:" << endl;
            cout << *resultado << endl
                 << endl;

            while (repetir)
            {
                cout << endl
                     << "*** Menú de la civilización: " << c.getNombre() << " ***" << endl;

                cout << "1) Agregar aldeano." << endl;
                cout << "2) Eliminar aldeano." << endl;
                cout << "3) Clasificar aldeanos." << endl;
                cout << "4) Buscar aldeano." << endl;
                cout << "5) Modificar aldeano." << endl;
                cout << "6) Mostrar aldeanos." << endl;
                cout << "*** Barcos ***" << endl;
                cout << "7) Agregar barco." << endl;
                cout << "8) Mostrar barcos." << endl;
                cout << "9) Buscar barco." << endl;
                cout << "10) Eliminar barco." << endl;
                cout << "0) Salir" << endl;
                cout << "Introduce una opción: ";
                cin >> opcion;
                cin.ignore();

                switch (opcion)
                {
                case 1:
                    c.agregarAldeano();
                    break;
                case 2:
                    if (resultado->getAldeanos().size() == 0)
                    {
                        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
                    }
                    else
                    {
                        c.eliminarAldeanos();
                    }
                    break;
                case 3:
                    if (resultado->getAldeanos().size() == 0)
                    {
                        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
                    }
                    else
                    {
                        c.clasificarAldeanos();
                    }
                    break;
                case 4:
                    if (resultado->getAldeanos().size() == 0)
                    {
                        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
                    }
                    else
                    {
                        c.buscarAldeano();
                    }
                    break;
                case 5:
                    if (resultado->getAldeanos().size() == 0)
                    {
                        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
                    }
                    else
                    {
                        c.modificarAldeano();
                    }
                    break;
                    break;
                case 6:
                    if (resultado->getAldeanos().size() == 0)
                    {
                        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
                    }
                    else
                    {
                        c.mostrarAldeanos();
                    }
                    break;
                case 7:
                    c.agregarBarco();
                    break;
                case 8:
                    c.mostrarBarcos();
                    break;
                case 9:
                    c.buscarBarco();
                    break;
                case 10:
                    c.eliminarBarco();
                    break;
                default:
                    cout << endl
                         << "Saliendo." << endl;
                    repetir = false;
                    break;
                }
            }
        }

        else
        {
            cout << "No se encontro ninguna civilización con el nombre: " << nombre << "." << endl;
        }
    }
    else
    {
        cout << "La lista de civilizaciones esta vacía." << endl;
    }
}

void Videogame::modificarCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
        string nombre;
        string data;
        int i;
        cout << endl
             << "Introduce el nombre de la civilización que deseas modificar:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);

        auto resultado = find(civilizaciones.begin(), civilizaciones.end(), nombre);
        if (resultado != civilizaciones.end())
        {

            int opcion;
            bool repetir = true;

            while (repetir)
            {
                cout << endl
                     << endl
                     << "*** Civilizacion encontrada ***" << endl;
                // encabezado
                cout << left;
                cout << setw(17) << "Nombre:";
                cout << setw(17) << "Pos X:";
                cout << setw(17) << "Pos Y:";
                cout << setw(17) << "Score:" << endl;
                cout << *resultado << endl
                     << endl;
                cout << "1) Modificar nombre" << endl;
                cout << "2) Modificar ubicación en X" << endl;
                cout << "3) Modificar ubicación en Y" << endl;
                cout << "4) Modificar puntuación" << endl;
                cout << "0) Salir" << endl;
                cout << "Introduce una opción: ";
                cin >> opcion;
                cin.ignore();

                switch (opcion)
                {
                case 1:
                    cout << endl
                         << "Nuevo nombre: ";
                    getline(cin, data);
                    resultado->setNombre(data);
                    break;
                case 2:
                    cout << endl
                         << "Nueva posición X: ";
                    cin >> i;
                    cin.ignore();
                    resultado->setX(i);
                    break;
                case 3:
                    cout << endl
                         << "Nueva posición Y: ";
                    cin >> i;
                    cin.ignore();
                    resultado->setY(i);
                    break;
                case 4:
                    cout << endl
                         << "Nueva puntuación: ";
                    cin >> i;
                    cin.ignore();
                    resultado->setPuntuacion(i);
                    break;
                default:
                    cout << endl
                         << "Saliendo." << endl;
                    repetir = false;
                    break;
                }
            }
        }

        else
        {
            cout << "No se encontro ninguna civilización con el nombre: " << nombre << "." << endl;
        }
    }
    else
    {
        cout << "No hay ninguna civilización para mostrar." << endl;
    }
}

void Videogame::resumen()
{
    if (nombreUsuario.size() != 0)
    {

        cout << "Jugador: " << nombreUsuario << endl;
    }
    else
    {
        cout << "No hay ningún jugador registrado." << endl;
    }

    if (civilizaciones.size() > 0)
    {
        cout << endl
             << "Civilizaciones: " << endl;

        // encabezado
        cout << left;
        cout << setw(17) << "Nombre:";
        cout << setw(17) << "Pos X:";
        cout << setw(17) << "Pos Y:";
        cout << setw(17) << "Score:" << endl;

        for (size_t i = 0; i < civilizaciones.size(); i++)
        {
            cout << civilizaciones[i] << endl;
        }
    }
    else
    {
        cout << "No hay ninguna civilización en el juego." << endl;
    }
}

void Videogame::guardar()
{
    if (nombreUsuario.size() == 0)
    {
        cout << "Para guardar el juego es necesario registrar un nombre de usuario." << endl;
        return;
    }

    if (civilizaciones.size() == 0)
    {
        cout << "Para guardar el juego es necesario agregar por lo menos una civilización." << endl;
        return;
    }

    cout << "Guardando..." << endl;
    string nombreArchivo = nombreUsuario + ".txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {

        for (size_t i = 0; i < civilizaciones.size(); i++)
        {
            archivo << civilizaciones[i].getNombre() << endl;
            archivo << to_string(civilizaciones[i].getX()) << endl;
            archivo << to_string(civilizaciones[i].getY()) << endl;
            archivo << to_string(civilizaciones[i].getPuntuacion()) << endl;
            civilizaciones[i].guardarCivilizacion(nombreUsuario);
            cout << "Guardando... " << (i + 1) << " de " << civilizaciones.size() << endl;
        }

        cout << "El juego ha sido guardado correctamente." << endl;
    }
    archivo.close();
}

void Videogame::cargar()
{
    if (nombreUsuario.size() == 0)
    {
        cout << "Para cargar el juego es necesario registrar un nombre de usuario." << endl;
        return;
    }

    string nombreArchivo = nombreUsuario + ".txt";

    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        civilizaciones.clear();
        string linea;
        Civilizacion c;

        while (true)
        {
            getline(archivo, linea); // Nombre
            if (archivo.eof())
                break;
            c.setNombre(linea);

            getline(archivo, linea); // X
            c.setX(stoi(linea));

            getline(archivo, linea); // Y
            c.setY(stoi(linea));

            getline(archivo, linea); // Puntuación
            c.setPuntuacion(stoi(linea));

            civilizaciones.push_back(c);
        }

        for (size_t i = 0; i < civilizaciones.size(); i++)
        {
            string nombreArchivoCiv = nombreUsuario + "-" + civilizaciones[i].getNombre() + ".txt";
            ifstream archivoCiv(nombreArchivoCiv);

            if (archivoCiv.is_open())
            {
                civilizaciones[i].getAldeanos().clear();
                string linea;
                Aldeano a;
                while (true)
                {
                    getline(archivoCiv, linea); // Nombre
                    if (archivoCiv.eof())
                        break;
                    a.setNombre(linea);

                    getline(archivoCiv, linea); // EDAD
                    a.setEdad(stoi(linea));

                    getline(archivoCiv, linea); // GENERO
                    a.setGenero(stoi(linea));

                    getline(archivoCiv, linea); // SALUD
                    a.setSalud(stoi(linea));

                    civilizaciones[i].agregarAldeanoFinal(a);
                }
            }
        }

        cout << "El juego ha sido cargado correctamente." << endl;
        resumen();
    }
    else
    {
        cout << "No hay ningún juego guardado para el usuario " << nombreUsuario << "." << endl;
    }

    archivo.close();
}
