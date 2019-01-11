#include <iostream>


using namespace std;

//interfejs dla Bazy Pytan
class BazaPytan
{
public:
    virtual ~BazaPytan() {};
    virtual Pytanie const* PodajPytanie(unsigned int index) const = 0;
    virtual unsigned int ZwrocIloscWszystkichPytan() const = 0;
};
