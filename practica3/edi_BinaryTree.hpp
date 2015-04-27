#ifndef EDI_BinaryTree_HPP
#define EDI_BinaryTree_HPP


#include <cassert>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "clave.hpp"
#include "edi_exports.hpp"

namespace edi 
{
/** @brief ADT Binary tree.*/  
template<class T>
class EDI_API BinaryTree
{
public:
  /** @name Makers*/
  /**@{*/
  
  /** @brief Destructor.*/
  virtual ~BinaryTree (){}
  /**@}*/

  /** @name Observers*/
  /**@{*/
  
  /** @brief Is the tree empty?.
   * @return true if the tree is empty.
   */
  virtual bool isEmpty() const = 0;
  
  /** @brief Is this a sub-tree?.   
   * @return true if this is a sub-tree.
   */
  virtual bool isSubTree() const = 0;
  
  /** @brief Is this a tree without any childs?   
   * @return true if this is a leaf tree.
   */
  virtual bool isLeaf() const = 0;  
  
  /** @brief Has current got a left child?
   * @return true if current has got a left child.
   * @pre not isEmpty()
   */
  virtual bool hasLeftChild() const = 0;
  
  /** @brief Has current got a right child?
   * @return true if current has got a right child.
   * @pre not isEmpty()
   */
  virtual bool hasRightChild() const = 0;
    
  /** @brief Gets the stored data int the current node.   
   * @return a const reference to the data.
   */
  virtual const T& item() const = 0;
  
  /** @brief Gets the left sub-tree.   
   * @return a const pointer to the left sub-tree.
   * @pre not isEmpty().
   */
  virtual const BinaryTree<T>* leftSubTree() const  =0;
  
  /** @brief Gets the right sub-tree.
   * @return a const pointer to the right sub-tree.
   * @pre not isEmpty().
   */  
  virtual const BinaryTree<T>* rightSubTree() const = 0;
    
  /**@}*/

  /** @name Mutators*/
  /**@{*/

  /** @brief Gets the left sub-tree.
   * @return a pointer to the left sub-tree.
   * @pre not isEmpty().
   */
  virtual BinaryTree<T>* leftSubTree() = 0;
  
  /** @brief Gets the right sub-tree.   
   * @return a pointer to the right sub-tree.
   * @pre not isEmpty().
   */  
  virtual BinaryTree<T>* rightSubTree() = 0;  
    
  /** @brief Sets the data stored in current.
   * @arg[in] it is the data to be stored.
   * @pre not isEmpty().
   */
  virtual void setItem(const T& it) = 0;
  
  /** @brief Create the root node.   
   * @arg[in] it is the data stored in the node.
   * @pre isEmpty().
   * @pre not isSubTree().
   * @post not hasRightChild().
   * @post not hasLeftChild().   
   */
  virtual void createRoot(const T& it) = 0;  
  
  /** @brief Create the right child.
   * @arg[in] it is the data stored in the node.
   * @pre not isEmpty().
   * @pre not hasRightChild().
   * @post hasRightChild(). 
   */
  virtual void createRightSubTree(const T& it) = 0;
  
  /** @brief Create the left child.
   * @arg[in] it is the data stored in the node.   
   * @pre not isEmpty().
   * @pre not hasLeftChild().
   * @post hasLeftChild().
   */
  virtual void createLeftSubTree(const T& it) = 0;
  

  virtual void insert(const T& x) =0;
  /**@}*/  

        /*! 
        \fn     friend std::istream& operator>> (std::istream& in,  BinaryTree<edi::Clave>* t);
        \brief  Escribe los datos de BinaryTree en un flujo de salida 
        \note   Sobrecarga del operador de salida ">>"
        \param  in Flujo de salida 
        \param  t BinaryTree, cuyos datos se van a leer desde el flujo de entrada
        \return Flujo de salida en el que se han escrito los datos de BinaryTree
        \sa     friend std::ostream& operator<< (std::ostream& out,   BinaryTree<edi::Clave>* t);
      */
  friend  ifstream &operator>>(ifstream& in, BinaryTree<edi::Clave> *t)
{
 
  string token; // recoger el token '(' ')' o ':'
  string dato; // recoge el dato en la forma dni,pos
  int split; // para separar dni y posicion por la coma.
 
  vector<int> v;
 
  Clave aux; // Guardar el dato recogido e insertarlo en el arbol.
  Clave vacio; // Crear un arbol derecho/izquierdo vacio.
 
 
  in >> token; // Se lee el primer token que debe empezar por '('
 
 // cout << "token1: " << token << endl;   //comentar
 
 
  in >> dato; // Seguidamente el dato
 
   //cout << "dato: " << dato << endl;  //comentar
 
 
  // Para separar el dni y la posicion.
  stringstream ss(dato);
 
  while (ss >> split)
  {
 
   v.push_back(split);
 
      if (ss.peek() == ',')
          ss.ignore();
  }
 
  // Insertamos en la Clave y sacamos del vector.
  aux.setDni(v[0]);
  aux.setPosicion(v[1]);
  v.pop_back();
  v.pop_back();
 
 
  // Si el arbol esta vacio, creamos la raiz con ese dato.
  if ( t->isEmpty() and not t->isSubTree() )
     t->createRoot(aux);
 
  // En caso contrario, insertamos donde corresponda.
  else
     t->setItem(aux);
 
 
  in >> token;
  //cout << "token2: " << token << endl;  //comentar
 
  if (token == "(" ) // Hay subarbol izquierdo
  {
    in.putback('('); // lo devolvemos al buffer para que vuelva a leerlo en la llamada.
    t->createLeftSubTree(vacio);
    in >> t->leftSubTree();
  }
 
  if (token == ":" ) 
  {

  }
 
  in >> token;
  //cout << "token3: " << token << endl; //comentar
 
 
  if (token == "(" ) // Hay subarbol izquierdo
  {
    in.putback('(');
    t->createRightSubTree(vacio);
    in >> t->rightSubTree();
  }
 
  if (token == ":" )
  {

  }
 
  in >> token;
 
  //cout << "token4: " << token << endl; //comentar
 
 
  return in;
 
}    

