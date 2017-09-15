#include <iostream>
#include "ArbolDosTres.h"
#include <fstream>
#include<ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    
    ArbolDosTres<int> nuevoArbol;
    int tam;
    ifstream archivo;
    
    archivo.open("100000.txt");
    archivo >> tam;
    
    for (int i=0; i<tam; i++)
    {
        int nuevoDato;
        archivo >> nuevoDato;
        nuevoArbol.insertar23(nuevoDato);
    }
    
    cout << "Se terminó de insertar" << endl;
    
    int aBuscar[] = {10, 99999, 34718, 666, 13000, 60000, 80570, 43263, 32055, 8729};
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    duration<double> time_span;
    
    for(int i=0; i<10; i++)
    {
        cout << "Se busca el elemento: " << aBuscar[i] << endl;
        t1 = high_resolution_clock::now();
        nuevoArbol.buscar(aBuscar[i]);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(t2-t1);
        cout << time_span.count() << "seconds" << endl;
        
    }
    return 0;
}