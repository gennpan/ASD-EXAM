#include <iostream>

using namespace std;

class Animale {
    public:
        virtual void GetFood() const { cout << "Sto mangiando: " << cibo << endl; } // Metodo virtuale per polimorfismo
    protected: 
        string cibo = "cibo generico"; // Inizializzazione della variabile
};

class Gatto : public Animale {
    public:
        void GetFood() const override { cout << "Sto mangiando pesce" << endl; } // Override del metodo
};

class Cane : public Animale {
    public: 
        void GetFood() const override { cout << "Sto mangiando carne" << endl; } // Override del metodo
};

int main() {
    Animale* bestia2 = new Cane(); // Puntatore di tipo Animale per polimorfismo
    Animale* bestia3 = new Gatto(); // Puntatore di tipo Animale per polimorfismo

    bestia2->GetFood(); // Polimorfismo: chiamata a Cane::GetFood
    bestia3->GetFood(); // Polimorfismo: chiamata a Gatto::GetFood

    delete bestia2; // Liberazione della memoria
    delete bestia3; // Liberazione della memoria
}


/*Definisco il metodo virtual per il polimorfismo, poi nelle classi derivate, effettuo l'override del metodo e infine
  nel main creo due oggetti bestia2 e bestia3 di tipo animale cane e animale gatto. */