#include "hashtable.hpp"


int main(){ 
  
    ifstream in("hash.txt"); 
    //controllo apertura 
    int hashsize; 
    in>>hashsize; 
    hashtable<int> H(hashsize); 
  
    //riempimento hashtable 
    for(int i=0; i<hashsize; i++){ 
        int key, value; 
        in>>key>>value; 
        item<int>* itemx = new item<int>(key, value); 
        H.insert(itemx); 
    } 
  
    in.close(); 
  
    item<int>* result = H.search(2); 
  
    ofstream out("hashoutput.txt"); 
  
    if(result != nullptr){ 
        out<<"element found, its key: "<<result->key<<", its value: "<<result->value<<endl; 
    } else if (result == nullptr){ 
        out<<"element not found"<<endl; 
    } 
    
    out.close(); 
    cout<<"creato file output"<<endl; 

    return 0;  
} 