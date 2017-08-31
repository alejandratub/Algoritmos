#include <iostream> //declara la librería para archivos de entrada y salida

using namespace std;
const int tamano = 10, MAXIMO = 100;

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


void bubbleSort(int arreglo[]) //inicialización de la función bubble sort
{
    for(int i = 0; i < tamano - 1; i++) //mientras que el indice sea menor a la penúltima posición del arreglo
    {
        for(int j = 0; j < tamano - i - 1; j++) 
        {
            if(arreglo[j+1] < arreglo[j]) // si el elemento depúes de j es menor a j
            {
                intercambiar(j+1, j);
                 }  
        }
        imprime();
    }
} 

void Arreglo::intercambiar(int a, int b) //inicialización de la función auxiliar para intercambair valores
{
    //declaro una variable temporal
    int tmp;
    //intercambio el elemento en a por el elemento en b
    tmp = arreglo[a];
    arreglo[a] = arreglo[b];
    arreglo[b] = tmp;
}

void imprime(int arreglo[])
{
    for(int i = 0; i < tamano; ++i)
     {
        cout << " " << arreglo[i] << endl;
     }
}
void Escribe(int arreglo[]) //inicialización de la función para escribir los datos
{
    int Indice;
        for (Indice = 0; Indice < tamano; Indice++) //mientras que el indice sea menor al tamaño del arreglo
        {
            cout << "\nPosicion[" << Indice << "] = " << arreglo[Indice]; //imprime los elementos del arreglo
        }
    cout << "\n";
}