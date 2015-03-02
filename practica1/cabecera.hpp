#ifndef CABECERA_H
#define CABECERA_H

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

#endif