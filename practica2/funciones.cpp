#include "generarpersona.hpp"
#include "lista.hpp"
#include <cstring>
#include <string>

void crearAsignatura(Listadoble <Persona> &lista) 
{
	int numeroPersonas;
	vector<Persona> listaPersona;

	do{
	cout << "\nIntroduzca el numero de personas que desea(entre 0 y 100): ";
	cin >> numeroPersonas;
	}while(numeroPersonas>100);

	string fichero="personas.txt";
	char f1[15];
	strcpy(f1,fichero.c_str());


	listaPersona=generarPersonas(f1, numeroPersonas);
	vector<Persona>::iterator it;

	for (it = listaPersona.begin(); it < listaPersona.end(); it++)
	{
		lista.inserta(*it);
	}


}

void mostrarAscendentemente(const Listadoble<Persona> &lista)
{
	Persona people;

	for (int i = 0; i < lista.getNumeroElementos(); i++)
	{
		people=lista.dato(i);
		cout<<people<<endl;
	}

}

void mostrarDescendentemente(const Listadoble<Persona> &lista)
{
	Persona people;

	for (int i = lista.getNumeroElementos()-1; i >=0 ; i--)
	{
		people=lista.dato(i);
		cout<<people<<endl;
	}
}

void mostrarEntreAscendentemente(const Listadoble<Persona> &lista )
{
	Persona people;
	Persona people1;
	Persona people2;
	Persona auxiliar;
	int posicion1;
	int posicion2;

	cout<<"Introduce la 1 persona: ";
	cin>>people1;
	
	cout<<"Introduce la 2 persona: ";
	cin>>people2;

	if(people1 == people2)
	{
		cout<<"Ha introducido dos personas iguales"<<endl;
		cout<<"Por favor, Introduzca dos personas distintas"<<endl;
		mostrarEntreAscendentemente(lista);
	}
	else
		if(people1 > people2)
		{
			auxiliar=people2;
			people2=people1;
			people1=auxiliar;
		}

	posicion1=lista.buscaDato(people1,0);
	posicion2=lista.buscaDato(people2,posicion1);


	for (int i = posicion1; i <= posicion2 ; i++)
	{
		people=lista.dato(i);
		cout<<people<<endl;
	}

}

void mostrarEntreDescendentemente(const Listadoble<Persona> &lista )
{
	Persona people;
	Persona people1;
	Persona people2;
	Persona auxiliar;
	int posicion1;
	int posicion2;

	cout<<"Introduce la 1 persona: ";
	cin>>people1;

	cout<<"Introduce la 2 persona: ";
	cin>>people2;

	if(people1==people2)
	{
		cout<<"Ha introducido dos personas iguales"<<endl;
		cout<<"Por favor, Introduzca dos personas distintas"<<endl;
		mostrarEntreAscendentemente(lista);
	}
	else
		if(people1 > people2)
		{
			auxiliar=people2;
			people2=people1;
			people1=auxiliar;
		}

	posicion1=lista.buscaDato(people1,0);
	posicion2=lista.buscaDato(people2,posicion1);


	for (int i = posicion2; i >= posicion1 ; i--)
	{
		people=lista.dato(i);
		cout<<people<<endl;
	}

}

void modificar(Listadoble<Persona> &lista)
{
	Persona people;
	Persona auxiliar;
	int posicion;


	cout<<"Introduce la persona desea modificar ";
	cin >> people;


	cout<<"Introduzca los nuevos datos "<<endl;
	cin >> auxiliar;

	posicion=lista.buscaDato(people,0);
	lista.borrarPosicion(posicion);
	lista.inserta(auxiliar);

}


