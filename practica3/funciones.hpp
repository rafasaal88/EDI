/*!
  \file funciones.hpp
  \brief  definicion de funciones
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/


#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "persona.hpp"
#include "generarpersona.hpp"
#include "clave.hpp"
#include "listaDoble.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "nodoDoble.hpp"
#include "funciones.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"



/*! 
	\fn     void crearAsignatura(ListaDoble <Persona> &lista);
	\brief  Crea la lista de asignatura
	\param	lista que se va a crear a partir del fichero personas.txt
*/
void crearAsignatura(ListaDoble <Persona> &lista);

/*! 
	\fn     void guardarLista(ListaDoble <Persona> const &lista, const char *fichero);
	\brief  Guarga la lista de asignatura en un fichero
	\param	lista asignatura
	\param	fichero que se crea con la lista asignatura
*/
void guardarLista(ListaDoble <Persona> const &lista, const char *fichero);

/*! 
	\fn     void cargarLista(ListaDoble <Persona>  &lista, const char *fichero);
	\brief  Guarga el fichero en la lista
	\param	lista asignatura a rellenar con el fichero
	\param	fichero creado anteriormente
*/
void cargarLista(ListaDoble <Persona>  &lista, const char *fichero);

/*! 
	\fn     void insertarEnArbol(ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol);
	\brief  Inserta la lista en el arbol
	\param	lista asignatura 
	\param	arbol que se rellena con la lista asignatura
*/
void insertarEnArbol(ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol);

/*! 
	\fn     void guardarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero);
	\brief  guarda el arbol en el fichero
	\param	arbol creado a partir de la lista asignatura
	\param	fichero en el que se va a insertar el arbol 

*/
void guardarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero);



/*! 
	\fn     void cargarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero);
	\brief  carga el fichero en el arbol
	\param	arbol creado a partir de la lista asignatura
	\param	fichero en el que se va a insertar el arbol 

*/
void cargarArbol(LinkedOrderedBinaryTree <Clave> &arbol, const char *fichero);

/*! 
	\fn     void buscar(int dni, ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol);
	\brief  busca una persona a traves de su dni
	\param	arbol creado a partir de la lista asignatura
	\param	lista creada a partir de personas.txt 

*/
void buscar(int dni, ListaDoble <Persona> const &lista, LinkedOrderedBinaryTree <Clave> &arbol);


/*! 
	\fn     void mostrarAscendentemente(const ListaDoble<Persona> &lista );
	\brief  muestra en orden ascedente los alumnos
*/

void mostrarAscendentemente(const ListaDoble<Persona> &lista );

#endif