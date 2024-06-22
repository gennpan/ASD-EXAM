#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class MinHeap {
private:
    
    vector<T> heap;

    void minHeapify(int i) {
        
        int left = 2*i+1;
        int right = 2*i+2;
        int min = i;
        
        if (left < heap.size() && heap[left] < heap[i])
            min = left;
        if (right < heap.size() && heap[right] < heap[min])
            min = right;
        if (min != i) {
            swap(heap[i], heap[min]);
            minHeapify(min);
        }
    }

public:
    MinHeap() {}

    void insert(const T& value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void buildHeap() {
        for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
            minHeapify(i);
        }
    }

    void readFromFile(const std::string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        T num;
        while (file >> num) {
            insert(num);
        }
        file.close();
        buildHeap();
    }

    void writeToFile(const std::string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        for (const T& num : heap) {
            file << num << " ";
        }
        file.close();
    }
};

#endif // MIN_HEAP_H


int main() {
    
    MinHeap<int> minHeap;   // Crea un'istanza di MinHeap di tipo int
    minHeap.readFromFile("HEAP.txt");   // Leggi i numeri dal file "HEAP.txt" e inseriscili nel min-heap
    minHeap.writeToFile("OUT.txt");     // Scrivi il contenuto del min-heap nel file "OUT.txt"
    cout << "Contenuto del min-heap scritto nel file 'OUT.txt'" << endl;  // Stampa un messaggio di conferma

    return 0;
}
