#include <iostream>

using namespace std;


class Komponent
{
public:
    virtual void drukuj() = 0;
};

class Potwierdzenie : public Komponent
{
public:
    void drukuj();
};

void Potwierdzenie::drukuj()
{
    cout << "POTWIERDZENIE" << endl;
}



class Dekorator : public Komponent
{
public:
    virtual void drukuj();
    Dekorator(Komponent* mojK);
private:
    Komponent* mojKomponent;
};
Dekorator::Dekorator(Komponent* mojK)
{
    mojKomponent = mojK;
}
void Dekorator::drukuj()
{
    if (mojKomponent != 0)
        mojKomponent->drukuj();
}



class Naglowek1 : public Dekorator
{
public:
    void drukuj();
    Naglowek1(Komponent* mojKomponent) : Dekorator(mojKomponent) {}
};
void Naglowek1::drukuj()
{
    cout << "NAGLOWEK 1" << endl;
    Dekorator::drukuj();
}

class Naglowek2 : public Dekorator
{
public:
    void drukuj();
    Naglowek2(Komponent* mojKomponent) : Dekorator(mojKomponent) {}
};
void Naglowek2::drukuj()
{
    cout << "NAGLOWEK 2" << endl;
    Dekorator::drukuj();
}



class Stopka1 : public Dekorator
{
public:
    void drukuj();
    Stopka1(Komponent* mojKomponent) : Dekorator(mojKomponent) {}
};
void Stopka1::drukuj()
{
    Dekorator::drukuj();
    cout << "STOPKA 1" << endl;
}

class Stopka2 : public Dekorator
{
public:
    void drukuj();
    Stopka2(Komponent* mojKomponent) : Dekorator(mojKomponent) {}
};
void Stopka2::drukuj()
{
    Dekorator::drukuj();
    cout << "STOPKA 2" << endl;
}


class Konfiguracja
{
public:
    static Komponent* PotwNaglowki()
    {
        return new Naglowek1(new Naglowek2(new Stopka2(new Potwierdzenie())));
    }

    static Komponent* PotwStopki()
    {
        return new Naglowek1(new Stopka2(new Stopka1(new Potwierdzenie())));
    }
};



class Zamowienie
{
public:
    void drukuj();
};

void Zamowienie::drukuj()
{
    Komponent* mojePotw2;
    mojePotw2 = Konfiguracja().PotwStopki();
    mojePotw2->drukuj();
    cout << "\n";

    Komponent* mojePotw1;
    // pobiera ³añcuch z³o¿ony z dekoratorów oraz
    // potwierdzenia utworzony przez inny obiekt
    // zawieraj¹cy odpowiednie regu³y.
    // ³añcuch mo¿e byæ te¿ pobrany w konstruktorze
    // zamiast w ka¿dym wywo³aniu metody wydruku
    mojePotw1 = Konfiguracja().PotwNaglowki();

    // drukuje potwierdzenie z odpowiednimi
    // nag³ówkami i stopkami
    mojePotw1->drukuj();

}



int main(void)
{

    Zamowienie* zam = new Zamowienie();
    zam->drukuj();

    return 0;
}
