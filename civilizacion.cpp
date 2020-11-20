#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){}

void Civilizacion::setNombre(const string &s){
    nombre = s;
}

void Civilizacion::setX(int i){
    x = i;
}

void Civilizacion::setY(int i){
    y = i;
}

void Civilizacion::setPuntuacion(int i){
    puntuacion = i;
}

string Civilizacion::getNombre(){
    return nombre;
}

int Civilizacion::getX(){
    return x;
}

int Civilizacion::getY(){
    return y;
}

int Civilizacion::getPuntuacion(){
    return puntuacion;
}