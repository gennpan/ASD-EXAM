//la coda di priorità la facciamo su un heap perchè dal punto di vista
//logico si comporta come un albero (ma è un vettore)
/*Se ho due cose da fare, posso sapere quale devo fare prima ? si, con una 
priorità basata su chiavi*/


#ifndef codaPriorita_hpp
#define codaPriorita_hpp
#include "abr.hpp"
#include "node.hpp"

template <typename T>
class codaPriorita 
{
    private: 
        Abr<T> abr;
    
    public:
        void insert(T& value){ 
            abr.insert(value);
        }

        T& extractMax(){
            Node<T>* x = abr.minimum(abr.getRoot());
            const T& value = x->getData();
            abr.deleteNode(x);
            return value;
        }

};
#endif