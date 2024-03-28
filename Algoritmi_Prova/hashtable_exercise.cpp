// hashtable
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
class item
{
public:
    T key;
    T value;
    item(T key, T value) : key(key), value(value) {}
};

template <typename T>
class hashtable
{
public:
    vector<item<T> *> table;
    int m;
    hashtable(int m) : m(m) {}
    int hash(T key, int i)
    { // ispezione lineare
        return (key + i) % m;
    }
    int hash_quadratica(int key, int i)
    {
        // hash con ispezione quadratica
        return (key + i + i * i) % m;
    }
    int doppio_hashing(int key, int i)
    {
        // hash con doppio hashing
        int hash1 = key % m;
        int hash2 = 1 + (key % (m - 1));
        return (hash1 + i * hash2) % m;
    }
    void insert(item<T> *item)
    {
        int i = 0;
        while (i != m)
        {
            int j = hash(item->key, i);
            if (table.size() <= j)
            {
                table.resize(j + 1, nullptr);
            }
            if (table[j] == nullptr)
            {
                table[j] = item;
                return;
            }
            else
            {
                i++;
            }
        }
        cout << "errore overflow";
    }
    item<T> *search(T key)
    {
        int i = 0;
        int j = hash(key, 0);
        while (table[j] != nullptr && i != m)
        {
            if (table[j]->key == key)
            {
                return table[j];
            }
            i++;
            j = hash(key, i);
        }
        return nullptr;
    }
};

int main()
{
    ifstream in("hash.txt");
    // controllo apertura
    int hashsize;
    in >> hashsize;
    hashtable<int> H(hashsize);
    // riempimento hashtable
    for (int i = 0; i < hashsize; i++)
    {
        int key, value;
        in >> key >> value;
        item<int> *itemx = new item<int>(key, value);
        H.insert(itemx);
    }
    in.close();
    item<int> *result = H.search(2);
    ofstream out("hashoutput.txt");
    if (result != nullptr)
    {
        out << "element found, its key: " << result->key << ", its value: "<< result->value <<endl;
    }
    else if (result == nullptr)
    {
        out << "element not found" << endl;
    }
    out.close();
    cout << "creato file output" << endl;
    return 0;
}