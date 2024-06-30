#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;




enum colors{bianco,grigio,nero};
enum type{Oriented,Notoriented};
int tempo=0;

template<class T>
class nodo{
    public:
        T rango;
        T id;
        T key;
        int d=0,f=0;
        int distanza=INT_MAX;
        int chiave=INT_MAX;
        colors color=bianco;
        nodo<T>* par;
        nodo(T id, T key): id(id),key(key), par(nullptr){}
};

template<class T>
class arco{
public:
    nodo<T>* sorgente;
    nodo<T>* destinazione;
    T peso;
    arco(nodo<T>* sorgente, nodo<T>* destinazione,T peso): sorgente(sorgente),destinazione(destinazione),peso(peso){}
};

template<class T>
class comparatore_nodi{
public:
    bool operator ()(nodo<T>* x, nodo<T>* y){return x->chiave < y->chiave;}


};

template<class T>
class grafo{
public:
    int numa,numv;
    type tipo;
    nodo<T>* radice;
    vector<nodo<T>*> nodi;
    vector<arco<T>*> archi;
    map<T,vector<pair<T,T>>> adiacenze;
    grafo(int numa,int numv,type tipo):numa(numa),numv(numv),tipo(tipo){}

    void Addnodo(nodo<T>* node){
    if(node!=nullptr){
            for(auto a:nodi){
                if(a->id==node->id){
                    cout<<"Nodo con stesso id gia' inserito. Impossibile inserire"<<endl;
                   return;
                }
            }
            if(nodi.empty()){
                radice=node;
                //cout<<" ID RADICE: "<<radice->id<<endl;
            }
        auto it=find(nodi.begin(),nodi.end(),node);
        if (it==nodi.end()){
            nodi.push_back(node);
            //cout<<"nodo inserito"<<endl;
        }
        else {cout<<"nodo gia' inserito!"<<endl;}

    }
    }

    void Addarco(arco<T>* edge){
    if(edge!=nullptr){
            for(auto a:archi){
                if(a->sorgente->id==edge->sorgente->id&&a->destinazione->id==edge->destinazione->id&&a->peso==edge->peso){
                    cout<<"arco gia' inserito"<< endl;
                    return;
                }
            }
        auto it=find(archi.begin(),archi.end(),edge);
        if(it==archi.end()){
            archi.push_back(edge);
    adiacenze[edge->sorgente->id].push_back(make_pair(edge->destinazione->id,edge->peso));
        if(tipo==Notoriented){
            adiacenze[edge->destinazione->id].push_back(make_pair(edge->sorgente->id,edge->peso));
        }
        }
    }
    }

    void BFS(){
    radice->color=grigio;
    radice->distanza=0;
    queue<nodo<T>*> coda;
    coda.push(radice);
    while(!coda.empty()){
        nodo<T>* elem=coda.front();
        coda.pop();
        nodo<T>* nuovo=nullptr;
    for(auto v:adiacenze[elem->id]){
        for(auto a:nodi){
            if(a->id==v.first){
                nuovo=a;
                break;
            }
        }
        if(nuovo->color==bianco)
            {
                nuovo->color=grigio;
                nuovo->par=elem;
                nuovo->distanza=elem->distanza+1;
                coda.push(nuovo);
            }
            }
        elem->color=nero;
        cout<<"ID: "<<elem->id<<endl;
    }
    }

    void DFS(){
        for(auto u:nodi){
            if(u->color==bianco){
                DFS_visit(u);
            }
        }
    }

    void DFS_visit(nodo<T>* u){
        u->color=grigio;
        tempo+=1;
        u->d=tempo;
        nodo<T>* elem=nullptr;
        for(auto v:adiacenze[u->id]){
                for(auto a:nodi){
                    if(a->id==v.first){
                        elem=a;
                        break;
                    }
                }
                if(elem!=nullptr && elem->color==bianco){
                elem->par=u;
                DFS_visit(elem);
                }
        }
        tempo+=1;
        u->f=tempo;
        u->color=nero;

        cout<<"ID: "<<u->id<<" INIZIO:"<<u->d<<" FINE:"<<u->f<<endl;
    }

    void make_set(nodo<T>* x){
    x->par=x;
    x->rango=0;
    }

    nodo<T>* find_set(nodo<T>* x){
    if(x!=x->par){
        x->par=find_set(x->par);
        return x->par;
    }
    }

