#ifndef CIVILIZACION
#define CIVILIZACION

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion
{
private:
    string nombre;
    int x;
    int y;
    int puntuacion;

public:
    Civilizacion();
    Civilizacion(const string &nombre, int x, int y, int puntuacion);

    string getNombre();
    int getX();
    int getY();
    int getPuntuacion();

    void setNombre(const string &);
    void setX(int);
    void setY(int);
    void setPuntuacion(int);

    string toString();

    friend ostream &operator<<(ostream &out, const Civilizacion &c)
    {

        out << left;
        out << setw(17) << c.nombre;
        out << setw(17) << c.x;
        out << setw(17) << c.y;
        out << setw(17) << c.puntuacion;
        return out;
    }

    friend istream &operator>>(istream &in, Civilizacion &c)
    {
        int i;

        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Posición X: ";
        cin >> i;
        cin.ignore();
        c.x = i;

        cout << "Posición Y: ";
        cin >> i;
        cin.ignore();
        c.y = i;

        cout << "Puntuación: ";
        cin >> i;
        cin.ignore();
        c.puntuacion = i;

        return in;
    }

    bool operator == (const Civilizacion &c) const{
        return nombre == c.nombre;
    }

    bool operator == (const string st) const{
        return nombre == st;
    }
};

#endif
