#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class nodo{
public:
    nodo<T>* fd;
    nodo<T>* fs;
    nodo<T>* par;
    T key;

    nodo(T key): fd(nullptr),fs(nullptr),par(nullptr),key(key){};
};

template<class T>
class ABR{
public:
    nodo<T>* rad;
    ABR():rad(nullptr){};


    void preorder(nodo<T>* node){
    if(node==nullptr){return;}

    cout<<node->key<<endl;
    preorder(node->fs);
    preorder(node->fd);
    }

    void inorder(nodo<T>* node,ofstream& out){
    if(node==nullptr){return;}
    inorder(node->fs,out);
    out<<node->key<<endl;
    inorder(node->fd,out);
    }

    void postorder(nodo<T>* node){
    if (node==nullptr){return;}

    postorder(node->fs);
    postorder(node->fd);
    cout<<node->key<<endl;
    }

    int Altezza(nodo<T>* node){
    if(node==nullptr){return 0;}
    else{
     int altezzasin=Altezza(node->fs);
     int altezzades=Altezza(node->fd);
    return 1+max(altezzasin,altezzades);

    }
    }

nodo<T>* Treemin(nodo<T>* node){
if(node==nullptr){return nullptr;}
while(node->fs!=nullptr){
    node=node->fs;
}
return node;
}

nodo<T>* Treemax(nodo<T>* node){
if(node==nullptr){return nullptr;}
while(node->fd!=nullptr){
    node=node->fd;
}
return node;
}

nodo<T>* Ricerca_nodo(T chiave,nodo<T>* node){
if(node==nullptr){return nullptr;}
if(node->key==chiave){
    return node;
}
if(chiave<node->key){return Ricerca_nodo(chiave,node->fs);}
else{return Ricerca_nodo(chiave,node->fd);}
}

nodo<T>* RicercaIT(T chiave, nodo<T>* node){
if (node==nullptr){return nullptr;}
while(node!=nullptr && chiave!= node->key){
    if(node->key>chiave){node=node->fs;}
    else{node=node->fd;}
}
return node;
}

nodo<T>* predecessore(nodo<T>* node){
if(node==nullptr){return nullptr;}
    if(node->fs!=nullptr){ return Treemax(node->fs);}
    auto y=node->par;
    while(y!=nullptr&& node!=y->fd){
        node=y;
        y=node->par;
    }
    return y;
}

nodo<T>* successore(nodo<T>* node){
if(node==nullptr){return nullptr;}
    if(node->fd!=nullptr){return Treemin(node->fd);}
    auto y=node->par;
    while(y!=nullptr&&node!=y->fs){
        node=y;
        y=node->par;
    }
 return y;
}

void transplant(nodo<T>* x,nodo<T>* y){
if(x->par==nullptr){rad=y;}
    else if(x==x->par->fs){x->par->fs=y;}
        else{x->par->fd=y;}
if(y!=nullptr){
        y->par=x->par;
}
}


void inserire(nodo<T>* node){
nodo<T>* y=nullptr;
nodo<T>* x=rad;
    while(x!=nullptr){
       y=x;
       if(node->key > x->key){
        x=x->fd;
       }
    else{
        x=x->fs;
    }}
    node->par=y;
    if(y==nullptr){rad=node;}
    else if(node->key> y->key){
        y->fd=node;
    }
        else{y->fs=node;}
}

void cancellare(nodo<T>* node){
if(node==nullptr){return ;}
    if(node->fs==nullptr){transplant(node,node->fd);}
        else if(node->fd==nullptr){transplant(node,node->fs);}
            else{
                nodo<T>* y=Treemin(node->fd);
                if(y->par->key!=node->key){
                    transplant(y,y->fd);
                    y->fd=node->fd;
                    y->fd->par=y;
                }
                transplant(node,y);
                y->fs=node->fs;
                y->fs->par=y;
            }

}



};




int main()
{
    ABR<int>* albero= new ABR<int>();
    ifstream input("ABR.txt");
    if(!input.is_open()){
        cout<<"ERRORE!"<<endl;
        return -1;
    }
    int element;
    while(input>>element){
            albero->inserire(new nodo<int> (element));
    }
    input.close();
    ofstream out("OUT.txt");
    //albero->inorder(albero->rad);
    nodo<int>* A=albero->RicercaIT(1,albero->rad);
    albero->cancellare(A);
    albero->inorder(albero->rad,out);
    out.close();

}
