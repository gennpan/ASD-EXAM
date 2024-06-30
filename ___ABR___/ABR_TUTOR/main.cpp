#include <iostream>
#include "node.hpp"
#include "abr.hpp"
using std::cout;
using std::endl;

int main()
{
    //                                15
    //                6                                  18
    //            3              7                    17      20
    //        2       4               13
    //                            9

    int v15 = 15;
    int v6 = 6;
    int v18 = 18;
    int v3 = 3;
    int v7 = 7;
    int v17 = 17;
    int v20 = 20;

    // Node n15(v15);
    // Node n6(v6);
    // Node n18(v18);
    // Node n3(v3);
    // Node n7(v7);
    // Node n17(v17);
    // Node n20(v20);

    // n15.setLeft(&n6);
    // n15.setRight(&n18);
    // n15.setParent(nullptr);

    // n6.setLeft(&n3);
    // n6.setRight(&n7);
    // n6.setParent(&n15);

    // n18.setLeft(&n17);
    // n18.setRight(&n20);
    // n18.setParent(&n15);

    // n3.setLeft(nullptr);
    // n3.setRight(nullptr);
    // n3.setParent(&n6);

    // n7.setLeft(nullptr);
    // n7.setRight(nullptr);
    // n7.setParent(&n6);

    // n17.setLeft(nullptr);
    // n17.setRight(nullptr);
    // n17.setParent(&n18);

    // n20.setLeft(nullptr);
    // n20.setRight(nullptr);
    // n20.setParent(&n18);

    Abr<int> abr;
    abr.insert(v15);
    abr.insert(v6);
    abr.insert(v18);
    abr.insert(v3);
    abr.insert(v7);
    abr.insert(v17);
    abr.insert(v20);
    cout << abr;

    cout << "Altezza albero: " << abr.altezza() << endl;
}