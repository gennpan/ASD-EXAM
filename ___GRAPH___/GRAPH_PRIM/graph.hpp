#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definizione della classe Grafo
class Grafo {
private:
    int V; // Numero di vertici del grafo
    vector<vector<pair<int, int>>> adj; // Lista di adiacenza dei vertici
public:
    // Costruttore della classe Grafo
    Grafo(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    // Funzione per aggiungere un arco al grafo
    void aggiungiArco(int u, int v, int peso) {
        adj[u].push_back(make_pair(v, peso));
        adj[v].push_back(make_pair(u, peso));
    }
 
    // Funzione per l'algoritmo di Prim
    int prim() {
        // Creazione della coda di priorità per gli archi del grafo
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src = 0; // Sorgente
        vector<int> key(V, INT_MAX); // Inizializzazione delle chiavi
        vector<bool> inMST(V, false); // Inizializzazione del MST
        vector<int> parent(V, -1); // Inizializzazione dei genitori
        // Inserimento del primo vertice nella coda di priorità
        pq.push(make_pair(0, src));
        key[src] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
            // Scorrimento dei vertici adiacenti al vertice corrente
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = i->first;
                int peso = i->second;
                // Se v non è presente nel MST e il peso dell'arco u-v è minore della chiave di v
                if (inMST[v] == false && peso < key[v]) {
                    key[v] = peso;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
    
        int costoTotale = 0;
        // Stampa degli archi del MST e calcolo del costo totale
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " " << key[i] << endl;
            costoTotale += key[i];
        }
        return costoTotale;
    }
};
#endif;
