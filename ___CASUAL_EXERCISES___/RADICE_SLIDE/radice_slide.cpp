#include <iostream>
#include <cmath>

int Radice(int X) { return int(sqrt(double(X)));}   //stesso nome, parametri diversi --> overloading della funzione
double Radice(double Y) { return sqrt(Y); }

int main()
{
    auto A = 1234;  //int 
    double B = 56.789;
    std::cout << "Radice intera di: " << A << " = " << Radice(A) << std::endl;

    std::cout << "Radice reale di: " << B << " = " << Radice(B) << std::endl;

    return 0;
}
