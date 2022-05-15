#pragma once

#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include "../include/node.h"
//#include "node.cc"

class Arbol_Bin {
  private:
    Nodo *root;

  public:
    Arbol_Bin(): root(NULL) {}
    ~Arbol_Bin();
    Nodo* getRoot();
    void Podar(Nodo* parameter);
    bool IsEmpty(Nodo *parameter);
    bool IsLeaf(Nodo *parameter);
    int TreeSize();
    int BranchSize(Nodo *parameter);
    int TreeHeight();
    int BranchHeight(Nodo *parameter);
    bool TreeBalanced();
    bool BranchBalanced(Nodo *parameter);
    void TreeInsertionBal(Clave data);
    void BranchInsertionBal(Clave data, Nodo *parameter, int level);
    void Printer(Nodo *parameter, int level);
    void ExploreByLevels(Nodo *paremeter);
    bool Search(Clave data);
    bool RecursiveSearch(Clave data, Nodo* parameter);
};
