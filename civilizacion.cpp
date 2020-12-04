#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion() {}

void Civilizacion::setNombre(const string &s)
{
    nombre = s;
}

void Civilizacion::setX(int i)
{
    x = i;
}

void Civilizacion::setY(int i)
{
    y = i;
}

void Civilizacion::setPuntuacion(int i)
{
    puntuacion = i;
}

string Civilizacion::getNombre()
{
    return nombre;
}

int Civilizacion::getX()
{
    return x;
}

int Civilizacion::getY()
{
    return y;
}

int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarAldeanoInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::agregarAldeanoFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::eliminarAldeanoPorNombre(const string &nombre)
{
    bool eliminado = false;
    for (auto i = aldeanos.begin(); i != aldeanos.end(); i++)
    {
        Aldeano &a = *i;
        if (a.getNombre() == nombre)
        {
            aldeanos.erase(i);
            cout << endl
                 << "Se ha eliminado el aldeano: " << nombre << endl
                 << endl;
            eliminado = true;
            puntuacion -= 100;
            break;
        }
    }
    if (!eliminado)
    {
        cout << "No se encontro ningun aldeano con el nombre: " << nombre << "." << endl
             << endl;
    }
}

void Civilizacion::eliminarAldeanosPorSalud(int salud)
{
    list<Aldeano> elementosAEliminar;
    auto it = aldeanos.begin();
    while (it != aldeanos.end())
    {
        if (it->getSalud() < salud)
        {
            elementosAEliminar.push_back(*it);
        }
        it++;
    }

    for (auto i = elementosAEliminar.begin(); i != elementosAEliminar.end(); i++)
    {
        aldeanos.erase(remove(aldeanos.begin(), aldeanos.end(), *i), aldeanos.end());
    }

    cout << endl
         << "Se han eliminado " << elementosAEliminar.size() << " aldeanos." << endl
         << endl;
    puntuacion -= elementosAEliminar.size() * 100;
}

void Civilizacion::eliminarAldeanosPorEdad()
{
    list<Aldeano> elementosAEliminar;
    auto it = aldeanos.begin();
    while (it != aldeanos.end())
    {
        if (it->getEdad() >= 60)
        {
            elementosAEliminar.push_back(*it);
        }
        it++;
    }

    for (auto i = elementosAEliminar.begin(); i != elementosAEliminar.end(); i++)
    {
        aldeanos.erase(remove(aldeanos.begin(), aldeanos.end(), *i), aldeanos.end());
    }

    cout << endl
         << "Se han eliminado " << elementosAEliminar.size() << " aldeanos." << endl
         << endl;
    puntuacion -= elementosAEliminar.size() * 100;
}

void Civilizacion::ordenarAldeanosPorNombre()
{
    aldeanos.sort();
}

bool comparadorSalud(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getSalud() > a2.getSalud();
}

void Civilizacion::ordenarAldeanosPorSalud()
{
    aldeanos.sort(comparadorSalud);
}

void Civilizacion::ordenarAldeanosPorEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2) { return a1.getEdad() > a2.getEdad(); });
}

list<Aldeano> Civilizacion::getAldeanos()
{
    return aldeanos;
}

void Civilizacion::agregarAldeano()
{
    int opcion;
    cout << endl
         << "Agregar aldeano: " << endl;
    Aldeano a;
    cin >> a;

    cout << endl
         << "¿En donde deseas agregar el aldeano?" << endl;
    cout << "1- Agregar al inicio. " << endl;
    cout << "2- Agregar al final. " << endl;

    cout << "Introduce una opción: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1)
    {
        agregarAldeanoInicio(a);
        cout << "Aldeano agregado correctamente." << endl
             << endl;
        setPuntuacion(getPuntuacion() + 100);
    }
    else
    {
        agregarAldeanoFinal(a);
        cout << "Aldeano agregado correctamente." << endl
             << endl;
        setPuntuacion(getPuntuacion() + 100);
    }
}

void Civilizacion::eliminarAldeanos()
{

    string nombre;
    int edad;
    int salud;
    bool salir = false;
    int opcion;

    while (!salir)
    {
        cout << "*** Eliminar aldeanos ***" << endl;
        cout << "1- Eliminar por nombre. " << endl;
        cout << "2- Eliminar aldeanos por salud. " << endl;
        cout << "3- Eliminar aldeanos mayores a 59 años. " << endl;
        cout << "0- Salir. " << endl;

        cout << "Introduce una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            cout << "Nombre del aldeano a eliminar: ";
            getline(cin, nombre);
            eliminarAldeanoPorNombre(nombre);
        }
        else if (opcion == 2)
        {
            cout << "Eliminar aldeanos con salud menor a: " << endl;
            cout << "Salud: ";
            cin >> salud;
            eliminarAldeanosPorSalud(salud);
        }
        else if (opcion == 3)
        {
            eliminarAldeanosPorEdad();
        }
        else
        {
            salir = true;
            cout << "Saliendo..." << endl
                 << endl;
        }
    }
}

