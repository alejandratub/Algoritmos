/*
LA SUBSECUENCIA COMÚN MÁXIMA

Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de
X (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales que
para todo j = 1, 2, ..., k tenemos xij = zj.

Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es subsecuencia
de X y subsecuencia de Y.

Complejidad: O(n*m) porque se recorren las dos secuencias

*/
#include <string>
#include <iostream>
using namespace std;

string subsecuencia(string texto, int n , string segundo, int m);
int revisar(string texto, int i, string segundo, int j);
string textoIJ(string texto, int i, string segundo, int j);

int revisar(string texto, int i, string segundo, int j)
{
  int maximo = 0;
  while(texto[i] == segundo[j])
  {
    ++i;
    ++j;
    maximo++;
  }
  return maximo;
}
string subsecuencia(string texto, int n , string segundo, int m)
{
  int j;
  string maximo;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(texto[i] == segundo[j])
      {
        if(revisar(texto, i, segundo, j) >= maximo.length())
        {
          maximo = textoIJ(texto, i, segundo, j);
        }
      }
    }
  }
  if (maximo == "")
  {
    return "No existe";
  }
  else
  {
    return maximo;
  }
}

string textoIJ(string texto, int i, string segundo, int j)
{
  string maximo = " ";
  while(texto[i] == segundo[j]){
    maximo += texto[i];
    ++i;
    ++j;
  }
  return maximo;
}

int main(){
  string X = "alejandra tubilla castellanos";
  string Z = "tubilla castellanos fernanda";
   cout << subsecuencia(X, X.length(), Z, Z.length()) << endl;

  return 0;
}
