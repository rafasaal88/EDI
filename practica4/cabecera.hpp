/*!
  \file   cabecera.hpp
  \brief  Fichero cabecera del programa principal
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef CABECERA_HPP
#define CABECERA_HPP

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include "algoritmos.hpp"


using namespace std;
using namespace edi;


/*!
	\brief Hace una busqueda profunda dentro del grafo
	\param g
	\pre Ninguna
	\post Ninguna
*/
void profundidad(GraphMatrix & g);

/*!
	\brief Carga desde el fichero los datos al grafo
	\param g, fichero
	\pre Ninguna
	\post Ninguna
*/
bool cargar(GraphMatrix * &g, string &fichero);

/*!
	\brief Funcion que recoge los datos y los envia para que se ejecute el algoritmo de Floyd
	\param g
	\pre Ninguna
	\post Ninguna
*/
void floyd(GraphMatrix * &g);

/*!
	\brief Funcion para reservar memoria de una matriz de floats
	\param nFil, nCol
	\pre Ninguna
	\post Ninguna
*/
float ** reservarMemoriaMatrizFloat( int nFil, int nCol);

/*!
	\brief Funcion para reservar memoria de una matriz de enteros
	\param nFil, nCol
	\pre Ninguna
	\post Ninguna
*/

int ** reservarMemoriaMatrizInt( int nFil, int nCol);

/*!
	\brief Funcion para liberar memoria de una matriz de floats
	\param nCol, matriz
	\pre Ninguna
	\post Ninguna
*/

void liberarMemoriaMatrizInt(int nCol, int **matriz);

/*!
	\brief Funcion para liberar memoria de una matriz de enteros
	\param nCol,matriz
	\pre Ninguna
	\post Ninguna
*/

void liberarMemoriaMatrizFloat(int nCol, float **matriz);

#endif
