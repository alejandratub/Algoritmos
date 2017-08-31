#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	ArbolBinario arbol;
	string nombre;
	cout << " Ingresa el nombre del archivo que desea abrir (Ej. archivo.txt): ";
    	cin >> nombre;
	
	clock_t t;
        int f;
        t = clock();
        arbol.crear(nombre);
    	t = clock() - t;
   	 printf ("%f seconds\n",((float)t)/CLOCKS_PER_SEC);

	
	return 0;
}
