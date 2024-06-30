#include "graph.hpp"

int main() {
    int V = 5; // Numero di vertici
    
    // Creazione del grafo
    Grafo g(V);
    // Aggiunta degli archi del grafo
    g.aggiungiArco(0, 1, 2);
    g.aggiungiArco(0, 3, 6);
    g.aggiungiArco(1, 2, 3);
    g.aggiungiArco(1, 3, 8);
    g.aggiungiArco(1, 4, 5);
    g.aggiungiArco(2, 4, 7);
    g.aggiungiArco(3, 4, 9);
    // Applicazione dell'algoritmo di Prim e stampa del costo totale
    cout << "Costo totale del mst "<<endl;
    cout<<g.prim()<<endl;
 
    return 0;
}
