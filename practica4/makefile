OBJECTS = entrada_salida.o algoritmos.o funciones.o main.o
CPPFLAGS = -c -g -ansi -Wall

practica4 : $(OBJECTS)
	g++ $(OBJECTS) -o practica4

main.o: main.cpp entrada_salida.hpp vertex.hpp graph_matrix.hpp algoritmos.hpp cabecera.hpp
	g++ $(CPPFLAGS) main.cpp

entrada_salida.o : entrada_salida.cpp entrada_salida.hpp
	g++ $(CPPFLAGS) entrada_salida.cpp

algoritmos.o : algoritmos.hpp
	g++ $(CPPFLAGS) algoritmos.cpp

funciones.o : cabecera.hpp
	g++ $(CPPFLAGS) funciones.cpp

clean :
	rm -f *.o
