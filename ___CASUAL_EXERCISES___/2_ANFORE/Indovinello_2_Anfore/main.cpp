#include "indovinello.hpp"

int main(int argc, const char * argv[]) {
    Anfora anfora1(5, 0.00), anfora2(3, 0.00);
    Indovinello nuovoIndovinello(anfora1, anfora2);
    
    nuovoIndovinello.risolvi();
    return 0;
}
