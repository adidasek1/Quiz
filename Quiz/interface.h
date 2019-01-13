#ifndef __interface_h__
#define __interface_h__

#include <iostream>
#include "pytanie.h"

//interfejs dla Bazy Pytan
class BazaPytan
{
public:
    virtual ~BazaPytan() {};
    virtual Pytanie const* PodajPytanie(unsigned int index) const = 0;
    virtual unsigned int ZwrocIloscWszystkichPytan() const = 0;
};

#endif //__interface_h__
