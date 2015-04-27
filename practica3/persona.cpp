/*!
  \file persona.cpp
  \brief  Implememtación de la clase Persona 
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/
#include <iostream>
#include "persona.hpp"
#include <fstream>

using namespace edi;

Persona::Persona(const  string &n, const  string &a, const int &d)
{
	setNombre(n);
	setApellido(a);
	setDni(d);
  	borrado('n');
};

Persona::Persona()
{
	setNombre("");
	setApellido("");
	setDni(0);
  	borrado('n');
};
		
Persona::Persona(const Persona &p)
{
	*this = p;
};

Persona & Persona::operator=(const Persona &p)
{
	if (this != &p)
	{
		setNombre(p.getNombre());
		setApellido(p.getApellido());
		setDni(p.getDni());
	}
	return *this;
};
	
bool Persona::operator==(const Persona &p) const
{
	return getApellido() == p.getApellido() and getNombre() == p.getNombre() and getDni() == p.getDni();
};

bool Persona::operator!=(const Persona &p) const
{
	return getApellido() != p.getApellido() or getNombre() != p.getNombre() or getDni() != p.getDni();
};
//Sobrecarga del operador < para la ordenación.
bool Persona::operator<(const Persona &p) const
{
	if (getApellido() < p.getApellido())
		return true;
	else if (getApellido() == p.getApellido())
	{
		if (getNombre() < p.getNombre())
			return true;
		else if (getNombre() == p.getNombre())
		{
			if (getDni() < p.getDni())
				return true;
			return false;
		}
		else
			return false;
	}
	else
		return false;
};

bool Persona::operator<=(const Persona &p) const
{
	return (*this < p or *this == p);
};

bool Persona::operator>(const Persona &p) const
{
	return not (*this <= p);
};

bool Persona::operator>=(const Persona &p) const
{
	return not (*this < p);
};

// IMPORTANTE:: Las funciones amigas se incluyen en el espacio de nombres edi
/*! 
  \brief Espacio de nombres de la asignatura de Estructuras de datos y de la información
*/
namespace edi{
	/*! 
		\fn     ostream & operator<<( ostream &stream, const Persona &p)
		\brief  Escribe los datos de la Persona en un flujo de salida
		\note   Sobrecarga del operador de salida "<<"
		\param	stream Flujo de salida
		\param  p Persona, cuyos datos se van a escribir en el flujo de salida
		\return Flujo de salida en el que se han escrito los datos de la Persona
		\sa     operator>>
	*/
	ostream & operator<<( ostream &stream, const Persona &p)
	{
		stream << p.getNombre() << " " << p.getApellido() << " " << p.getDni() <<  endl;
		return stream;
	};

	/*! 
		\fn     istream &operator>>( istream &stream, Persona &p)
		\brief  Lee los datos de la Persona desde un flujo de entrada
		\note   Sobrecarga del operador de salida ">>"
		\param	stream Flujo de entrada
		\param  p Persona, cuyos datos se van a leer desde el flujo de entrada
		\return Flujo de salida en el que se han escrito los datos de la Persona
		\sa     operator<<
	*/
	istream &operator>>( istream &stream, Persona &p)
	{
		char aux[30];
		int dni;
		cout << "Nombre: ";
		stream >> aux;
		p.setNombre(aux);
		cout << "Apellido: ";
		stream >> aux;
		p.setApellido(aux);
		cout << "Dni: ";
		stream >> dni;
		p.setDni(dni);
		p.borrado('n');
		
		return stream;
	};

  	ofstream & operator<<( ofstream &out, const Persona &p)
  	{
  		out << p.getNombre() << " " << p.getApellido() << " " << p.getDni() <<  endl;
		return out;
	};
  	
			
		
  ifstream & operator>>( ifstream &in, Persona &p)
  {
  		char aux[30];
		int dni;
		
		in >> aux;
		p.setNombre(aux);
		
		in >> aux;
		p.setApellido(aux);
		
		in >> dni;
		p.setDni(dni);
		p.borrado('n');
		
		return in;
  };


}

const  string & Persona::getNombre()const
{
	return _nombre;
};

const  string & Persona::getApellido()const
{
	return _apellido;
};

const int & Persona::getDni() const
{
	return _dni;
};

const char & Persona::borrado() const
{
	return _borrado;
};

void Persona::setNombre(const  string &nombre)
{
	_nombre = nombre;
};

void Persona::setApellido(const  string &apellido)
{
	_apellido = apellido;
};

void Persona::setDni(const int &dni)
{
	_dni = dni;
};

void Persona::borrado(const char &borrado)
{
	_borrado = borrado;
};

