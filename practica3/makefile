OBJECTS = main.o funciones.o clave.o persona.o generarpersona.o


main: $(OBJECTS) 
	g++ -o ejercicio3  $(OBJECTS)
	

main.o: main.cpp funciones.hpp listaDoble.hpp nodoDoble.hpp
	g++ -c  main.cpp 

funciones.o: funciones.cpp funciones.hpp listaDoble.hpp nodoDoble.hpp edi_exports.hpp edi_OrderedBinaryTree.hpp edi_LinkedBinaryTree.hpp edi_BinaryTree.hpp edi_LinkedBinaryTreeNode.hpp clave.hpp
	g++ -c  funciones.cpp 

persona.o: persona.cpp persona.hpp
	g++ -c persona.cpp

clave.o: clave.cpp clave.hpp
	g++ -c clave.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp 
	g++ -c generarpersona.cpp

clean:
	rm -f  $(OBJECTS) *~

