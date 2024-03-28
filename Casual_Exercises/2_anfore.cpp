#include <iostream>

class contenitore
{
    public:
        contenitore(){}
        void versa(double);
        void togli(double);
        double getQt() {return lt;}

    private:
        double lt;
};

void contenitore::versa(double litri) { lt=litri; }
void contenitore::togli(double litri) { lt=litri; }

class anfora : public contenitore
{
    public:
        anfora(double cap) : capacita(cap), contenuto(0.0) {};
        double getCapacita() {return capacita;}
        void riempi(double) {contenuto = capacita;}
        void svuota() {contenuto = 0.0;}
        double isVuota() {return contenuto == 0;}
        double isPiena() {return contenuto == capacita;}
        void spostaContenuto(anfora);


    private:
        double capacita, contenuto;

}