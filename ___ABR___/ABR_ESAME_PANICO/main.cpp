#include <iostream>
#include <fstream>
#include "node.hpp"
#include "abr.hpp"

using std::cout;
using std::endl;

int main() {
    ABR<int>* albero= new ABR<int>();
    ifstream input("ABR.txt");
    if(!input.is_open()){
        cout<<"ERRORE: File non trovato o non presente nella cartella."<<endl;
        return -1;
    }
    
    int element;
    while(input>>element){
            albero->inserire(element);
    }
    
    input.close();
    ofstream out("OUT.txt");
    //albero->inorder(albero->root,out);
    
    Node<int>* A=albero->RicercaIT(1,albero->root);
    albero->cancellare(A);
    albero->inorder(albero->root,out);
    out.close();

    delete albero; // Liberiamo la memoria
    return 0;
}