#ifndef indovinello_hpp
#define indovinello_hpp
#include <iostream>
#include "contenitore.hpp"

#endif /* indovinello_hpp */

using namespace std;

class Indovinello {
private:
    Anfora anfora1;
    Anfora anfora2;
public:
    Indovinello(Anfora anfora1, Anfora anfora2) : anfora1(anfora1), anfora2(anfora2) { }
//    Indovinello(Anfora anfora1, Anfora anfora2) {
//        this->anfora1 = Anfora(anfora1.getCapacita(), anfora1.getQt());
//        this->anfora2 = Anfora(anfora2.getCapacita(), anfora2.getQt());
//    }
    
    void risolvi();
    void printInfo();
};
