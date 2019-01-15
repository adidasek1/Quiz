#include <fstream>

#include "baza_pytan_z_pliku.h"

BazaPytanZPliku::~BazaPytanZPliku()
{
    //dtor
}

bool BazaPytanZPliku::Inicjalizuj(std::string const& nazwa_pliku_z_pytaniami)
{
    /*
        immplementacja zaklada ze format pliku z pytaniami przedstawia sie nastepujaco:
        - kazde pytanie zapisane jest w 6 liniach:
            - piewsza to tresc pytania
            - 4 nastepne to odpowiedzi a-c
            - 6 linia zawiera informacje ktora z odpowiedzi jest poprawna
        - format nie zawiera bezposredniej informacji ile jest pytan w pliku
        - propozycje odpowiedzi nie sa poprzedzone identyfikatorami (a-c)

    */

    //Naiwne rozwiazanie - wszytkie pytania zaladowanie do pamieci
    std::ifstream uchwyt_pliku;
    uchwyt_pliku.open(nazwa_pliku_z_pytaniami);
    if (!uchwyt_pliku.is_open())
    {
        return false;
    }
    //nie ma zadnych zabezpieczen przed danymi zapisanymi niewlasciwie
    std::string line;
    std::string tresc_pytania;
    while (!uchwyt_pliku.eof())
    {
        //przeczytaj tresc pytania
        std::getline(uchwyt_pliku, tresc_pytania);
        tresc_pytania += "\n";
        //przeczytaj 1 odpowiedz (a)
        std::getline(uchwyt_pliku, line);
        tresc_pytania += std::string("a) ") +  line + "\n";
        //przeczytaj 2 odpowiedz (b)
        std::getline(uchwyt_pliku, line);
        tresc_pytania += std::string("b) ") +  line + "\n";
        //przeczytaj 3 odpowiedz (c)
        std::getline(uchwyt_pliku, line);
        tresc_pytania += std::string("c) ") +  line + "\n";
        //przeczytaj 4 odpowiedz (d)
        std::getline(uchwyt_pliku, line);
        tresc_pytania += std::string("d) ") +  line + "\n";
        //przeczytaj poprawna odpowiedz (d)
        std::getline(uchwyt_pliku, line);
        Pytanie pytanie;
        pytanie.Inicjalizuj(tresc_pytania, line[0]);
        pytania_.emplace_back(pytanie);
    }
    return true;
}

Pytanie const* BazaPytanZPliku::PodajPytanie(unsigned int index) const
{
    if (index >= pytania_.size())
    {
        return nullptr;
    }
    return &pytania_[index];
}

unsigned int BazaPytanZPliku::ZwrocIloscWszystkichPytan() const
{
    return pytania_.size();
}
