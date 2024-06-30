#ifndef ABR_HPP
#define ABR_HPP

#include <iostream>
#include "node.hpp"

template <typename T>
class Abr
{
private:
    Node<T> *root;

    void printAbr(std::ostream &out, Node<T> *node) const
    {
        if (node == nullptr)
            return;

        // figlio sinistro
        printAbr(out, node->getLeft());

        // nodo centrale
        out << *node;

        // figlio destro
        printAbr(out, node->getRight());
    }

    int altezza_helper(Node<T> *node) const
    {
        if (node == nullptr)
            return 0;

        int altezza_left = altezza_helper(node->getLeft());
        int altezza_right = altezza_helper(node->getRight());

        return 1 + (altezza_left > altezza_right ? altezza_left : altezza_right);
    }

    void deleteAbr(Node<T> *node)
    {
        if (node == nullptr)
            return;

        deleteAbr(node->getLeft());
        deleteAbr(node->getRight());
        std::cout << "Delete node with value: " << node->getData() << std::endl;
        delete node;
    }

public:
    Abr() : root{nullptr} {} //costruttore, inizializzo il membro root a nullptr in quanto root è un puntatore
    ~Abr()
    {
        deleteAbr(root);
    }

    void insert(T &value)
    {
        Node<T> *z = new Node<T>(value);
        Node<T> *y = nullptr;
        Node<T> *x = root;

        while (x)
        {
            y = x;
            if (z->getData() < x->getData())
            {
                x = x->getLeft();
            }
            else
            {
                x = x->getRight();
            }
        }

        z->setParent(y);

        if (y == nullptr)
        {
            root = z;
        }
        else if (z->getData() < y->getData())
        {
            y->setLeft(z);
        }
        else
        {
            y->setRight(z);
        }
    }

    int altezza() const
    {
        return altezza_helper(root);
    }

    friend std::ostream &operator<<(std::ostream &out, const Abr &abr)
    {
        if (abr.root == nullptr)
        {
            out << "nullptr" << std::endl;
            return out;
        }

        abr.printAbr(out, abr.root);
        return out;
    }
};

#endif
