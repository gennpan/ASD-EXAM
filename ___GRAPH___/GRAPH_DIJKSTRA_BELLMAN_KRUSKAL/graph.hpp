#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

class Node {
public:
    int id, val, dist, rank, key;
    Node* parent;
    Node(int id, int val) : id(id), val(val), 
    dist(numeric_limits<int>::max()) {}
};

class Edge {
public:
    int weight;
    Node* source;
    Node* destination;
    Edge(int weight, Node* source, Node* destination) : weight(weight), 
    source(source), destination(destination) {}
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
    return a->key > b->key;
    }
};

class Graph {
public:
    vector<Node*> nodes;
    vector<Edge*> edges;
    vector<int> parent;
    vector<int> distance;
    map<int, vector<pair<int, int>>> adjacencyList; // nuova mappa
    Graph(int n) {
    parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        distance.resize(n, numeric_limits<int>::max());
    }
 
    void addNode(Node* node) {
        nodes.push_back(node);
    }

    void addEdge(Edge* edge) {
        edges.push_back(edge);
        adjacencyList[edge->source->id].push_back({edge->destination->id, 
        edge->weight}); // nuova riga
    }

    void initializeSingleSource(Node* source) {
        for (auto node : nodes) {
            node->dist = numeric_limits<int>::max();
        }
        source->dist = 0;
        distance[source->id] = 0;
    }
    
    void relax(Edge* edge) {
        int newDist = edge->source->dist + edge->weight;
        if (newDist < edge->destination->dist) {
            edge->destination->dist = newDist;
            distance[edge->destination->id] = newDist;
            parent[edge->destination->id] = edge->source->id;
        }
    }
 
    void dijkstra(Node* source) {
        initializeSingleSource(source);
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, 
        greater<pair<int, Node*>>> pq;
        pq.push({ source->dist, source });
        while (!pq.empty()) {
                Node* curr = pq.top().second;
                pq.pop();
            for (auto edge : edges) {
                if (edge->source == curr) {
                    relax(edge);
                    pq.push({ edge->destination->dist, edge->destination});
                }
            }
        }
    }
 
    string bellman_ford(Node* source){
        initializeSingleSource(source);
        int i=0;
        while(i<nodes.size()){
            for(auto edge : edges){
                relax(edge);
            }
            for(auto edge : edges){
                if(edge->destination->dist > edge->source->dist + edge->weight){
                    return "Trovato ciclo negativo \n";
                }
            }
        i++;
        }
        return "Non trovato ciclo negativo \n";
    }

    void make_set(Node* x){
        x->parent = x;
        x->rank = 0;
        }

    Node* findset(Node* x){
        if (x != x->parent){
            x->parent = findset(x->parent);
        }
        return x->parent;
    }

    void link(Node* x, Node* y){
        if(x->rank>y->rank){
            y->parent = x;
        } else {
            x->parent = y;
        }
        if(x->rank == y->rank){
            y->rank++;
        }
}

    void union_set(Node* x, Node* y){
        link(findset(x), findset(y));
    }

    vector <Edge*> Kruskal(){
    vector<Edge*> A;
    for(auto node:nodes){
        make_set(node);
    }

    sort(edges.begin(), edges.end(),[](Edge* a, Edge* b){
        return a->weight<b->weight;
    });
 
    for(auto edge: edges){
        if( findset(edge->source) != findset(edge->destination)){
        A.push_back(edge);
        union_set(edge->source, edge->destination);
        }
    }
    return A;
    }

    void ShowAdjacentList(Node* u) {
        cout << "Lista di adiacenza del nodo " << u->id << ":\n";
        for (auto it = adjacencyList[u->id].begin(); it != adjacencyList[u->id].end(); it++) {
            cout << " " << u->id << " -> " << it->first << " (peso " << it->second << ")\n";
        }
    }
};
#endif
