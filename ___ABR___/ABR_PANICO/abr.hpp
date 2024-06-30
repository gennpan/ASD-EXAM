#ifndef ABR_HPP
#define ABR_HPP

#include "test2.hpp"
#include <iostream>

template <typename T>
class Abr 
{
    private: 
        Node<T> *root;
    /*Importante modo di fare, la funzione viene riscritta nella parte privata della classe*/
    void printAbr(std::ostream &out, Node<T>* node) const
    {
        //condizione di uscita - caso base
        if (node == nullptr) 
            return;

        //figlio sinistro -chiamata ricorsvia
        printAbr(out, node->getLeft());
        //nodo centrale
        out << *node;
        //figlio destro - chiamata ricorsiva
        printAbr(out, node->getRight());
    }

    int altezza_helper(Node<T> *node) const
    {
        //caso passo
        if (node == nullptr)
            return 0; //0 per fare i calcoli

        //passo induttivo
        int altezza_left = altezza_helper(node->getLeft());
        int altezza_right = altezza_helper(node->getRight());

        return 1 + (altezza_left > altezza_right ? altezza_left : altezza_right);
    }

    void deleteAbr(Node<T> *node)
    {
        if (node == nullptr) return;

        deleteAbr(node->getLeft());
        deleteAbr(node->getRight());
        std::cout << "Delete node with value:  " << node->getData() << std::endl;
    }

    Node<T>* minimum(Node<T>* x)
    {
        Node<T>* app = x;
        while(app->getRight()){
            app = app->getRight();
        }
        return app;
    }

    void transplant(Node<T>* x, Node<T>* y) 
    {
        if (x->getParent() == nullptr)
            root = y;
        else if (x == x->getParent()->getLeft())
            x->getParent()->setLeft(y);
        else
            x->getParent()->setRight(y);
        if (y != nullptr )
            x->setParent(y->getParent());
    }

public:
    Abr() : root{nullptr} {}    //costruttore
    ~Abr() 

    //Node<T>* getRoot() 
    {
        deleteAbr(root);
    } //distruttore, al momento non fa nulla ma bisogna distruggere i nodi creati
    //è importante che sia friend perchè altrimenti non posso prendere la printAbr che sta nella parte privata
    
    
    void insert(T &value)
    {
        Node<T> *z = new Node<T>(value);
        Node<T> *y = nullptr;
        Node<T> *x = root;

        while(x)
        {
            y = x;
            if (z->getData() < x->getData()){
                x = x -> getLeft();
            } else { 
                x = x -> getRight();
            }
        }

        z->setParent(y);
        //decidiamo dove inserire il nodo
        if(y == nullptr) {
            root = z;
        } else if (z -> getData() < y->getData()) {
                y->setLeft(z);
        } else {
            y -> setRight(z);
        }

    }
    
    
    int altezza() const {
        return altezza_helper(root);
    }


    friend std::ostream &operator<<(std::ostream&out, const Abr& abr)
    {
        //se albero è vuoto non entro nella funzione
        if(abr.root == nullptr) {
            out << "nullptr" << std::endl;
            return out;
        }

        abr.printAbr(out, abr.root);
        return out;
    }

    void deleteNode(Node<T>* z)
    {
        if (z->getLeft() == nullptr)
            transplant(z, z->getRight());
        else if (z->getRight() == nullptr)
            transplant(z, z->getLeft());
        else {
            Node<T>* y = minimum(z->getRight());
            if (y->getParent() !=  z){
                transplant(y, y->getRight());
                y->setRight(z->getRight());
                y->getRight()->setParent(y);
            }
            transplant(z, y);
            y->setLeft(z->getLeft());
            y->getLeft()->setParent(y);
        }
        delete z;   //in questo modo viene liberata la memoria associata a quel nodo
    }


};

#endif

/*Se l'albero è vuoto, funziona bene ? */



