#ifndef __quiz_h__
#define __quiz_h__

#include <string>
#include <iostream>
#include "interface.h"

//uzyta tylko do testow czy klasa Gra i sterowanie w main dziala poprawnie
class BazaPytanZPlikuFake : public BazaPytan
{
public:
    bool Inicjalizuj(std::string const& nazwa_pliku_z_pytaniami);
    virtual Pytanie const* PodajPytanie(unsigned int index) const;
    virtual unsigned int ZwrocIloscWszystkichPytan() const;

private:
    Pytanie pytania[3];
};

class Gra
{
public:
    Gra(unsigned int ilosc_pytan_w_grze, BazaPytan const* baza_pytan, std::string const& uzytkownik);
    bool CzyGraWToku() const;
    std::string const& PodajNazweUzytkownika() const;
    Pytanie const& LosujPytanie();
    void ZapiszWynikOdpowiedzi(bool czy_poprawna);
    unsigned int PodajIloscWszystkichPytanWGrze() const;
    unsigned int PodajIloscPoprawnychOdpowiedzi() const;

private:
    unsigned int const ilosc_pytan_w_grze_;
    BazaPytan const* baza_pytan_;
    std::string const uzytkownik_;

    unsigned int ilosc_wylosowanych_pytan_;
    unsigned int ilosc_poprawnych_odpowiedzi_;
};

#endif //__quiz_h__
