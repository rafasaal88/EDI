OBJECTS = main.o funciones.o persona.o generarpersona.o


main: $(OBJECTS)
	g++ -o programa.exe  $(OBJECTS)
	

main.o: main.cpp funciones.hpp lista.hpp nododoble.hpp
	g++ -c  main.cpp 

funciones.o: funciones.cpp funciones.hpp lista.hpp nododoble.hpp
	g++ -c  funciones.cpp 

persona.o: persona.cpp persona.hpp
	g++ -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp 
	g++ -c generarpersona.cpp

clean:
	rm -f  $(OBJECTS) *~