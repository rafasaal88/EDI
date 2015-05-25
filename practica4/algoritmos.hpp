  /*!
  \file   algoritmos.hpp
  \author Rafael Salido Álvarez
  \brief  Fichero de cabecera de las funciones de algoritmos para trabajar con el grafo
  \date   27/04/2015
*/

#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <fstream>
#include "vertex.hpp"
#include "graph_matrix.hpp"
#include "edge.hpp"
#include <iostream>

using namespace edi;

/*!
  \brief Esta funcion realiza un recorrido por todo el grafo desde un vertice hasta el ultimo.
  \note Es de tipo recursiva.
  \param g, u, lista
  \pre Ninguna
  \post Ninguna
*/
void recorrido_profundidad(GraphMatrix & g, Vertex u, vector<int> &lista);

/*!
  \brief Esta funcion es para limpiar la variable global lista.
  \pre Ninguna
  \post Ninguna
*/


/*!
  \brief Esta funcion realiza el algoritmo de Floyd.
  \note Vamos a crear dos matrices auxiliares, una para distancias y otra para los intermedios
  \param g, matriz_distancias, matriz_intermedios
  \pre Ninguna
  \post Ninguna
*/
void algoritmo_Floyd(GraphMatrix & g, float ** matriz_distancias, int ** matriz_intermedios);


/*!
  \brief Función para calcular la distancia minima entre dos vertices.
  \param g, matriz_distancias, matriz_intermedios, origen, destino
  \pre Ninguna
  \post Ninguna
*/
void distancia_Minima(GraphMatrix & g, float ** matriz_distancias, int ** matriz_intermedios, Vertex & origen, Vertex & destino);

#endif