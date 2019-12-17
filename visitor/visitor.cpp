#include <iostream>
#include <locale.h>

using namespace std;


class Zwierze
{
public:
    virtual void accept(class Visitor*) = 0;
    virtual string zwierze() = 0;
    double _cenaO = 0;
    double _cenaS = 0;
    double _cenaCZ = 0;
    bool _stan;
    Zwierze(double cenaO, double cenaS, bool stan)
    {
        _cenaO = cenaO;
        _cenaS = cenaS;
        _stan = stan;
    };
    Zwierze(double cenaO, double cenaS, double cenaCZ, bool stan)
    {
        _cenaO = cenaO;
        _cenaS = cenaS;
        _cenaCZ = cenaCZ;
        _stan = stan;
    };
};

class Ssaki : public Zwierze
{
public:
    void accept(Visitor* v);
    Ssaki(double cenaO, double cenaS, bool stan) : Zwierze(cenaO, cenaS, stan) {};
    string zwierze()
    {
        return "Ssak";
    }
};
class Ptaki : public Zwierze
{
public:
    void accept(Visitor* v);
    Ptaki(double cenaO, double cenaS, double cenaCZ, bool stan) : Zwierze(cenaO, cenaS, cenaCZ, stan) {};
    string zwierze()
    {
        return "Ptak";
    }
};
class Gady : public Zwierze
{
public:
    void accept(Visitor* v);
    Gady(double cenaO, double cenaS, bool stan) : Zwierze(cenaO, cenaS, stan) {};
    string zwierze()
    {
        return "Gad";
    }
};
class Ryby : public Zwierze
{
public:
    void accept(Visitor* v);
    Ryby(double cenaO, double cenaS, bool stan) : Zwierze(cenaO, cenaS, stan) {};
    string zwierze()
    {
        return "Ryba";
    }
};




class Visitor
{
public:
    virtual void visit(Zwierze* e) = 0;
};
void Ssaki::accept(Visitor* v)
{
    v->visit(this);
}
void Ptaki::accept(Visitor* v)
{
    v->visit(this);
}
void Gady::accept(Visitor* v)
{
    v->visit(this);
}
void Ryby::accept(Visitor* v)
{
    v->visit(this);
}


class OfficialPrice : public Visitor
{
private:
    double cena = 0.0;
public:
    void visit(Zwierze* e)
    {
        cena += e->_cenaO;
    }
    void Cena()
    {
        cout << "Suma cen oficjalnych zwierząt: " << cena << endl;
    }
};
class OfficialPriceNeighbor : public Visitor
{
private:
    double cena = 0.0;
public:
    void visit(Zwierze* e)
    {
        if (e->_cenaCZ == 0)
            cena += e->_cenaS;
        else
            cena += e->_cenaS + e->_cenaCZ;
    }
    void Cena()
    {
        cout << "Suma cen sklepowych+czarnorynkowych zwierząt: " << cena << endl;
    }
};
class Weterynarz : public Visitor
{
public:
    void visit(Zwierze* e)
    {
        string diagnoza;
        string leczenie;
        if (e->_stan == true)
        {
            diagnoza = "zdrowy.";
            leczenie = "niewymagane.";
        }
        else
        {
            diagnoza = "chory.";
            if (e->_cenaCZ != 0)
            {
                if (e->_cenaCZ >= 2 * e->_cenaO)
                    leczenie = "zabrane do lecznicy.";
                else
                    leczenie = "antybiotyki, dieta.";
            }
            else
                leczenie = "antybiotyki.";

        }

        cout << "Odwiedzane zwierzę: " + e->zwierze() + "    Diagnoza: " + diagnoza + "    Leczenie: " + leczenie << "\n    Cena oficjalna/sklepowa/czarnorynkowa: " << e->_cenaO << ", " << e->_cenaS << ", " << e->_cenaCZ << "\n" << endl;
    }
};





int main(void)
{
    setlocale(LC_CTYPE, "Polish");

    int chore = 0;
    int zdrowe = 1;
    Zwierze* list[] =
    {
        new Ptaki(25,33,997,chore),
        new Ptaki(25,33,10,chore),
        new Ssaki(100,82,zdrowe),
        new Gady(55,52,chore),
        new Ryby(123,111,chore),
        new Ssaki(95,90,zdrowe),
        new Ptaki(25,33,10,zdrowe)
    };

    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
    {
        cout << i + 1 << ". " << list[i]->zwierze() << endl;
    }cout << "\n";

    OfficialPriceNeighbor* opn;
    opn = new OfficialPriceNeighbor();

    OfficialPrice* op;
    op = new OfficialPrice();


    Weterynarz wet;


    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
    {
        list[i]->accept(op);
        list[i]->accept(opn);
    }

    op->Cena();
    opn->Cena();

    cout << "\n";
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
    {
        cout << i + 1 << ". ";
        list[i]->accept(&wet);
    }




    return 0;
}
