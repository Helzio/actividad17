#ifndef VIDEOGAME
#define VIDEOGAME

#include <iostream>
#include <vector>
#include <fstream>
#include "civilizacion.h"
#include "aldeano.h"


class Videogame
{
private:
    std::vector<Civilizacion> civilizaciones;
    std::string nombreUsuario;

public:
    Videogame();

    // opcion 1
    void agregarNombreUsuario();

    // opcion 2
    void agregarCivilizacion();

    // opcion 3
    void insertarCivilizacion();

    // opcion 4
    void crearCivilizaciones();

    // opcion 5
    void primeraCivilizacion();

    // opcion 6
    void ultimaCivilizacion();

    // opcion 7
    void ordenarCivilizaciones();

    void ordenarCivilizacionesPorNombre();
    void ordenarCivilizacionesPorX();
    void ordenarCivilizacionesPorY();
    void ordenarCivilizacionesPorPuntuacion();

    // opcion 8
    void eliminarCivilizacion();

    // opcion 9
    void buscarCivilizacion();

    // opcion 10
    void modificarCivilizacion();

    // opcion 11
    void resumen();

    // opcion 12
    void guardar();

    // opcion 13
    void cargar();


};

#endif