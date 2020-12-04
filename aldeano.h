#ifndef ALDEANO
#define ALDEANO

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
private:
    string nombre;
    int edad;
    int genero;
    int salud;

public:
    Aldeano();
    Aldeano(const string &nombre, int edad, int genero, int salud);

    string getNombre();
    int getEdad() const;
    int getGenero();
    int getSalud() const;

    void setNombre(const string &);
    void setEdad(int);
    void setGenero(int);
    void setSalud(int);

    string toString();

    friend ostream &operator<<(ostream &out, const Aldeano &c)
    {

        out << left;
        out << setw(17) << c.nombre;
        out << setw(17) << c.edad;
        if (c.genero == 0)
        {
            out << setw(17) << "Hombre";
        }
        else
        {
            out << setw(17) << "Mujer";
        }
        out << setw(17) << c.salud;
        return out;
    }

    friend istream &operator>>(istream &in, Aldeano &c)
    {
        int i;

        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Edad: ";
        cin >> i;
        cin.ignore();
        c.edad = i;

        cout << "Genero (0 - Hombre, 1 - Mujer): ";
        cin >> i;
        cin.ignore();
        c.genero = i;

        cout << "Salud: ";
        cin >> i;
        cin.ignore();
        c.salud = i;

        return in;
    }

    bool operator==(const Aldeano &a) const
    {
        return nombre == a.nombre;
    }

    bool operator==(const string st) const
    {
        return nombre == st;
    }

    bool operator<(const Aldeano &a) const
    {
        return nombre < a.nombre;
    }
};

#endif
