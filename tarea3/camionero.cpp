
/*
EL CAMIONERO CON PRISA

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a abastecer gasolina el menor número de veces posible.

Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.

Complejidad: O(n) ya que solo hay un ciclo

*/
#include <iostream>
using namespace std;

void paro(int kmRecorridos, int n, int *numGas, int gasolineras)
 {
	int i = 0;
	int temp = 0;
	while (gasolineras > i)
	 {
		if (n - kmRecorridos == (numGas[i + 1] - numGas[i]) || n - 1 == (numGas[i + 1] - numGas[i]))
		{
			cout << "Carga gasolina en la gasolinera # " << numGas[i] << endl;
			kmRecorridos = 0;
		}
		else {
			cout << "No es necesario cargar" << endl;
		}
		i++;
		kmRecorridos++;
		temp++;

	}
}

int main()
{
	int distancia = 20;
	int n = 5;
	int numeroDegasolineras = 8;
  int gasolineras[numeroDegasolineras] =  {1, 2, 3, 5, 7, 11, 15, 19};
  paro(0, n, gasolineras, numeroDegasolineras);

  return 0;
}
