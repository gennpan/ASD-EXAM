#include "contenitore.hpp"

void Contenitore::versa(float litri){
    this -> qt += litri;
}

void Contenitore::togli(float litri) {
    this->qt = this->getQt() - litri < 0.00 ? 0.00 : litri;
}

bool Anfora::isPiena() {
    return (this->getCapacita() == this->getQt());
}

bool Anfora::isVuota() {
    return(this->getQt() == 0);
}

void Anfora::riempi() {
    this->versa(this->getCapacita() - this->getQt());
}

void Anfora::svuota() {
    this->togli(this->getQt());
}


void Anfora::spostaContenuto(Anfora &DoveSpostaContenuto) {
    if(!isVuota()) {
        if(!DoveSpostaContenuto.isPiena()) {
            float litriSpostati = DoveSpostaContenuto.getCapacita() - DoveSpostaContenuto.getQt();
            if(litriSpostati > getQt()) litriSpostati = getQt();

            DoveSpostaContenuto.versa(litriSpostati);
            togli(litriSpostati);
        }
    }
}