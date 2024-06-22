#include "indovinello.hpp"

void Indovinello::risolvi() {
    printInfo();
    anfora1.riempi();
    printInfo();
    anfora1.spostaContenuto(anfora2);
    printInfo();
    anfora2.svuota();
    printInfo();
    anfora1.spostaContenuto(anfora2);
    printInfo();
    anfora1.riempi();
    printInfo();
    anfora1.spostaContenuto(anfora2);
    printInfo();
    anfora2.svuota();
    printInfo();
    std::cout << "Indovinello Risolto." << std::endl;
}

void Indovinello::printInfo() {
    std::cout << "Anfora 1 - Capacità: " << anfora1.getCapacita() << " || Quantità: " << anfora1.getQt() << std::endl;
    std::cout << "Anfora 2 - Capacità: " << anfora2.getCapacita() << " || Quantità: " << anfora2.getQt() << std::endl << std::endl;
}
