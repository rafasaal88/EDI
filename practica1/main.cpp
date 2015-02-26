#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "punto2D.hpp"
#include "recta.hpp"

using namespace std;
using namespace ed;

void cargarcontorno(vector <Punto2D> &contorno, string fichero);
void cargaraproximacion(vector <int> &aproximacion, string fichero);
double error(const vector<Punto2D> &contorno, const vector<int> &aproximacion);

int main()
{

	vector <Punto2D> contorno;
	vector <int> aproximacion;
	double error_=0.0;

	string ficherocontorno="abrelatas.txt";
	string aproxpoligonal="aproximacion.txt";

	cargarcontorno(contorno, ficherocontorno);
	cargaraproximacion(aproximacion, aproxpoligonal);
	
	error_=error(contorno, aproximacion);

	cout << "El error es: " << error_ << "\n";

return 0;
}


void cargarcontorno(vector <Punto2D> &contorno, string fichero)
{
	double x, y;
	ifstream fichero1;
	fichero1.open(fichero.c_str());
	
	if(!fichero1)
		cout << "No se puede abrir el fichero";

	while(fichero1 >> x >> y)
	{
	 	Punto2D punto(x, y);

	 	contorno.push_back(punto);

	}
		

	fichero1.close();

}

void cargaraproximacion(vector <int> &aproximacion, string fichero)
{
	double x;
	ifstream fichero1;
	fichero1.open(fichero.c_str());

	if(!fichero1)
		cout << "No se puede abrir el fichero";

	while(fichero1 >> x)
	{

		aproximacion.push_back(x);
	}
		aproximacion.pop_back();


	fichero1.close();

}



double error(const vector<Punto2D> &contorno, const vector<int> &aproximacion)
{
	double error=0.0;

	for(int i=0; i<aproximacion.size()-1; i++){

		Punto2D puntoinicial=contorno[aproximacion[i]];
		Punto2D puntofinal=contorno[aproximacion[i+1]];
		Recta2D recta=Recta2D(puntoinicial, puntofinal);

		if(aproximacion[i]<aproximacion[i+1]){

			for(int j=aproximacion[i]+1; j<aproximacion[i+1]; j++){

				error+=pow(recta.distancia(contorno[j]),2);

			}

		}

		else{
			for(int k=aproximacion[i]; k<aproximacion[contorno.size()-1]; k++){
				error+=pow(recta.distancia(contorno[k]), 2);
			}

			for(int l=0; l<aproximacion[i]; l++){
				error+=pow(recta.distancia(contorno[l]), 2);
			}
	
		}

		
		
	}
	return error;	
}