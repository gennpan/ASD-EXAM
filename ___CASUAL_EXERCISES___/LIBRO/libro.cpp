#include <iostream>



class X {
private :                   //la rappresentazione(implementazione) è privata
    int m;
public :                    //la user interface è pubblica
    X(int i =0) :m{i} {} //costruttore, inizializza il dato membro m

    int mf(int i)    //membro di funzione
    {
        int old = m;
        int m = i;      //setta un nuovo valore
        return old;     //ritorna il vecchio valore
    }
};

X var {7}; //una variabile di tipo X, è inizializzata a 7

int user(X var, X*ptr)
{
    int x = var.mf(7);      //accesso usando .
    int y = ptr->mf(9);     //accesso usando ->
    int z = var.m;          //errore: non è possibile accedere a un membro privato
  
}