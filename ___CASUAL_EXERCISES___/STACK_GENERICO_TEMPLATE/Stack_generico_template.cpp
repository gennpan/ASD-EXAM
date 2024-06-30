




#include <iostream>
#include "STACK.hpp"
#include "STACK.cpp"

using namespace std;

    main()
    { int N;
        float F;
        STACK <int> Sti;
        STACK <float> Stf;
        Sti.Push (25);
        Stf.Push (3.141592);
        if ( Sti.Pop(N) ) cout << N << endl;
        if ( Stf.Pop(F) ) cout << F << endl;
    }