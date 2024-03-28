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

class Node
{
public:
    int id, val, dist, rank, key;
    Node *parent;
    Node(int id, int val) : id(id), val(val), dist(numeric_limits<int>::max()) {}
};

class Edge
{
public:
    int weight;
    Node *source;
    Node *destination;
    Edge(int weight, Node *source, Node *destination) : weight(weight), source(source), destination(destination) {}
};

struct CompareNode
{
    bool operator()(const Node *a, const Node *b) const
    {
        return a->key > b->key;
    }
};

class Graph
{
public:
    vector<Node *> nodes;
    vector<Edge *> edges;
    vector<int> parent;
    vector<int> distance;
    map<int, vector<pair<int, int>>> adjacencyList; // nuova mappa
    
    Graph(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        distance.resize(n, numeric_limits<int>::max());
    }
    void addNode(Node *node)
    {
        nodes.push_back(node);
    }
    void addEdge(Edge *edge)
    {
        edges.push_back(edge);
        adjacencyList[edge->source->id].push_back({edge->destination->id, edge->weight}); // nuova riga
    }
    void initializeSingleSource(Node *source)
    {
        for (auto node : nodes)
        {
            node->dist = numeric_limits<int>::max();
        }
        source->dist = 0;
        distance[source->id] = 0;
    }
    void relax(Edge *edge)
    {
        int newDist = edge->source->dist + edge->weight;
        if (newDist < edge->destination->dist)
        {
            edge->destination->dist = newDist;
            distance[edge->destination->id] = newDist;
            parent[edge->destination->id] = edge->source->id;
        }
    }
    void dijkstra(Node *source)
    {
        initializeSingleSource(source);
        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>>pq;
        pq.push({source->dist, source});
        while (!pq.empty())
        {
            Node *curr = pq.top().second;
            pq.pop();
            for (auto edge : edges)
            {
                if (edge->source == curr)
                {
                    relax(edge);
                    pq.push({edge->destination->dist, edge->destination});
                }
            }
        }
    }

    string bellman_ford(Node *source)
    {
        initializeSingleSource(source);
        int i = 0;
        while (i < nodes.size())
        {
            for (auto edge : edges)
            {
                relax(edge);
            }
            for (auto edge : edges)
            {
                if (edge->destination->dist > edge->source->dist + edge -> weight)
                {
                    return "Trovato ciclo negativo \n";
                }
            }
            i++;
        }
        return "Non trovato ciclo negativo \n";
    }
    void make_set(Node *x)
    {
        x->parent = x;
        x->rank = 0;
    }
    Node *findset(Node *x)
    {
        if (x != x->parent)
        {
            x->parent = findset(x->parent);
        }
        return x->parent;
    }
    void link(Node *x, Node *y)
    {
        if (x->rank > y->rank)
        {
            y->parent = x;
        }
        else
        {
            x->parent = y;
        }
        if (x->rank == y->rank)
        {
            y->rank++;
        }
    }
    void union_set(Node *x, Node *y)
    {
        link(findset(x), findset(y));
    }
    vector<Edge *> Kruskal()
    {
        vector<Edge *> A;
        for (auto node : nodes)
        {
            make_set(node);
        }
        sort(edges.begin(), edges.end(), [](Edge *a, Edge *b)
             { return a->weight < b->weight; });

        for (auto edge : edges)
        {
            if (findset(edge->source) != findset(edge -> destination))
            {
                A.push_back(edge);
                union_set(edge->source, edge->destination);
            }
        }
        return A;
    }
    void ShowAdjacentList(Node *u)
    {
        cout << "Lista di adiacenza del nodo " << u->id << ":\n";
        for (auto it = adjacencyList[u->id].begin(); it != adjacencyList[u -> id].end(); it++)
        {
            cout << " " << u->id << " -> " << it->first << " (peso " << it -> second << ")\n";
        }
    }
};


int main()
{
    bool pesiNegativi;
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "errore";
        return 1;
    }
    int numNodes, numEdges;
    file >> numNodes >> numEdges;
    Graph graph(numNodes);
    // Create nodes
    for (int i = 0; i < numNodes; i++)
    {
        int id, val;
        file >> id >> val;
        Node *node = new Node(id, val);
        graph.addNode(node);
    }
    // Create edges

    for (int i = 0; i < numEdges; i++)
    {
        int sourceId, destinationId, weight;
        file >> sourceId >> destinationId >> weight;
        Node *sourceNode = graph.nodes[sourceId];
        Node *destinationNode = graph.nodes[destinationId];
        if (weight < 0)
        {
            pesiNegativi = true;
        }
        Edge *edge = new Edge(weight, sourceNode, destinationNode);
        graph.addEdge(edge);
    }
    file.close();
    Node *source = graph.nodes[0];
    // creiamo file output
    ofstream file2("output.txt");
    if (!file2.is_open())
    {
        cout << "Errore nella creazione del file di output." << endl;
        return 1;
    }
    // Run algoritmo di bellman ford
    string result;
    result = graph.bellman_ford(source);
    file2 << result;
    file2 << endl;
    // Run Dijkstra
    // DISCLAIMER: DIJKSTRA NON FUNZIONERA' SE NEL FILE VI SONO INPUT NEGATIVI
    if (pesiNegativi)
    {
        file2 << "Dijkstra non puo' essere effettuato in quanto vi sono pesi negativi "<< endl;
    }
    else
    {
        graph.dijkstra(source);
        for (auto node : graph.nodes)
        {
            file2 << "Node " << node->id << ": distance=" << node->dist << ", parent = " << graph.parent[node->id] << endl;
        }
    }
    file2 << endl;
    vector<Edge *> mst_K;
    vector<Edge *> mst_P;
    file2 << "MST KRUSKAL:" << endl;
    mst_K = graph.Kruskal();
    for (Edge *edge : mst_K)
    {
        int sourceID = edge->source->id;
        int destinationID = edge->destination->id;
        int weight = edge->weight;
        file2 << "source: " << sourceID << " destination: " << destinationID << "weight : "<< weight <<endl;
    }

    file2 << endl;

    file2.close();
    cout << "creato file output" << endl;
    return 0;
}