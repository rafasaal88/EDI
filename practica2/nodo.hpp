#ifndef NODO_H
#define NODO_H


namespace ed{
template <class T>
class Nodo{
	
	private:
		T nodo_;
		Nodo<T> * ant_;
		Nodo<T> * sig_;
		

	public:
		Nodo<T>(const Nodo<T> * ant, const Nodo<T> * sig, const T &valor)
		{
			nodo_=valor;
			ant_=ant;
			sig_=sig;
		};

		//Observadores

		T getNodo()const{return nodo_;};
		Nodo<T>	getAnt()const{return * ant_;};
		Nodo<T> getSig()const{return * sig_;};
		
		//modificadores

		void setNodo(const T &nodo){nodo_=nodo;};
		void setAnt(const Nodo<T> * ant){ant_=ant;};
		void setSig(const Nodo<T> * sig){sig_=sig;};
};
}
#endif