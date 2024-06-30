#include <iostream>

using namespace std;

class SETTE {
    public: 
        SETTE() { Info = 7; }
        int GetInfo1() { return Info; }
    private: 
        int Info;   //istanziati separatamente
};


class UNDICI {
    public: 
        UNDICI() { Info = 11; }
        int GetInfo2() { return Info; }     //se quì avessi messo GetInfo1() si sarebbe generata ambiguità 
    private:
        int Info;   //istanziati separatamente
};

class NOVA: public SETTE, public UNDICI {   //classe che eredita 
    /*codice */
};


int main() {

    NOVA A;
    cout << A.GetInfo1() << endl;
    cout << A.GetInfo2() << endl;

}


/*In questo caso non abbiamo problemi di sovrapposizione in quanto le due variabili
  info sono istanziate separatamente nella sezione private.*/





//MANTENENDO lo stessa struttura del codice, cambiando solamente i due metodi con un metodo
//singolo GetInfo(), si genera un ambiguità.