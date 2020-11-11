#pragma once
#include "Nodo.h"
class Lista
{
private:
	
	Nodo* frente;
	Nodo* final;
public:
	int tamanio;
	Lista();
	bool Vacia();
	void InsertarFinal(string, string, string, float);
	void InsertarFrente(string, string, string, float);
	void EliminarFinal();
	void Eliminar(int ref);
	string retornarCancion(int pos);
	void InsertarVacia(string, string, string, float);
	Nodo* ObtenerValorPosicion(int);
	void Mostrar();
};

