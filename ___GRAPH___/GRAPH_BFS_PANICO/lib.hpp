#ifndef LIB_HPP
#define LIB_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>

using namespace std;

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int INF = 99999;

template<typename T>
class Node{
    public: 
    	T key, val, distance;
    	Node<T>* parent;
    	int color = WHITE;

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
    	vector<Node<T>*> nodes;
    	vector<Edge<T>*> edges;
    	unordered_map<T, vector<pair<T,T>>> adj;
    	
	//METODI UTILI 
    	void addNode(Node<T>* node){
        	nodes.push_back(node);
    	}
    
    	void addEdge(T weight, Node<T>* source, Node<T>* destination){
        	Edge<T>* edge = new Edge<int>(weight, source, destination);
        	edges.push_back(edge);
        
        	//Definisco un grafo Orientato.
        	adj[source->val].push_back(make_pair(destination->val, weight));
        	adj[destination->val].push_back(make_pair(source->val, weight));
    	}
   
    	//Visita in ampiezza del Grafo.
    	void BFS(Node<T>* snode){
        		for(Node<T>* node: nodes){
            			node->color = WHITE;
            			node->parent = nullptr;
            			node->distance = INF;
        			}
        	snode->color = GREY;
        	snode->parent = nullptr;
        	snode->distance = 0;
        	queue<Node<T>*> Q;
        	Q.push(snode);
        	while(!Q.empty()){
            		Node<T>* u = Q.front();
            		Q.pop();
            		for(auto v: adj[u->val]){
                		Node<T>* node = nullptr;
                		for(Node<T>* n: nodes){
                    			if(n->val == v.first){
                        			node = n;
                        			break;
                    				}
                			}
                			if(node == nullptr){ continue; }
                			if(node->color == WHITE){
                    				node->color = GREY;
                    				node->parent = u;
                    				node->distance = u->distance + v.first;
                    				Q.push(node);
                			}
            			}
            			u->color = BLACK;
        		}
    		}
};
#endif