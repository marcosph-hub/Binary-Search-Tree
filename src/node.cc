#include "../include/node.h"

Nodo::~Nodo() {}

Clave Nodo::getData() {
  return data;
}

Nodo* Nodo::getLeftNode() {
  return left_node;
}

Nodo* Nodo::getRightNode() {
  return right_node;
}

void Nodo::setData (const Clave parameter){
  data = parameter; 
}

void Nodo::setLeftNode(Nodo *parameter) {
  left_node = parameter;
}

void Nodo::setRightNode(Nodo *parameter) {
  right_node = parameter;
}

Nodo* Nodo::operator=(Nodo *parameter) {
  this -> data = parameter->getData();
  this -> left_node = parameter->getLeftNode();
  this -> right_node = parameter->getRightNode();
  return this;
}

bool Nodo::operator==( Nodo *parameter) const {
  if ( this -> data == parameter->getData() &&
       this -> left_node == parameter->getLeftNode() &&
       this -> right_node == parameter->getRightNode()) { 
    return true; 
  } else { 
      return false;
  }
}

std::ostream& operator<<(std::ostream &os, Nodo *parameter) {
  os << "[ " << parameter->getData() << "]";
  return os;

}
