template <typename T>
class STACK
{ private:
    int Dim, // massima occupazione della pila
    Top; // ultimo elemento inserito
    T *Vet; // pila di T
public:
    STACK ()
    { Vet = nullptr; // pila vuota
        Dim = 0;
        Top = -1;
    }
    void Push (T Elm);
    bool Pop (T &Elm);
};