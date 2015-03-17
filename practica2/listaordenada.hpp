#ifndef LISTAORDENADA_HPP
#define LISTAORDENADA_HPP

#include "nodo.hpp"
#include <cstdio.h>

namespace ed{



template <class T>
class ListaOrdenada{

	private:
		Nodo<T> *cabeza;
		Nodo<T>	*actual;

	public:
		//Observadores

		bool esUltimo(const int &pos){};

		bool esValida(const int &pos){};


		T item(const int &pos){};

		int buscaItem(const T &item, const int &from){};

		Nodo<T> getCabeza(){};
		Nodo<T> getPuntero(){};
		bool goTo(){};

		void inserta(const T &item){};

		void borraPosicion(const int &pos);


};
}
#endif