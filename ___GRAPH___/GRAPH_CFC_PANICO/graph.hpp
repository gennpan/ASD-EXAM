#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Classe che rappresenta un grafo diretto mediante liste di adiacenza
class Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void printSCCs();
    void DFSUtil(int v, bool visited[], stack<int> &stack);
    void DFSUtil2(int v, bool visited[]);
    Graph transpose();
};

    Graph::Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void Graph::addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void Graph::DFSUtil(int v, bool visited[], stack<int> &stack) {
        visited[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                DFSUtil(*i, visited, stack);
            }
        }
        stack.push(v);
    }

    Graph Graph::transpose() {
        Graph g(V);
        for (int v = 0; v < V; v++) {
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            g.adj[*i].push_back(v);
            }
        }
    return g;
    }

    void Graph::DFSUtil2(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                DFSUtil2(*i, visited);
            }
        }
    }

    void Graph::printSCCs() {
        stack<int> stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, stack);
            }
        }
        Graph g = transpose();
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }  
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();
            if (!visited[v]) {
                g.DFSUtil2(v, visited);
                cout << endl;
            }
        }
    }

#endif;