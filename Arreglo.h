//Alejandra Tubilla Castellanos 

//(Links usados como referencia)
//http://www.geeksforgeeks.org
//http://www.sourcetricks.com
//http://www.sanfoundry.com
#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

template <class T>
class Arreglo
{
    private:
        int *Datos =NULL;
        int Tam;
    public:
    	//Declaración de funciones 
        Arreglo(); 
        ~Arreglo(); 
        void Escribe();
        void lecturaDatos(string); 
        void selectionSort(); 
        void bubbleSort(); 
        void insertionSort(); 
        void mergeSort(int, int); 
        void merge(int,int, int); 
        void quickSort(int, int); 
        int particion(int,int);
        void intercambiar(int, int); 
        void bucketSort();
        void cocktailSort();
        void RadixSort();
        void ShellSort();
        void heapSort();
        void filtrar(int inicio, int fin);
        void countingSort();
};


template <class T>
Arreglo<T>::Arreglo() //inicialización del constructor
{
    //Tam = valor; //asigna el tamaño del arreglo recibido 
}
template <class T>
Arreglo<T>::~Arreglo()
{
    delete [] Datos;
}

/*-------------Función para escritura de los datos (arreglo)------------------*/
template <class T>
void Arreglo<T>::Escribe() //inicialización de la función para escribir los datos
{
    int Indice;
        for (Indice = 0; Indice < Tam; Indice++) //mientras que el indice sea menor al tamaño del arreglo
        {
            cout << "\nPosicion[" << Indice << "] = " << Datos[Indice]; //imprime los elementos del arreglo
        }
    cout << "\n";
}

/*-------------Función para lectura de los datos (arreglo) desde un archivo ------------------*/
template <class T>
void Arreglo<T>::lecturaDatos(string archivo) //función para leer los datos
{
    int i = 0; // declaración de la variable "i", inicialización de "i" en 0
    fstream archivo_num;// Declaracion del archivo
    string linea;//creo una variable tipo string para recibir el valor que se encuentra en la linea del archivo 
    archivo_num.open(archivo.c_str());//abre el archivo
    
    if(archivo_num.is_open()) // si el archivo está abierto
    {
    	cout << "Se abrió el archivo correctamente" << endl; //le muestra al usuario que se realizó correctamente
    	getline(archivo_num,linea);
    	Tam = atoi(linea.c_str()); //se le asigna un valor al tamaño al leer la primera linea del archivo
    	Datos = new int [Tam]; // se le asigna al arreglo un tamaño
    	while(!archivo_num.eof()) //mientras no se termine el archivo
    	{
    		archivo_num.ignore(0,'\n');
    		getline(archivo_num, linea); //se lee los valores
    		Datos[i] = atoi(linea.c_str()); // se va guardando un elemento en cada posición del arreglo
    		i++; // se le suma 1 al contador para poder avanzar en las posiciones del arreglo
    	}
    }
    else //si no se abrió el archivo 
    {
    	cout << "No se pudo abrir el archivo " << endl; //le avisa al usuario que no se abrio correctamente 
    }
    archivo_num.close();// se cierra el archivo
}

/*--------------------Función para intercambiar valores------------------*/
template <class T>
void Arreglo<T>::intercambiar(int a, int b) //inicialización de la función auxiliar para intercambair valores
{
    //declaro una variable temporal
    T tmp;
    //intercambio el elemento en a por el elemento en b
    tmp = Datos[a];
    Datos[a] = Datos[b];
    Datos[b] = tmp;
}

/*--------------------Selection Sort-----------------------------------*/
template <class T>
void Arreglo<T>:: selectionSort() //inicialización de la función selection Sort
{
    int contador;
    for (int i = 0; i < Tam - 1; i++)  //mientras que el indice sea menor al tamaño del arreglo
    {
        int minimo = i;
        for (int j = i + 1; j < Tam; j++) //mientras que el indice sea menor al tamaño del arreglo
        {
            if (Datos[j] < Datos[minimo])  //si el elemento en la posición j es menor al elemento en la posición del minimo
            {
            minimo = j; //igualar los elementos
            contador ++;
            }
            
        }
    intercambiar(i, minimo); //intercambiar los valores
    }
}

/*----------------------Bubble Sort----------------------------*/
template <class T>
void Arreglo<T>::bubbleSort() //inicialización de la función bubble sort
{
    for(int i = 0; i < Tam - 1; i++) //mientras que el indice sea menor a la penúltima posición del arreglo
    {
        for(int j = 0; j < Tam - i - 1; j++) 
        {
            if(Datos[j+1] < Datos[j]) // si el elemento depúes de j es menor a j
            {
                intercambiar(j+1, j);
                 }  
        }
    }
    
} 

/*------------------Insertion Sort----------------------------*/
template <class T>
void Arreglo<T>::insertionSort() //inicialización de la función insertion sort
{
    for (int i = 0; i < Tam - 1; i++) //mientras que el indice sea menor al tamaño del arreglo -1 
    {
        //declaración de variables
        int j = i + 1;
        int tmp = Datos[j];
        while (j > 0 && tmp < Datos[j-1]) //mientras j sea mayor que 0 y el elemento en j sea menor al element en j-1
        {
            Datos[j] = Datos[j-1]; //iguala
            j--;//disminuye el contador
        }
        Datos[j] = tmp; //igualo elemento a la variable temporal
    }
  }

  /*-----------------Bucket Sort----------------------*/
