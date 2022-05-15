#include "../include/arbol_bin.h"

Arbol_Bin::~Arbol_Bin()
{
  Podar(root);
}

Nodo* Arbol_Bin::getRoot() {
  return root;
}

void Arbol_Bin::Podar(Nodo* parameter) {
  if (parameter == NULL)
    return;
  Podar(parameter->getLeftNode()); 
  Podar(parameter->getRightNode());
  delete parameter;
  parameter = NULL;
}

bool Arbol_Bin::IsEmpty(Nodo *parameter) {
  return parameter == NULL;
}

bool Arbol_Bin::IsLeaf(Nodo *parameter) {
  return IsEmpty(parameter);

}

int Arbol_Bin::TreeSize() {
  return BranchSize(root);
}

int Arbol_Bin::BranchSize(Nodo *parameter) {
  if (parameter == NULL) return 0;
  return (1 + BranchSize(parameter->getLeftNode()) + BranchSize(parameter->getRightNode()));
}

int Arbol_Bin::TreeHeight() {
  return BranchHeight(root);
}

int Arbol_Bin::BranchHeight(Nodo *parameter) {
  if (parameter == NULL) return 0;
  int left_height = BranchHeight(parameter->getRightNode());
  int right_height = BranchHeight(parameter->getLeftNode());
  if (right_height > left_height) return right_height++;
  else return left_height++;
}

bool Arbol_Bin::TreeBalanced() {
  return BranchBalanced(root);
}

bool Arbol_Bin::BranchBalanced(Nodo *parameter){
  if (parameter == NULL) return true;
  int balance = BranchSize(parameter->getLeftNode()) - BranchSize(parameter);
  switch (balance){
    case -1:
    case 0: 
    case 1:
      return BranchBalanced(parameter->getLeftNode()) && BranchBalanced(parameter -> getRightNode());
    default: return false;
  }
}

void Arbol_Bin::TreeInsertionBal(Clave data) {
  int level = 0;
  if(root == NULL) {
    root = new Nodo(data, NULL, NULL);

  }
  else BranchInsertionBal(data, root, level+1);
}

void Arbol_Bin::BranchInsertionBal(Clave data, Nodo *parameter, int level)  {
  if (BranchSize(parameter -> getLeftNode()) <= BranchSize(parameter -> getRightNode())) {
    if (parameter -> getLeftNode() !=NULL) { 
      BranchInsertionBal(data, parameter -> getLeftNode(), level+1); 
    }
    else { 
      Nodo *auxiliar = new Nodo(data, NULL, NULL);
      parameter -> setLeftNode(auxiliar);
     }
  }
  else {
    if (parameter -> getRightNode() !=NULL) { 

      BranchInsertionBal(data, parameter -> getRightNode(), level+1); 
    }
    else {
      Nodo *auxiliar = new Nodo(data, NULL, NULL);
      parameter -> setRightNode(auxiliar);
    }
  }
}

void Arbol_Bin::Printer(Nodo *parameter, int level) {
  if (parameter == NULL) return;
  std::cout <<"Nivel " << level << parameter << std::endl;
  Printer(parameter -> getLeftNode(), level+1);
  Printer(parameter -> getRightNode(), level+1);
}


void Arbol_Bin::ExploreByLevels(Nodo *paremeter) {
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
        std::cout << "\nNivel: " << copy.second << std::endl;
        std::cout  << copy.first;
      } else {
        std::cout << copy.first;
      }
      cola.push(std::make_pair(copy.first ->getLeftNode(), copy.second+1));
      cola.push(std::make_pair(copy.first ->getRightNode(), copy.second+1));
    } else {
      if(check) {
        std::cout << "\nNivel: " << copy.second << std::endl;
        std::cout << "[Ø]";
      } else {
        std::cout << "[Ø]";
      }
    }
  }
}


bool Arbol_Bin::Search(Clave data) {
  return RecursiveSearch(data, root);
}

bool Arbol_Bin::RecursiveSearch(Clave data, Nodo* parameter)  {
  if(parameter != NULL && parameter -> getData() == data){
    return true;
  } if (parameter != NULL) {
    bool aux = false;
    aux = RecursiveSearch(data, parameter -> getLeftNode());
    if(aux) return aux;
    aux = RecursiveSearch(data, parameter -> getRightNode());
    if(aux) return aux;
   }
  return false;
}

