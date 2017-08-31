#include <iostream>
using namespace std;
#include "Arreglo.h"
int main()
{
    
    Arreglo <int> array;
    string nombre;
    cout << "\n *****ARCHIVO*****" << endl;
    cout << " Ingresa el nombre del archivo que desea abrir (Ej. archivo.txt): ";
    cin >> nombre;
    array.lecturaDatos(nombre);
    clock_t t;
      int f;
      t = clock();
      array.bucketSort();
    t = clock() - t;
    printf ("%f seconds\n",((float)t)/CLOCKS_PER_SEC);
  // array.Escribe();
   return 0;
}
