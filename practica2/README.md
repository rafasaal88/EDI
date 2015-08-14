# EDI-PRACTICA2"
+ Programa
Funciona correctamente, pero no ha incluido la opción para modificar los datos de una pesona

No ha incluido los asertos o postcondiciones de la función "inserta"

Se deben incluir comentarios dentro del código para explicar los casos posibles.
Por ejemplo, en la función "inserta"
- Lista vacía
- Insertar al principio
- Insertar en medio
- Insertar al final

+ Makefile: correcto

+ Doxygen
Los comentarios de los párametros de las funciones tiene el formato
@param nombre_parámetro Descripción...

Se deben comentar todas las funciones de las clases.

También se deben comentar las funciones auxiliares.

Los prototipos siguientes deberían estar un un fichero funciones.hpp

void crearAsignatura(Listadoble<Persona> &lista);
void mostrarAscendentemente(const Listadoble<Persona> &lista );
void mostrarDescendentemente(const Listadoble<Persona> &lista );
void mostrarEntreAscendentemente(const Listadoble<Persona> &lista );
void mostrarEntreDescendentemente(const Listadoble<Persona> &lista );
void modificar(Listadoble<Persona> &lista);
