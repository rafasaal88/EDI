#include "funciones.hpp"

using namespace std;  
using namespace edi;  


int main ()
{
	int opcion;
	Listadoble<Persona> asignatura;
	do{
		
	do {
		cout << "1. Crear asignatura\n";
		cout << "2. Mostrar Ascendentemente\n";
		cout << "3. Mostrar Descendentemente\n";
		cout << "4. Mostrar entre Ascendentemente\n";
		cout << "5. Mostrar entre Descendentemente\n";
		cout << "0. Salir\n";
		cout << "Introduzca una opción para el menú: ";
		cin>> opcion;

	}

	while((opcion<0) || (opcion>6));





		switch(opcion)
		{
			case 1:
					crearAsignatura(asignatura);
				break;

			case 2:
					mostrarAscendentemente(asignatura);
				break;
			case 3:
					mostrarDescendentemente(asignatura);
				break;
			case 4:
					mostrarEntreAscendentemente(asignatura);
				break;
			case 5:
					mostrarEntreDescendentemente(asignatura);
				break;
			case 6:
					modificar(asignatura);
				break;
		}

	}
	while(opcion!=0);


}
