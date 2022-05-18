#include "../include/arbol_bin.h"
template <class Clave>
Arbol_Bin<Clave>::~Arbol_Bin()
{
  Podar(root);
}
template <class Clave>
Nodo* Arbol_Bin<Clave>::getRoot() {
  return root;
}
template <class Clave>
void Arbol_Bin<Clave>::Podar(Nodo* parametre) {
  if (parametre == NULL)
    return;
  Podar(parametre->getLeftNode()); 
  Podar(parametre->getRightNode());
  delete parametre;
  parametre = NULL;
}

template <class Clave>
bool Arbol_Bin<Clave>::IsEmpty(Nodo *parametre) {
  return parametre == NULL;
}

template <class Clave>
bool Arbol_Bin<Clave>::IsLeaf(Nodo *parametre) {
  return IsEmpty(parametre);

}

template <class Clave>
int Arbol_Bin<Clave>::TreeSize() {
  return BranchSize(root);
}

template <class Clave>
int Arbol_Bin<Clave>::BranchSize(Nodo *parametre) {
  if (parametre == NULL) return 0;
  return (1 + BranchSize(parametre->getLeftNode()) + BranchSize(parametre->getRightNode()));
}

template <class Clave>
int Arbol_Bin<Clave>::TreeHeight() {
  return BranchHeight(root);
}

template <class Clave>
int Arbol_Bin<Clave>::BranchHeight(Nodo *parametre) {
  if (parametre == NULL) return 0;
  int left_height = BranchHeight(parametre->getRightNode());
  int right_height = BranchHeight(parametre->getLeftNode());
  if (right_height > left_height) return right_height++;
  else return left_height++;
}

template <class Clave>
bool Arbol_Bin<Clave>::TreeBalanced() {
  return BranchBalanced(root);
}

template <class Clave>
bool Arbol_Bin<Clave>::BranchBalanced(Nodo *parametre){
  if (parametre == NULL) return true;
  int balance = BranchSize(parametre->getLeftNode()) - BranchSize(parametre);
  switch (balance){
    case -1:
    case 0: 
    case 1:
      return BranchBalanced(parametre->getLeftNode()) && BranchBalanced(parametre -> getRightNode());
    default: return false;
  }
}

template <class Clave>
void Arbol_Bin<Clave>::TreeInsertionBal(Clave data) {
  int level = 0;
  if(root == NULL) {
    root = new Nodo(data, NULL, NULL);

  }
  else BranchInsertionBal(data, root, level+1);
}

template <class Clave>
void Arbol_Bin<Clave>::BranchInsertionBal(Clave data, Nodo *parametre, int level)  {

  if(parametre == NULL) {
    parametre = new Nodo(data);
  }
  else if (data < parametre->getData()) {
    if (parametre -> getLeftNode() !=NULL) { 
      BranchInsertionBal(data, parametre -> getLeftNode(), level+1); 
    }
    else { 
      Nodo *auxiliar = new Nodo(data, NULL, NULL);
      parametre -> setLeftNode(auxiliar);
     }
  }
  else {
    if (parametre == NULL) {
      Nodo *auxiliar = new Nodo(data, NULL, NULL);
      parametre -> setLeftNode(auxiliar);
    } else if (data < parametre->getData()) {
      BranchInsertionBal(data, parametre -> getRightNode(), level+1); 
    } else {
      BranchInsertionBal(data, parametre -> getLeftNode(), level+1); 
    }
    
    if (parametre -> getRightNode() !=NULL) { 

      BranchInsertionBal(data, parametre -> getRightNode(), level+1); 
    }
    else {
      Nodo *auxiliar = new Nodo(data, NULL, NULL);
      parametre -> setRightNode(auxiliar);
    }
  }
}

template <class Clave>
void Arbol_Bin<Clave>::Remove(Clave data) {
  RemoveBranch(root, data);
}

template <class Clave>
void Arbol_Bin<Clave>::RemoveBranch(Nodo* parametre, Clave data) {
  if(parametre == NULL) {
    std::cout << "Fatal error. Node dont exist" << std::endl;
    exit(1);
  };
  if(data < parametre->getData()){
    RemoveBranch(parametre->getLeftNode(),data);
  } else if (data > parametre->getData()) {
    RemoveBranch(parametre->getRightNode(),data);
  } else {
    Nodo* Eliminado = parametre;
    if(parametre->getRightNode() == NULL) {
      parametre = parametre->getLeftNode();
    } else if(parametre->getLeftNode() == NULL) {/*
      parametre = parametre->getRightNode();
*/
    } else {
      Replace(Eliminado, parametre->getLeftNode());
    }
    delete (Eliminado);
    
  }
}

template <class Clave>
void Arbol_Bin<Clave>::Replace(Nodo* removed, Nodo* replaced) {
/*
  if (replaced->getRightNode() != NULL) {
    Replace(removed, replaced->getRightNode());
  } else {
    removed->getData() = replaced->getData();
    removed = replaced;
    replaced = replaced->getLeftNode();
  }
*/
}


template <class Clave>
bool Arbol_Bin<Clave>::Search(Clave data) {
  return RecursiveSearch(data, root);
}

template <class Clave>
bool Arbol_Bin<Clave>::RecursiveSearch(Clave data, Nodo* parametre)  {
  if(parametre != NULL && parametre -> getData() == data){
    return true;
  } if (parametre != NULL) {
    bool aux = false;
    aux = RecursiveSearch(data, parametre -> getLeftNode());
    if(aux) return aux;
    aux = RecursiveSearch(data, parametre -> getRightNode());
    if(aux) return aux;
   }
  return false;
}

template <class Clave>
void Arbol_Bin<Clave>::ExploreByLevels(Nodo *paremeter) {
  std::queue <std::pair <Nodo*,int>> cola;
  int nivel_actual = 0;
  cola.push(std::make_pair(paremeter, nivel_actual));
  while (!cola.empty()) {
    bool check = false;
    std::pair <Nodo*, int> copy = cola.front();
    cola.pop(); 
    if(copy.second > nivel_actual) {
      check = true;
      nivel_actual = copy.second;
    }
    if(copy.first != NULL) {
      if(check) {
        std::cout << std::endl;
        std::cout  << copy.first;
      } else {
        std::cout << copy.first;
      }
      cola.push(std::make_pair(copy.first ->getLeftNode(), copy.second+1));
      cola.push(std::make_pair(copy.first ->getRightNode(), copy.second+1));
    } else {
      if(check) {
        std::cout << std::endl;
        std::cout << "[Ø]";
      } else {
        std::cout << "[Ø]";
      }
    }
  }
}