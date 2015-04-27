/*!
  \file   NodoDoble.hpp
  \brief  Definición de la clase NodoDoble 
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/


#ifndef NodoDoble_HPP
#define NodoDoble_HPP
 
//using namespace std;  
 
namespace edi
{

//!  Definición de la plantilla de la clase NodoDoble
  template <class T>
  class  NodoDoble
  {
      private:
      T _dato; //!< dato del NodoDoble
      NodoDoble<T> * _siguiente; //!< puntero al  NodoDoble siguiente del NodoDoble
      NodoDoble<T> * _anterior; //!< puntero al NodoDoble anterior del NodoDoble 


    public:

//! \name CONSTRUCTORES
/*! 
      \fn       NodoDoble(const NodoDoble &p);
      \brief      Constructor parametrizado de la clase NodoDoble
      \attention  Función sobrecargada  
      \param     dato Dato del NodoDoble
      \param     siguiente puntero al siguiente NodoDoble del NodoDoble
      \param     anterior puntero al anterior NodoDoble del NodoDoblede       
      \pre        Ninguna
      \post       Los valores de los atributos deben ser los valores de los parámetros
    */

      NodoDoble(const T& dato, NodoDoble<T>* siguiente, NodoDoble<T>* anterior)  
      {
        setDato(dato);
        setSiguiente(siguiente);
        setAnterior(anterior);
      }
 

       ~NodoDoble () {} //destructor

/*----------------------------------------Observadores----------------------------------------------*/



//! \name OBSERVADORES

    /*! 
      \fn     const  T& getDato() const;
      \brief  Función que permite consultar el dato del NodoDoble
      \return valor del atributo _dato
      \pre    El NodoDoble debe existir
      \post   Ninguna
      \sa     getSiguiente() const; getAnterior() const;
    */
      const  T& getDato() const
      {
				return _dato;
      }


    /*! 
      \fn     const NodoDoble<T>* getSiguiente() const;
      \brief  Función que permite consultar el siguiente NodoDoble del NodoDoble
      \return el siguiente NodoDoble
      \pre    El NodoDoble debe existir
      \post   Ninguna
      \sa     getDato() const; getAnterior() const;
    */
       const NodoDoble<T>* getSiguiente() const
      {
        return _siguiente;
      }

    /*! 
      \fn     const NodoDoble<T>* getAnterior() const;
      \brief  Función que permite consultar el anterior NodoDoble del NodoDoble
      \return el anterior NodoDoble
      \pre    El NodoDoble debe existir
      \post   Ninguna
      \sa     getDato() const; getSiguiente() const;
    */

      const NodoDoble<T>* getAnterior() const
      {
        return _anterior;
      }


       NodoDoble<T>* getSiguiente()
      {
        return _siguiente;  
      }


      NodoDoble<T>* getAnterior()
      {
        return _anterior; 
      }


/*----------------------------------------Modificadores------------------------------------------*/
//! \name MODIFICADORES

    /*! 
      \fn     void setDato (const T& dato);
      \brief  Función que permite modificar el dato del NodoDoble
      \param  dato Nuevo valor del atributo _dato
      \pre    El NodoDoble debe existir
      \post   El valor del atributo _dato debe ser igual al valor del parámetro dato
      \sa      setSiguiente(NodoDoble<T>* siguiente);  setAnterior(NodoDoble<T>* anterior);
    */
       void setDato (const T& dato)
      {
        _dato=dato;
      }


    /*! 
      \fn     void setSiguiente(NodoDoble<T>* siguiente);
      \brief  Función que permite modificar el NodoDoble siguiente del NodoDoble
      \param  siguiente Nuevo valor del atributo _siguiente
      \pre    El NodoDoble debe existir
      \post   El valor del atributo _siguiente debe ser igual al valor del parámetro siguiente
      \sa      setDato (const T& dato);  setAnterior(NodoDoble<T>* anterior);
    */
       void setSiguiente(NodoDoble<T>* siguiente)
      {
				_siguiente=siguiente;
      }

    /*! 
      \fn     void setAnterior(NodoDoble<T>* anterior);
      \brief  Función que permite modificar el NodoDoble anterior del NodoDoble
      \param  anterior Nuevo valor del atributo _anterior
      \pre    El NodoDoble debe existir
      \post   El valor del atributo _anterior debe ser igual al valor del parámetro anterior
      \sa      setDato (const T& dato);  setAnterior(NodoDoble<T>* anterior);
    */
      void setAnterior(NodoDoble<T>* anterior)
      {
        _anterior=anterior;
      }
};
  
} //namespace

#endif 