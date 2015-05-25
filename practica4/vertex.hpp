/*!
  \file   vertex.hpp
  \brief  Definicion de la clase Vertex
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <cassert>
#include <fstream>
	

using namespace std;

/*! 
  \name Espacio de nombres de la asignatura de Estructuras de datos y de la información
*/

namespace edi
{

	/*!\brief Vertices del grafo.*/
	class Vertex
	{
		private:
			string _data; //!<Dato del vertice
			int _label; //!<Label of the vertex

		public:

			/*!
			*************************************************************
			  \brief getData() devuelve la variable data_ del Vértice.
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			const string & getData()const
			{
				return _data;
			}

			/*!
			*************************************************************
				\brief getLabel() devuelve la variable label_ del vértice.
				\pre Ninguna
				\post Ninguna
			*************************************************************
			*/
			const int & getLabel()const
			{
				return _label;
			}

			/*!
			*************************************************************
			  \brief setData() inserta en data_ el string que le pasamos
				\param data
			  \pre Ninguna
			  \post Ninguna
			*************************************************************
			*/
			void setData(const string &data)
			{
				_data = data;
			}

			/*!
			*************************************************************
				\brief setLabel() inserta en label_ el int que le pasamos
				\param label
				\pre Ninguna
				\post Ninguna
			*************************************************************
			*/
			void setLabel(const int &label)
			{
				_label = label;
			}

			/*!
			*************************************************************
				\brief sobrecarga del operador == de vertex.
				\param v
				\pre Ninguna
				\post Ninguna
			*************************************************************
			*/
			bool operator==(const Vertex &v)const
			{
				return (v.getData() == getData());
			}

			/*!
			*************************************************************
				\brief Sobrecarga del loperador !=
				\param v
				\pre Ninguna
				\post Ninguna
			*************************************************************
			*/
			bool operator!=(const Vertex &v)const
			{
				return (v.getData() != getData());
			}
	};


} 

#endif