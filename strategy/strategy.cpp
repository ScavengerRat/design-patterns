#include <iostream>
#include "podatki.h"

using namespace std;

class Zamowienie
{
protected:
    double* tTowary;
    int size;

public:
    void ObliczPodatek();
    Zamowienie(double* Towary, int size);

};

Zamowienie::Zamowienie(double* Towary, int size)
{
    tTowary = new double[size];
    for (int i(0); i < size; i++)
    {
        this->tTowary[i] = Towary[i];
    }
    this->size = size;
}

void Zamowienie::ObliczPodatek()
{
    cout << "Towar\tPodatek Polska\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << tTowary[i] + PodatekPolska().kwotaPodatku(tTowary[i]) << endl;
    }


    cout << "Towar\tPodatek Niemcy\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << tTowary[i] + PodatekNiemcy().kwotaPodatku(tTowary[i]) << endl;
    }
}




int main()
{
    Zamowienie* a;

    double produkty[] = { 20.1,10.5,11.8,5.5,2.7,7.7,1.9,9.9 };
    a = new Zamowienie(produkty, (sizeof produkty / sizeof * produkty));
    a->ObliczPodatek();
    delete a;

}
