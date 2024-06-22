/* #include <iostream>
using namespace std;

int Dividi(int a, int b) { return a/b; }
float Dividi(float a, float b) { return a/b; }  //overloading

int main()
{
    int x=5, y=2;
    int &rx = x;    //accesso all'area di memoria associata alla variabile
    float n=5.0, m=2.0;

    cout << Dividi(rx,y) << endl << Dividi(n,m) << endl;

    cout << rx << endl;
    rx = 2;
    cout << x << endl; 
} */

/*ESEMPIO FUNZIONE SOVRACCARICATA CON ALIAS*/
#include <iostream>
using namespace std;

int Dividi(int a, int b) { return a/b; }
float Dividi(float a, float b) { return a/b; }

int main()
{
    int x=5, y=2;
    int &rx = x;    //accesso all'area di memoria associata alla variabile
    float n=5.0, m=2.0;

    cout << Dividi(rx,y) << endl << Dividi(n,m) << endl;

    cout << rx << endl;
    rx = 2;
    cout << x << endl;

    return 0;
}