template <class T>
void Arreglo<T>::bucketSort()
 {  
 	 vector<int> b[Tam];
     for (int i=0; i<Tam; i++) //insertar elementos en diferente "buckets"
     {
         int bi = (Tam*Datos[i])%Tam; 
         b[bi].push_back(Datos[i]);
     }

     for (int i=0; i<Tam; i++) //ordena los "buckets"
         sort(b[i].begin(), b[i].end());

     int index = 0; //Arma el arreglo
     for (int i = 0; i < Tam; i++)
         for (int j = 0; j < b[i].size(); j++)
             Datos[index++] = b[i][j];
}

/*-------------------Cocktail Sort-------------------*/
template <class T>
void Arreglo<T>::cocktailSort()
{
    bool swapped = true;
    int start = 0;
    int end = Tam-1;
 
    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (Datos[i] > Datos[i + 1])
            {
                swap(Datos[i], Datos[i+1]);
                swapped = true;
            }
        }

        if (!swapped) //si no se movio nada ya está ordenado
            break;
        swapped = false; 
        --end;
 
        for (int i = end - 1; i >= start; --i)
        {
            if (Datos[i] > Datos[i + 1])
            {
                swap(Datos[i], Datos[i+1]);
                swapped = true;
            }
        }
        ++start;
    }
} 

/*-------------------Radix Sort --------------------*/
template <class T>
void Arreglo<T>::RadixSort()
{
  int i;
  int maxNum = Datos[0]; //encontrar el número máximo del arreglo
  for (i = 1; i < Tam; i++)
  {
    if (Datos[i] > maxNum) //si el elemento del arreglo es mayor al maximo
      maxNum = Datos[i]; //asignar como el máximo
  }
  int exp = 1;
  int *tmpBuffer = new int[Tam];
  while (maxNum / exp > 0) //for para los decimales
  {
    int decimalBucket[10] = {  0 };
    for (i = 0; i < Tam; i++) //contar las ocurrencas en el decimal
      decimalBucket[Datos[i] / exp % 10]++;
    for (i = 1; i < 10; i++) //preparar la posición para reorganizar los numeros en el decimal
      decimalBucket[i] += decimalBucket[i - 1];
    for (i = Tam - 1; i >= 0; i--) //reorganizar los numeros en el arreglo temporal para despues pasarlos al original
      tmpBuffer[--decimalBucket[Datos[i] / exp % 10]] = Datos[i];
    for (i = 0; i < Tam; i++)
      Datos[i] = tmpBuffer[i];
    exp *= 10; //mover al siguiente decimal

  }
}

/*-----------------------Shell Sort---------------------------*/
template <class T>
void Arreglo<T>::ShellSort()
{
	int i, j, k, temp;
	for(i = Tam/2; i > 0; i = i/2)
	{
		for(j = i; j < Tam; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				if(Datos[k+i] >= Datos[k]) //si es mayor el elemento sale del loop
				break;
				else
				{
					intercambiar(k,k+1); //si no es mayor intercambiar valores
				}
			}
		}
	}
}

/*---------------------Heap Sort---------------------*/
template <class T>
 void Arreglo<T>::heapSort()
    {
        int comienzo = (Tam - 2) / 2; //asignar el índice en la última hoja padre
        //este ciclo selecciona el "nodo" al índice "comienzo" para que todos los nodos
        //debajo del índice "comienzo" queden ordenados en un heap
        while (comienzo >= 0)
        {
            filtrar(comienzo, Tam - 1);
            comienzo--;
        }
        int ultimo = Tam-1;
        while(ultimo > 0)
        {
            intercambiar(ultimo, 0);//intercambiar la raíz del heap con el último elemento
            filtrar(0, ultimo - 1);//regresa el heap a que cumpla la condición del máximo padre para que sus hijos sean menores
            ultimo--;//disminuye el tamaño del heap para que el valor máximo quede en su lugar
        }
    }

/*---------------------Función auxiliar del heap Sort-------------------------*/
template <class T>
 void Arreglo<T>::filtrar(int inicio, int fin)
    {
        int raiz = inicio;
        while((2*raiz + 1) <= fin) //mientras aún tenga una hoja la raíz
        {
            int hoja = 2*raiz + 1;//se va a la hoja de la izquierda
            if((hoja + 1) <= fin && Datos[hoja] < Datos[hoja+1])//si la hoja tiene hermano hoja y es menor a él
            {
                hoja++;//entonces se va a la hoja de la derecha
            }
            if(Datos[raiz] < Datos[hoja])//si se sale de orden
            {
                intercambiar(raiz, hoja);//intercambiar la raíz con una hoja hija
                raiz = hoja;//se asigna el valor de la hoja a la raíz para continuar revisando la hoja
            }
            else{
                return;
            }
        }
    }

