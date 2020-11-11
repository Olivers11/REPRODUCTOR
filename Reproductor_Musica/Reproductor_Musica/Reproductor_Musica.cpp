// Reproductor_Musica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Lista.h"
#include "Nodo.h"
using namespace std;

int main()
{
	Lista a = Lista();
	Lista h = Lista();
	int opcion;
	int contador = 0;
	do
	{
		system("cls");
		cout << "Reproduciendo: | " << a.retornarCancion(contador) << " |" << endl;
		cout << "(2) siguiente cancion \n";
		cout << "(3) anterior cancion \n";
		cout << "(4) agregar cancion \n";
		cout << "(5) reproducir cancion \n";
		cout << "(6) historial \n";
		cout << "(8) Ver canciones de lista \n";
		cout << "(7) salir \n";
		cout << "opcion: ";
		cin >> opcion;

		if (opcion == 2)
		{
			Nodo* aux = a.ObtenerValorPosicion(contador+1);
			if (aux != NULL)
			{
				contador++;
			}
			else
			{
				system("cls");
				cout << "TOPE" << endl;
				system("pause");
			}
		}
		else if (opcion == 3)
		{
			Nodo* aux = a.ObtenerValorPosicion(contador - 1);
			if (aux != NULL)
			{
				contador--;
			}
			else
			{
				system("cls");
				cout << "TOPE" << endl;
				system("pause");
			}
		}
		else if (opcion == 4)
		{
			string n, al, ar;
			float duracion;
			system("cls");
			cout << "Nmbre de cancion: ";
			cin >> n;
			cout << "Artista: ";
			cin >> ar;
			cout << "Album: ";
			cin >> al;
			cout << "Duracion: ";
			cin >> duracion;
			a.InsertarFinal(n, ar, al, duracion);
		}
		else if (opcion == 5)
		{
			system("cls");
			a.Mostrar();
			int n;
			cout << "Numero de cancion: ";
			cin >> n;
			Nodo* aux = a.ObtenerValorPosicion(n);
			if (aux != NULL)
			{
				float d = aux->retornarDuracion();
				string* p = aux->RetornarAtributos();
				a.InsertarFrente(*(p + 0), *(p + 1), *(p + 2), d);//insertamos antes de eliminar el nodo
				h.InsertarFrente(*(p + 0), *(p + 1), *(p + 2), d);
				a.Eliminar(n);
				contador = 0;
			}
		}
		else if (opcion == 6)
		{
			system("cls");
			cout << "| HISTORIAL |" << endl;
			h.Mostrar();
		}
		else if (opcion == 8)
		{
			system("cls");
			cout << "| canciones | \n";
			a.Mostrar();
			system("pause");
		}

	} while (opcion != 6);
}

