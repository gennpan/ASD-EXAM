#ifndef NODE_HPP //Se NODE_H non è definito 
#define NODE_HPP //definisci NODE_H

#include <iostream>

template <class T> 
class Node { 
    private:
        Node<T>* right;
        Node<T>* left;
        Node<T>* parent;
        T key;
    public: 
        Node(T key): right(nullptr),left(nullptr),parent(nullptr),key(key){};
        ~Node() {}  //distruttore (ovviamente unico)
    
        //setter
        void setLeft(Node *left) { this->left = left; }
        void setRight(Node *right) { this->right = right; }
        void setParent(Node *parent) { this->parent = parent; }
        void setKey(T &key) { this->key = key; }

        //getter
        Node *getLeft() const { return this -> left; }
        Node *getRight() const { return this -> right; }
        Node *getParent() const { return this -> parent; }
        const T &getKey() const { return key; }

        friend std::ostream &operator<<(std::ostream &out, const Node &node) {
                out << "Node key: " << node.getKey() << "\t" << "adress: " << &node << std::endl;
                out << "Left: " << node.getLeft() << "\tRight: " << node.getRight() << "\tParent: " << node.getParent() << std::endl;
                return out;
        }
};

#endif  //se è stato già definito NODE_H salto all'endif ignorando il codice precedente 






//COSTRUTTORI E DISTRUTTORI
//avere più costruttori ci consente di inizializzare gli oggetti in modi diversi, a seconda delle necessità.
//Node() : left(nullptr), right{nullptr}, parent{nullptr} {}; //costruttore di "inizializzazione predefinita"
/*Questo costruttore permette di creare un oggetto Node senza fornire alcun dato iniziale. 
Questo può essere utile quando si vuole creare un nodo vuoto e riempirlo successivamente. 
Garantisce che il nodo non abbia figli o genitori al momento della creazione*/
       
       
//Node(T &key) : key{key}, left{nullptr}, right{nullptr}, parent{nullptr} {}; //costruttore parametrizzato 
/*Permette di creare un nodo e di inizializzarlo con un valore specifico per il membro 'data'.
Questo è utile quando si vuole creare un nodo con un valore già noto. 
Come quello di inizializzazione, garantisce che il nodo non abbia figli o genitori al momento della creazione*/
           
//overload dell'operatore << 
//friend mi serve per accedere agli attributi del nodo senza usare le funzioni getter 
//la funzione deve restituire lo stream






/*L'abr può essere rappresentato come una struttura dati concatenata di nodi. Ogni nodo di un 
  ABR, contiene: la chiave(key), puntatore al padre, puntatore al figlio destro, puntatore al 
  figlio sinistro, eventuali dati satelliti. 
  
  Le chiavi, sono memorizzate in modo che sia sempre rispettata la proprietà dell'albero binario
  di ricerca.
  
  Sia x un nodo dell'albero binario di ricerca: 
  -se y è un nodo del sottoalbero sinistro di x, allora key[x] >= key[y]. 
  -se y è un nodo del sottoalbero destro di x , allora key[x] <= key[y].
  
  VISITA = attraversamento di tutti i nodi che costituiscono l'albero.
  Esistono in particolare 3 tipi di visite:
  1) visita simmetrica = il nodo radice è visitato dopo il suo sottoalbero sinistro e prima di quello destro.
  2) visita anticipata = il nodo radice è visitato prima del suo sottoabero sinistro e prima di quello destro.
  3) visita differita = il nodo radice è visitato dopo il suo sottoalbero sinistro e dopo quello destro
  
  LA PROPRIETA' DEGLI ALBERI BINARI DI RICERCA CONSENTE DI IMPLEMENTARE QUESTE VISITE CON UN SEMPLICE ALGORITMO
  RICORSIVO.
  
  */   


//Queste sono direttive al preprocessore, prendono il nome di "include guard" e sono necessarie per evitare 
//problemi quando un file.h viene incluso più volte in un progetto.