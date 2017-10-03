/*
LA DIVISIÓN EN PÁRRAFOS

Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas
en líneas de longitud L. Las palabras están separadas por espacios cuya amplitud ideal (en milímetros)
es b, pero los espacios pueden reducirse o ampliarse si es necesario (aunque sin solapamiento de palabras),
de tal forma que una línea pi, pi+1, ..., pj tenga exactamente longitud L. Sin embargo, existe una
penalización por reducción o ampliación en el número total de espacios que aparecen o desaparecen.
El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios,
es decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra) el costo será cero
a menos que b’ < b (ya que no es necesario ampliar la última línea).


Complejidad: O(n) ya que solo se usa un for para revisar el espacio.

 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


float reducirCosto(float red, float amplitudI, int j, int i);
float ampliarCosto(float amp, float amplitudI, int j, int i);

int main(int argc, const char * argv[]) {

  vector<string> texto = {"Tres", "tristes", "tigres", "tragaban", /*"trigo", "en","un", "trigal"*/};
  vector<int> tamPalabras;
  vector<string> linea;

  float tamLinea = 19;
  float palabraCompleta = 0;
  float tamPalEsp = 0;

  float amplitudI = 1;
  float sobrante;

  int i = 0;
  int j;

  float red;
  float amp;

  bool mostrado = true;

  for (int i = 0; i < texto.size(); i++)
  {
    tamPalabras.push_back( int(texto[i].length()) );
  }

  for (j = 0; j < texto.size(); j++)
   {
    if (mostrado)
     {
      i = j;
      mostrado = false;
      linea.clear();
      palabraCompleta = 0;
    }

    palabraCompleta += tamPalabras[j];
    tamPalEsp = palabraCompleta + ((j - i) * amplitudI);

    if (tamPalEsp > tamLinea)
     {
      sobrante = tamPalEsp - tamLinea;
      red = amplitudI - (sobrante / (j - i));
      amp = amplitudI + (tamLinea - ( (palabraCompleta - tamPalabras[j]) + (amplitudI * (j - i - 1) ) ) ) / (j - i - 1);

      if ( ampliarCosto(amp,amplitudI,j,i) > reducirCosto(red, amplitudI,j,i) && red > 0 )
       {
        linea.push_back(texto[j]);

        for (int i = 0; i < linea.size(); i++)
         {
          cout << linea[i] << " ";
        }

        cout << " " <<  "la línea se redujo: " << red << " mm." << endl;
        mostrado = true;
      }
      else {
        for (int i = 0; i < linea.size(); i++)
         {
          cout << linea[i] << " ";
        }

        cout << " " << "la línea se amplió: " << amp << " mm." << endl;
        j--;
        mostrado = true;
      }
    }
    linea.push_back(texto[j]);
  }

  for (int i = 0; i < linea.size(); i++)
   {
    std::cout << linea[i] << " ";
  }

  cout << endl;

}



float reducirCosto(float red, float amplitudI, int j, int i)
{
  return ( fabs(red - amplitudI) * (j - i) );
}

float ampliarCosto(float amp, float amplitudI, int j, int i)
 {
  return ( fabs(amp - amplitudI) * (j - i - 1) );
}
