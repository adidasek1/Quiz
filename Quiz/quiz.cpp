#include <iostream>
#include "quiz.h"
#include "interface.h"

using namespace std;

void Pytanie::Inicjalizuj(string const& tresc, char poprawna_odpowiedz)
{
    tresc_ = tresc;
    poprawna_odpowiedz_ = poprawna_odpowiedz;
}

string const& Pytanie::ZwrocTresc() const
{
    return tresc_;
}

bool Pytanie::CzyPoprawna(char odpowiedz) const
{
    return odpowiedz == poprawna_odpowiedz_;
}

bool BazaPytanZPlikuFake::Inicjalizuj(string const& nazwa_pliku_z_pytaniami)
{
    pytania[0].Inicjalizuj("Pytanie 1 \n a)\n b)\n c)\n", 'a');
    pytania[1].Inicjalizuj("Pytanie 2 \n a)\n b)\n c)\n", 'b');
    pytania[2].Inicjalizuj("Pytanie 3 \n a)\n b)\n c)\n", 'c');
    return true;
}

Pytanie const* BazaPytanZPlikuFake::PodajPytanie(unsigned int index) const
{
    if(index < 3)
    {
        return &pytania[index];
    }
    return NULL;
}

unsigned int BazaPytanZPlikuFake::ZwrocIloscWszystkichPytan() const
{
    return 3;
}

Gra::Gra (unsigned int ilosc_pytan_w_grze, BazaPytan const* baza_pytan, string const& uzytkownik)
: ilosc_pytan_w_grze_(ilosc_pytan_w_grze)
, baza_pytan_(baza_pytan)
, uzytkownik_(uzytkownik)
, ilosc_wylosowanych_pytan_(0)
, ilosc_poprawnych_odpowiedzi_(0)
{
}

bool Gra::CzyGraWToku() const
{
    return ilosc_wylosowanych_pytan_ <= ilosc_pytan_w_grze_;
}

Pytanie const& Gra::LosujPytanie()
{
    ++ilosc_wylosowanych_pytan_;
    srand(time(NULL));
    int index_pytania = rand() % baza_pytan_->ZwrocIloscWszystkichPytan();
    return *baza_pytan_->PodajPytanie(index_pytania);
}

void Gra::ZapiszWynikOdpowiedzi(bool czy_poprawna)
{
    if (czy_poprawna)
    {
        ++ilosc_poprawnych_odpowiedzi_;
    }
}

unsigned int Gra::PodajIloscWszystkichPytanWGrze() const
{
    return ilosc_pytan_w_grze_;
}

unsigned int Gra::PodajIloscPoprawnychOdpowiedzi() const
{
    return ilosc_poprawnych_odpowiedzi_;
}

