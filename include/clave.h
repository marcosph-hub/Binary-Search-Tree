//#pragma once
#ifndef CLAVE_H__
#define CLAVE_H__

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

class Clave {

  private:

    int numeric_value;
    std::pair<char,char> dni_symbols;

  public:

  Clave();
  Clave(int param_numeric, std::pair<char,char> param_symbols);
  ~Clave();
  int getClave(); 
  void setClave(Clave parameter);
  int getNumeric_Value();
  std::pair<char,char> getSymbols();
  int getFirst_Symbol();
  int getSecond_Symbol();
  void setNumeric_Value(int parameter);
  void setSymbols(std::pair<char,char> parameter);
  bool operator<(Clave &parameter);
  Clave& operator=(const Clave &parameter);
  bool operator==(const Clave &parameter) const;
  friend std::ostream& operator<<(std::ostream& os,  Clave parameter);
  
};
#endif 