#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Mediator;

class Widget
{
public:
    Widget(Mediator* mediator, const char* name)
    {
        _mediator = mediator;
        strcpy_s(_name, name);
    }
    virtual void changed();
    virtual void updateWidget() = 0;
    virtual void stay() = 0;
protected:
    char _name[50];
private:
    Mediator* _mediator;
};

class List : public Widget
{
public:
    List(Mediator* m, const char* name) : Widget(m, name) {}
    void updateWidget()
    {
        cout << _name << " X" << endl;
    }
    void stay()
    {
        cout << _name << endl;
    }
};

class Mediator
{
public:
    enum Widgets
    {
        L1,
        L2,
        L3
    };
    Mediator()
    {
        _components[L1] = new List(this, "1. Cwiczenia zaliczone.");
        _components[L2] = new List(this, "2. Wyklad (egzamin) zaliczony.");
        _components[L3] = new List(this, "3. Przedmiot zaliczony (wygrany konkurs).");
    }
    virtual ~Mediator();
    void handle(int which)
    {
        _components[which]->changed();
    }
    virtual void widgetChanged(Widget* theChangedWidget)
    {
        if (theChangedWidget == _components[L1])
        {
            _components[L1]->updateWidget();
            _components[L2]->stay();
            _components[L3]->stay();
            cout << "4. Wyjscie z programu." << endl;
        }
        else if (theChangedWidget == _components[L2])
        {
            _components[L1]->updateWidget();
            _components[L2]->updateWidget();
            _components[L3]->stay();
            cout << "4. Wyjscie z programu." << endl;
        }
        else if (theChangedWidget == _components[L3])
        {
            _components[L1]->updateWidget();
            _components[L2]->updateWidget();
            _components[L3]->updateWidget();
            cout << "4. Wyjscie z programu." << endl;
        }
    }
private:
    Widget* _components[3];
};
Mediator::~Mediator()
{
    for (int i = 0; i < 3; i++)
        delete _components[i];
}
void Widget::changed()
{
    _mediator->widgetChanged(this);
}



int main(void)
{
    Mediator c;
    int i;

    cout << "1. Cwiczenia zaliczone.\n2. Wyklad (egzamin) zaliczony.\n3. Przedmiot zaliczony (wygrany konkurs).\n4. Wyjscie z programu.\n ";
    cin >> i;

    while (i)
    {
        if (i == 4) exit(997);
        c.handle(i - 1);
        cout << "\n";
        cin >> i;
    }

    return 0;
}
