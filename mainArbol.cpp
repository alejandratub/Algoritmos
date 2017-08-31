#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	ArbolBinario p1;
	string nombre;
	cout << " Ingresa el nombre del archivo que desea abrir (Ej. archivo.txt): ";
    cin >> nombre;
	
	clock_t t;
      int f;
      t = clock();
      p1.crear(nombre);
    t = clock() - t;
    printf ("%f seconds\n",((float)t)/CLOCKS_PER_SEC);
	//p1.inorden(p1.raiz);
	//cout<<endl;
	
	return 0;
}