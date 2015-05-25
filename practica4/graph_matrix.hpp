/*!
  \file   graph_matrix.hpp
  \brief  Definicion de la clase GraphMatrix
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
#include <limits>

#include "edge.hpp"
#include "vertex.hpp"
#include "edge.hpp"

using namespace std;
using namespace edi;

/*!
\brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace edi
{
	/*!\brief Grafo.*/
	class GraphMatrix
	{
		private:
			
			vector<Vertex> vertexes_;//!<Vector de vertices
			float** matrix_;//!<Matriz de adyacencia
			bool directed_;//!<Booleano para controlar si es dirigido o no
			Vertex* cursor_vertexes_;//!<Cursos de vertices
			Edge* cursor_edges_;//!<Cursor de lados
			int numVertexes_;//!<Numero de vertices
			int numEdges_;//!<Numero de lados
			int capacity_;//!<Capacidad del grafo

		public:
			/*!
				\brief Constructor que crea una GraphMatrix.
				\attention Se inicia a 0 y dirigido.
				\note Se inicia la matriz de adyacencia.
				\param capacity, isDirected
				\pre Ninguna
				\post Ninguna
			*/
			GraphMatrix(const int & capacity = 0, const bool & isDirected = true) //Constructor por defecto.
			{
				capacity_ = capacity; //Inicializamos la capacidad a 0 por defecto en caso de no recibir nada.
				directed_ = isDirected; //Se inicializa por defecto como dirigido.
				
			   	matrix_=new float*[capacity]; //reservamos filas
			 	for (int i = 0; i < capacity; i++)
				{
			 	matrix_[i]=new float[capacity]; //Reservamos las columnas para cada fila
				}



				for (int i = 0; i < capacity; i++)
				{
					for (int j = 0; j < capacity; j++)
					{
						if (i==j)
							matrix_[i][j]=0; //Diagonal principal a 0
						else
							matrix_[i][j]=numeric_limits<float>::infinity(); //Resto a infinito
					}
				}
				cursor_vertexes_ = NULL; //El cursor de vertices apunta a NULL cuando creamos el grafo
				cursor_edges_ = NULL;//El cursor de lados al crear un grafo apunta a NULL
				numVertexes_ = 0; //Inicializamos el numero de vertices por defecto al no haber añadido ningún vertice
				numEdges_ = 0; //Inicializamos el numero de lados a 0 al no haber añadido ningun lado.
			}

			/*!
				\brief Destructor
				\pre Ninguna
				\post Ninguna
			*/
				~GraphMatrix()
			{
					// Elimino cada vector de la matriz
				for ( int i = 0 ; i < capacity() ; i++ )
			    {
			   		delete matrix_[i];  // Borramos los objetos creados con matrix_[i]=new int[capacity];;
			    }
	  				delete matrix_; // Borramos el objeto creado con _m=new int*[nFil];

			}
			/*!
				\brief Devuelve el número de vértices.
				\pre Ninguna
				\post Ninguna
			*/


			const int &numVertexes()const{
				return numVertexes_;
			}

			/*!
				\brief Devuelve el número de lados.
				\pre Ninguna
				\post Ninguna
			*/
			const int &numEdges()const{
				return numEdges_;
			}

			/*!
				\brief Devuelve la capacidad.
				\pre Ninguna
				\post Ninguna
			*/
			const int &capacity()const{
				return capacity_;
			}

			/*!
				\brief Comprobamos que el grafo este vacio.
				\note No hay parámetros.
				\pre Ninguna
				\post Ninguna
			*/
			bool isEmpty() const{
				if (capacity_ == 0)
					return true;
				else
					return false;
			}

			/*!
				\brief Comprueba si un grafo es dirigido o no.
				\note Devuelve true si el grafo es dirigido y false si no lo es (bool).
				\pre Ninguna
				\post Ninguna
			*/
			const bool & isDirected() const{
					return directed_;
			}

			/*!
				\brief Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
				\note Usaremos los dos vértices indicicados.
				\param u, v
				\pre Ninguna
				\post Ninguna
			*/
			const float adjacent(const Vertex & u, const Vertex & v) const {
				return matrix_[u.getLabel()][v.getLabel()];
			}

			/*!
				\brief Comprueba si el cursor de vértices está en posición válida
				\note Devuelve true si está correcto y false si apunta a NULL
				\pre Ninguna
				\post Ninguna
			*/
			bool hasCurrVertex() const{
				if(cursor_vertexes_ == NULL)
					return false;
				return true;
			}

			/*!
				\brief Devuelve el vértice referenciado por el cursor de vértices.
				\pre hasCurrVertex() is true.
				\post Ninguna
			*/

			const Vertex & currVertex() const{
				return *cursor_vertexes_;
			}

			/*!
				\brief Comprueba si el cursor de lados está en posición válida.
				\note Devuelve rue si está correcto y false si apunta a NULL.
				\pre Ninguna
				\post Ninguna
			*/
			bool hasCurrEdge() const{
				if(cursor_edges_ == NULL)
					return false;
				return true;
			}

			/*!
				\brief Devuelve el lado referenciado por el cursor de lados.
				\pre hasCurrEdge() is true
				\post Ninguna
			*/

			const Edge currEdge(){
				return *cursor_edges_;
			}

			/*!
				\brief Crea un grafo dirigido
				\note convierte la variable directed_ privada a true.
				\pre Ninguna
				\post Ninguna
			*/
			void makeDirected(){
				directed_ = true;
			}

			/*!
				\brief Crea un grafo no dirigido
				\note convierte la variable directed_ privada a false.
				\pre Ninguna
				\post Ninguna
			*/

			void makeUndirected(){
				directed_ = false;
			}

			/*!
				\brief Añade un vertice al grafo a partir del data
				\note Aumentamos el numero de vertices en 1.
				\param data tipo string que es el nombre de un vértice.
				\pre numVertexes() < capacity()
				\post Ninguna
			*/

			void addVertex(const string & data){
				Vertex v; 								//Vértice auxiliar
				v.setData(data);					//Establecemos data como data del vértice
				v.setLabel(numVertexes_);		//Si es el primer elemento, numEdges es 0 y lo vamos aumentando.
				vertexes_.push_back(v);		//Introducimos por la cola en el vector de vertices.
				numVertexes_++;						//Aumentando como he dicho arriba
			}

			/*!
				\brief Añade un lado al grafo a partir de sus dos vértices y su peso.
				\note Esto se reflejará sólo en la matriz de adyacencia
				\param data, u, v
				\pre u y v pertenecen al grafo.
				\post Ninguna
			*/
			void addEdge(const double & data, const Vertex & u, const Vertex & v){
				int v1 = u.getLabel();
				int v2 = v.getLabel();
				if(!isDirected()){
					matrix_[v1][v2] = data;
					matrix_[v2][v1] = data;
				}
				else
					matrix_[v1][v2] = data;

				numEdges_++;
			}

			/*!
				\brief Busca un vertice a partir de su data, colocando el cursor en dicho vértice
				\param data tipo string.
				\pre Ninguna
				\post Ninguna
			*/
			void searchVertex(const string &data){
				bool encontrado = false;
				for (int i = 0; i < numVertexes_; i++) {
					if (vertexes_[i].getData() == data) {
						cursor_vertexes_ = &vertexes_[i];
					//	cout << "Vertice:" << vertexes_[i].getData() << endl;
						encontrado = true;
					}
				}
					if(!encontrado){
						cursor_vertexes_ = NULL;
					}
				}

			/*!
				\brief Lleva el cursor a un vertice a partir de dicho vertice
				\attention Inicia con capacidad a 0 y dirigido true en caso de no recibir nada.
				\param u
				\pre u pertenece al grafo
				\post Ninguna
			*/
			void goTo(const Vertex & u){
				/*compruebo con lo vertices del vector si coincide lo igualo cursor_vertexes = &vertexes_[i]; */
				for (int i = 0; i < numVertexes_; i++) {
					if ((vertexes_[i].getData() == u.getData()) && (vertexes_[i].getLabel() == u.getLabel()) ) {
						//cout << "Coincide" << endl;
						cursor_vertexes_ = &vertexes_[i];
					}
				}
			}

			/*!
				\brief Lleva el cursor a un vértice a partir de la posicion de dicho vertice
				\param idx que es un int y buscaremos el vértice que tenga la misma etiqueta.
				\pre 0 <= idx < numVertexes()
				\post Ninguna
			*/
			void goTo(const int &idx){
						cursor_vertexes_ = &vertexes_[idx];
					}


		  	/*!
		  		\brief Lleva el cursor a un lado a partir de sus vertices
		  		\note Usaremos un lado auxiliar
		  		\param u, v
		  		
		  		\pre u y v pertenecen al grafo
		  		\post Ninguna
		  	*/
			void searchEdge(const Vertex & u, const Vertex & v){
				/*creo lado auxiliar, a ese le meto el peso de los vertices en la matriz,
				 edge.firts(u) y el segundo y luego ya cursor = edge */
				Edge *aux = new Edge;
				aux->setData(adjacent(u, v)); //Mejor que la de abajo, aqui usamos una función.
				//aux->setData(matrix_[u.getLabel()][v.getLabel()]); //Son dos opciones.
				aux->setFirst(u);
				aux->setSecond(v);
				cursor_edges_ = aux;
			}

			/*!
				\brief Lleva el cursor al primer vertice
				\pre Ninguna
				\post Ninguna
			*/
			void beginVertex(){
				cursor_vertexes_ = &vertexes_[0];
			}

			/*!
				\brief Avanza el cursor al siguiente vertice.
				\pre Ninguna
				\post Ninguna
			*/

			void nextVertex(){
				cursor_vertexes_++; //Al ser posición de memoria, avanzo con ++
			}

			/*!
				\brief Comprueba si el cursor ha sobrepasado su última posicion válida
				\note Si el cursor es la ultima posicion del vértice.
				\pre Ninguna
				\post Ninguna
			*/
			bool afterEndVertex() const{
				if (cursor_vertexes_ == &vertexes_[numVertexes_])
					return true;

				return false;
			}

			/*!
				\brief Lleva el cursor al primer lado que sale del vertice u
				\note Tenemos que ir buscando el primer lado que se forma.
				\param u
				\pre Ninguna
				\post Ninguna
			*/
			void beginEdge(const Vertex & u){
				Edge *aux = new Edge; //Variable Edge

				float infinito = numeric_limits<float>::infinity(); //Infinito, necesitamos la libreria <limits>.

				int pos = u.getLabel(); //Variable int en la que introduciremos la etiqueta del vértice.
				bool encontrado = false; //Variable booleana para controlar si hemos encontrado el lado o no.
				for (int i = 0; i < capacity_ || encontrado == false; i++) {
					if ((matrix_[pos][i] > 0) && (matrix_[pos][i] < infinito)){
						//el if es así porque si es 0 o infinito no es ningun lado.
						aux->setData(matrix_[pos][i]); //Al lado aux le establecemos Data
						aux->setFirst(u); //Al lado aux le establecemos el primer vertice.
						aux->setSecond(vertexes_[i]); //Al lado aux le establecemos el segundo vertice.
						encontrado = true; //Así no volvemos a entrar en el bucle. :)
					}
				}
				if (encontrado){
					cursor_edges_ = aux; //Establecemos el cursor de lados al lado aux.
				}
			}


			/*!
				\brief Avanza el cursor al siguiente lado que sale de currEdge().first()
				\note Si no hay lado siguiente, igualamos a NULL el cursor de lados.
				\pre Ninguna
				\post Ninguna
			*/
			void nextEdge(){
				Edge *aux = new Edge; //Variable Edge
				float infinito = numeric_limits<float>::infinity();
				bool encontrado = false; //Variable booleana para controlar si hemos encontrado el lado o no.

				for (int i = cursor_edges_->second().getLabel()+1; i < capacity_ || encontrado == true; i++) {
					if ((matrix_[cursor_edges_->first().getLabel()][i] != 0) && (matrix_[cursor_edges_->first().getLabel()][i] != infinito))
					{
						aux->setData(matrix_[cursor_edges_->first().getLabel()][i]); //Al lado aux le establecemos Data
						aux->setFirst(cursor_edges_->first()); //Al lado aux le establecemos el primer vertice
						aux->setSecond(vertexes_[i]); //Al lado aux le establecemos el segundo vertice
						cursor_edges_ = aux; //establecemos el cursor en el lado aux.
						encontrado = true;
					}
				}

				if(!encontrado){
					cursor_edges_ = NULL; //Si no hay siguiente lado, ponemos a null el cursor.
				}
			}


			/*!
				\brief Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
				\note Devolvemos true si el cursor apunta a null.
				\pre Ninguna
				\post Ninguna
			*/
			bool afterEndEdge(){
				if (cursor_edges_ == NULL)
					return true;
				return false;
			}

	};
}

	#endif
