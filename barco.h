#ifndef BARCO
#define BARCO

#include <iostream>
#include <iomanip>
#include <stack>
#include "guerrero.h"

using namespace std;

class Barco
{
private:
    int id;
    float combustible;
    float velocidad;
    float armadura;
    stack<Guerrero> guerreros;

public:
    Barco();
    Barco(int id, float combustible, float velocidad, float armadura);

    int getId();
    float getCombustible();
    float getVelocidad();
    float getArmadura();

    void setId(int);
    void setCombustible(float);
    void setVelocidad(float);
    void setArmadura(float);

    void agregarGuerrero();
    void eliminarGuerrero();
    void obtenerGuerrero();
    void mostrarGuerreros();

    friend ostream &operator<<(ostream &out, const Barco &g)
    {

        out << left;
        out << setw(17) << g.id;
        out << setw(17) << g.combustible;
        out << setw(17) << g.velocidad;
        out << setw(17) << g.armadura;
        out << setw(17) << g.guerreros.size();
        return out;
    }

    friend istream &operator>>(istream &in, Barco &b)
    {
        int i;
        float f;

        cout << "Id: ";
        cin >> i;
        cin.ignore();
        b.id = i;

        bool combustible = false;
        while (!combustible)
        {
            cout << "Combustible (0.0 - 100.0): ";
            cin >> f;
            cin.ignore();

            if (f >= 0.0 && f <= 100.0)
            {

                b.combustible = f;
                combustible = true;
            }
            else
            {
                cout << "Introduce un número entre 0.0 y 100.0. " << endl;
            }
        }

        bool velocidad = false;
        while (!velocidad)
        {
            cout << "Velocidad (0.0 - 14.0): ";
            cin >> f;
            cin.ignore();

            if (f >= 0.0 && f <= 14.0)
            {

                b.velocidad = f;
                velocidad = true;
            }
            else
            {
                cout << "Introduce un número entre 0.0 y 14.0. " << endl;
            }
        }

        bool armadura = false;
        while (!armadura)
        {
            cout << "Armadura (0.0 - 100.0): ";
            cin >> f;
            cin.ignore();

            if (f >= 0.0 && f <= 100.0)
            {

                b.armadura = f;
                armadura = true;
            }
            else
            {
                cout << "Introduce un número entre 0.0 y 100.0. " << endl;
            }
        }

        return in;
    }

    bool operator==(const Barco &a) const
    {
        return id == a.id;
    }

    bool operator==(int i) const
    {
        return id == i;
    }

    bool operator<(const Barco &a) const
    {
        return id < a.id;
    }
};

#endif
