//Grafo e componenti fortemente connesse
#include "graph.hpp"

using namespace std;

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout << "Componenti fortemente connesse:" << endl;
    g.printSCCs();

 return 0;

}
