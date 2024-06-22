#ifndef contenitore_hpp
#define contenitore_hpp
#endif


class Contenitore{
private: 
    float qt;
protected:
    Contenitore();

    void versa(float litri);
    void togli(float litri);
public:
    Contenitore(float qt) : qt(0.00) { this->qt = qt; }

    float getQt() {return this-> qt; }
};


class Anfora: public Contenitore {
private: 
    const float capacita;
public:
    Anfora(float capacita, float qt) : capacita(capacita), Contenitore(qt) { }

    float getCapacita() { return this-> capacita; }

    void riempi();
    void svuota();
    bool isVuota();
    bool isPiena();
    void spostaContenuto(Anfora &DoveSpostaContenuto);
};

