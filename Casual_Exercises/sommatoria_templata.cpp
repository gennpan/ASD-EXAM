/* Spesso ci capita di voler sviluppare più funzioni in cui varia solo il tipo degli argomenti e del valore di ritorno
 *  ma non la sequenza delle operazioni che devono essere eseguite. Dunque le isrtuzioni presenti nel codice sarebbero
 *  sempre le stesse. Ad esempio se volessimo calcolare la sommatoria degli elementi di un array, dovremmo normalmente
 *  (in C) implementare 3 funzioni, che prendono come parametro l'array int/float/double e la dimensione dell'array.
 *  Come detto dovremmo riscrivere per 3 volte lo stesso codice. Avremo una situazione del tipo:
 *
 *  int SumArrI (int V[], int N)
 *    { int i; int Acc = 0;
 *     for (i=0; i<N; i++) Acc += V[i];
 *     return Acc;
 *   }
 *
 *   float SumArrF (float V[], int N)
 *   { int i; float Acc = 0.0;
 *     for (i=0; i<N; i++) Acc += V[i];
 *     return Acc;
 *   }
 *
 *   double SumArrD (double V[], int N)
 *   { int i; double Acc = 0.0;
 *     for (i=0; i<N; i++) Acc += V[i];
 *     return Acc;
 *   }
 *
 *  In C++ possiamo sfruttare l'overloading delle funzioni e assegnare lo stesso nome a diverse funzioni, in questo modo
 *  risolviamo le chiamate alle funzioni, nel senso che non dovremmo preoccuparci di chiamare la funzione giusta, ma
 *  comunque dovremmo scrivere 3 funzioni con lo stesso nome e le stesse istruzioni fatta eccezione per i paramentri che
 *  prendono in input.
 *
 *  TEMPLATE:
 *  Possiamo evitare ciò utilizzando le raffinate funzioni Template, in questo modo si evita per l'appunto di riscrivere
 *  lo stesso codice più volte. FORMAT:
 *
 *  template <class T1, class T2, ...>
 *  Tr Funzione (Tp1 Param1, Tp2 Param2, ...)
 *  { Tp3 variabili locali;
 *    istruzioni della funzione ...
 *  }
 *
 *  T2, T2, ... sono gli identificatori di TIPI GENERICI
 *
 *  Tr è il tipo di ritorno della funzione e può essere un tipo predefinito (int, float, ...) o un tipo generico
 *  definito nel template.
 *
 *  TP1, TP2, ... sono i tipi dei parametri e possono essere un tipo predefinito o un tipo generico definito nel
 *  template
 *
 *  */

//Per semplicità scrivo tutto in unico file, ma generalmente la classe template va definita in un file a parte

#include <iostream>

using namespace std;


template <class T>
T SumArray (T V[], int N)
{   int i;
    T Acc = 0;
    for (i=0; i<N; i++) Acc += V[i];
    return Acc;
}

/* T rappresenta il tipo generico che viene di volta in volta sostituito dal compilatore con il tipo di parametro
 * passato come primo argomento. Pertanto, a seconda che l'array passato alla funzione SumArray come primo parametro sia
 * di tipo int, float, oppure double, T sarà int, float o double.
 * */


main()
{   int A[10]; float B[20]; double D[30];
    cout << SumArray (A,10) << endl
         << SumArray (B,20) << endl
         << SumArray (D, 30) << endl;
}

//TEORIA - TERMINOLOGIA
/* Una funzione GENERICA, viene anche chiamata funzione template, il compilatore istanzia le funzioni template sulla
 * base dei parametri attuali specificati al momento della chiamata. Quando il compilatore crea una versione specifica
 * di una funzio e generica, si dice che ha creato una FUNZIONE GENERATA: una funzione generata è una specifica istanza
 * di una funzione template.
 * RICORDA: Una funzione generica deve eseguire le stesse opreazioni generali in tutte le sue versioni
 * a differenza di una funzione modificata tramite overloading.
 * */


//TEORIA POLIMORFISMO PARAMETRICO
/* Il C++ fornisce un metodo per creare un polimorfismo parametrico, è possibile utilizzare lo stesso codice per tipi
 * differenti: il tipo della variabile diventa un parametro. Ogni volta che nella definizione della funzione appare il
 * nome simbolico dell'identificatore, il compilatore lo sostituisce con il tipo fornito nella chiamata.
 * */


//TEORIA - TYPENAME
/* La parola chiave typename, può essere usata come alternativa a class, nelle dichiarazioni di template. Non c'è alcuna
 * ragione per preferire class a typename o viceversa, salvo alcuni casi come "template template" o "l'istanza specifica
 * di un template", casi in cui è NECESSARIO usare class - Stroutrup.
 *
 *  template <typename T1, typename T2, ...>
 *  Tr Funzione (Tp1 Param1, Tp2 Param2, ...)
 *  { Tp3 variabili locali;
 *    istruzioni della funzione ...
 *  }
 * */

//TEORIA - CLASSI GENERICHE
/* Una classe generica contiene algoritmi per i quali il tipo di dati da manipolare è specificato al momento dell'
 * istanza di ogni elemento della classe. Sono utili quando una classe contiene operazioni logiche generalizzabili :
 *
 *
 * template <typename T1, ...>
 * class NomeClasse
 * { definizione degli attributi...
 *   prototipi dei metodi...
 *  }
 *
 * Una classe template può avere un numero qualsiasi di parametri predefiniti e/o template. Per definire i metodi non
 * inline, bisogna dichiarare per ogni membro che si tratta di codice relativo ad un template e specificare il parametro
 * del template
 *
 * template <typename T>
 * T NomeClasse<T>::Metodo(...){...}
 *
 * Dopo aver definito una classe generica, è possibile crearne una specifica istanza usando la forma:
 *
 * NomeClasse <tipo> Oggetto;
 * */