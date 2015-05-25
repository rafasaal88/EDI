/*!
  \file   entrada_salida.hpp
  \brief  Fichero de cabera de las funciones del fichero de funciones entrada_salida
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef ENTRADA_SALIDA_HPP
#define ENTRADA_SALIDA_HPP
#include <fstream>
#include "vertex.hpp"
#include "graph_matrix.hpp"
#include "edge.hpp"
#include <iostream>

using namespace std;
using namespace edi;

/*!
	\brief Función que carga el grafo
	\param g, fileGraph
	\pre Ninguna
	\post Ninguna
*/
bool cargarGrafo(GraphMatrix * &g, string fileGraph);

/*!
	\brief Función para mostrar el grafo
	\param g
	\pre Ninguna
	\post Ninguna
*/
void mostrarGrafo(GraphMatrix & g);



#endif
