#ifndef GUERRERO
#define GUERRERO

#include <iostream>
#include <iomanip>

using namespace std;

class Guerrero
{
private:
    int id;
    int salud;
    float fuerza;
    float escudo;
    int tipo;

public:
    Guerrero();
    Guerrero(int id, int salud, float fuerza, float escudo, int tipo);

    int getId();
    int getSalud();
    float getFuerza();
    float getEscudo();
    int getTipo();

    void setId(int);
    void setSalud(int);
    void setFuerza(float);
    void setEscudo(float);
    void setTipo(int);

    string toString();

    friend ostream &operator<<(ostream &out, const Guerrero &g)
    {

        out << left;
        out << setw(17) << g.id;
        out << setw(17) << g.salud;

        out << setw(17) << g.fuerza;
        out << setw(17) << g.escudo;
        switch (g.tipo)
        {
        case 0:
            out << setw(17) << "Campeon";
            break;

        case 1:
            out << setw(17) << "Alabardero";
            break;

        case 2:
            out << setw(17) << "Paladin";
            break;

        case 3:
            out << setw(17) << "Lancero";
            break;

        default:
            out << setw(17) << "Desconocido";
            break;
        }
        return out;
    }

    friend istream &operator>>(istream &in, Guerrero &g)
    {
        int i;
        float f;

        cout << "Id: ";
        cin >> i;
        cin.ignore();
        g.id = i;

        bool salud = false;
        while (!salud)
        {
            cout << "Salud (0 - 100): ";
            cin >> i;
            cin.ignore();

            if (i >= 0 && i <= 100)
            {

                g.salud = i;
                salud = true;
            }
            else
            {
                cout << "Introduce un número entre 0 y 100. " << endl;
            }
        }

        bool fuerza = false;
        while (!fuerza)
        {
            cout << "Fuerza (0.0 - 60.0): ";
            cin >> f;
            cin.ignore();

            if (f >= 0.0 && f <= 60.0)
            {

                g.fuerza = f;
                fuerza = true;
            }
            else
            {
                cout << "Introduce un número entre 0.0 y 60.0. " << endl;
            }
        }

        bool escudo = false;
        while (!escudo)
        {
            cout << "Escudo (0.0 - 30.0): ";
            cin >> f;
            cin.ignore();

            if (f >= 0.0 && f <= 30.0)
            {

                g.escudo = f;
                escudo = true;
            }
            else
            {
                cout << "Introduce un número entre 0.0 y 30.0. " << endl;
            }
        }

        cout << "Tipo: " << endl;
        cout << "0 - Campeon, 1 - Alabardero, 2 - Paladin, 3 - Lancero" << endl;
        cout << "Tipo: ";
        cin >> i;
        cin.ignore();
        g.tipo = i;

        return in;
    }

    bool operator==(const Guerrero &a) const
    {
        return id == a.id;
    }

    bool operator==(int i) const
    {
        return id == i;
    }

    bool operator<(const Guerrero &a) const
    {
        return id < a.id;
    }
};

#endif