void Civilizacion::clasificarAldeanos()
{

    int opcion;
    bool salir = false;
    while (!salir)
    {
        cout << endl
             << "*** Clasificar aldeanos ***" << endl;
        cout << "1- Clasificar aldeanos por nombre. " << endl;
        cout << "2- Clasificar aldeanos por salud. " << endl;
        cout << "3- Clasificar aldeanos edad. " << endl;
        cout << "0- Salir. " << endl;

        cout << "Introduce una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            ordenarAldeanosPorNombre();
            mostrarAldeanos();
        }
        else if (opcion == 2)
        {
            ordenarAldeanosPorSalud();
            mostrarAldeanos();
        }
        else if (opcion == 3)
        {
            ordenarAldeanosPorEdad();
            mostrarAldeanos();
        }
        else
        {
            salir = true;
            cout << "Saliendo..." << endl
                 << endl;
        }
    }
}

void Civilizacion::buscarAldeano()
{
    if (aldeanos.size() > 0)
    {
        string nombre;
        cout << endl
             << "Introduce el nombre del aldeano que deseas encontrar:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);

        auto resultado = find(aldeanos.begin(), aldeanos.end(), nombre);
        if (resultado != aldeanos.end())
        {
            cout << endl
                 << "*** Aldeano encontrado ***" << endl;
            // encabezado
            cout << left;
            cout << setw(17) << "Nombre:";
            cout << setw(17) << "Edad:";
            cout << setw(17) << "Genero:";
            cout << setw(17) << "Salud:" << endl;
            cout << *resultado << endl
                 << endl;
        }

        else
        {
            cout << "No se encontro ningun aldeano con el nombre: " << nombre << "." << endl;
        }
    }
    else
    {
        cout << "La lista de aldeanos de esta civilización esta vacía." << endl;
    }
}

void Civilizacion::modificarAldeano()
{
    if (aldeanos.size() > 0)
    {
        string nombre;
        string data;
        int i;
        cout << endl
             << "Introduce el nombre del aldeano que deseas modificar:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);

        auto resultado = find(aldeanos.begin(), aldeanos.end(), nombre);
        if (resultado != aldeanos.end())
        {

            int opcion;
            bool repetir = true;

            while (repetir)
            {
                cout << endl
                     << "*** Aldeano encontrado ***" << endl;
                // encabezado
                cout << left;
                cout << setw(17) << "Nombre:";
                cout << setw(17) << "Edad:";
                cout << setw(17) << "Genero:";
                cout << setw(17) << "Salud:" << endl;
                cout << *resultado << endl
                     << endl;
                cout << "1) Modificar nombre" << endl;
                cout << "2) Modificar edad" << endl;
                cout << "3) Modificar genero" << endl;
                cout << "4) Modificar salud" << endl;
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
                         << "Nueva edad: ";
                    cin >> i;
                    cin.ignore();
                    resultado->setEdad(i);
                    break;
                case 3:
                    cout << endl
                         << "Nuevo genero (0 - Hombre, 1 - Mujer): ";
                    cin >> i;
                    cin.ignore();
                    resultado->setGenero(i);
                    break;
                case 4:
                    cout << endl
                         << "Nueva salud: ";
                    cin >> i;
                    cin.ignore();
                    resultado->setSalud(i);
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
            cout << "No se encontro ningun aldeano con el nombre: " << nombre << "." << endl;
        }
    }
    else
    {
        cout << "No hay ningun aldeano para mostrar." << endl;
    }
}

void Civilizacion::mostrarAldeanos()
{
    if (aldeanos.size() > 0)
    {
        cout << endl
             << "*** Aldeanos ***" << endl;

        // encabezado
        cout << left;
        cout << setw(17) << "Nombre:";
        cout << setw(17) << "Edad:";
        cout << setw(17) << "Genero:";
        cout << setw(17) << "Salud:" << endl;

        for (auto i = aldeanos.begin(); i != aldeanos.end(); i++)
        {
            cout << *i << endl;
        }
    }
    else
    {
        cout << "No hay ninguna aldeanos en esta civilización en el juego." << endl;
    }
}

void Civilizacion::guardarCivilizacion(const string &n)
{
    if (aldeanos.size() > 0)
    {
        string nombreArchivoCiv = n + "-" + nombre + ".txt";
        ofstream archivoCiv(nombreArchivoCiv);
        for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it)
        {
            Aldeano &aldeano = *it;
            archivoCiv << aldeano.getNombre() << endl;
            archivoCiv << to_string(aldeano.getEdad()) << endl;
            archivoCiv << to_string(aldeano.getGenero()) << endl;
            archivoCiv << to_string(aldeano.getSalud()) << endl;
        }
        archivoCiv.close();
    }
}

