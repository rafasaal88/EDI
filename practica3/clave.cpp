/*!
  \file clave.cpp
  \brief  Implememtación de la clase Clave 
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#include <iostream>
#include "clave.hpp"

using namespace edi;

//Sobrecarga del operador < para la ordenación.
bool Clave::operator<(const Clave &c) const
{
	
	if (getDni() < c.getDni())
	{	
		return true;
	}
	else
	{	
		return false;
	}
		
};

bool Clave::operator>(const Clave &c) const
{
	return not (*this <= c);
};

bool Clave::operator>=(const Clave &c) const
{
	return not (*this < c);
};


namespace edi{

	/*! 
	\fn     friend ofstream & operator<<( ofstream &out, const Clave &c);
	\brief  Escribe los datos de la Clave en un flujo de salida
	\note   Sobrecarga del operador de salida "<<"
	\param	out Flujo de salida 
	\param  c Clave, cuyos datos se van a escribir en el flujo de salida
	\return Flujo de salida en el que se han escrito los datos de la Clave
	\sa    	friend ifstream & operator>>( ifstream &in, Clave &c);
*/

  	ostream & operator<<( ostream &out, const Clave &c)
  	{
  		out << c.getDni() << "," << c.getPosicion();
		return out;
	};
  	
	/*! 
		\fn     friend ifstream & operator>>( ifstream &in, Clave &c);
		\brief  Escribe los datos de la Clave en un flujo de salida 
		\note   Sobrecarga del operador de salida ">>"
		\param	in Flujo de salida 
		\param  c Clave, cuyos datos se van a leer desde el flujo de entrada
		\return Flujo de salida en el que se han escrito los datos de la Clave
		\sa    	friend ifstream & operator>>( ifstream &in, Clave &c);
	*/
	

  istream &operator>>( istream &in, Clave &c)
  {
  		int aux;
		int dni;
		char caracter;
		
		in >> aux;
		c.setPosicion(aux);

		// Se lee la coma que separa el dni de la posición
		in >> caracter;
		
		in >> dni;
		c.setDni(dni);
		
		return in;
  };

}
