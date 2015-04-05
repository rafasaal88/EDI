#include "listaordenada.hpp"
#include "nodo.hpp"
#include <iostream>
#include <vector>
#include "generarpersona.hpp"
#include "persona.hpp"
#include <string>
#include <cstring>


using namespace std;
using namespace edi;

int main()
{

	int numeroPersonas=0;
	do{
	cout << "Introduzca el numero de personas que desea(entre 0 y 100): ";
	cin >> numeroPersonas;
	}while(numeroPersonas>100);

	string fichero="personas.txt";
	char f1[15];
	strcpy(f1,fichero.c_str());

	vector <Persona> personas;

	personas=generarPersonas(f1,numeroPersonas);



	Lista asignatura;


	cout << personas[0].nombre();
	cout << personas[1].nombre();









	return 0;
}