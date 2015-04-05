#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodo.hpp"
#include <cstdio>
#include <cassert>
#include <vector>

using namespace ed;
namespace ed{

template <class T>
class Lista{

	private:
		Nodo<T> *cabeza_;
		Nodo<T>	*actual_;
		Nodo<T> *anterior_;

	public:

		Lista()
		{
			cabeza_=0;
			actual_=0;
			anterior_=0;
			//(assert(estaVacia()));
		};

		//Obeservadores y modificadores de la clase lista
		Nodo<T> *getCabeza() const{return cabeza_;};

		void setCabeza(Nodo<T> *newV){cabeza_=newV;};

		const Nodo<T> * getAct() const{return actual_;};

		void setAct(Nodo<T> *newV){actual_=newV;};


		//Observadores

		bool esUltimo(const int &pos){

			assert(esValida(pos));
				Nodo<T> * _this = const_cast<Nodo<T>*>(this);
				Nodo<T> * guardarActual=_this->getAct();
				Nodo<T> * guardarAnterior=_this->getAnt();
				_this->goTo(pos);
				bool retVal=getAct()->getSig()==0;
				_this->setAct(guardarActual);
				_this->setAnt(guardarAnterior);
				return retVal;
		};


		bool esValida(const int pos) const{

				Nodo<T> * _this = const_cast<Nodo<T>*>(this);
				Nodo<T> * guardarActual=_this->getAct();
				Nodo<T> * guardarAnterior=_this->getAnt();
				_this->goTo(pos);
				bool retVal=getAct()!=0;
				_this->setAct(guardarActual);
				_this->setAnt(guardarAnterior);
				return retVal;

			}

		


};
}
#endif