/*-----------------------Counting Sort---------------------------*/
 template <class T>
 void Arreglo<T>::countingSort()
{
	   int i, j, k;
     int idx = 0;
     int min, max;
     
     min = max = Datos[0];
     for(i = 1; i < Tam; i++) {
         min = (Datos[i] < min) ? Datos[i] : min;
         max = (Datos[i] > max) ? Datos[i] : max;
     }
     
     k = max - min + 1;
     //crea "buckets"
     int *B = new int [k];
     for(i = 0; i < k; i++) B[i] = 0;
     
     for(i = 0; i < Tam; i++) B[Datos[i] - min]++;
     for(i = min; i <= max; i++)
         for(j = 0; j < B[i - min]; j++) Datos[idx++] = i;
     
     
     delete [] B;
}

/*------------------------Merge Sort----------------------------*/
 template <class T>
 void Arreglo<T>::mergeSort(int lo, int hi) //inicialización de la función 
 {
     if (lo >= hi)  //si el inicio es mayor o igual al fin 
     {
         return; //termina la función
     }
    int medio = (lo + hi)/2; // crear una nueva variable para obtener la mitad del arreglo 
    mergeSort(lo, medio); // se vuelve a llamar a la misma función pero ahora empezando en el principio del arreglo y terminando en la mitad
    mergeSort( medio + 1, hi); //se vuelve a llamar a la misma función pero ahora empezando en la mitad + 1 y terminando en el final original
    merge(lo, medio, hi); // manda a llamar a la función merge con los parametros de principio y fin 
}  

/*-------------Función auxiliar del merge sort-----------------------------*/
template <class T>
void Arreglo<T>:: merge(int lo, int mid, int hi) //inicialización de la función
{
    
   int aux[Tam]; //declaración de un arreglo temporal 
    int i = lo; // declaración de un nuevo índice para el inicio del arreglo
    int j = mid + 1; //declaración de un nuevo índice para la mitad del arreglo
    int k = lo; //declaración de un nuevo índice para el arreglo auxiliar
     for (int a = lo; a <= hi; a++) //dentro de este ciclo se hace la copia del arreglo original 
    {
        aux[a] = Datos[a];
    }
    
    while( i <= mid && j <= hi) //mientras el inicio del arreglo sea menos o igual al medio y el 
    {
            if(aux[i] <= aux[j]) //si el elemento de la primera mitad del arreglo es menor al elemento de la segunda mitad del arreglo
            {
                Datos[k] = aux[i]; // insertar el elemento en el nuevo arreglo
                i++; //aumento el contador de la primera mitad
                k++; //aumento el contador del arreglo auxiliar
            }
            else 
            {
                Datos[k] = aux[j]; /// instertar el elemento en el nuevo arreglo
                j++; //aumento el contador en la segunda mitad
                k++; //aumento el contador del arreglo auxiliar
            }
    }
    if( i == mid && j <= hi) //si el contador de la primera mitad ya llegó a la mitad y el segundo contador toda vía no termina
        {
                while (j <= hi) // mientras el contador sea menor o igual al tamaño final
                {
                    Datos[k] = aux[j]; //inserto los elementos en el arreglo
                    k++; //aumento el contador del arreglo auxiliar
                    j++; //aumento el contador de la segunda mitad
                }
                
        }
    else 
    {
        while (i <= mid) //mientras el contador de la primera mitad sea menor o igual a la mitad del arreglo
        {
            Datos[k] = aux[i]; //inserto los elementos en el nuevo arreglo
            k++; //aumento el contador del arreglo auxiliar
            i++; //aumento el contador de la primera mitad
        }
    }
}

/*------------------------------Quick Sort-------------------------------*/
template <class T>
void Arreglo<T>::quickSort(int lo, int hi) //inicialización de la función
{
    int pivote; //declaración del pivote
    if (lo < hi)  //si el inicio es mas grande que el fin
    {
        //return; //termina la funcion
    //}
     pivote = particion(lo, hi);// declaración del pivote llamando a la función "partición"
        quickSort(lo, pivote- 1); //mandar a llamar a la función pero ordenando la primera mitad
        quickSort(pivote + 1, hi);//mandar a llamar a la función pero ordenando la segunda mitad
    }
}

/*--------------------Función auxiliar del Quick Sort-----------------------*/
template <class T>
int Arreglo<T>::particion(int lo, int hi)
{
    //declaración de variables 
    int inicio = lo;
    int fin = hi + 1;
    int pivote = lo;
    
    
    while (inicio < fin)//mientras el inicio sea menor al fin
    {
        do
        {
            fin--; //disminuir el contador
        }
        while (Datos[fin] > Datos[pivote]);//mientras el elemento del final sea mayor que el pivote
        
        do
        {
            inicio++; //aumenta el contador 
        }
        while ((inicio <= hi) && (Datos[inicio] < Datos[pivote])); //mientras el inicio sea menor que el fin y el elemento del inicio sea menor o igual al pivote
        
        
        if (inicio < fin)  //si el inicio es menor que el fin
        {
            intercambiar(inicio,fin);
        }
    }
  
   intercambiar(pivote, fin);
 
    return fin; //devolver la nueva posición del pivote
}
