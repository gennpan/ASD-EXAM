#include "lib.hpp"

using namespace std;

int main() {
	
	//dichiarazioni
	int numNodes, numEdges;
	unordered_map<int, Node<int>*> nodesMap;
	Graph<int> G;
	string input = "input.txt";
	string output = "output.txt";
	
	//gestione dell'errore per il file di input
	ifstream in(input); 	//apertura lettura
	if(!in){
		cerr << "Errore, FILE: " << input << " e' illegibile o inesistente." << endl;
		return 1;
	}
	
	in >> numNodes >> numEdges;
	
	for(int i=0; i<numEdges; i++){
		int weight, sourceVal, destVal;
		in >> weight >> sourceVal >> destVal;
		Node<int>* sourceNode = nullptr;
		auto itsource = nodesMap.find(sourceVal);
		if(itsource == nodesMap.end()){
			sourceNode = new Node<int>(sourceVal);
			nodesMap[sourceVal] = sourceNode;
			G.addNode(sourceNode);
		} else {
			sourceNode= itsource->second;
		}
		Node<int>* destNode = nullptr;
		auto itdest = nodesMap.find(destVal);
		if(itdest == nodesMap.end()){
			destNode = new Node<int>(destVal);
			nodesMap[destVal] = destNode;
			G.addNode(destNode);
		} else {
			destNode = itdest->second;
		}
		G.addEdge(weight, sourceNode, destNode);
	}
	in.close();	//chiusura lettura

	Node<int>* snode = G.nodes[0];
	
	ofstream out(output);	//apertura scrittura
	G.BFS(snode);
	out << "Distanze dal nodo " << snode->val << ": \n" << endl;
	for(Node<int>* node : G.nodes){
		out << "DISTANZA DAL NODO " << node->val << ": " << node->distance << endl;
	}
	out.close();		//chiusura scrittura
	
	
	cout << "Il file chiamato: " << output << " e' stato creato." << endl;
	return 0;
}