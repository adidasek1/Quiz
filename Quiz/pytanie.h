#ifndef __pytanie_h__
#define __pytanie_h__

#include <string>

class Pytanie
{
public:
    void Inicjalizuj(std::string const& tresc, char poprawna_odpowiedz);
    std::string const& ZwrocTresc() const;
    bool CzyPoprawna(char odpowiedz) const;

private:
    std::string     tresc_;
    char            poprawna_odpowiedz_;
};
#endif //__pytanie_h__
