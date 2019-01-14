#include "pytanie.h"

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

