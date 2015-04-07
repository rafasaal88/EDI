/*!
  \file   nododoble.hpp
  \brief  Definición de la clase Nododoble 
  \author Name
  \date   16/03/2015
*/

#ifndef Nododoble_HPP
#define Nododoble_HPP
 
 /*!
   \brief Espacio de nombres para la asignatura de Estructura de datos y de la información
*/ 
namespace edi
{
 
  template <class T>
//!  Definición de la plantilla de la clase Nodoble

  class  Nododoble
  {
      private:
      T _dato;  //!< nombre del dato a guardar en el nodo
      Nododoble<T> * _siguiente; //!< puntero al siguiente nodo
      Nododoble<T> * _anterior; //!< puntero al nodo anterior


    public:

    //! \name CONSTRUCTOR

    /*! 
      \fn        Nododoble();
      \brief     Constructor parametrizado de la clase Nododoble
      \pre       Es necesario valores de constructor al inicializar la clase
      \post      Ninguna
     */

      Nododoble(const T& dato, Nododoble<T>* siguiente, Nododoble<T>* anterior)  
      {
        setDato(dato);
        setSiguiente(siguiente);
        setAnterior(anterior);
      }
 

       ~Nododoble () {} //destructor

    //! \name OBSERVADORES

    /*! 
      \fn    const  T& getDato() const
      \brief  Función que permite consultar el valor almacenado en el nodo
      \return Valor del dato
      \pre    Ninguna
      \post   Ninguna
    */

      const  T& getDato() const
      {
				return _dato;
      }

    /*! 
      \fn    const Nododoble<T>* getSiguiente() const
      \brief  Función que permite consultar el puntero al siguiente nodo
      \return Posicion de memoria del siguiente nodo
      \pre    Ninguna
      \post   Ninguna
    */

       const Nododoble<T>* getSiguiente() const
      {
        return _siguiente;
      }

    /*! 
      \fn    const Nododoble<T>* getAnterior() const
      \brief  Función que permite consultar el puntero al anterior nodo
      \return Posicion de memoria del anterior nodo
      \pre    Ninguna
      \post   Ninguna
    */

      const Nododoble<T>* getAnterior() const
      {
        return _anterior;
      }

       Nododoble<T>* getSiguiente()
      {
        return _siguiente;  
      }


      Nododoble<T>* getAnterior()
      {
        return _anterior; 
      }

    //! \name MODIFICADORES
    /*! 
      \fn     void setDato (const T& dato)
      \brief  Función que permite modificar el valor del dato que contiene el nodo
      \pre    Ninguna
      \post   Ninguna
    */  

       void setDato (const T& dato)
      {
        _dato=dato;
      }

    /*! 
      \fn     void setSiguiente(Nododoble<T>* siguiente)
      \brief  Función que permite modificar el puntero al siguiente nodo
      \pre    Ninguna
      \post   Ninguna
    */  
       void setSiguiente(Nododoble<T>* siguiente)
      {
				_siguiente=siguiente;
      }

    /*! 
      \fn     void setAnterior(Nododoble<T>* anterior)
      \brief  Función que permite modificar el puntero al anterior nodo
      \pre    Ninguna
      \post   Ninguna
    */  
      void setAnterior(Nododoble<T>* anterior)
      {
        _anterior=anterior;
      }




  };
  
}

#endif 