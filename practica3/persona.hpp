/*!
  \file   persona.hpp
  \brief  Definición de la clase Persona 
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>

using namespace std;

/*! 
  \name Espacio de nombres de la asignatura de Estructuras de datos y de la información
*/
namespace edi
{
	//!  Definición de la plantilla de la clase Persona
	class Persona
	{
		private:
			string _nombre;    //!< Nombre de la Persona
			string _apellido;  //!< Apellido de la Persona
			int _dni;		//!< DNI de la Persona
			char _borrado;		//!< Atributo lógico que indica si la Persona está borrada
		public:
			//! \name CONSTRUCTORES
			/*! 
				\fn        Persona();
				\brief     Constructor por defecto de la clase Persona
				\attention Función sobrecargada	
				\sa        Persona(const string  &n, const  string &a, const int &d); Persona(const Persona &p);
			*/
			Persona();
			
			/*! 
				\fn    		Persona(const string  &n, const  string &a, const int &d);
				\brief     Constructor parametrizado de la clase Persona
				\attention Función sobrecargada
				\param     n Nombre de la Persona
				\param     a Apellidos de la Persona
				\param     d DNI de la Persona
				\sa        Persona(); Persona(const Persona &p);
			*/
			Persona(const string  &n, const  string &a, const int &d);
			
			/*! 
				\fn 	    Persona(const Persona &p);
				\brief      Constructor de copia de la clase Persona
				\attention  Función sobrecargada	
				\param      p Persona de la que se van copiar los valores de los atributos.
				\sa         Persona(); Persona(const string  &n, const  string &a, const int &d); 
			*/
			Persona(const Persona &p);
			
			//! \name OPERADORES

			/*! 
				\fn     Persona & operator=(const Persona &p);
				\brief  Sobrecarga del operador de asignación
				\param  p Persona que se va a copiar en la Persona actual
				\post   Los valores de la Persona creada deben ser iguales a los de la Persona p
				\return Referencia a la Persona actual
				\sa     operator==, operator<, operator<=, operator>, operator>=
			*/
			Persona & operator=(const Persona &p);
			
			/*! 
				\fn     bool operator==(const Persona &p)const;
				\brief  Sobrecarga del operador relacional de igualdad
				\param  p Persona con la que va a comparar a la Persona actual
				\post   El valor devuelto debe ser true si la Persona actual es igual a la Persona p y false en caso contrario
				\return Valor lógico que indica si la Persona actual es igual que la Persona p
				\sa     operator==, operator<, operator<=, operator>, operator>=
			*/
			bool operator==(const Persona &p)const;

			bool operator!=(const Persona &p) const;

			
			/*! 
				\fn     bool operator<(const Persona &p) const;
				\brief  Sobrecarga del operador relacional "menor que"
				\param  p Persona con la que va a comparar a la Persona actual
				\post   El valor devuelto debe ser true si la Persona actual es alfabéticamente posterior a la Persona p y false en caso contrario
				\return Valor lógico que indica si la Persona actual es alfabéticamente anterior a la Persona p
				\sa     operator==, operator<=, operator>, operator>=
			*/			
			bool operator<(const Persona &p) const;
			
			/*! 
				\fn     bool operator>(const Persona &p) const;
				\brief  Sobrecarga del operador relacional "mayor que"
				\param  p Persona con la que va a comparar a la Persona actual
				\return Valor lógico que indica si la Persona actual es alfabéticamente posterior a la Persona p
				\post   El valor devuelto debe ser true si la Persona actual es alfabéticamente posterior a la Persona p y false en caso contrario
				\sa     operator==, operator<, operator<=, operator>=
			*/			
			bool operator>(const Persona &p) const;

			/*! 
				\fn     bool operator<=(const Persona &p) const;
				\brief  Sobrecarga del operador relacional "menor o igual que"
				\param  p Persona con la que va a comparar a la Persona actual
				\return Valor lógico que indica si la Persona actual es alfabéticamente anterior o igual que la Persona p
				\post   El valor devuelto debe ser true si la Persona actual es alfabéticamente posterior o igual que la Persona p y false en caso contrario
				\sa     operator==, operator<, operator>, operator>=
			*/
			bool operator<=(const Persona &p) const;
			
