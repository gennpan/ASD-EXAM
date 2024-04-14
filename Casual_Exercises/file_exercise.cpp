//
// Created by panic on 28/03/2024.
//
#include <fstream>
using namespace std;
int main()
{
    ofstream filewrite("fileExercise.txt");
    filewrite << "Ciao Gente"<< endl;
    filewrite.close();
    return 0;
}
