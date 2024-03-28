//ABR TUTOR ESERCIZIO
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
	 private:
	 		Node* left;
	 		Node* right;
	 		Node* parent;
	 		T data;
	 public:
	 		Node() : left(nullptr), right{nullptr}, parent{nullptr} {}
	 		Node(T& data) : data{data}, left(nullptr), right{nullptr}, parent{nullptr} {}
	 		 ~Node() {}//distruttore facoltativo per "igiene del codice"


	 		void setLeft(Node *left) {this->left = left ;}
	 		void setRight(Node *right) {this->right = right;}
	 		void setParent(Node *parent) {this->parent = parent ;}
	 		void setData(T &data) {this->data = data; }
	 		Node *getLeft() const { return this->left; }	
	 		Node *getRight() const { return this->right; }
	 		Node *getParent() const { return this->parent; }
	 		const T &getData() const {return data;}
            
            //friend mi serve per accedere agli attributi del nodo senza usare le funzioni getter 
            //la funzione deve restituire lo stream
            friend std::ostream &operator<<(std::ostream &out, const Node &node)
            {
                out << "Node data: " << node.getData() << "\t" << "address: " << &node << std::endl;
                out << "Left: " << node.getLeft() << "\tRight: " << node.getRight() << "\tParent: " << node.getParent() << std::endl;

                return out;
            }
};

#endif