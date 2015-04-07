#include <iostream>
#include <cstring>
#include "persona.hpp"



Persona::Persona(const char * n, const char * a, const int &d)
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
	return strcmp(getApellido(), p.getApellido()) == 0 and strcmp(getNombre(), p.getNombre()) == 0 and getDni() == p.getDni();
};

bool Persona::operator!=(const Persona &p) const
{
	return strcmp(getApellido(), p.getApellido()) != 0 or strcmp(getNombre(), p.getNombre()) != 0 or getDni() != p.getDni();
};



//Sobrecarga del operador < para la ordenación.
bool Persona::operator<(const Persona &p) const
{
	if (strcmp(getApellido(), p.getApellido()) < 0)
		return true;
	else if (strcmp(getApellido(), p.getApellido()) == 0)
	{
		if (strcmp(getNombre(), p.getNombre()) < 0)
			return true;
		else if (strcmp(getNombre(), p.getNombre()) == 0)
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



ostream & operator<<(ostream &stream, const Persona &p)
{
	stream << p.getNombre() << " " << p.getApellido() << " " << p.getDni() << endl;
	return stream;
};



istream &operator>>(istream &stream, Persona &p)
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

const char *Persona::getNombre()const
{
	return (char *)_nombre;
};

const char * Persona::getApellido()const
{
	return (char *)_apellido;
};

const int &Persona::getDni() const
{
	return _dni;
};

const char &Persona::borrado() const
{
	return _borrado;
};

void Persona::setNombre(const char * nombre)
{
	strcpy(_nombre, nombre);
};

void Persona::setApellido(const char * apellido)
{
	strcpy(_apellido, apellido);
};

void Persona::setDni(const int &dni)
{
	_dni = dni;
};

void Persona::borrado(const char &borrado)
{
	_borrado = borrado;
};

