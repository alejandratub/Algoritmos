#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class nodo
{
public:
	int valor;
        nodo *hijoIzq=nullptr;
       nodo *hijoDer=nullptr;
  	 nodo(int dato)
    {
    	valor = dato;
    }
};


class ArbolBinario
{
public:
	nodo *raiz=NULL;
	
/*----------------Crear------------------*/
	void crear(string archivo)
	{
		string line;
		int pos=0;
		ifstream myfile (archivo);
		if(myfile.is_open())
		{
			while(getline(myfile, line))
			{
				if (pos==0)
				{
					++pos;
				}
				else
				{
					insertar(stoi(line));
				}
			}
		}
	}
/*---------------------Insertar------------------*/
	void insertar(int num)
	{
        insert(raiz, num);
	}
	void insert(nodo *&a, int num)
	{
		if (a==nullptr)
		{
			a=new nodo(num);
		}
		else if(a->valor>num || a->valor==num)
		{
			insert(a->hijoIzq, num);
		}
		else if(a->valor<num)
		{
			insert(a->hijoDer, num);
		}
	}

/*------------------Buscar---------------*/
	bool buscar(int num, nodo *&a)
	{
		if (a==nullptr)
		{
			cout<<"Valor no encontrado "<<endl;
			return false;
		}
		else
		{
			if (a->valor==num)
			{
				cout<<"Valor encontrado!!"<<endl;
				return true;
			}
			else if(a->valor>num || a->valor==num)
			{
				buscar(num, a->hijoIzq);
			}
			else if(a->valor<num)
			{
				buscar(num, a->hijoDer);
			}
		}
	}
/*------------------Eliminar-------------------*/
	bool elimina(int num)
	{
		eliminarNodo(raiz, num);
	}
	bool eliminarNodo(nodo *&a, int num)
	{
		if (a==nullptr)
		{
			cout<<"Valor no encontrado, no se puede eliminar"<<endl;
			return false;
		}
		else
		{
			if (a->valor==num)
			{
				eliminarReal(raiz, num);
			}
			else if(a->valor>num || a->valor==num)
			{
				eliminarNodo(a->hijoIzq, num);
			}
			else if(a->valor<num)
			{
				eliminarNodo(a->hijoDer, num);
			}
		}
	}

/*-------------------Eliminar Real------------------*/
	bool eliminarReal(nodo *&a, int num)
		{
		//nodo *a;
		nodo *padre;
		a=raiz;
		if (a->hijoIzq==nullptr && a->hijoDer==nullptr)
				{
					if (padre->hijoDer=a)
					{
						padre->hijoDer=nullptr;
					}
					else
					{
						padre->hijoIzq=nullptr;
					}
					cout<<"Valor eliminado"<<endl;
					return true;					
				}
				else if(a->hijoIzq==nullptr && a->hijoDer!=nullptr)
				{
					if (padre->hijoIzq==a)
					{
						padre->hijoIzq=a->hijoDer;
						delete a;
					}
					else
					{
						padre->hijoDer=a->hijoDer;
						delete a;
					}
					cout<<"Valor eliminado"<<endl;
					return true;
				}
				else if (a->hijoIzq!=nullptr && a->hijoDer==nullptr)
				{
					if (padre->hijoIzq==a)
					{
						padre->hijoIzq=a->hijoIzq;
						delete a;
					}
					else
					{
						padre->hijoDer=a->hijoIzq;
						delete a;
					}
					cout<<"Valor eliminado"<<endl;
					return true;
				}
				else if(a->hijoIzq!=nullptr && a->hijoDer!=nullptr)
				{
					nodo *aux;
					aux=a->hijoDer;
					if ((aux->hijoIzq==nullptr) && (aux->hijoDer==nullptr))
					{
						a=aux;
						delete aux;
						a->hijoDer=nullptr;
					}
					else
					{
						if ((a->hijoDer)->hijoIzq!=nullptr)
						{
							nodo *o;
							nodo *op;
							op=a->hijoDer;
							o=(a->hijoDer)->hijoIzq;
							while(o->hijoIzq!=nullptr)
							{
								op=o;
								o=o->hijoIzq;
							}
							a->valor=o->valor;
							cout<<o<<endl;
							delete o;
							op->hijoIzq=nullptr;
						}
						else
						{
							nodo *temp;
							temp=a->hijoDer;
							a->valor=temp->valor;
							a->hijoDer=temp->hijoDer;
							delete temp;
						}
					}
					cout<<"Valor eliminado"<<endl;
					return true;
				}
	}

/*----------------------Recorrer el árbol en preorden-------------------*/
	void preorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			cout<<a->valor<<" ";
			preorden(a->hijoIzq);
			preorden(a->hijoDer);
		}
	}
/*---------------------Recorrer el árbol en postorden------------------------*/
	void postorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			postorden(a->hijoIzq);
			postorden(a->hijoDer);
			cout<<a->valor<<" ";
		}
	}
/*---------------------Recorrer el árbol en inorden--------------*/
	void inorden(nodo *&a)
	{
		if (a==nullptr)
		{
			return;
		}
		else
		{
			inorden(a->hijoIzq);
			cout<<a->valor<<" ";
			inorden(a->hijoDer);
		}
	}
	
