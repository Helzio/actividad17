#include "guerrero.h"

Guerrero::Guerrero()
{
}

Guerrero::Guerrero(int i, int s, float f, float e, int t)
{
    id = i;
    salud = s;
    fuerza = f;
    escudo = e;
    tipo = t;
}

void Guerrero::setId(int i)
{
    id = i;
}
void Guerrero::setSalud(int i)
{
    salud = i;
}
void Guerrero::setFuerza(float f)
{
    fuerza = f;
}
void Guerrero::setEscudo(float f)
{
    escudo = f;
}
void Guerrero::setTipo(int i)
{
    tipo = i;
}

int Guerrero::getId(){
    return id;
}

int Guerrero::getSalud(){
    return salud;
}

int Guerrero::getTipo(){
    return tipo;
}

float Guerrero::getFuerza(){
    return fuerza;
}

float Guerrero::getEscudo(){
    return escudo;
}