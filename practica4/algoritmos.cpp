/*!
  \file   algoritmos.cpp
  \author Rafael Salido Álvarez
  \brief  Fichero de funciones de algoritmos para trabajar con el grafo
  \date   27/04/2015
*/

#include <fstream>
#include "edge.hpp"
#include "vertex.hpp"
#include <vector>
#include <limits>

#include "graph_matrix.hpp"
#include "algoritmos.hpp"
#include <iostream>

using namespace std;
using namespace edi;

/*!
  \brief Esta funcion realiza un recorrido por todo el grafo desde un vertice hasta el ultimo.
  \note Es de tipo recursiva.
  \param g, u, lista
  \pre Ninguna
  \post Ninguna
*/

void recorrido_profundidad(GraphMatrix & g, Vertex u, vector<int> &lista) {

      bool encontrado; //Booleano para comprobar la existencia del vertice
      float infinito = numeric_limits<float>::infinity(); //Variable con valor infinito
      vector<int>::iterator it; //
      
      g.goTo(u.getLabel()); //Nos deplazamos hasta la posicion del vertice
      lista.push_back(u.getLabel()); //Guardamos en la lista el nombre del vertice
      cout << g.currVertex().getData(); //Lo mostramos por pantalla

      Vertex *aux = new Vertex;

      for(int pos = 0; pos < g.capacity(); pos++) //Comprobamos vertices adyacentes
      {
        encontrado = false;
        g.goTo(pos);
        *aux = g.currVertex();
        //cout << "vertice "<< g.currVertex().getLabel();// << endl;


        if((g.adjacent(u, *aux) > 0) && (g.adjacent(u, *aux) < infinito)) //Comprobamos los vertices adyacentes
        {
          for(it = lista.begin(); it != lista.end(); it++) //Comprobamos que los vertices no los hemos visitado ya antes
          {
              if(*it == aux->getLabel())
              {
                encontrado = true; //Si encontramos un nodo que ya hemos visitado anteriormente, cambiamos el valor de encontrado
              }
          }

          if (!encontrado) //En caso contrario, seguimos recorriendo.(Recordemos que estamos en una funcion recursiva) 
          {
            cout << endl<< "  |" << endl;
            cout << "  |" << endl;
            recorrido_profundidad(g, *aux, lista);
          }
        }
      }
}


/*!
  \brief Esta funcion realiza el algoritmo de Floyd.
  \note Vamos a crear dos matrices auxiliares, una para distancias y otra para los intermedios
  \param g, matriz_distancias, matriz_intermedios
  \pre Ninguna
  \post Ninguna
*/

void algoritmo_Floyd(GraphMatrix & g, float ** matriz_distancias, int ** matriz_intermedios) {

    //Variables para calcular las adyacencias
    Vertex vertice1, vertice2;

    //Rellenamos la matriz de intermedios.
    for(int i = 0 ; i < g.numVertexes() ; i ++)
    {
      for(int j = 0 ; j < g.numVertexes() ; j ++)
      {
        if (i==j)
          matriz_intermedios[i][j]=0; //La diagonal principal la rellenamos a 0.
        else
          matriz_intermedios[j][i]=i; //En caso contrario, todas las columnas iguales.
      }
    }

    //Rellenamos la matriz de distancias.
    for (int i = 0; i < g.numVertexes(); i++)
    {
      //Nos situamos en la ciudad i para calcular la adyacencia
      g.goTo(i);
      vertice1 = g.currVertex();
      
      for (int j = 0; j < g.numVertexes(); j++)
      {
      //Nos situamos en la ciudad j para calcular la adyacencia
          g.goTo(j); 
          vertice2 = g.currVertex();

          matriz_distancias[i][j] = g.adjacent(vertice1, vertice2); //Adyacencia de la ciudad i y j
            
          //Si es demasiado grande la hacemos infinta  
          if (matriz_distancias[i][j] > 1000 || matriz_distancias[i][j] < 0)
          {
          matriz_distancias[i][j] = numeric_limits<float>::infinity(); //Necesaria la libreria <limits>
          }
      }
    }

    //Algoritmo de Floyd
    for(int k = 0; k < g.numVertexes(); k++) //Iteración del algoritmo
    { 
      for (int i = 0; i < g.numVertexes(); i++) //Filas
      {
        for (int j = 0; j < g.numVertexes(); j++) //Columnas
        {
          float dist = (matriz_distancias[i][k] + matriz_distancias[k][j]); //Distancia
          
          if(matriz_distancias[i][j] > dist)
          { //Si la distancua es menor que la que figura en la matriz de distancias:
          matriz_distancias[i][j] = dist; //La cambiamos
          matriz_intermedios[i][j] = matriz_intermedios[i][k]; //Realizamos el intercambio ya que ahora tiene otro intermediario
          }
        }
      }
    }
}


/*!
  \brief Función para calcular la distancia minima entre dos vertices.
  \param g, matriz_distancias, matriz_intermedios, origen, destino
  \pre Ninguna
  \post Ninguna
*/

void distancia_Minima(GraphMatrix & g, float ** matriz_distancias, int ** matriz_intermedios, Vertex & origen, Vertex & destino) {
  
  float distancia = matriz_distancias[origen.getLabel()][destino.getLabel()]; //Variable para guardar la distancia entre las dos ciudades
  cout << "La distancia desde " <<origen.getData() <<  " a " << destino.getData() << " es de: "<< distancia << " kms por el camino mas corto que es: " << endl; 

  bool directo = true; //Comprobamos si existe un camino directo entre las dos ciudades
  int orgen = origen.getLabel(); //Volcamos en orgen la ciudad de origen
  int destno = destino.getLabel(); //Volcamos en destno la ciudad de destino.
  int intermedio = matriz_intermedios[orgen][destno]; //Iremos controlando la ciudad intermediaria.


  if (intermedio != destno) 
  { //Si la variable intermedia es diferente de la de destno, no existe un camino directo.
    while (intermedio != destno) //Mientras no sea camino directo, vamos imprimiendo el camino intermedio
    { 
      g.goTo(orgen); //Situamos el cursor en el origen actual
      cout << g.currVertex().getData() << "-->"; //Imprimimos la ciudad en la que nos encontramos actualmente
      orgen = intermedio; //Origen pasa a ser el nodo intermedio para calcular el siguiente intermedio
      intermedio = matriz_intermedios[orgen][destno]; //El intermedio nuevo será entre el origen nuevo y el destino que no cambia.
    }
    directo = false; //Cambiamos la variabe para que no se muestre que existe un camino directo.
  }

  //Como nuestro bucle se para cuando la ciudad intermedia y destino sean la misma, debemos imprimir la última ciudad

  g.goTo(orgen); //Nos situamos en la ultima ciudad intermedia.
  cout << g.currVertex().getData() << "-->"; //Imprimimos el orgen actual, que es la ultima ciudad intermedia.
  cout << destino.getData() << endl; //Imprimimos el destino.

  if(directo) //Si no ha habido ciudades entre medias:
    cout << "Existe un camino directo entre ambas ciudades" << endl;
}

