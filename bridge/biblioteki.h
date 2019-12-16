#ifndef BIBLIOTEKI_HPP
#define BIBLIOTEKI_HPP

using namespace std;



class Biblioteka
{
public:
    virtual void rysujProstokat(double x1, double y1, double x2, double y2) = 0;
    virtual void rysujOkrag(double x, double y, double r) = 0;
};


class BG1
{
public:
    static void rysuj_prostokat(double x1, double y1, double x2, double y2)
    {
        cout << "Rysuje prostokat BG1\n";
    }
    static void rysuj_okrag(double x, double y, double r)
    {
        cout << "Rysuje okrag BG1\n";
    }
};

class BG2
{
public:
    static void narysujProstokat(double x1, double x2, double y1, double y2)
    {
        cout << "Narysuj Prostokat BG2\n";
    }
    static void narysujOkrag(double x, double y, double r)
    {
        cout << "Narysuj okrag BG2\n";
    }
};


class BibliotekaV1 : public Biblioteka
{
public:
    void rysujProstokat(double x1, double y1, double x2, double y2);
    void rysujOkrag(double x, double y, double r);
};

void BibliotekaV1::rysujProstokat(double x1, double y1, double x2, double y2)
{
    BG1 bg1;
    bg1.rysuj_prostokat(x1, y1, x2, y2);
}

void BibliotekaV1::rysujOkrag(double x, double y, double r)
{
    BG1 bg1;
    bg1.rysuj_okrag(x, y, r);
}

class BibliotekaV2 : public Biblioteka
{
public:
    void rysujProstokat(double x1, double y1, double x2, double y2);
    void rysujOkrag(double x, double y, double r);
};

void BibliotekaV2::rysujProstokat(double x1, double y1, double x2, double y2)
{
    BG2 bg2;
    bg2.narysujProstokat(x1, y1, x2, y2);
}

void BibliotekaV2::rysujOkrag(double x, double y, double r)
{
    BG2 bg2;
    bg2.narysujOkrag(x, y, r);
}

#endif
