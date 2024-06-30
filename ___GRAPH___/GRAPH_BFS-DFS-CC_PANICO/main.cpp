#include "graph.hpp"


int main() {
    
    ifstream input("inputG.txt");
    if (!input) {
        cerr << "Errore durante la lettura del file di input" << endl;
        return 1;
    }
            
    int numNodes, numEdges;
    input >> numNodes >> numEdges;
    
    // Mappa che tiene traccia dei nodi già creati e dei loro valori
    unordered_map<int, Node<int>*> nodesMap;
    Graph<int> g;
    for(int i=0; i<numEdges; i++) {
        int sourceVal, destVal, weight;
        input >> sourceVal >> destVal >> weight;
 
        // Cerca il nodo di partenza nella mappa, creandolo se non esiste
        Node<int>* sourceNode = nullptr;
        auto itSource = nodesMap.find(sourceVal);
        if (itSource == nodesMap.end()) {
            sourceNode = new Node<int>(sourceVal);
            nodesMap[sourceVal] = sourceNode;
            g.addNode(sourceNode);
        } else {
            sourceNode = itSource->second;
        }
 
        // Cerca il nodo di destinazione nella mappa, creandolo se non esiste
        Node<int>* destNode = nullptr;
        auto itDest = nodesMap.find(destVal);
        if (itDest == nodesMap.end()) {
            destNode = new Node<int>(destVal);
            nodesMap[destVal] = destNode;
            g.addNode(destNode);
            } else {
                destNode = itDest->second;
            }
            g.addEdge(sourceNode, destNode, weight);
        }
    
    input.close();
    // Esegui BFS e stampa le distanze dai nodi sorgente
    g.bfs(nodesMap[1]);
    for (Node<int>* node : g.nodes) {
        cout << "Distanza dal nodo " << nodesMap[1]->val << " al nodo " 
                << node->val << ": " << node->distance << endl;
    }
 
    // Esegui DFS e stampa i tempi di scoperta e completamento dei nodi
    g.dfs();
    for (Node<int>* node : g.nodes) {
        cout << "Nodo " << node->val << ": tempo di scoperta=" << node->discovery_time 
        << ", tempo di completamento=" << node->finish_time << endl;
    }
return 0;
}