//#pragma once
#ifndef NODE_H__
#define NODE_H__

#include <iostream>
#include "../include/clave.h"
//#include "clave.cc" 

class Nodo{

  private:
    Clave data;
    Nodo *left_node;
    Nodo *right_node;
  
  
  public:
  
    Nodo(Clave data_parameter, Nodo *left_parameter=NULL, Nodo *right_parameter=NULL):
    data(data_parameter), 
    left_node(left_parameter), 
    right_node(right_parameter)
    {}
    ~Nodo();
    Clave& getData();
    Nodo* getLeftNode();
    Nodo* getRightNode();
    void setData(const Clave parameter);
    void setLeftNode(Nodo *parameter);
    void setRightNode(Nodo *parameter);
    Nodo* operator=(Nodo *parameter);
    bool operator==(Nodo *parameter) const;
    friend std::ostream& operator<<(std::ostream& os, Nodo *parameter);
    

};
#endif
