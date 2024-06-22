#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>

class Item
{
public:
    T value;
    T weight;
    Item(T value, T weight) : value(value), weight(weight) {}
};

template <typename T>

class Knapsack
{
public:
    vector<Item<T> *> items;
    T value;
    T capacity;
    Knapsack(vector<Item<T> *> items, T capacity) : items(items), capacity(capacity) {}
    vector<Item<T>> solve01()
    {
        int n = items.size();
        vector<Item<T>> inTheKnapsack;
        vector<vector<T>> maxValues(n + 1,
                                    vector<T>(capacity + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                if (items[i - 1]->weight > j)
                {
                    maxValues[i][j] = maxValues[i - 1][j];
                }
                else
                {
                    maxValues[i][j] = max(maxValues[i - 1][j], items[i - 1]->value + maxValues[i - 1][j - items[i - 1]->weight]);
                }
            }
        }
        int i = n;
        int j = capacity;
        while (i > 0 && j > 0)
        {
            if (maxValues[i][j] != maxValues[i - 1][j])
            {
                inTheKnapsack.push_back(*items[i - 1]);
                j -= items[i - 1]->weight;
            }
            i--;
        }
        return inTheKnapsack;
    }
    vector<pair<Item<T>, double>> solvefractional()
    {
        vector<pair<Item<T>, double>> x;
        int n = items.size();
        int k = 1;
        T value = 0.0;

        while (k <= n && capacity > 0.0)
        {
            if (items[k - 1]->weight <= capacity)
            {
                x.push_back(make_pair(*items[k - 1], 1.0));
                value += items[k - 1]->value;
                capacity -= items[k - 1]->weight;
            }
            else
            {
                double fraction = capacity / items[k - 1]->weight;
                x.push_back(make_pair(*items[k - 1], fraction));
                value += fraction * items[k - 1]->value;
                capacity = 0.0;
            }
            k++;
        }
        return x;
    }
};



int main()
{
    // Creazione di una lista di oggetti
    Item<int> *item1 = new Item<int>(4, 2);
    Item<int> *item2 = new Item<int>(3, 1);
    Item<int> *item3 = new Item<int>(6, 3);
    Item<int> *item4 = new Item<int>(7, 2);
    vector<Item<int> *> items{item1, item2, item3, item4};
    // Creazione dello zaino con una capacità massima di 7
    Knapsack<int> knapsack(items, 7);
    // Risoluzione del problema con il metodo solve01
    vector<Item<int>> solution = knapsack.solve01();
    // Stampa degli oggetti all'interno dello zaino
    cout << "Gli oggetti all'interno dello zaino sono:" << endl;
    for (auto item : solution)
    {
        cout << "Valore: " << item.value << " - Peso: " << item.weight << endl;
    }
    vector<pair<Item<int>, double>> solutionF =
        knapsack.solvefractional();
    cout << "Gli oggetti all'interno dello zaino sono:" << endl;
    for (auto item : solutionF)
    {
        cout << "Valore: " << item.first.value << " - Peso: " << item.first.weight << " - Frazione: " << item.second << endl;
    }
    return 0;
}