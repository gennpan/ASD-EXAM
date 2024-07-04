#ifndef DFS_HPP
#define DFS_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;

template<typename T>
class Node{
    public:
    	T val, key;
    	T discovery = 0;
    	T finish = 0;
    	int color = WHITE;
    	Node<T>* parent;

    	Node(T val) : val(val){}
};

template<typename T>
class Edge{
    public:
    	T weight;
    	Node<T>* source;
    	Node<T>* destination;
    	Edge(T weight, Node<T>* source, Node<T>* destination) : weight(weight), source(source), destination(destination){}
};

template<typename T>
class Graph{
    public:
    	T time = 0;
    	vector<Node<T>*> nodes;
    	vector<Edge<T>*> edges;
    	unordered_map<T, vector<pair<T,T>>> ver;

	    //METODI UTILI	
    	void addNode(Node<T>* node){
        	nodes.push_back(node);
    	}

    	void addEdge(T weight, Node<T>* source, Node<T>* destination){
        	Edge<T>* edge = new Edge<T>(weight, source, destination);
        	edges.push_back(edge);
        
        	//Definisco un grafo non-orientato
        	ver[source->val].push_back(make_pair(destination->val, weight));
    	}

	    //Visita in profondità di un grafo
    	void DFS(){		
        	for(auto u: nodes){
            		u->color = WHITE;
            		u->parent = nullptr;
        	}
        	for(auto u: nodes){
            		if(u->color == WHITE){
                		DFS_VISIT(u);
            		}
        	}
    	}

    	void DFS_VISIT(Node<T>* u){
        	u->color = GREY;
        	u->discovery = ++time;
       	 	for(auto v : ver[u->val]){
            		Node<T>* node = nullptr;
            		for(Node<T>* n: nodes){
                		if(n->val == v.first){
                    			node = n;
                    			break;
                		}
            		}
            		if(node == nullptr){ continue; }
            		if(node->color == WHITE){
                		node->parent = u;
                		DFS_VISIT(node);
            		}
        	}
        	u->color = BLACK;
        	u->finish = ++time;
    	}
};
#endif