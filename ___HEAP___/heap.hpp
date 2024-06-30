#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
class Node{
    public:
        T k;
        Node(T k): k(k){}
};

template <typename T>
class Heap{
    private:
        vector<Node<T>*> data;
        int heapsize;

        void max_heapify(int i){
            int l = i*2+1;
            int r = i*2+2;
            int max = i;
            
            if(l<heapsize && data[l]->k > data[max]->k){
                max = l;
            }

            if(r<heapsize && data[r]->k > data[max]->k){
                max = r;
            }
            
            if(max!= i){
                swap(data[i], data[max]);
                max_heapify(max);
            }
        }

        void build_max_heap(){
            for(int i =heapsize/2; i>=0; i--){
                max_heapify(i);
            }
        }
    
    public: 
        Heap(vector<Node<T>*> &values) : data(values), heapsize(values.size()){ build_max_heap(); }
        T getmax() const{ return data[0]->k; }
        vector<Node<T>*> getNodes(){ return this->data; }
        
        T extractmax(){
            if(heapsize == 0){
                throw out_of_range("heap is empty");
            }
        
            T max = getmax();
            data[0] = data[heapsize-1];
            heapsize--;
            data.pop_back();
            max_heapify(0);
            return max;
        }

        void insert(T key){
            heapsize++;
            data.push_back(new Node<T>(key));
            int i = heapsize-1;
            
            while(i>=0 && data[(i-1)/2]->k<data[i]->k){
                    swap(data[i], data[(i-1)/2]);
                    i=(i-1)/2;
                }
            }

        void heapsort(){
            build_max_heap();
            for(int j = heapsize-1; j>=1; j--){
                swap(data[0], data[j]); 
                heapsize--;
                max_heapify(0);
            }
        }
};
#endif

