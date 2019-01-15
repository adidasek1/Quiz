#ifndef BAZA_PYTAN_Z_PLIKU_H
#define BAZA_PYTAN_Z_PLIKU_H

#include <vector>
#include <string>
#include "interface.h"

//szczegolna implementacja bazyPytan czytajaca pytania z pliku (plik pelni role repozytorium)
class BazaPytanZPliku : public BazaPytan
{
public:
    virtual ~BazaPytanZPliku();
    bool Inicjalizuj(std::string const& nazwa_pliku_z_pytaniami);
    virtual Pytanie const* PodajPytanie(unsigned int index) const;
    virtual unsigned int ZwrocIloscWszystkichPytan() const;

private:
    std::vector<Pytanie> pytania_;
};

#endif // BAZA_PYTAN_Z_PLIKU_H