			/*! 
				\fn     bool operator>=(const Persona &p) const;
				\brief  Sobrecarga del operador relacional "mayor o igual que"
				\param  p Persona con la que va a comparar a la Persona actual
				\return Valor lógico que indica si la Persona actual es alfabéticamente posterior o igual que la Persona p
				\post   El valor devuelto debe ser true si la Persona actual es alfabéticamente posterior o igual que la Persona p y false en caso contrario
				\sa     operator==, operator<, operator<=, operator>
			*/
			bool operator>=(const Persona &p) const;
			
			/*! 
				\fn     friend ostream & operator<<(ostream &stream, const Persona &p);
				\brief  Escribe los datos de la Persona en un flujo de salida
				\note   Sobrecarga del operador de salida "<<"
				\param	stream Flujo de salida
				\param  p Persona, cuyos datos se van a escribir en el flujo de salida
				\return Flujo de salida en el que se han escrito los datos de la Persona
				\sa    friend  istream & operator>>( istream &stream, Persona &p);
			*/
			friend  ostream & operator<<( ostream &stream, const Persona &p);
			
			/*! 
				\fn     friend istream & operator>>(istream &stream, Persona &p);
				\brief  Lee los datos de la Persona desde un flujo de entrada
				\note   Sobrecarga del operador de salida ">>"
				\param	stream Flujo de entrada
				\param  p Persona, cuyos datos se van a leer desde el flujo de entrada
				\return Flujo de salida en el que se han escrito los datos de la Persona
				\sa     friend  ostream & operator<<( ostream &stream, const Persona &p);
			*/			
			friend  istream & operator>>( istream &stream, Persona &p);

			/*! 
				\fn     friend ostream & operator<<(ostream &out, const Persona &p);
				\brief  Escribe los datos de la Persona en un flujo de salida
				\note   Sobrecarga del operador de salida "<<"
				\param	out Flujo de salida
				\param  p Persona, cuyos datos se van a escribir en el flujo de salida
				\return Flujo de salida en el que se han escrito los datos de la Persona
				\sa    friend  istream & operator>>( istream &out, Persona &p);
			*/
			friend  ofstream & operator<<( ofstream &out, const Persona &p);
			
			/*! 
				\fn     friend istream & operator>>(istream &in, Persona &p);
				\brief  Lee los datos de la Persona desde un flujo de entrada
				\note   Sobrecarga del operador de salida ">>"
				\param	in Flujo de entrada
				\param  p Persona, cuyos datos se van a leer desde el flujo de entrada
				\return Flujo de salida en el que se han escrito los datos de la Persona
				\sa     friend  ostream & operator<<( ostream &in, const Persona &p);
			*/			
			friend  ifstream & operator>>( ifstream &in, Persona &p);

			//! \name OBSERVADORES

			/*! 
				\fn     const string &getNombre()const;
				\brief  Función que permite consultar el nombre de la Persona
				\return valor del atributo _nombre
			*/			
			const string &getNombre()const;
			
			/*! 
				\fn     const string &getApellido()const;
				\brief  Función que permite consultar el apellido de la Persona
				\return valor del atributo _apellido
			*/
			const string &getApellido()const;
			
			/*! 
				\fn     const int &getDni()const;
				\brief  Función que permite consultar el DNI de la Persona
				\return valor del atributo _dni
			*/			
			const int &getDni()const;
			
			/*! 
				\fn     const char &borrado() const;
				\brief  Función que permite consultar el valor del atributo borrado de la Persona
				\return valor del atributo _borrado
			*/			
			const char &borrado() const;
			
		//! \name MODIFICADORES
			/*! 
				\fn     void setNombre(const  string &nombre);
				\brief  Función que permite modificar el nombre de la Persona
				\param  nombre Nuevo valor del atributo _nombre
			*/
			void setNombre(const  string &nombre);
			
			/*! 
				\fn     void setApellido(const  string &apellido);
				\brief  Función que permite modificar el apellido de la Persona
				\param  apellido Nuevo valor del atributo _apellido
			*/			
			void setApellido(const  string &apellido);
			
			/*! 
				\fn     void setDni(const int &dni);
				\brief  Función que permite modificar el dni de la Persona
				\param  dni Nuevo valor del atributo _dni 
			*/			
			void setDni(const int &dni);

			/*! 
				\fn     void borrado(const char &borrado);
				\brief  Función que permite modificar el dni de la Persona
				\param  borrado Nuevo valor del atributo _borrado
			*/
			void borrado(const char &borrado);


	};
}

#endif
