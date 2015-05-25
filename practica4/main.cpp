/*!
  \file   main.cpp
  \brief  Programa principal
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#include "cabecera.hpp"


/*!
	\brief Programa principal
	\pre Ninguna
	\post Ninguna
*/
int main ()
{
	GraphMatrix *g = 0;
	bool ficherocargado = false;
	string archivografo;
	int opcion;


	do {
		do{
			cout << "1. Cargar un grafo desde un fichero." << endl; 
			cout << "2. Mostrar el grafo por pantalla." << endl; 
			cout << "3. Realizar el recorrido en profundidad a partir de un nodo." << endl; 
			cout << "4. Aplicar el algoritmo de Floyd." << endl; 
			cout << "5. Terminar." << endl;
			cout << "Opcion: ";
			cin>> opcion;
		}
			while((opcion<1) || (opcion>5));

		switch (opcion) {

			case 1:
				if(ficherocargado==false)
				{
				ficherocargado=cargar(*&g, archivografo);
				}
				else
				{
				*g = 0;
				ficherocargado=cargar(*&g, archivografo);
				}

			break;

			case 2:
				if(ficherocargado==true)
					mostrarGrafo(*g);
				else
					cout << "No hay ningun grafo cargado"<<endl;
			break;

			case 3:
				if(ficherocargado==true)
				{
					profundidad(*g);
				}
				else
				{
					cout << "No hay ningun grafo cargado"<<endl;
				}
			break;

			case 4:
				if(ficherocargado==true)
				{
					floyd(*&g);
				}
				else
				{
					cout << "No hay ningun grafo cargado"<<endl;
				}
			break;

			case 5:
				if(ficherocargado==true)
				{
				*g = 0;
				exit(1);
				}
					
				exit(1);
				break;

			default:
				cout << "Introduzca una opcion valida...." << endl;
		}
	}while(opcion != 5);

  return 0;
}