void Civilizacion::agregarBarco()
{

    cout << endl
         << "*** Agregar barco ***" << endl;
    Barco *b = new Barco();
    cin >> *b;
    puerto.push_back(b);
    cout
         << "Barco agregado correctamente." << endl;
}

void Civilizacion::mostrarBarcos()
{
    if (puerto.size() > 0)
    {
        cout << endl
             << "*** Barcos ***" << endl;

        // encabezado
        cout << left;
        cout << setw(17) << "Id:";
        cout << setw(17) << "Combustible:";
        cout << setw(17) << "Velocidad:";
        cout << setw(17) << "Armadura:";
        cout << setw(17) << "No. Guerreros:" << endl;

        for (auto i = puerto.begin(); i != puerto.end(); i++)
        {
            cout << **i << endl;
        }
    }
    else
    {
        cout << "El puerto esta vació." << endl;
    }
}

void Civilizacion::buscarBarco()
{
    if (puerto.size() > 0)
    {
        bool encontrado = false;
        int id;
        cout << endl
             << "Introduce el id del barco que deseas encontrar:" << endl;
        cout << "Id: ";
        cin >> id;
        cin.ignore();

        for (auto const &b : puerto)
        {
            if (b->getId() == id)
            {
                encontrado = true;

                cout << endl
                     << "*** Barco encontrado ***" << endl;
                // encabezado
                cout << left;
                cout << setw(17) << "Id:";
                cout << setw(17) << "Combustible:";
                cout << setw(17) << "Velocidad:";
                cout << setw(17) << "Armadura:" << endl;
                cout << *b << endl
                     << endl;

                bool repetir = true;
                int opcion;
                while (repetir)
                {
                    cout << endl
                         << "*** Menú del barco ***" << endl;

                    cout << "1) Agregar guerrero." << endl;
                    cout << "2) Eliminar guerrero." << endl;
                    cout << "3) Mostrar último guerrero." << endl;
                    cout << "4) Mostrar todos los guerreros." << endl;
                    cout << "0) Salir" << endl;
                    cout << "Introduce una opción: ";
                    cin >> opcion;
                    cin.ignore();

                    switch (opcion)
                    {
                    case 1:
                        b->agregarGuerrero();
                        break;
                    case 2:
                        b->eliminarGuerrero();
                        break;
                    case 3:
                        b->obtenerGuerrero();
                        break;
                    case 4:
                        b->mostrarGuerreros();
                        break;
                    default:
                        cout << endl
                             << "Saliendo." << endl;
                        repetir = false;
                        break;
                    }
                }
                break;
            }
        }

        if (!encontrado)
        {
            cout << "No se encontro ningun barco con el id: " << id << "." << endl;
        }
    }
    else
    {
        cout << "El puerto esta vació." << endl;
    }
}

void Civilizacion::eliminarBarco()
{
    int id;
    int combustible;
    bool salir = false;
    int opcion;

    while (!salir)
    {
        cout << endl << "*** Eliminar barco ***" << endl;
        cout << "1- Eliminar por id. " << endl;
        cout << "2- Eliminar por combustible. " << endl;
        cout << "0- Salir. " << endl;

        cout << "Introduce una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            cout << "Id del barco a eliminar: ";
            cin >> id;
            cin.ignore();
            eliminarBarcoPorId(id);
            salir = true;
            mostrarBarcos();
        }
        else if (opcion == 2)
        {
            cout << "Eliminar barcos con combustible menor a: " << endl;
            cout << "Combustible: ";
            cin >> combustible;
            eliminarBarcosPorCombustible(combustible);
            salir = true;
            mostrarBarcos();
        }
        else
        {
            salir = true;
            cout << "Saliendo..." << endl
                 << endl;
        }
    }
}

void Civilizacion::eliminarBarcoPorId(int id)
{
    puerto.remove_if([id](Barco *b) {
        if (b->getCombustible() == id)
        {
            delete b;
            return true;
        }
        else
        {
            return false;
        }
    });
cout << "Se ha eliminado el barcos correctamente." << endl << endl;

}

void Civilizacion::eliminarBarcosPorCombustible(int combustible)
{
    puerto.remove_if([combustible](Barco *b) {
        if (b->getCombustible() < combustible)
        {
            delete b;
            return true;
        }
        else
        {
            return false;
        }
    });

    cout << "Se han eliminado los barcos correctamente." << endl << endl;
}