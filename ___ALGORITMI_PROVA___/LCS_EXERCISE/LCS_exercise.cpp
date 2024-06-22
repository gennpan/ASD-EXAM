#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;
string X, Y;
int n, m, c[N][N];
char b[N][N];

void printLCS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == '\\')
    {
        printLCS(i - 1, j - 1);
        cout << X[i - 1];
    }
    else if (b[i][j] == '|')
        printLCS(i - 1, j);
    else
        printLCS(i, j - 1);
}

void LCS()
{
    n = X.length();
    m = Y.length();
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<';
            }
        }
    }
}

void printB()
{
    cout << "Matrice delle soluzioni B:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Inserire la prima stringa: ";
    cin >> X;
    cout << "Inserire la seconda stringa: ";
    cin >> Y;
    LCS();
    cout << "LCS lunghezza: " << c[n][m] << endl;
    cout << "LCS: ";
    printLCS(n, m);
    cout << endl;
    printB();
    return 0;
}
