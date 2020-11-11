#include "Nodo.h"


Nodo::Nodo(string n, string a, string album, float d)
{
	this->nombre = n;
	this->artista = a;
	this->album = album;
	this->duracion = d;
	this->siguiente = NULL;
}


string* Nodo::RetornarAtributos()
{
	static string arr[] = { this->nombre, this->artista, this->album};
	return arr;
}


float Nodo::retornarDuracion()
{
	return this->duracion;
}

string Nodo::retornarCadena()
{
	return this->nombre + " - " + this->artista + " - " + this->album + " ";
}


string Nodo::retornarNombre()
{
	return this->nombre;
}