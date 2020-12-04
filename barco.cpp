#include "barco.h"

Barco::Barco()
{
}

Barco::Barco(int i, float c, float v, float a)
{
    id = i;
    combustible = c;
    velocidad = v;
    armadura = a;
}

void Barco::setId(int i)
{
    id = i;
}
void Barco::setCombustible(float f)
{
    combustible = f;
}
void Barco::setVelocidad(float f)
{
    velocidad = f;
}
void Barco::setArmadura(float f)
{
    armadura = f;
}

int Barco::getId()
{
    return id;
}

float Barco::getCombustible()
{
    return combustible;
}

float Barco::getVelocidad()
{
    return velocidad;
}

float Barco::getArmadura()
{
    return armadura;
}

void Barco::agregarGuerrero()
{
    Guerrero guerrero;
    cin >> guerrero;

    guerreros.push(guerrero);
    cout << "Guerrerro agregado correctamente." << endl;
}

void Barco::eliminarGuerrero()
{
    if (guerreros.empty())
    {
        cout << "La lista de gerreros esta vacía." << endl;
    }
    else
    {
        guerreros.pop();
        cout << "Guerrerro eliminado correctamente." << endl;
        mostrarGuerreros();
    }
}

void Barco::obtenerGuerrero()
{
    if (guerreros.empty())
    {
        cout << "La lista de gerreros esta vacía." << endl;
    }
    else
    {
        // encabezado
        cout << "*** Último guerrero agregado ***" << endl;
        cout << left;
        cout << setw(17) << "Id:";
        cout << setw(17) << "Salud:";
        cout << setw(17) << "Fuerza:";
        cout << setw(17) << "Escudo:";
        cout << setw(17) << "Tipo:" << endl;
        cout << guerreros.top() << endl;
    }
}

void Barco::mostrarGuerreros()
{
    if (guerreros.empty())
    {
        cout << "La lista de gerreros esta vacía." << endl;
    }
    else
    {
        // encabezado
        cout << "*** Lista de guerreros del barco ***" << endl;
        cout << left;
        cout << setw(17) << "Id:";
        cout << setw(17) << "Salud:";
        cout << setw(17) << "Fuerza:";
        cout << setw(17) << "Escudo:";
        cout << setw(17) << "Tipo:" << endl;

        stack<Guerrero> copia(guerreros);
        while (!copia.empty())
        {
            cout << copia.top() << endl;
            copia.pop();
        }
        
        
    }
}