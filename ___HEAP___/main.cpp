#include "heap.hpp"

int main(){
    
    ifstream in("nodiheap.txt");
    //controlliamo apertura
    int val;
    vector<Node<int>*> nodes;
    while(in>>val){
        Node<int>* nodo = new Node<int>(val);
        nodes.push_back(nodo);
    }

    Heap<int> H(nodes);
    for(auto h : H.getNodes()){
        cout<<h->k<<endl;
    }
    cout<<endl;
    cout<<"inseriamo 77"<<endl;
    int k = 77;
    H.insert(k);
    for(auto h : H.getNodes()){
        cout<<h->k<<endl;   
    }

    cout<<endl;
    cout<<"inseriamo 9"<<endl;
    int kk = 9;
    H.insert(kk);
    
    for(auto h : H.getNodes()){
        cout<<h->k<<endl;
    }

    cout<<endl;
    cout<<"estraiamo il massimo : "<<H.extractmax()<<endl;
    for(auto h : H.getNodes()){
        cout<<h->k<<endl;
    }
    cout<<endl;
    cout<<"facciamo l'heapsort:"<<endl; 
    H.heapsort();
    for(auto h : H.getNodes()){
        cout<<h->k<<endl;
    }

    return 0;
}
