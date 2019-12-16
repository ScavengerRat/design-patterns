#include <iostream>

using namespace std;

class Figura
{
public:
    virtual void wyswietl() = 0;
};

class XXOkrag
{
public:
    void wyswietlaj()
    {
        //gadatliwa metoda
        cout << "XXOkrag::wyswietlaj()\n";
    }
};

class Okrag : public Figura
{
private:
    XXOkrag* pxc;

public:
    Okrag()
    {
        pxc = new XXOkrag();
    }

    ~Okrag()
    {
        delete pxc;
    }

    void wyswietl()
    {
        cout << "Rysuje Okrag\n";
        pxc->wyswietlaj();
    }
};

class Kwadrat : public Figura
{
public:
    void wyswietl()
    {
        cout << "Rysuje Kwadrat\n";
    }
};


class Figury {
    Figura** tab;
    int size;

public:
    Figury() {
        tab = new Figura * [4];
        size = 0;
    }

    void Dodaj_Figure(Figura* fig) {
        if (size < 4) {
            tab[size] = fig;
            size++;
        }

    }

    ~Figury() {
        for (int i = 0; i < size; i++)
            delete tab[i];
        delete[] tab;
    }
    void wyswietl() {
        for (int i = 0; i < size; i++)
            tab[i]->wyswietl();
    }
};


int main()
{
    Figura* fig = new Okrag();
    fig->wyswietl();

    Figury figury = Figury();
    figury.Dodaj_Figure(new Kwadrat());
    figury.Dodaj_Figure(new Kwadrat());
    figury.Dodaj_Figure(new Okrag());
    figury.wyswietl();

    return 0;
}
