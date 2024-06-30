#include "graph.hpp"


int main() {
    bool pesiNegativi;
    ifstream file("input.txt");
    if(!file.is_open()){
        cout<<"errore";
        return 1;
    }

    int numNodes, numEdges;
    file>>numNodes>>numEdges;
    Graph graph(numNodes);
    
    // Create nodes
    for(int i=0; i<numNodes; i++){
        int id, val;
        file>>id>>val;
        Node* node = new Node(id, val);
        graph.addNode(node);
    }
 
    // Create edges
    for(int i=0; i<numEdges; i++){
        int sourceId, destinationId, weight;
        file>>sourceId>>destinationId>>weight;
        Node* sourceNode = graph.nodes[sourceId];
        Node* destinationNode = graph.nodes[destinationId];
        if(weight<0){
            pesiNegativi = true;
        }
        Edge* edge = new Edge(weight, sourceNode, destinationNode);
        graph.addEdge(edge);
    }

    file.close();
    Node* source = graph.nodes[0];

    //creiamo file output
    ofstream file2("output.txt");
    if(!file2.is_open()){
        cout << "Errore nella creazione del file di output." << endl;
        return 1;
    }

    //Run algoritmo di bellman ford
    string result;
    result = graph.bellman_ford(source);
    file2<<result;
    file2<<endl;
    
    //Run Dijkstra
    //DISCLAIMER: DIJKSTRA NON FUNZIONERA' SE NEL FILE VI SONO INPUT NEGATIVI
    
    if (pesiNegativi){
        file2<<"Dijkstra non puo' essere effettuato in quanto vi sono pesi negativi"<<endl;
    } else {
        graph.dijkstra(source);
        for (auto node : graph.nodes) {
            file2 << "Node " << node->id << ": distance=" << node->dist << ", parent=" << graph.parent[node->id] << endl;
        }
    }

    file2<<endl;
    vector<Edge*> mst_K;
    vector<Edge*> mst_P;
    file2<<"MST KRUSKAL:"<<endl;
    mst_K = graph.Kruskal();
    for(Edge* edge: mst_K){
        int sourceID = edge->source->id;
        int destinationID = edge->destination->id;
        int weight = edge->weight;
        file2<<"source: "<<sourceID<<" destination: "<<destinationID <<"weight: "<< weight <<endl;
    }
 
    file2<<endl;
 
    file2.close();
    cout<<"creato file output"<<endl;
    return 0;
}