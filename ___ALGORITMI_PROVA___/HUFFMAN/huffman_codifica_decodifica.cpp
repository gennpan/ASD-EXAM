#ifndef HUFF_HPP
#define HUF_HPP
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Node
{
public:
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
};

class Compare
{
public:
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

class HuffmanTree
{
public:
    Node *root;
    unordered_map<char, string> codes; // ad ogni carattere corrisponderà una stringa codificata
    HuffmanTree(string data)
    {
        unordered_map<char, int> freq; // ad ogni carattere corrisponderà una frequenza 
        for (char c : data)
        {
            freq[c]++;
        }
        priority_queue<Node *, vector<Node *>, Compare> pq; // creo la coda di priorità, e metto tutti i caratteri con le loro frequenze 
        for (auto pair : freq)
        {
            pq.push(new Node(pair.first, pair.second));
        }
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            Node *parent = new Node('$', left->freq + right -> freq); // il nostro nodo zeta che ha come frequenza la somma delle frequenze di x e y ovvero dx e sx
                parent->left = left;
            parent->right = right;
            pq.push(parent); // lo imposto come padre e lo metto nella coda
        }
        root = pq.top();
        pq.pop();
        generateCode(root, " ");
    }
    void generateCode(Node *node, string code)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            codes[node->data] = code;
            return;
        }
        generateCode(node->left, code + "0");
        generateCode(node->right, code + "1");
    }
    string encode(string data)
    { // metodo che concatena tutte le codifiche in un unica stringa
            string encoded = "";
        for (char c : data)
        {
            encoded += codes[c];
        }
        return encoded;
    }
    string decode(string data)
    {
        string decoded = "";
        Node *current = root;
        for (char c : data)
        {
            if (c == '0')
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            if (current->left == nullptr && current->right ==nullptr)
            {
                decoded += current->data;
                current = root;
            }
        }
        return decoded;
    }
};
#endif

//#include "HUFF.hpp"

int main()
{
    ifstream inputFile("stringa.txt");
    // controllo file aperto corettamente
    string data;
    inputFile >> data;
    HuffmanTree tree(data);
    string encoded = tree.encode(data);
    string decoded = tree.decode(encoded);
    inputFile.close();
    ofstream outputFile("huffman.txt");
    outputFile << "la stringa di partenza: " << data << endl;
    outputFile << "la stringa codificata: " << encoded << endl;
    outputFile << "la stringa decodificata: " << decoded << endl;
    outputFile.close();
    cout << "creato file di output";
    return 0;
}