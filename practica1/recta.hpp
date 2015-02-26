/*!
  \file recta.hpp
  \brief Se representa el TAD recta
*/


#ifndef Recta_HPP
#define Recta_HPP

#include "punto2D.hpp"
#include <iostream>
#include <cmath>
#include <cassert>


/*!
   \brief Espacio de nombres para la asignatura Estructura de datos.

*/
using namespace std;
namespace ed{

	class Recta2D
	{
		private:
			double a_;
			double b_;
			double c_;

		public:
			Recta2D(const double a, const double b, const double c){a_=a; b_=b; c_=c;};

			Recta2D(const Punto2D &p, const Punto2D &q)
			{
				//assert(not p.sonIguales(q));

				a_=q.getY() - p.getY();
				b_=p.getX() - q.getX();
				c_=p.getY()*(q.getX() - p.getX()) - p.getX()*(q.getY()-p.getY());

			}
				double getA() const{return a_;};
				double getB() const{return b_;};
				double getC() const{return c_;};

				double distancia(const Punto2D &p) const{
				return ((abs(a_*p.getX() + b_*p.getY() + c_))/ (sqrt(pow(a_, 2) + pow(b_, 2))));};

			void setA(double nuevoA){a_=nuevoA;};
			void setB(double nuevoB){b_=nuevoB;};
			void setC(double nuevoC){c_=nuevoC;};

	};

}
#endif