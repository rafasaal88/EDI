ifstream &operator>>(ifstream& in, BinaryTree<edi::Clave> *t)
{
 
  string token; // recoger el token '(' ')' o ':'
  string dato; // recoge el dato en la forma dni,pos
  int split; // para separar dni y posicion por la coma.
 
  vector<int> v;
 
  Clave aux; // Guardar el dato recogido e insertarlo en el arbol.
  Clave vacio; // Crear un arbol derecho/izquierdo vacio.
 
 
  in >> token; // Se lee el primer token que debe empezar por '('
 
  // cout << "token1: " << token << endl;
 
 
  in >> dato; // Seguidamente el dato
 
  // cout << "dato: " << dato << endl;
 
 
  // Para separar el dni y la posicion.
  stringstream ss(dato);
 
  while (ss >> split)
  {
 
   v.push_back(split);
 
      if (ss.peek() == ',')
          ss.ignore();
  }
 
  // Insertamos en la Clave y sacamos del vector.
  aux.dni(v[0]);
  aux.posicion(v[1]);
  v.pop_back();
  v.pop_back();
 
 
  // Si el arbol esta vacio, creamos la raiz con ese dato.
  if ( t->isEmpty() and not t->isSubTree() )
     t->createRoot(aux);
 
  // En caso contrario, insertamos donde corresponda.
  else
     t->setItem(aux);
 
 
  in >> token;
  // cout << "token2: " << token << endl;
 
  if (token == "(" ) // Hay subarbol izquierdo
  {
    in.putback('('); // lo devolvemos al buffer para que vuelva a leerlo en la llamada.
    t->createLeftSubTree(vacio);
    in >> t->leftSubTree();
  }
 
  if (token == ":" ) {}
 
  in >> token;
  // cout << "token3: " << token << endl;
 
 
  if (token == "(" ) // Hay subarbol izquierdo
  {
    in.putback('(');
    t->createRightSubTree(vacio);
    in >> t->rightSubTree();
  }
 
  if (token == ":" ){}
 
  in >> token;
 
  // cout << "token4: " << token << endl;
 
 
  return in;
 
}