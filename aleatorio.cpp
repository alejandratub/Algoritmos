#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

using namespace std;
const int tamano = 100000, MAXIMO = 100;
int main(){


int arreglo[ tamano ] = { 0 };
   int i;
   srand( time( 0 ) );
   for ( i = 0; i < tamano; ++i )
      arreglo[ i ] = rand() % MAXIMO;
   cout << "Los valores del arreglo son:\n";
   cout << "[ ";
   for ( i = 0; i < tamano; ++i )
   {
     cout << arreglo[ i ] << " " ;
   }
   cout << "] \n";
   cout << "tiempo de ejecución: " << clock << endl;
}