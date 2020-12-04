
#include "aldeano.h"

Aldeano::Aldeano() {}

Aldeano::Aldeano(const string &n, int e, int g, int s)
{
    nombre = n;
    edad = e;
    genero = g;
    salud = s;
}

string Aldeano::getNombre()
{
    return nombre;
}

int Aldeano::getSalud() const
{
    return salud;
}

int Aldeano::getEdad() const
{
    return edad;
}

int Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setNombre(const string &n)
{
    nombre = n;
}

void Aldeano::setEdad(int e)
{
    edad = e;
}

void Aldeano::setGenero(int g)
{
    genero = g;
}

void Aldeano::setSalud(int s)
{
    salud = s;
}