  /*friend std::istream& operator>> (std::istream& in,  BinaryTree<edi::Clave>* t)
  {
    assert(not t->isEmpty() && t!=0);
   edi::Clave key;
    while (in>>key)
      {
        t->insert(key);
      }
  return in;
  }*/

      /*! 
        \fn     friend std::ostream& operator<< (std::ostream& out,   BinaryTree<edi::Clave>* t);
        \brief  Escribe los datos del arbol en un flujo de salida
        \note   Sobrecarga del operador de salida "<<"
        \param  out Flujo de salida 
        \param  t BinaryTree, cuyos datos se van a escribir en el flujo de salida
        \return Flujo de salida en el que se han escrito los datos de la BinaryTree
        \sa     friend std::istream& operator>> (std::istream& in,  BinaryTree<edi::Clave>* t);
      */

  friend std::ofstream& operator<< (std::ofstream& out,BinaryTree<edi::Clave>* t)
  {
    assert(t!=0);

    out<<" ( " << t->item();

    if ( t->hasLeftChild() )
    {
      
      out<< t->leftSubTree();    
    }
    else
    {
      out << " : ";
    }

    if (t->hasRightChild() )
    {
      out<< t->rightSubTree();   
    }

    else
    {
      out << " : "; 
    }
    out << " ) ";
  
    return out;
  }



};

/** @addtogroup BTUtils Binary Tree Utilities.
 * @ingroup edi
 * @{
 */

/** @brief Carries out a post order traversal through the tree.
 * This template makes use of a Functor class with the interface:
 * 
 * bool operator()(const T& t) method.
 *  
 * @arg[in] t is the tree.
 * @arg[in] f is a functor object with the 
 * @return false if the process must stop or true in other case.
 */
template <class T, class Functor>
bool postorderBinaryTreeProcessor(const BinaryTree<T>* t, Functor& f)
{
  bool retVal=true;
  
  if (not t->isEmpty())
  {
    if (t->hasLeftChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->leftSubTree());
      retVal = postorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);
    }
    if (retVal and t->hasRightChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->rightSubTree());
      retVal = postorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);
    }
    if (retVal)
      retVal = f(t->item());      
  }
  
  return retVal;
}

/** @brief Carries out an in order traversal through the tree.
 * This template makes use of a Functor class with the interface:
 * 
 * bool operator()(const T& t) method.
 *  
 * @arg[in] t is the tree.
 * @arg[in] f is a functor object with the 
 * @return false if the process must stop or true in other case.
 */
template <class T, class Functor>
bool inorderBinaryTreeProcessor(const BinaryTree<T>* t, Functor& f)
{
  bool retVal=true;
  
  if (not t->isEmpty())
  {
    if (t->hasLeftChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->leftSubTree());
      retVal = inorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);
    }
    if (retVal)
      retVal = f(t->item());
    if (retVal and t->hasRightChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->rightSubTree());
      retVal = inorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);
    }
  }
  
  return retVal;
}

/** @brief Carries out a pre order traversal through the tree.
 * This template makes use of a Functor class with the interface:
 * 
 * bool operator()(const T& t) method.
 *  
 * @arg[in] t is the tree.
 * @arg[in] f is a functor object with the 
 * @return false if the process must stop or true in other case.
 */
template <class T, class Functor>
bool preorderBinaryTreeProcessor(const BinaryTree<T>* t, Functor& f)
{
  bool retVal=true;
  
  if (not t->isEmpty())
  {    
    retVal = f(t->item());
    if (retVal and t->hasLeftChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->leftSubTree());
      retVal = preorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);
    }
    if (retVal and t->hasRightChild())
    {
      std::auto_ptr<const BinaryTree<T> > ptr(t->rightSubTree());
      retVal = preorderBinaryTreeProcessor<T, Functor>(ptr.get(), f);      
    }
  }
  
  return retVal;
}




/** @}*/
}
#endif //__EDI_BinaryTree_HPP__