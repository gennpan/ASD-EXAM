#ifndef ABR_HPP
#define ABR_HPP

#include <iostream>
#include "node.hpp"

using namespace std;

template <class T>
class ABR {
   public:
    Node<T> *root;

        ABR() : root{nullptr} {}    //costruttore
        ~ABR() { deleteAbr(root); } 

        int altezza_helper(Node<T> *node) const {
            //caso passo
            if (node == nullptr)
                return 0; //0 per fare i calcoli
            //passo induttivo
            int altezza_left = altezza_helper(node->getLeft());
            int altezza_right = altezza_helper(node->getRight());
            return 1 + (altezza_left > altezza_right ? altezza_left : altezza_right);
        }

        void deleteAbr(Node<T> *node) {
             if (node == nullptr) return;
             deleteAbr(node->getLeft());
             deleteAbr(node->getRight());
             cout << "Delete node with value:  " << node->getKey() << endl;
        }

        Node<T>* minimum(Node<T>* x) {
        Node<T>* app = x;
        while(app->getRight()){
            app = app->getRight();
            }   
            return app;
        }

    void transplant(Node<T>* x, Node<T>* y) {
         if (x->getParent() == nullptr)
             root = y;
         else if (x == x->getParent()->getLeft())
             x->getParent()->setLeft(y);
         else
             x->getParent()->setRight(y);
         if (y != nullptr )
             x->setParent(y->getParent());
        }


    void preorder(Node<T>* node) {
        if (node == nullptr)
            return;
        cout << node->getKey() << endl;
        preorder(node->node.getLeft());
        preorder(node->node.getRight());
    }


    void inorder(Node<T>* node,ofstream& out){
        if(node==nullptr){return;}
        inorder(node->getLeft(),out);
        out<<node->getKey()<< endl;
        inorder(node->getRight(),out);
    }

    void postorder(Node<T>* node){
    if (node==nullptr){return;}

    postorder(node->getLeft());
    postorder(node->getRight());
    cout<< node->key<< endl;
    }


    Node<T>* Treemin(Node<T>* node){
    if(node==nullptr){return nullptr;}
        while(node->getLeft()!=nullptr){
            node=node->getLeft();
        }
        return node;
    }

    Node<T>* Treemax(Node<T>* node){
    if(node==nullptr){return nullptr;}
        while(node->getRight()!=nullptr){
            node=node->getRight();
        }
        return node;
    }


    Node<T>* Ricerca_nodo(T chiave,Node<T>* node){
    if(node==nullptr){return nullptr;}
        if(node->getKey()==chiave){
            return node;
        }
    if(chiave<node->getKey()){return Ricerca_nodo(chiave,node->getLeft());}
        else{return Ricerca_nodo(chiave,node->getRight());}
    }


    Node<T>* RicercaIT(T chiave, Node<T>* node){
    if (node==nullptr){return nullptr;}
        while(node!=nullptr && chiave!= node->getKey()){
    if(node->getKey()>chiave){node=node->getLeft();}
        else{node=node->getRight();}
        }
        return node;
    }


    Node<T>* predecessore(Node<T>* node){
    if(node==nullptr){return nullptr;}
        if(node->getLeft()!=nullptr){ return Treemax(node->getLeft());}
            auto y=node->getParent();
        while(y!=nullptr&& node!=y->getRight()){
            node=y;
            y=node->getParent();
        }
        return y;
    }


    Node<T>* successore(Node<T>* node){
    if(node==nullptr){return nullptr;}
        if(node->getRight()!=nullptr){return Treemin(node->getRight());}
            auto y=node->getParent();
        while(y!=nullptr&&node!=y->getLeft()){
            node=y;
            y=node->getParent();
        }
        return y;
    }


    void inserire(T &value)
    {
        Node<T> *z = new Node<T>(value);
        Node<T> *y = nullptr;
        Node<T> *x = root;
        while(x) {
            y = x;
            if (z->getKey() < x->getKey()){
                x = x -> getLeft();
            } else { 
                x = x -> getRight();
            }
        }
        z->setParent(y);
        //decidiamo dove inserire il nodo
        if(y == nullptr) {
            root = z;
        } else if (z -> getKey() < y->getKey()) {
                y->setLeft(z);
        } else {
            y -> setRight(z);
        }
    }

    

    int altezza() const {
        return altezza_helper(root);
    }


    friend std::ostream &operator<<(std::ostream&out, const ABR& abr) {
        //se albero è vuoto non entro nella funzione
        if(abr.root == nullptr) {
            out << "nullptr" << endl;
            return out;
        }
        abr.printAbr(out, abr.root);
        return out;
    }


    void cancellare(Node<T>* z) {
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