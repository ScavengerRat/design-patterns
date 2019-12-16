#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

class Graphic
{
public:
    virtual void Draw() const = 0;
    virtual void AddChild(Graphic* g) {}
    virtual void Remove(Graphic* g) {}
    virtual void GetChild(int) {}
};

class Line : public Graphic
{
public:
    void Draw() const
    {
        cout << "Rysuje Linie\n";
    }
};

class Rectangle : public Graphic
{
public:
    void Draw() const
    {
        cout << "Rysuje Prostokat\n";
    }
};

class Text : public Graphic
{
public:
    void Draw() const
    {
        cout << "Pisze tekst\n";
    }
};


class Picture : public Graphic
{
private:
    vector <Graphic*> gChild;

public:
    void Draw() const
    {
        for_each(gChild.begin(), gChild.end(), mem_fun(&Graphic::Draw));
    }

    void AddChild(Graphic* new_graphic)
    {
        gChild.push_back(new_graphic);
    }

    //        Graphic *GetChild(int gc)
    //        {
    //            return gChild(gc);
    //        }

    void Remove(Graphic* remove_graphic)
    {
        gChild.erase(remove(gChild.begin(), gChild.end(), remove_graphic), gChild.end());
    }
};





int main(void)
{
    Line aLine;
    Rectangle aRectangle;
    Text aText;


    Graphic* a = new Picture();
    a->AddChild(&aLine);
    a->AddChild(&aRectangle);
    a->Draw();

    a->Remove(&aLine);
    a->Remove(&aRectangle);


    Picture* b = new Picture();
    b->AddChild(&aText);
    b->AddChild(&aLine);
    b->AddChild(&aRectangle);
    b->Draw();

    a->AddChild(&aLine);
    a->Draw();

    return 0;
}
