#include "../include/clave.h"

Clave::Clave() {
  srand(time(NULL));
  numeric_value = 100 +rand() % (999 - 100);
  dni_symbols.first = 65 + rand() % (91 - 65);
  dni_symbols.second = 65 + rand() % (91 - 65);
}

Clave::Clave(int param_numeric, std::pair<char,char> param_symbols) {
  numeric_value = param_numeric;
  dni_symbols = param_symbols;
}

Clave::~Clave(){}

int Clave::getClave() {
  int numeric_dni = numeric_value + dni_symbols.first + dni_symbols.second;
  return numeric_dni;
}

void Clave::setClave(Clave parameter) {
  this->numeric_value = parameter.numeric_value;
  this->dni_symbols = parameter.dni_symbols;
}

int Clave::getNumeric_Value() {
  return numeric_value;
}

std::pair<char,char> Clave::getSymbols() {
  return dni_symbols;
}

int Clave::getFirst_Symbol() {
  int ASCII_symbol = dni_symbols.first;
  return ASCII_symbol;
}

int Clave::getSecond_Symbol() {
  int ASCII_symbol = dni_symbols.second;
  return ASCII_symbol;
}

void Clave::setNumeric_Value(int parameter) {
  numeric_value = parameter;
}

void Clave::setSymbols(std::pair<char,char> parameter) {
  dni_symbols.first = parameter.first;
  dni_symbols.second = parameter.second;
}


bool Clave::operator<(Clave &parameter) {
  if (this->getFirst_Symbol() < parameter.getFirst_Symbol()){
    return true;
  } else if (this->getFirst_Symbol() > parameter.getFirst_Symbol()) {
    return false;
  } else if (this->getClave() < parameter.getClave()) {
    return true;
  } else { return false; }
}

Clave& Clave::operator=(const Clave &parameter) {
  this -> numeric_value = parameter.numeric_value;
  this -> dni_symbols = parameter.dni_symbols;
  return *this;
}

bool Clave::operator==(const Clave &parameter) const {
  if ( this -> numeric_value == parameter.numeric_value &&
       this -> dni_symbols.first == parameter.dni_symbols.first &&
       this -> dni_symbols.second == parameter.dni_symbols.second) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, Clave parameter) {
  os << parameter.getSymbols().first << parameter.getNumeric_Value() << parameter.getSymbols().second << "  "; 
  return os;
}
