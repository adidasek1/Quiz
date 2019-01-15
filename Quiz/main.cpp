#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "interface.h"
#include "baza_pytan_z_pliku.h"
#include "gra.h"
using namespace std;

int main()
{
    //Inicjalizacja bazy pytan - uzywamy bazy zapisanej w pliku
    cout << "Witam w Quiz" << endl;
    cout << "Podaj swoje imie:";
    string imie;
    cin >> imie;
    cout << "Podaj poziom gry ktory ciebie interesuje:" << endl;
    cout << "1 - ³atwy" << endl;
    cout << "2 - œredni" << endl;
    cout << "3 - trudny" << endl;
    cout << "4 - nie chce jednak grac" << endl;

    bool poziom_gry_wybrany = false;
    BazaPytanZPliku baza_pytan;
    unsigned int ilosc_pytan;
    bool status_inicjalizacji;
    do
    {
        poziom_gry_wybrany = true;
        cout << "Jaki poziom gry:";
        unsigned int podany_poziom_gry;
        cin >> podany_poziom_gry;
        switch (podany_poziom_gry)
        {
            case 1:
                status_inicjalizacji = baza_pytan.Inicjalizuj("latwe.txt");
                ilosc_pytan = 10;
                break;
            case 2:
                status_inicjalizacji = baza_pytan.Inicjalizuj("srednie.txt");
                ilosc_pytan = 15;
                break;
            case 3:
                status_inicjalizacji = baza_pytan.Inicjalizuj("trudne.txt");
                ilosc_pytan = 20;
                break;
            case 4:
                cout << "Ok. To konczymy zabawe";
                exit(0);
            default:
                cout << "Nie poprawny wybor!!! Sprobuj jeszcze raz!" << endl;
                poziom_gry_wybrany = false;
        }
    }
    while(!poziom_gry_wybrany);


    if (!status_inicjalizacji)
    {
        cout << "Niestety nastapil problem z inicjalizacja bazy pytan " << endl;
        exit(1);
    }


    //startujemy gre !!
    Gra gra(ilosc_pytan, &baza_pytan, imie);
    unsigned char odpowiedz;
    while (gra.CzyGraWToku())
    {
        Pytanie const& pytanie = gra.LosujPytanie();
        cout << "Tresc pytania:" << endl;
        cout << pytanie.ZwrocTresc();
        cout << "Podaj prawidlowa odpowiedz: ";

        cin >> odpowiedz;
        bool rezultat = pytanie.CzyPoprawna(odpowiedz);
        gra.ZapiszWynikOdpowiedzi(rezultat);

        if (rezultat)
        {
            cout << "Brawo to poprawna odpowiedz :)" << endl;
        }
        else
        {
            cout << "Niestety nie jest to poprawna odpowiedz :(" << endl;
        }
    }

    cout << "To byly juz wszystkie pytania." << endl;
    cout << "Liczba pytan z poprawna odpowiedzia = " << gra.PodajIloscPoprawnychOdpowiedzi() << endl;
    cout << "Liczba wszystkich pytan = " << gra.PodajIloscWszystkichPytanWGrze() << endl;

    cout << "Dziekuje za gre." << endl;
    cout << "Do nastepnego razu!!!" << endl;
    exit(0);
}
