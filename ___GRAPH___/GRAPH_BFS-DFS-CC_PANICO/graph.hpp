//Grafo con: BFS, DFS, CONNECTED COMPONENTS, 
//+operazioni insiemi disgiunti

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <functional>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int MY_INFINITY = 9999;

template<typename T>
class Node{
    public:
        T val, key;
        int rank;
        int color = WHITE;
        T discovery_time = 0;
        T finish_time = 0;
        T distance = MY_INFINITY;
 
        Node<T>* parent;
 
        Node(T val) : val(val){}
};

template<typename T>
class Edge{
    public:
        T weight;
        Node<T>* source;
        Node<T>* destination;
        Edge(T weight, Node<T>* source, Node<T>* destination) : 
        weight(weight), source(source), destination(destination){}
};

template<typename T>
class minCompare {
    public:
        bool operator()(Node<T>* a, Node<T>* b) {
        return a->key > b->key;
        }
};

template<typename T>
class Graph{
    public:
        T time = 0;
        vector<Node<T>*> nodes;
        vector<Edge<T>*> edges;
        map<T, vector<pair<T,T>>> adjacencyList;
        
        void addNode(Node<T>* node) {
            nodes.push_back(node);
        }
        
        void addEdge(Node<T>* source, Node<T>* destination, T weight) {
            Edge<T>* edge = new Edge<T>(weight, source, destination);
            edges.push_back(edge);
            adjacencyList[source->val].push_back(make_pair(destination->val, weight));
            
            // aggiungo anche l'arco inverso se il grafo non è orientato
            adjacencyList[destination->val].push_back(make_pair(source->val, weight));
        }

        void bfs(Node<T>* startNode) {
            for (Node<T>* node : nodes) {
                node->color = WHITE;
                node->distance = MY_INFINITY;
                node->parent = nullptr;
            }
            startNode->color = GREY;
            startNode->distance = 0;
            startNode->parent = nullptr;
            queue<Node<T>*> q;
            q.push(startNode);
            while (!q.empty()) {
                    Node<T>* u = q.front();
                    q.pop();
            for (auto v : adjacencyList[u->val]) {
                Node<T>* node = nullptr;
            for (Node<T>* n : nodes) {
                if (n->val == v.first) {
                    node = n;
                    break;
                }
            }
            if (node == nullptr) {
                continue;
            }
            if (node->color == WHITE) {
                node->color = GREY;
                node->distance = u->distance + v.second;
                node->parent = u;
                q.push(node);
                }
            }
            u->color = BLACK;
        }
    }
 

        void dfs(){
                for(auto u: nodes){
                    u->color = WHITE;
                    u->parent = nullptr;
                }
                for(auto u: nodes){
                    if(u->color == WHITE){
                        dfs_visit(u);
                    }
                }
        }

        void dfs_visit(Node<T>* u){
                    u->color = GREY;
                    u->discovery_time=++time;
        for (auto v : adjacencyList[u->val]) {
            Node<T>* node = nullptr;
            for (Node<T>* n : nodes) {
                if (n->val == v.first) {
                    node = n;
                    break;
                }
            }
            if (node == nullptr) {
                continue;
            }
            if(node->color==WHITE){
                node->parent= u;
                dfs_visit(node);
            }
        }
        u->color=BLACK;
        u->finish_time=++time;
    }

        void unionSet(Node<T>* x, Node<T>* y){
            linkSet(findSet(x), findSet(y));
        }

        void linkSet(Node<T>*x, Node<T>* y){
            if(x->rank > y->rank){
                y->parent = x;
            } else {
                x->parent = y;
            }
        if(x->rank == y->rank){
            y->rank++;
            }
        }

        Node<T>* findSet(Node<T>* x){
                        if(x!=x->parent){
                            x->parent = findSet(x->parent);
                        }
                    return x->parent;
        }

        void makeSet(Node<T>* x){
            x->parent = x;
            x->rank = 0;
        }
        
        void connected_components(){
            for(auto v : nodes){
                makeSet(v);
        }
        for(auto edge : edges){
        if(findSet(edge->source) != findSet(edge->destination)){
                unionSet(edge->source, edge->destination);
                }
            }
        }
};
#endif
