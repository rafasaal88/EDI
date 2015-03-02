#include "cabecera.hpp"

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


