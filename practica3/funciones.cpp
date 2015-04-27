#include "funciones.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
using namespace edi;

void crearAsignatura( ListaDoble <Persona> &lista ) 
{

	int numeroPersonas;
	vector<Persona> listaPersona;
	string fich="personas.txt";
	char fichero[20];
	strcpy(fichero,fich.c_str());

		if(not lista.estaVacia())
		{
			lista.borrarLista();			
		}

	cout<<"Introduzca el numero de elemento ";
	cin>>numeroPersonas;

	listaPersona=generarPersonas(fichero, numeroPersonas);
	vector<Persona>::iterator it;

	for (it = listaPersona.begin(); it < listaPersona.end(); it++)
	{
		lista.inserta(*it);
	}
}


void guardarLista(ListaDoble <Persona> const &lista, const char *fichero)
{
	ofstream salidaFichero(fichero);
	if(salidaFichero.is_open())
	{
		Persona people;

		for (int i = 0; i < lista.getNumeroElementos(); i++)
		{
			people=lista.dato(i);
			salidaFichero<<people<<endl;
		}

 	salidaFichero.close();
	}
}


void cargarLista(ListaDoble <Persona>  &lista, const char *fichero)
{
	Persona people;
	ifstream entradaFichero(fichero);
	if(entradaFichero.is_open())
	{

		while (entradaFichero>>people)
		{
			lista.inserta(people) ;
		}
 		
 		entradaFichero.close();
	}
}


void insertarEnArbol(ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol)
{
	Persona people;
	Clave key;

		for (int i = 0; i < lista.getNumeroElementos(); i++)
		{
			people=lista.dato(i);
			key.setDni(people.getDni());
			key.setPosicion(i);
			arbol.insert(key);
		}
}

void guardarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero)
{
	assert (not arbol.isEmpty());
    arbol.goToRoot();

	Clave key;
	ofstream salidaFichero(fichero);
	if(salidaFichero.is_open())
	{
		salidaFichero<<&arbol;

 		salidaFichero.close();
	}
}


void cargarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero)
{
	ifstream entradaFichero(fichero);
	if(entradaFichero.is_open())
	{

		entradaFichero>>&arbol;
		

 		entradaFichero.close();
	}
}

void buscar(int dni, ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol)
{
	Persona people;
	Clave key;
	key.setDni(dni);
	arbol.search(key);
	if (arbol.existsItem())
	{
		key=arbol.item();
		people=lista.dato(key.getPosicion());
		cout<<"Persona encontrada"<<endl;
		cout<<people.getNombre() << "  " <<people.getApellido()<<endl;
	} 
	else
	{
		cout<< "ERROR. dni no encontrado "<<endl;
	}
}

void mostrarAscendentemente(const ListaDoble<Persona> &lista )
{
	Persona people;

	for (int i = 0; i < lista.getNumeroElementos(); i++)
	{
		people=lista.dato(i);
		cout<<people<<endl;
	}

}