    void link(nodo<T>* x,nodo<T>* y){
    if(x->rango > y->rango){
        y->par=x;
    }
    else {x->par=y;}
    if(x->rango==y->rango){
        y->rango+=1;
    }
    }

    void unione(nodo<T>* x,nodo<T>* y){
    link(find_set(x),find_set(y));
    }

    vector<arco<T>*> Kruskal(){
    vector<arco<T>*> S;
    for(auto a:nodi){
        make_set(a);
    }
    sort(archi.begin(),archi.end(),[](arco<T>* a1,arco<T>* a2){return a1->peso < a2->peso;});
    for (auto b:archi)
    {
        cout<<"**"<< b->peso<<endl;
        if(find_set(b->sorgente)!=find_set(b->destinazione)){
            S.push_back(b);
            unione(b->sorgente,b->destinazione);
        }
    }

    return S;




    }



void prim(){
radice->chiave=0;
priority_queue<nodo<T>*,vector<nodo<T>*>,greater<nodo<T>*>> pq;
vector<nodo<T>*> estratti;
for (auto a:nodi){
    pq.push(a);

}
while(!pq.empty()){
   auto b=pq.top();
   pq.pop();
   estratti.push_back(b);
   for(auto v:adiacenze[b->id]){
        nodo<T>* elem=nullptr;
        for(auto c:nodi){
            if(c->id==v.first){
               elem=c;
                break;
            }
        }
    if(find(estratti.begin(),estratti.end(),elem)== estratti.end() && v.second< elem->chiave){
        elem->par=b;
        elem->chiave=v.second;
            }
        }
    }
    for(auto elem:nodi){
         cout<<"ID: "<< elem->id<<" CHIAVE: "<<elem->chiave<<endl;
    }
    }




    void InitSS(){
    radice->distanza=0;}

    void relax(nodo<T>* u,nodo<T>* v, T peso){
    if(v->distanza> u->distanza+ peso){
        v->distanza=u->distanza+peso;
        v->par=u;
    }
    }

    vector<nodo<T>*> Dijkstra(){
    InitSS();
    vector<nodo<T>*> S;
    priority_queue<nodo<T>*,vector<nodo<T>*>,greater<nodo<T>*>> mpq;
    for (auto a:nodi){
        mpq.push(a);
    }
    while(!mpq.empty()){
        nodo<T>* u=mpq.top();
        mpq.pop();
        S.push_back(u);
        for(auto v:adiacenze[u->id]){
            nodo<T>* elem=nullptr;
            for(auto b:nodi){
                if(b->id==v.first){
                    elem=b;
                    break;}
                    }
            relax(u,elem,v.second);
        }
    }
    for(auto c:S){
        cout<<"ID: "<<c->id<<" Distanza: "<<c->distanza<<endl;
    }

    }

    bool BellmanFord(){
    InitSS();
    for(int i=0;i<nodi.size()-1;i++){
        for(auto a:archi){
                relax(a->sorgente,a->destinazione,a->peso);
        }
    }
    for(auto a:archi){
        if(a->destinazione->distanza > a->sorgente->distanza + a->peso){
            cout<<"FALSE"<<endl;
            return false;
        }
    }
            cout<<"TRUE"<<endl;
            return true;
    }
/*

    BF
    ISS
    for i =1 to |V|-1
        for each u,v in G.E
            Relax(u,v,w)
    for each u,v in G.E
        if v.d>u.d+w(u,v)
            return false
        return true


    */
};




int main()
{
int numa,numv,element;
ifstream input("grafo.txt");
if(!input.is_open()){
    cout<<"ERRORE!"<<endl;
    return -1;
}
input>>numa>>numv;
grafo<int>* g=new grafo<int>(numa,numv,Oriented);
for(int i=0;i<numv;i++){
    input>>element;
   g->Addnodo(new nodo<int>(i,element));
}

int sid,did,w;
for(int i=0;i<numa;i++){
    input>>sid>>did>>w;
 nodo<int>* X=g->nodi[sid];
 nodo<int>* Y=g->nodi[did];
 g->Addarco(new arco<int>(X,Y,w));
    }
  // g->Addarco(new arco<int>(new nodo<int>(0,5),new nodo<int>(1,3),3));
//g->BFS();
//g->DFS();
//g->Kruskal();
//g->prim();
//g->Dijkstra();
g->BellmanFord();
}


