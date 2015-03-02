#include "cabecera.hpp"

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
	//	contorno.pop_back();

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
	//aproximacion.pop_back();


	fichero1.close();

}



double error(const vector<Punto2D> &contorno, const vector<int> &aproximacion)
{
	double error=0.0;

	for(int i=0; i<aproximacion.size()-1; i++){

			int aprox1=aproximacion[i];
			int aprox2=aproximacion[(i+1) % aproximacion.size()];

			Punto2D puntoinicial=Punto2D(contorno[aprox1]);
			Punto2D puntofinal=Punto2D(contorno[aprox2]);
			Recta2D recta=Recta2D(puntoinicial, puntofinal);

			


			if(aprox1<aprox2)
			{

				for(int j=aprox1+1; j<aprox2; j++){

					error+=pow(recta.distancia(contorno[j]),2);

				}

			}

			else
			{	
				for(int k=aprox1+1; k<contorno.size(); k++){
					error+=pow(recta.distancia(contorno[k]), 2);
				}

				for(int l=0; l<aprox2; l++){
					error+=pow(recta.distancia(contorno[l]), 2);
				}		
			}			
		}
		return error;
}