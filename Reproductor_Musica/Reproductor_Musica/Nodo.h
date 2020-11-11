#pragma once
#include <string>
using namespace std;

class Nodo
{
private:
	string nombre;
	string album;
	string artista;
	float duracion;
public:
	Nodo* siguiente;
	Nodo(string, string, string, float);
	string* RetornarAtributos();
	string retornarCadena();
	string retornarNombre();
	float retornarDuracion();
};

