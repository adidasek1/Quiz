#include <iostream>
#include "interface.h"

using namespace std;

class Pytanie
{
public:
    void Inicjalizuj(string const& tresc, char poprawna_odpowiedz);
    string const& ZwrocTresc() const;
    bool CzyPoprawna(char odpowiedz) const;

private:
    string     tresc_;
    char       poprawna_odpowiedz_;
};

//szczegolna implementacja bazyPytan czytajaca pytania z pliku (plik pelni role repozytorium)
class BazaPytanZPliku : public BazaPytan
{
public:
    bool Inicjalizuj(string const& nazwa_pliku_z_pytaniami);
    virtual Pytanie const* PodajPytanie(unsigned int index);
    virtual unsigned int ZwrocIloscWszystkichPytan();
};

class BazaPytanZPlikuFake : public BazaPytan
{
public:
    bool Inicjalizuj(string const& nazwa_pliku_z_pytaniami);
    virtual Pytanie const* PodajPytanie(unsigned int index) const;
    virtual unsigned int ZwrocIloscWszystkichPytan() const;

private:
    Pytanie pytania[3];
};

class Gra
{
public:
    Gra(unsigned int ilosc_pytan_w_grze, BazaPytan const* baza_pytan, string const& uzytkownik);
    bool CzyGraWToku() const;
    string const& PodajNazweUzytkownika() const;
    Pytanie const& LosujPytanie();
    void ZapiszWynikOdpowiedzi(bool czy_poprawna);
    unsigned int PodajIloscWszystkichPytanWGrze() const;
    unsigned int PodajIloscPoprawnychOdpowiedzi() const;

private:
    unsigned int const ilosc_pytan_w_grze_;
    BazaPytan const* baza_pytan_;
    string const uzytkownik_;

    unsigned int ilosc_wylosowanych_pytan_;
    unsigned int ilosc_poprawnych_odpowiedzi_;
};

//przyklad innej implementacji - DO USUNIECIA ALBO POKAZANIA ZE ROZUMIEM OOO
class BazaPytanZBazyDanych : public BazaPytan
{
public:
    bool Inicjalizuj(string const& url_bazy_danych);
    virtual Pytanie const* PodajPytanie(unsigned int index);
    virtual unsigned int ZwrocIloscWszystkichPytan();
};
