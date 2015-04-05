#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodo.hpp"
#include <cstdio>
#include <cassert>
#include <vector>

using namespace ed;
namespace edi{

template <class T>
class Lista{

	private:
		Nodo<T> *cabeza_;
		Nodo<T>	*actual_;
		
	public:

		Lista()
		{
			cabeza_=0;
			actual_=0;
			
			//(assert(estaVacia()));
		};

		//Observadores y modificadores de la clase lista
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

		bool estaVacia() const{
				return getCabeza()==0;

			}
		
		T& item(const int pos) const{
				int indice=0;
				assert (esValida(pos));
				Nodo<T> * aux=getCabeza();
				
				while((aux!=0)&&(indice<pos))
				{
					indice++;
					aux=aux->getSig();
				}
				return aux->getNodo();
			}

		int buscaItem(const T &item, const int from){
				assert (esValida(from));
				int indice=0;
				Nodo<T> * aux=getCabeza();
				while((aux!=0)&&(indice<from))
				{
					indice++;
					aux=aux->getSig();
				}
				while((aux!=0)&&(aux->getNodo()!=item))
				{
					indice++;
					aux=aux->getSig();
				}
				if (aux==0)
				{
					return -1;
				}
					return indice;
			}

		void inserta(const T &item){
			Nodo<T> * nodo(0,0,item);

			if(estaVacia()){
				setCabeza(nodo);
				return true;
			}

			else{
				Nodo<T> *n=getCabeza();
				Nodo<T> *aux;
				for(;;)
				{
					if(n->getSig())
						{
							if(item > n.item())
							{
								n=n->getSig();
							}						
							else
							{
								aux=n->getAnt();
								n->setAnt(nodo);
								nodo->setAnt(aux);
								nodo->setSig(n);
								return true;
							}

						}
					else
					{
						if(item< n->item)
						{
							setCabeza(nodo);
							nodo->setAnt(n);
							setAct(nodo);
							return true;
						}
						else
						{
							n->setSig(nodo);
							nodo->setAnt(n);
							setAct(nodo);
							return true;
						}

					}

				}
			}

		}

		void borraPosicion(const int pos){
			assert(not estaVacia());
			assert(esValida(pos));
			
			Nodo<T> * actual=getAct();
			goTo(pos);

			if(actual.getAnt()==0)
			{
				setCabeza(actual->getSig());
			}
			else
			{
				Nodo<T> * sig=actual.getSig();
				Nodo<T> * ant=actual.getAnt();
			}

			delete actual;


		}

		void goTo(const int pos){

			setCabeza(getCabeza());
			//setAnt(0);
			for(int i=0; i<pos and actual_!=0; i++){
				setAnt(getAct());
				setAct(getAct()->getSig());
			}
		}



};

}
#endif