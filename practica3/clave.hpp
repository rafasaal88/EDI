/*!
  \file   clave.hpp
  \brief  Definicion de la clase clave
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#ifndef CLAVE_HPP
#define CLAVE_HPP
#include <fstream>
#include <iostream>

using namespace std;

/*! 
  \name Espacio de nombres de la asignatura de Estructuras de datos y de la información
*/
namespace edi
{
//!  Definición de la plantilla de la clase Persona	

	class Clave
	{
		private:
			int _dni;
			int _posicion;
		public:
			//! \name CONSTRUCTORES
			/*! 
				\fn        Clave();
				\brief     Constructor por defecto de la clase Clave
				\attention Función sobrecargada	
				\sa        Clave(const int dni,const int posicion); Clave (const Clave &c);
			*/
			Clave ()
			{
				setDni(0);
				setPosicion(0);
			}

			/*! 
				\fn    		Clave(const int dni,const int posicion);
				\brief     Constructor parametrizado de la clase Persona
				\attention Función sobrecargada
				\param     dni, DNI de la Clave
				\param 		posicion, posicion de la Clave
				\sa        Clave (); Clave (const Clave &c);
			*/
			Clave(const int dni, const int posicion)
			{
				setDni(dni);
				setPosicion(posicion);
			}

			/*! 
				\fn 	    Clave (const Clave &c);
				\brief      Constructor de copia de la clase Clave
				\attention  Función sobrecargada	
				\param      c clave de la que se van copiar los valores de los atributos.
				\sa         Clave(); Clave(const int dni,const int posicion); 
			*/
			Clave (const Clave &c)
			{
				setDni(c.getDni());
				setPosicion(c.getPosicion());
			}
	
			//! \name MODIFICADORES
			/*! 
				\fn     void setDni(const int dni);
				\brief  Función que permite modificar el dni de la Clave
				\param  dni Nuevo valor del atributo _dni 
			*/		
			void setDni(const int dni)
			{
				_dni=dni;
			}

			/*! 
				\fn     void setPosicion(const int posicion);
				\brief  Función que permite modificar la posicion de la Clave
				\param  posicion Nuevo valor del atributo _posicion 
			*/	
			void setPosicion(const int posicion)
			{
				_posicion=posicion;
			}

			//! \name OBSERVADORES
			/*! 
				\fn     const int getDni()const;
				\brief  Función que permite consultar el DNI de la Clave
				\return valor del atributo _dni
			*/	
			int getDni() const
			{
				return _dni;
			}

			/*! 
				\fn     int getPosicion() const
				\brief  Función que permite consultar la posicion de la Clave
				\return valor del atributo _posicion
			*/	
			int getPosicion() const
			{
				return _posicion;
			}
			/*! 
				\fn     bool operator==(const Clave &c) const;
				\brief  Sobrecarga del operador relacional de igualdad
				\param  c Clave con la que va a comparar a la Clave actual
				\post   El valor devuelto debe ser true si la Clave actual es igual a la Clave c y false en caso contrario
				\return Valor lógico que indica si la Clave actual es igual que la Clave c
				\sa     operator==, operator<, operator<=, operator>, operator>=
			*/
			bool operator==(const Clave &c) const {return(getDni()==c.getDni());};


			/*! 
				\fn     bool operator!=(const Clave &c) const;
				\brief  Sobrecarga del operador relacional de desigualdad
				\param  c Clave con la que va a comparar a la Clave actual
				\post   El valor devuelto debe ser true si la Clave actual es desigual a la Clave c y false en caso contrario
				\return Valor lógico que indica si la Clave actual es desigual que la Clave c
				\sa     operator==, operator<, operator<=, operator>, operator>=
			*/
			bool operator!=(const Clave &c) const {return(getDni()!=c.getDni());};

			/*! 
				\fn     bool operator<(const Clave &c) const;
				\brief  Sobrecarga del operador relacional "menor que"
				\param  c Clave con la que va a comparar a la Clave actual
				\post   El valor devuelto debe ser true si la Clave actual es menor que la Clave c y false en caso contrario
				\return Valor lógico que indica si la Clave actual es menor que la Clave c
				\sa     operator==, operator<=, operator>, operator>=
			*/			
			bool operator<(const Clave &c) const;
			
			/*! 
				\fn     bool operator>(const Clave &c) const;
				\brief  Sobrecarga del operador relacional "mayor que"
				\param  c Clave con la que va a comparar a la Clave actual
				\return Valor lógico que indica si la Clave actual es alfabéticamente posterior a la Clave c
				\post   El valor devuelto debe ser true si la Clave actual es mayor que la Clave c y false en caso contrario
				\sa     operator==, operator<, operator<=, operator>=
			*/			
			bool operator>(const Clave &c) const;

			/*! 
				\fn     bool operator<=(const Clave &c) const;
				\brief  Sobrecarga del operador relacional "menor o igual que"
				\param  c Clave con la que va a comparar a la Clave actual
				\return Valor lógico que indica si la Clave actual es menor o igual que la Clave c
				\post   El valor devuelto debe ser true si la Clave actual es menor o igual que la Clave c y false en caso contrario
				\sa     operator==, operator<, operator>, operator>=
			*/
			bool operator<=(const Clave &c) const{return ((*this < c) or (*this == c));};
			
			/*! 
				\fn     bool operator>=(const Clave &c) const;
				\brief  Sobrecarga del operador relacional "mayor o igual que"
				\param  p Clave con la que va a comparar a la Clave actual
				\return Valor lógico que indica si la Clave actual es mayor o igual que la Clave p
				\post   El valor devuelto debe ser true si la Clave actual es mayor o igual que la Clave p y false en caso contrario
				\sa     operator==, operator<, operator<=, operator>
			*/
			bool operator>=(const Clave &c) const;
			
			/*! 
				\fn     friend ofstream & operator<<( ofstream &out, const Clave &c);
				\brief  Escribe los datos de la Clave en un flujo de salida
				\note   Sobrecarga del operador de salida "<<"
				\param	out Flujo de salida 
				\param  c Clave, cuyos datos se van a escribir en el flujo de salida
				\return Flujo de salida en el que se han escrito los datos de la Clave
				\sa    	friend ifstream & operator>>( ifstream &in, Clave &c);
			*/

			friend ostream & operator<<( ostream &out, const Clave &c);

			/*! 
				\fn     friend ifstream & operator>>( ifstream &in, Clave &c);
				\brief  Escribe los datos de la Clave en un flujo de salida 
				\note   Sobrecarga del operador de salida ">>"
				\param	in Flujo de salida 
				\param  c Clave, cuyos datos se van a leer desde el flujo de entrada
				\return Flujo de salida en el que se han escrito los datos de la Clave
				\sa    	friend ifstream & operator>>( ifstream &in, Clave &c);
			*/

			friend istream & operator>>( istream &in, Clave &c);
	};
}
#endif