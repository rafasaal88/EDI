#ifndef punto2D_HPP
#define punto2D_HPP

#include <vector>
#include <iostream>
#include <cassert>

namespace ed{

class Punto2D{

	private:
		double x_;
		double y_;
	
	public:
		Punto2D(double x, double y){x_=x;y_=y;};
		Punto2D(Punto2D const &p)
		{
			x_=p.x_;
			y_=p.y_;
		};
		
		double getX() const {return x_;};
		double getY() const {return y_;};


		bool sonIguales(const Punto2D &p) const{

			bool retV=(getX()==p.getX() && getY()==p.getY());

			#ifndef NDBUG
				if(retV)
					assert(getX()==p.getX() && getY()==p.getY());
			#endif

			return retV;

		}

		double setX(double nuevoX){x_=nuevoX;};
		double setY(double nuevoY){y_=nuevoY;};
};

}
#endif
