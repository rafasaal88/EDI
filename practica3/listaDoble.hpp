/*!
  \file   ListaDoble.hpp
  \brief  Definicion de la clase ListaDoble
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/


#ifndef ListaDoble_HPP
#define ListaDoble_HPP
#include "edi_List.hpp"
#include "nodoDoble.hpp"

#include <cassert>

using namespace std;  
using namespace edi;  

namespace edi {
 //!  Definición de la plantilla de la clase ListaDoble
 
template <class T>

  class ListaDoble: public Lista<T>
  {
      private:
      NodoDoble<T> * _cabeza; //!< puntero que apunta a la cabeza de la ListaDoble
      NodoDoble<T> * _cola;  //!< puntero que apunta a la cola de la ListaDoble
      int _numElementos;  //!< numero de elementos que tiene la lista

      public:
/*---------------------------observadores----------------------------*/
    /** @name Observers*/
    /**@{*/


    int getNumeroElementos() const
    {
      return _numElementos;
    }

    NodoDoble<T> * getCabeza() const
    {
      return _cabeza;
    }

    NodoDoble<T> * getCola()
    {
      return _cola;
    }

/*----------------------------------modificadores-----------------------------------------*/

    void setNumeroElementos(int numElementos)
    {
      _numElementos=numElementos;
    }

    void setCabeza(NodoDoble<T> * cabeza)
    {
      _cabeza=cabeza;
    }


    void setCola(NodoDoble<T> * cola)
    {
      _cola=cola;
    }

    
/*------------------------------------Constructor--------------------------------------*/
  
    ListaDoble()
    {
      _cabeza=0;
      _numElementos=0;
      _cola=0;
      assert(estaVacia());
    }

    ~ListaDoble()
    {
      borrarLista();
    }
/*-------------------------------Funciones que pide el ejercicio--------------------------------*/

      /** @brief Is the list empty?
      @return true if the list is empty.
      */
    virtual bool estaVacia() const
    {
      return _cabeza==0;
    }

      /** @brief Is pos the last list's position?
      @return true if the list is empty.
      */
    virtual bool esUltimo(const int pos) const
    {
      return (getNumeroElementos() -1)==pos;
    }

    /** @brief Is pos a valid List's position?
      @return true if pos is a valid list's position.
      */
    
    virtual bool esValida(const int pos) const
    {
       return ((pos >= 0) && (pos <= getNumeroElementos() - 1));
    }

    /*---------Devuelve el item de la listaOrdenada que está almacenado en posición----------*/

    /** @brief Get the item at a given position.
      * @arg[in] pos is the list's position.
      * @return a const reference to the stored.
      * @pre isValid(pos)
      */
    virtual const T& dato(const int pos) const 
    { 
      int indice=0;
      assert(esValida(pos));
      NodoDoble<T> * aux=getCabeza();
      while((aux !=0)&&(indice<pos))
      {
        indice++;
        aux=aux->getSiguiente();
      }
      return aux->getDato();
    }

    /*-----------------devuelve la posicion del item or -1, a partir de desde-------------------*/

    /** @brief Find the position of a given item.
      * @arg[in] item is the data to be found.
      * @arg[in] from give a position to start the search.
      * @return -1 if it does not found or the item's position.
      * @pre isValid(from)
      * @post retVal>=0 implies isValid(retVal)
      * @post retVal>=0 implies item(retVal)=item
      */
    virtual  int buscaDato (const T &datillo, const int desde) const
    {
      assert(esValida(desde));
      int indice=0;
      NodoDoble<T> * aux=getCabeza();
      while((aux !=0) && (indice<desde))
      {
        indice++;
        aux=aux->getSiguiente();
      }
      
      while((aux!=0) && (aux->getDato()!=datillo))
      {
        aux=aux->getSiguiente();
        indice ++;        
      }

      if(aux==0)
      {
        return -1;
      }

      else
      {
        return indice;
      }
    }

    /*---------------------------Inserción ordenada de dato---------------------------*/

    /** @name Mutators*/
    /**@{*/
      /** @brief Inserts item before a given position.
      * @arg[in] pos is the list's position to insert before.
      * @arg[in] item is the item to store.
      * @pre isValid(pos).
      * @post isValid(pos+1).
      * @post not isEmpty().
      * @post item(pos)=item.
      * @post item(pos+1)=old.item(pos)
      */
    virtual void inserta(const T &datillo) 
    {
      NodoDoble<T> * aux=getCabeza();
      NodoDoble<T> * anterior=0;
      NodoDoble<T> * nuevo=0;
      bool found=false;
      while((aux!=0) && (aux->getDato() < datillo))
      {

        anterior=aux;
        aux=aux->getSiguiente();
      }

      if(aux==getCabeza()) 
      {
        nuevo=new NodoDoble<T>(datillo, aux, 0);
        if (estaVacia())
        {
        	setCola(nuevo);
        }	        
        setCabeza(nuevo);
      }

      else
      {
        nuevo=new NodoDoble<T>(datillo, aux, anterior);
        anterior->setSiguiente(nuevo);    
        if (aux != 0)
        {
        	aux->setAnterior(nuevo); 
        }
        else
        {
        	setCola(nuevo);
        }
      }
      setNumeroElementos(getNumeroElementos()+1);

    }

    /*------------------------Inserción ordenada de dato.------------------------*/

    /** @brief Inserts item after a given position.
      * @arg[in] pos is the list's position to insert after.
      * @arg[in] item is the item to store.
      * @pre isValid(pos).
      * @post not isEmpty().
      * @post isValid(pos+1).
      * @post item(pos)=old.item(pos)
      * @post item(pos+1)=item
      */
    virtual void borrarPosicion(int posicion) 
    {
      NodoDoble<T> * aux=getCabeza();
      NodoDoble<T> * anterior=0;
      int indice=0;

      assert (estaVacia() || (/*not*/ esValida(posicion)));

      while((aux!=0) && (indice < posicion)) //
      {
        anterior=aux;
        aux=aux->getSiguiente();
        indice ++;
      }

      if(getCabeza() == aux)
      {
        setCabeza(aux->getSiguiente());

        if (aux->getSiguiente() == 0)
        {
          setCola(0);
          setCabeza(0);
        }
        else
        {
          setCabeza(aux->getSiguiente());
          getCabeza()->setAnterior(0);
        }
      }

      else
      {
        if(aux->getSiguiente() != 0 )
        {
          anterior->setSiguiente(aux->getSiguiente());
          aux->getSiguiente()->setAnterior(anterior);
        }
        else
        {
          anterior->setSiguiente(aux->getSiguiente());
          setCola(anterior);
        }
      }
      setNumeroElementos(getNumeroElementos()-1);
      delete(aux);

    }


      /** @brief Delete all  item .
      */
   void borrarLista() 
    {
      NodoDoble<T> * aux=getCabeza();

      assert ( not estaVacia() );

      while((_cabeza!=0) ) //
      {
        _cabeza=aux->getSiguiente();
        delete aux;
        aux=getCabeza();
      }

      _cabeza=0;
      _cola=0;  
      _numElementos=0;  

    }


};
}
 #endif