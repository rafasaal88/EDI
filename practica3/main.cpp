#include "funciones.hpp"

using namespace std;  
using namespace edi;  


int main ()
{
	int opcion;
	ListaDoble<Persona> asignatura;
	LinkedOrderedBinaryTree<Clave> arbol;
	string nombreFichero,nombre;
	int dni,pos;;
	do{
	
			do {
			cout<<"Menú"<<endl;
			cout<<"1: crear asignatura"<<endl;
			cout<<"2: Guardar asignatura."<<endl;
			cout<<"3: cargar asignatura."<<endl;
			cout<<"4: Buscar una persona en la asignatura actual."<<endl;
			cout<<"5: Mostrar alumnos."<<endl;
			cout<<"0: Salir."<<endl;

			cout<<"Introduzca una opcion: "<<endl;
			cin>> opcion;
	}

	while((opcion<0) || (opcion>5));



		switch(opcion)
		{
			case 1:
					crearAsignatura(asignatura);
					insertarEnArbol(asignatura, arbol);
				break;

			case 2:
					cout<<"Introduce el nombre del fichero a guardar"<<endl;
					cin>>nombreFichero;

					guardarLista( asignatura, nombreFichero.c_str());
					pos=nombreFichero.find_first_of('.',0);
					
					if(pos>0)
					{
						nombre=nombreFichero.substr(0,pos);
						nombreFichero=nombre + ".idx";
					}

					else
					{
						nombreFichero=nombreFichero+".idx";
					}

					guardarArbol(arbol, nombreFichero.c_str());

				break;
			case 3:

					while(arbol.isEmpty()==0)
					{
						arbol.removeItem();		
					}


					cout<<"Introduce el nombre del fichero a cargar"<<endl;
					cin>>nombreFichero;
					cargarLista(asignatura, nombreFichero.c_str());
					pos=nombreFichero.find_first_of('.',0);
					
					if(pos>0)
					{
						nombre=nombreFichero.substr(0,pos);
						nombreFichero=nombre + ".idx";
					}

					else
					{
						nombreFichero=nombreFichero+".idx";
					}


					cargarArbol(arbol,nombreFichero.c_str());

				break;
			case 4:

				cout<<"Introduce el dni de la persona a buscar"<<endl;
				cin>>dni;

				buscar(dni, asignatura, arbol);

					
				break;
			case 5:
				mostrarAscendentemente(asignatura);

					
				break;
		}

	}
	while(opcion!=0);


}
