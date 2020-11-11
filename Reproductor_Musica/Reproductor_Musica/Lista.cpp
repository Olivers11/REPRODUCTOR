#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
	this->frente = NULL;
	this->final = NULL;
	this->tamanio = 0;
}

bool Lista::Vacia()
{
	return(this->frente == NULL and this->final == NULL) ? true : false;
}

void Lista::InsertarVacia(string n, string a, string album, float d)
{
	Nodo* nuevo = new Nodo(n, a, album, d);
	this->frente = nuevo;
	this->final = nuevo;
	this->tamanio++;
}

void Lista::InsertarFinal(string n, string a, string album, float d)
{
	if (this->Vacia())
	{
		this->InsertarVacia(n, a, album, d);
	}
	else
	{
		Nodo* nuevo = new Nodo(n, a, album, d);
		this->final->siguiente = nuevo;
		this->final = nuevo;
		this->tamanio++;
	}
}

void Lista::InsertarFrente(string n, string a, string album, float d)
{
	if (this->Vacia())
	{
		this->InsertarVacia(n, a, album, d);
	}
	else
	{
		Nodo* nuevo = new Nodo(n, a, album, d);
		nuevo->siguiente = this->frente;
		this->frente = nuevo;
		this->tamanio++;
	}
	
}


void Lista::EliminarFinal()
{
	Nodo* aux = this->final;
	delete aux;
}






Nodo* Lista::ObtenerValorPosicion(int pos)
{
	int cont = 0;
	Nodo* aux = this->frente;
	while (aux != NULL)
	{
		if (cont == pos)
		{
			break;
		}
		else
		{
			aux = aux->siguiente;
			cont++;
		}
	}
	return aux;
}

void Lista::Mostrar()
{
	Nodo* aux = this->frente;
	int contador = 0;
	while (aux != NULL)
	{
		cout << "[" << contador << "] " << aux->retornarCadena() << aux->retornarDuracion() << endl;
		aux = aux->siguiente;
		contador++;
	}
}


void Lista::Eliminar(int ref)
{
	if (ref == this->tamanio)
	{
		this->EliminarFinal();
	}
	else if(ref != 0 and ref != this->tamanio)
	{
		Nodo* actual = this->ObtenerValorPosicion(ref);
		Nodo* anterior = this->ObtenerValorPosicion(ref - 1);
		anterior = actual->siguiente;
		delete actual;
	}
}

string Lista::retornarCancion(int pos)
{
	if (this->Vacia())
	{
		return "No hay ninguna cancion todavia";
	}
	else
	{
		if (this->ObtenerValorPosicion(pos) != NULL)
		{
			Nodo* aux = this->ObtenerValorPosicion(pos);
			return aux->retornarNombre();
		}
	}

}