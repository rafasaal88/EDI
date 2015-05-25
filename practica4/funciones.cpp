/*!
  \file   funciones.cpp
  \brief  Definicion del archivo de funciones del programa principal
  \author Rafael Salido Álvarez
  \date   27/04/2015
*/

#include "cabecera.hpp"
#include <vector>

/*!
	\brief Hace una busqueda profunda dentro del grafo
	\param g
	\pre Ninguna
	\post Ninguna
*/

void profundidad(GraphMatrix & g)
{

  	string ciudad; //Ciudad a buscar
  	bool correcto = true; //Booleano para comprobar que la ciudad a buscar es correcta
  	vector<int> lista; //
    cout << "Introduzca una ciudad: ";
    cin >> ciudad; //Introducimos la ciudad por teclado

    g.searchVertex(ciudad); //Buscamos la ciudad

	if (!g.hasCurrVertex()) //Comprobamos que la ciudad existe
	{
	    cout << "Ciudad no encontrada, por favor, inserte una que se encuentre en el grafo..." <<endl;
	    correcto = false;
	}

  	if (correcto == true) //Si la ciudad existe, procedemos a realizar el recorrido en profundidad
  	{
	    Vertex v;
	    v = g.currVertex();
	    lista.clear(); //Para poder recorrer más de una vez desde un nodo.
	    recorrido_profundidad(g, v, lista);
	    cout << "\n";
  }
}

/*!
	\brief Carga desde el fichero los datos al grafo
	\param g, fichero
	\pre Ninguna
	\post Ninguna
*/

bool cargar(GraphMatrix * &g, string &fichero)
{
	cout << "Indique el nombre del archivo que contiene el grafo: ";
	cin >> fichero; //Introducimos el nombre del fichero
	bool cargado=false; //Booleano para comprobar que el fichero ha sido correctamente cargado
	cargado = cargarGrafo(g, fichero); //Llamamos a la funcion de cargar el fichero
	
	if (cargado==true)
	{
		cout << "Grafo cargado correctamente" << endl;
		return true;
	}
	else
	{
		cout << "Error al cargar el grafo" << endl;
		return false;
	}
}

/*!
	\brief Funcion que recoge los datos y los envia para que se ejecute el algoritmo de Floyd
	\param g
	\pre Ninguna
	\post Ninguna
*/

void floyd(GraphMatrix * &g)
{
	bool fallo = false; //Controlaremos los fallos con una variable booleana.
	string ciudad1, ciudad2; //Ciudades origen / destino

	Vertex origen; //Vertice de la ciudad origen.
	Vertex destino; //Vertice de la ciudad destino

	float ** matriz_distancias; //Matriz de distancias.
	int ** matriz_intermedios; //Matriz de intermedios

	//Reservamos la matriz de distancias.
	matriz_distancias = reservarMemoriaMatrizFloat (g->capacity(),g->capacity());
	
	//Reservamos la matriz de intermedios
	matriz_intermedios = reservarMemoriaMatrizInt (g->capacity(),g->capacity());

	//Aplicamos el algoritmo de Floyd
	algoritmo_Floyd(*g, matriz_distancias, matriz_intermedios);

	cout << "Introduzca dos ciudades para mostrar el camino más corto entre ellas" << endl;
	cout << "Origen: ";
	cin >> ciudad1; //Introducimos la ciudad origen

	//Distancia minima

	g->searchVertex(ciudad1); //Situamos el cursor de vectores sobre la ciudad origen

	if(g->hasCurrVertex())
		{ //Si existe la ciudad(cursor != NULL)
		origen = g->currVertex(); //Marcamos la ciudad como la que marca el cursor
		}
	else
	{ //Si la ciudad ORIGEN no existe en nuestro grafo.
		cout << "Por favor, indique una ciudad valida..." << endl;
		fallo = true; //La ciudad no se encuentra en el grafo, cambiamos el bool a true.
	}

	if(fallo==false) //Si la ciudad1 existe seguimos ejecutando
	{
		cout << "Destino: "; 
		cin >> ciudad2; // Introducimos la ciudad 2

		if(ciudad1!= ciudad2)
		{
			g->searchVertex(ciudad2); //Situamos el cursor de vectores sobre la ciudad destino
			
			if(g->hasCurrVertex())
			{ //Si existe la ciudad(cursor != NULL)
				destino = g->currVertex(); //Marcamos la ciudad como la que marca el cursor
				distancia_Minima(*g, matriz_distancias, matriz_intermedios, origen, destino); //Funcion distancias
			}

			else //Si la ciudad destino no existe, salimos de la funcion.
			{
			cout << "Por favor, indique una ciudad valida..." << endl;
			}
		}
		else
		{
			cout << "Ha introducido dos veces la misma ciudad..." <<endl;
		}
	}

	//Liberamos memoria
	liberarMemoriaMatrizInt (g->capacity(),matriz_intermedios);
	liberarMemoriaMatrizFloat (g->capacity(),matriz_distancias);
}

/*!
	\brief Funcion para reservar memoria de una matriz de floats
	\param nFil, nCol
	\pre Ninguna
	\post Ninguna
*/


float ** reservarMemoriaMatrizFloat( int nFil, int nCol)
{
	float ** matriz=NULL;
		matriz=new float*[nFil]; //reservamos filas
		for (int i = 0; i < nFil; i++)
	{
		matriz[i]=new float[nCol]; //Reservamos las columnas para cada fila
	}
	return matriz;
}


/*!
	\brief Funcion para reservar memoria de una matriz de enteros
	\param nFil, nCol
	\pre Ninguna
	\post Ninguna
*/


int ** reservarMemoriaMatrizInt( int nFil, int nCol)
{
	int ** matriz=NULL;
		matriz=new int*[nFil]; //reservamos filas
		for (int i = 0; i < nFil; i++)
	{
		matriz[i]=new int[nCol]; //Reservamos las columnas para cada fila
	}
	return matriz;
}


/*!
	\brief Funcion para liberar memoria de una matriz de floats
	\param nCol, matriz
	\pre Ninguna
	\post Ninguna
*/

void liberarMemoriaMatrizFloat(int nCol, float **matriz)
{	
	for ( int i = 0 ; i < nCol ; i++ )// Elimino cada vector de la matriz
    {
   		 delete matriz[i];  // Borramos los objetos creados con matriz[i]=new int[nCol];
    }
  		delete matriz; // Borramos el objeto creado con matriz=new int*[nFila];
}

/*!
	\brief Funcion para liberar memoria de una matriz de enteros
	\param nCol,matriz
	\pre Ninguna
	\post Ninguna
*/

	
void liberarMemoriaMatrizInt(int nCol, int **matriz)
{
	for ( int i = 0 ; i < nCol ; i++ )// Elimino cada vector de la matriz
    {
   		 delete matriz[i];  // Borramos los objetos creados con matriz[i]=new int[nCol];;
    }
  		delete matriz; // Borramos el objeto creado con matriz=new int*[nFil];
}