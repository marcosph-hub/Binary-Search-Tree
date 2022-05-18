#pragma once

#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include "../include/node.h"
//#include "node.cc"
template <class Clave>
class Arbol_Bin {
  private:
    Nodo *root;

  public:
    Arbol_Bin(): root(NULL) {}
    ~Arbol_Bin();
    Nodo* getRoot();
    void Podar(Nodo* parametre);
    bool IsEmpty(Nodo *parametre);
    bool IsLeaf(Nodo *parametre);
    int TreeSize();
    int BranchSize(Nodo *parametre);
    int TreeHeight();
    int BranchHeight(Nodo *parametre);
    bool TreeBalanced();
    bool BranchBalanced(Nodo *parametre);
    void TreeInsertionBal(Clave data);
    void BranchInsertionBal(Clave data, Nodo *parametre, int level);
    void Printer(Nodo *parametre, int level);
    void ExploreByLevels(Nodo *paremeter);
    bool Search(Clave data);
    bool RecursiveSearch(Clave data, Nodo* parametre);
    void Remove(Clave data);
    void RemoveBranch(Nodo* parametre, Clave data);
    void Replace(Nodo* removed, Nodo* replaced);
};
