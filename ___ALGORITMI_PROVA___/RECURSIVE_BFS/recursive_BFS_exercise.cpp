#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int INF = 999999;

template <typename T>

class Node
{
public:
    T val;
    int color = WHITE;
    T dist;
    Node<T> *parent;
    vector<Node<T> *> adj;
    Node(T val) : val(val) {}
};

template <typename T>
class Edge
{
public:
    Node<T> *source;
    Node<T> *destination;
    Edge(Node<T> *source, Node<T> *destination) : source(source), destination(destination){}
};

template <typename T>
class Graph
{
public:
    vector<Node<T> *> nodes;
    vector<Edge<T> *> edges;
    Graph() {}
    void addNode(Node<T> *node)
    {
        nodes.push_back(node);
    }
    void addEdge(Node<T> *source, Node<T> *destination)
    {
        Edge<T> *edge = new Edge<T>(source, destination);
        edges.push_back(edge);
        source->adj.push_back(destination);
    }
    void BFS(Node<T> *s)
    {
        for (auto u : nodes)
        {
            if (u != s)
            {
                u->color = WHITE;
                u->dist = INF;
                u->parent = nullptr;
            }
        }
        s->color = WHITE;
        s->dist = 0;
        s->parent = nullptr;
        queue<Node<T> *> Q;
        Q.push(s);
        while (!Q.empty())
        {
            Node<T> *u = Q.front();
            Q.pop();
            for (auto v : u->adj)
            {
                if (v->color == WHITE)
                {
                    v->color = GREY;
                    v->dist = u->dist + 1;
                    v->parent = u;
                    Q.push(v);
                }
            }
            u->color = BLACK;
        }
    }
    void BFS_recursive(Node<T> *u)
    {
        u->color = GREY;
        for (auto v : u->adj)
        {
            if (v->color == WHITE)
            {
                v->parent = u;
                v->dist = u->dist + 1;
                BFS_recursive(v);
            }
        }
        u->color = BLACK;
    }
};


int main()
{
    Graph<int> G;

    // Creazione nodi
    Node<int> *A = new Node<int>(0);
    Node<int> *B = new Node<int>(1);
    Node<int> *C = new Node<int>(4);
    Node<int> *D = new Node<int>(5);
    Node<int> *E = new Node<int>(6);
    Node<int> *F = new Node<int>(3);

    // Aggiunta nodi al grafo
    G.addNode(A);
    G.addNode(B);
    G.addNode(C);
    G.addNode(D);
    G.addNode(E);
    G.addNode(F);

    // Aggiunta archi al grafo
    G.addEdge(A, B);
    G.addEdge(A, C);
    G.addEdge(B, D);
    G.addEdge(C, D);
    G.addEdge(C, E);
    G.addEdge(D, E);
    G.addEdge(D, F);

    // Esecuzione BFS iterativa a partire da A
    cout << "BFS iterativa a partire da A: ";
    G.BFS(A);
    for (auto u : G.nodes)
    {
        cout << u->val << "(" << u->dist << ") ";
    }
    cout << endl;

    // Reset colori e distanze dei nodi
    for (auto u : G.nodes)
    {
        u->color = WHITE;
        u->dist = INF;
    }

    // Esecuzione BFS ricorsiva a partire da A
    cout << "BFS ricorsiva a partire da A: ";
    A->dist = 0;
    G.BFS_recursive(A);
    for (auto u : G.nodes)
    {
        cout << u->val << "(" << u->dist << ") ";
    }
    cout << endl;

    return 0;
}