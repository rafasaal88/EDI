/*!
  \file   lista.hpp
  \brief  Definición de la clase Listadoble 
  \author Rafael Salido Álvarez
  \date   07/04/2015
*/

#ifndef Lista_HPP
#define Lista_HPP
#include "edi_List.hpp"
#include "nododoble.hpp"

// Asertos
#include <cassert>


/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos y de la información
*/ 
using namespace std;  
using namespace edi;  

namespace edi {
/** @brief Plantilla abstracta para la clase ListaOrdenada
*/
template <class T>

//!  Definición de la plantilla de la clase Listadoble
  class Listadoble: public Lista<T>
  {

      private:
      Nododoble<T> * _cabeza; //!< Puntero al nodo cabeza de la lista
      Nododoble<T> * _cola; //!< Puntero al nodo cola de la lista
      int _numElementos;  //!< Entero para almacenar el numero de elementos de la lista


      public:


    int getNumeroElementos() const
    {
      return _numElementos;
    }

    Nododoble<T> * getCabeza() const
    {
      return _cabeza;
    }

    Nododoble<T> * getCola()
    {
      return _cola;
    }

    //! \name CONSTRUCTOR

    /*! 
      \fn        Listadoble();
      \brief     Constructor por defecto de la clase Listadoble
      \attention  
      \note      Inicialmente se considera que la lista está vacia
      \pre       Ninguna
      \post      Ninguna
      \sa        Listadoble(const Nododoble<T> * cabeza, const int elementos, const Nododoble<T> * cola);
    */

    Listadoble()
    {
      _cabeza=0;
      _numElementos=0;
      _cola=0;
      assert(estaVacia());
    }

    //! \name OBSERVADORES

    /*! 
      \fn     virtual bool estaVacia() const
      \brief  Función que permite comprobar que la lista esta vacia
      \return 
      \pre    Ninguna
      \post   Ninguna
      \sa     
    */

    virtual bool estaVacia() const
    {
      return _cabeza==0;
    }

    /*! 
      \fn     virtual bool esUltimo(const int pos) const
      \brief  Función que permite comprobar que el numero de elementos de la lista
      \return Numero de elementos
      \pre    Ninguna
      \post   Ninguna
      \sa     
    */

    virtual bool esUltimo(const int pos) const
    {
      return (getNumeroElementos() -1)==pos;
    }

    /*! 
      \fn     virtual bool esValida(const int pos) const
      \brief  Función que permite comprobar que la posicion es valida
      \return Verdadero o falso
      \pre    Ninguna
      \post   Ninguna
      \sa     
    */
    
    virtual bool esValida(const int pos) const
    {
       return ((pos >= 0) && (pos <= getNumeroElementos() - 1));
    }

    /*! 
      \fn     virtual const T& dato(const int pos) const 
      \brief  Función que permite devolver una posicion de la lista
      \return El dato si existe
      \pre    Ninguna
      \post   Ninguna
      \sa     
    */


    virtual const T& dato(const int pos) const 
    { 
      int indice=0;
      assert(/*not*/ esValida(pos));
      Nododoble<T> * aux=getCabeza();
      while((aux !=0)&&(indice<pos))
      {
        indice++;
        aux=aux->getSiguiente();
      }
      return aux->getDato();
    }

    /*! 
      \fn     virtual  int buscaDato (const T &dato, const int desde) const 
      \brief  Función que permite buscar un dato en la lista
      \return 
      \pre    Ninguna
      \post   Ninguna
      \sa     
    */

    virtual  int buscaDato (const T &dato, const int desde) const
    {
      assert(/*not */esValida(desde));
      int indice=0;
      Nododoble<T> * aux=getCabeza();
      while((aux !=0) && (indice<desde))
      {
        indice++;
        aux=aux->getSiguiente();
      }
      
      while((aux!=0) && (aux->getDato()!=dato))
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

    //! \name MODIFICADORES
    /*! 
      \fn     void inserta(const T &dato);
      \brief  Función que permite insertar un nuevo nodo en la lista
      \param  &dato Nodo a insertar
      \pre    Ninguna
      \post   Ninguna
      \sa     virtual void inserta(const T &dato); 
    */  

    virtual void inserta(const T &dato) 
    {
      Nododoble<T> * aux=getCabeza();
      Nododoble<T> * anterior=0;
      Nododoble<T> * nuevo=0;
      bool found=false;
      while((aux!=0) && (aux->getDato() < dato))
      {

        anterior=aux;
        aux=aux->getSiguiente();
      }

      if(aux==getCabeza()) 
      {
        nuevo=new Nododoble<T>(dato, aux, 0);
        if (estaVacia())
        {
        	setCola(nuevo);
        }	        
        setCabeza(nuevo);
      }

      else
      {
        nuevo=new Nododoble<T>(dato, aux, anterior);
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

    /*! 
      \fn     void borrarPosicion(int posicion);
      \brief  Función que permite borrar un nodo de la lista
      \param  Posicion a borrar
      \pre    Ninguna
      \post   Ninguna
      \sa     virtual void borrarposicion(int posicion); 
    */  

    virtual void borrarPosicion(int posicion) 
    {
      Nododoble<T> * aux=getCabeza();
      Nododoble<T> * anterior=0;
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
    /*! 
      \fn     void setNumeroElementos(int numElementos);
      \brief  Función para modificar la variable privada _numElementos
      \param  Nuevo valor para _numElementos
      \pre    Ninguna
      \post   Ninguna
      \sa     void setNumeroElementos(int numElementos) 
    */ 

    void setNumeroElementos(int numElementos)
    {
      _numElementos=numElementos;
    }

    /*! 
      \fn     void setCabeza(Nododoble<T> * cabeza);
      \brief  Función para modificar el nodo privado _cabeza
      \param  Nuevo nodo para _cabeza
      \pre    Ninguna
      \post   Ninguna
      \sa     void setCabeza(Nododoble<T> * cabeza);
    */ 

    void setCabeza(Nododoble<T> * cabeza)
    {
      _cabeza=cabeza;
    }

    /*! 
      \fn     void setCola(Nododoble<T> * cola);
      \brief  Función para modificar el nodo privado _cola
      \param  Nuevo nodo para _cola
      \pre    Ninguna
      \post   Ninguna
      \sa     void setCola(Nododoble<T> * cola);
    */ 

    void setCola(Nododoble<T> * cola)
    {
      _cola=cola;
    }
};
}
 #endif