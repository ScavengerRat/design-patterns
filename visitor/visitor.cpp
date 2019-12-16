#include <iostream>

using namespace std;


class Element
{
public:
    virtual void accept(class Visitor*) = 0;
};
class Zwierze : public Element
{
public:
    void accept(Visitor* v);

};

class Diagnoza : public Element
{
public:
    void accept(Visitor* v);
    string diagnoza()
    {
        return "Diagnoza: ";
    }
};
class Leczenie : public Element
{
public:
    void accept(Visitor* v);
    string leczenie()
    {
        return "Leczenie: ";
    }
};



class Visitor
{
public:
    virtual void visit(Diagnoza* e) = 0;
    virtual void visit(Leczenie* e) = 0;
};
void Diagnoza::accept(Visitor* v)
{
    v->visit(this);
}
void Leczenie::accept(Visitor* v)
{
    v->visit(this);
}


class OfficialPrice : public Visitor
{
public:

};
class OfficialPriceNeighbor : public Visitor
{
public:

};
class Weterynarz : public Visitor
{
public:
    //        void visit(Zwierze *e)
    //        {
    //
    //        }
    void visit(Diagnoza* e)
    {
        cout << e->diagnoza() + "choroba. ";
    }
    void visit(Leczenie* e)
    {
        cout << e->leczenie() + "antybiotyki, dieta. " << endl;
    }
};





int main(void)
{
    Element* list[] =
    {
        new Diagnoza(), new Leczenie()
    };
    //    OfficialPrice op;
    //    OfficialPriceNeighbor opn;
    Weterynarz wet;

    for (int i = 0; i < 2; i++)
        list[i]->accept(&wet);
    //    for (int i = 0; i < 2; i++)
    //        list[i]->accept(&opn);


    return 0;
}
