// GREEDY ACTIVITY SELECTOR
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

void GreedyActivitySelector(list<int> A, vector<int> start, vector<int> finish)
{
    int n;
    cout << "inserire numero di attivita': ";
    cin >> n;
    int tempo_inizio;
    int tempo_fine;
    for (int i = 0; i < n; i++)
    {
        cout << "tempo di inizio dell'attivita' " << i << " :";
        cin >> tempo_inizio;
        start.push_back(tempo_inizio);
    }
    cout << endl;
    for (int x = 0; x < n; x++)
    {
        cout << "tempo di fine dell'attivita' " << x << " :";
        cin >> tempo_fine;
        finish.push_back(tempo_fine);
    }
    cout << endl;
    A.push_back(0);
    int prev = 0;
    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[prev])
        {
            A.push_back(j);
            prev = j;
        }
    }
    list<int>::iterator lii;
    for (lii = A.begin(); lii != A.end(); lii++)
    {
        cout << "Attivita schedulate: " << *lii << endl;
    }
}

int main()
{
    list<int> A;
    vector<int> start;
    vector<int> finish;
    GreedyActivitySelector(A, start, finish);
    return 0;
}
