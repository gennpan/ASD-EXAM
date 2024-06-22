template <typename T> void STACK<T>::Push (T Elm)
{
    if (Top == Dim-1) // se lo Stack è pieno
    { T *App;
        App = new T[Dim+10]; // trasloca lo stack
        for (int i=0; i<Dim; i++) App[i] = Vet[i];
        Dim += 10;
        delete [] Vet;
        Vet = App; // allunga lo stack
    }
    Vet[ ++Top ] = Elm;
}
template <typename T> bool STACK<T>::Pop (T &Elm) {
    bool Risp;
    if (Top >= 0) Risp = true, Elm = Vet[Top--];
    else Risp = false; // stack vuoto
    return Risp;
}
