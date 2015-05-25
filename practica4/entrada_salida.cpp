/*!
  \file   entrada_salida.cpp
  \brief  Fichero de funciones entrada_salida
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#include <fstream>
#include "edge.hpp"
#include "vertex.hpp"
#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include <iostream>

using namespace std;
using namespace edi;

/*!
	\brief Función que carga el grafo
	\param g, fileGraph
	\pre Ninguna
	\post Ninguna
*/

bool cargarGrafo(GraphMatrix * &g, string fileGraph)
{
	ifstream f(fileGraph.c_str()); //Se define el stream de lectura y se abre el fichero.
	if (not f)
		return false;

  //Se definen variables auxiliares para cargar el grafo.
  unsigned int vertexes;
  int type;
	bool isDirected;
	string dataVertex;
	string dataEdgeFirst, dataEdgeSecond;
	Vertex first, second;
	double weight;

  f >> vertexes; //Se lee el numero de nodos.
  f >> type; //Se lee el tipo.

  if (type == 0)
		isDirected = false;
	else
		isDirected = true;

	//std::cout << "cargados tipo y numero de nodos\n";

  g = new GraphMatrix (vertexes, isDirected); //Se reserva espacio para el grafo y se invoca al constructor.

	//Lectura de los data de los nodos
	for(unsigned int i = 1; i <= vertexes; i++)
	{
		f >> dataVertex;
		g->addVertex(dataVertex);

	}

//	std::cout << "Cargados nodos\n";
	//Lectura de los lados.

	//Inicializamos todos los lados a infinito y después se sobreescriben

	while(f >> dataEdgeFirst >> dataEdgeSecond >> weight )
	{
		//Creamos los nodos que forman parte del lado
		//std::cout << "Cargo Lado\n";
		//Para localizar el indice del nodo
		g->searchVertex(dataEdgeFirst);
		first.setLabel((g->currVertex()).getLabel());

		first.setData(dataEdgeFirst);

		//Para localizar el indice del nodo
		g->searchVertex(dataEdgeSecond);
		second.setLabel((g->currVertex()).getLabel());

		second.setData(dataEdgeSecond);

		//std::cout << "Buscados nodos del lado \n";

		//Añade el lado(first, second) con peso weight;
		g->addEdge(weight, first, second);

		//std::cout << "Lado añadido \n";
	}
	f.close();

	//std::cout << "Cargados lados\n";

	return true;
}

/*!
	\brief Función para mostrar el grafo
	\param g
	\pre Ninguna
	\post Ninguna
*/
void mostrarGrafo(GraphMatrix & g)
{
	g.beginVertex();
	cout << "Nodos del grafo\n";
	cout << "===============\n";

	Vertex v;

	do
	{
		v = g.currVertex();
		cout << v.getData() << endl;
		g.nextVertex();
	}while(not g.afterEndVertex());

	//Lados del grafo
	cout << "\nLados del grafo\n";
	cout << "===============\n";
	cout << " Lados = " << g.numEdges() << endl;

	Vertex aux;
	g.beginVertex();
	while(not g.afterEndVertex())
	{
		aux = g.currVertex();
		g.beginEdge(aux); //Se posiciona en el primer lado que tiene a aux como nodo origen
		while (not g.afterEndEdge())
		{
			cout << g.currEdge().first().getData() << ", " << g.currEdge().second().getData() << ", " << g.currEdge().getData() << endl;
			g.nextEdge();
		}
		g.nextVertex();
	}
}
