/*!
  \file   edi_List.hpp
  \brief  Definicion de la clase abstracta de Lista
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/


#ifndef EDI_List_HPP
#define EDI_List_HPP

 
namespace edi {
 
  /** @brief Abstrast template class to model the List[T] ADT.*/
  template <class T>
  class  Lista 
  {
    public:
 
    /** @name Makers*/
    /**@{*/
      virtual ~Lista () {}
    /**@}*/
  
    /** @name Observers*/
    /**@{*/
      /** @brief Is the list empty?
      @return true if the list is empty.
      */
      virtual bool estaVacia() const = 0;
      /** @brief Is pos the last list's position?
      @return true if the list is empty.
      */
      virtual bool esUltimo(const int pos) const = 0;
      /** @brief Is pos a valid List's position?
      @return true if pos is a valid list's position.
      */
      virtual bool esValida (const int pos) const = 0;
      /** @brief Get the item at a given position.
      * @arg[in] pos is the list's position.
      * @return a const reference to the stored.
      * @pre isValid(pos)
      */
      virtual const T& dato(const int pos) const = 0;
      /** @brief Find the position of a given item.
      * @arg[in] item is the data to be found.
      * @arg[in] from give a position to start the search.
      * @return -1 if it does not found or the item's position.
      * @pre isValid(from)
      * @post retVal>=0 implies isValid(retVal)
      * @post retVal>=0 implies item(retVal)=item
      */
      virtual int buscaDato(const T& dato, const int desde) const = 0;
    /**@}*/
 
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
      virtual void inserta(const T& datillo) = 0;
      /** @brief Inserts item after a given position.
      * @arg[in] pos is the list's position to insert after.
      * @arg[in] item is the item to store.
      * @pre isValid(pos).
      * @post not isEmpty().
      * @post isValid(pos+1).
      * @post item(pos)=old.item(pos)
      * @post item(pos+1)=item
      */

      virtual void borrarPosicion(const int pos) = 0;
      /**@}*/
  };
 
} //namespace
 
#endif //__EDI_List_HPP__