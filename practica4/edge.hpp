/*!
  \file   edge.hpp
  \brief  Definicion de la clase Edge
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

/*!
\brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace edi
{
	/*!\brief Lados del grafo*/
	class Edge
	{
		private:
			double _data; //!<Peso del lado
			Vertex _first; //!<Primer vertice del lado
			Vertex _second; //!<Segundo vertice del lado

		public:
			/*!
			*************************************************************
				Observadores
			*************************************************************
			*/

			/*!
			*************************************************************
			  \brief getData() devuelve la variable data_ del lado.
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			const double & getData() const
			{
				return _data;
			}

			/*!
			*************************************************************
			  \brief first() devuelve la variable first_ del lado.
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			const Vertex & first() const
			{
				return _first;
			}

			/*!
			*************************************************************
			  \brief second() devuelve la variable second_ del lado
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			const Vertex & second() const
			{
				return _second;
			}

			/*!
			*************************************************************
			  \brief has() Devuelve si el vértice tiene o no lado. (conexo)
			  \param u
				\pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			bool has(const Vertex & u) const
			{
				return u == first() or u == second();
			}

			/*!
			*************************************************************
			  \brief other() devuelve el vértice contrario del lado al que pertenece.
			  \param u
				\pre has(u) = true
			  \post Ninguna
			*************************************************************
			*/
			const Vertex & other(const Vertex & u) const
			{
				assert(has(u));
				if (u == first())
					return second();
				return first();
			}

			/*!
			*************************************************************
			  \brief setData() inserta en data_ el double que le pasamos
				\param data
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
      void setData(const double & data)
			{
				_data = data;
			}



			/*!
			*************************************************************
		  \brief setFirst() que establece como primer vertice del lado al vertex recibido
			\param first
		  \pre Ninguna
		  \post Ninguna
			*************************************************************
			*/
      void setFirst(const Vertex & first)
			{
				_first = first;

			}

			/*!
			*************************************************************
			\brief setFirst() que establece como segundo vertice del lado al vertex recibido
			\param second
			\pre Ninguna
			\post Ninguna
			*************************************************************
			*/
      void setSecond(const Vertex & second)
			{
				_second = second;
			}

			/*!
			*************************************************************
			\brief Sobrecarga del operador == para la clase Edge
			\param e
			\pre Ninguna
			\post Ninguna
			*************************************************************
			*/
			bool operator==(const Edge &e)const
			{
				return (e.first() == first() and e.second() == second());
			}
	};

}

#endif
