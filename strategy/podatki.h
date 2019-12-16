#ifndef PODATKI_HPP
#define PODATKI_HPP

using namespace std;

class ObliczPodatek
{
    public:
        double kwotaPodatku(double kwotaNetto)
        {
            return 0.0;
        }
};

class PodatekPolska : public ObliczPodatek
{
    public:
        double kwotaPodatku(double kwotaNetto)
        {
            return kwotaNetto*0.23;
        }
};

class PodatekNiemcy : public ObliczPodatek
{
    public:
        double kwotaPodatku(double kwotaNetto)
        {
            return kwotaNetto*0.15;
        }
};

#endif
