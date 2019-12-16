#include <iostream>
#include "biblioteki.h"

using namespace std;

class Figura
{
public:
    virtual void wyswietl() = 0;
    Figura() {}
    Figura(Biblioteka* bg);
    void rysujProstokat(double x1, double y1, double x2, double y2);
    void rysujOkrag(double x, double y, double r);
private:
    Biblioteka* _bg;
};
Figura::Figura(Biblioteka* bg)
{
    _bg = bg;
}
void Figura::rysujProstokat(double x1, double y1, double x2, double y2)
{
    _bg->rysujProstokat(x1, y1, x2, y2);
}
void Figura::rysujOkrag(double x, double y, double r)
{
    _bg->rysujOkrag(x, y, r);
}


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
    double _x, _y, _r;
    //        Okrag()
    //        {
    //            pxc = new XXOkrag();
    //        }
    Okrag(Biblioteka* bg, double x, double y, double r);
    Okrag();

    //        ~Okrag()
    //        {
    //            delete pxc;
    //        }

    void wyswietl();
    //        {
    //            cout << "Rysuje Okrag\n";
    //            pxc->wyswietlaj();
    //        }
};
Okrag::Okrag()
{
    pxc = new XXOkrag;
}
Okrag::Okrag(Biblioteka* bg, double x, double y, double r) : Figura(bg)
{
    _x = x; _y = y; _r = r;
}
void Okrag::wyswietl()
{
    rysujOkrag(_x, _y, _r);
    rysujOkrag(_x, _y, _r);
    rysujOkrag(_x, _y, _r);
    //   cout << "\nRysuje Okrag\n";
    pxc->wyswietlaj();
}


class Kwadrat : public Figura
{
public:
    void wyswietl()
    {
        cout << "Rysuje Kwadrat\n";
    }
};

class Prostokat : public Figura
{
public:
    double _x1, _x2, _y1, _y2;
    Prostokat(Biblioteka* bg, double x1, double y1, double x2, double y2);
    void wyswietl();
    //    {
    //        cout << "Rysuje Prostokat\n";
    //    }
};
Prostokat::Prostokat(Biblioteka* bg, double x1, double y1, double x2, double y2) : Figura(bg)
{
    _x1 = x1; _x2 = x2;
    _y1 = y1; _y2 = y2;
}

void Prostokat::wyswietl()
{
    rysujProstokat(_x1, _y1, _x2, _y1);
    rysujProstokat(_x2, _y1, _x2, _y2);
    rysujProstokat(_x2, _y2, _x1, _y2);
    rysujProstokat(_x1, _y2, _x1, _y1);
}




class Figury
{
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
    Figura* f1;
    Figura* f2;
    Figura* f3;
    Biblioteka* bg1, * bg2;

    bg1 = new BibliotekaV1;
    f1 = new Prostokat(bg1, 1, 1, 2, 2);

    bg2 = new BibliotekaV2;
    f2 = new Okrag(bg2, 2, 2, 4);
    f3 = new Prostokat(bg2, 1, 1, 2, 2);

    f1->wyswietl();
    f2->wyswietl();
    f3->wyswietl();

    delete f1; delete f2; delete f3;
    delete bg1; delete bg2;


    //    Figury figury = Figury();
    //    figury.Dodaj_Figure(new Kwadrat());
    //    figury.Dodaj_Figure(new Okrag());
    //    figury.wyswietl();


}
