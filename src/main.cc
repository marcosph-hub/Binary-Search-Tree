#include <iostream>
#include <cstdlib>
//#include "node.h"
#include "../include/arbol_bin.h"
//#include "arbol_bin.cc"


Clave RandomGenerator() {
  
  std::pair<char,char> symbols;
  symbols.first = 65 + rand() % (91 - 65);
  symbols.second = 65 + rand() % (91 - 65);
  int value = 1000000 +rand() % (9999999 - 1000000);
  Clave auxiliar(value, symbols);  
  return auxiliar;
}


Clave ManualGenerator() {
  char first_letter, second_letter;
  int dni_number;
  std::pair<char,char> dni_symbols;

  std::cout << "Primera letra del DNI: ";
  std::cin >> first_letter;
  std::cout << "Valores numéricos del DNI: ";
  std::cin >> dni_number;
  std::cout << "Última letra del DNI: ";
  std::cin >> second_letter;
  std::cout << std::endl << std::endl << std::endl;

  dni_symbols.first = first_letter;
  dni_symbols.second = second_letter;
  Clave auxkey(dni_number, dni_symbols);

  return auxkey;
}


int main () {

srand(time(0));
  int option;
  bool repeat = true;
  Arbol_Bin arbolB;
  do
  {
    std::cout << "\n\nMenú de Opciones: " << std::endl;
    std::cout << "[0] Salir." << std::endl;
    std::cout << "[1] Insertar Clave." << std::endl;
    std::cout << "[2] Buscar Clave." << std::endl;
    std::cin >> option;
    
    switch (option)
    {
    case 1: {
      int opt;
      std::cout << "[1] Clave Manual." << std::endl;
      std::cout << "[2] Clave Aleatoria." << std::endl;
      std::cin >> opt;

      if(opt == 1) {
        arbolB.TreeInsertionBal(ManualGenerator());
      } else if( opt == 2) {
        arbolB.TreeInsertionBal(RandomGenerator());
      } else std::cout << "ERROR.Opcion Incorrecta." << std::endl;      
      arbolB.ExploreByLevels(arbolB.getRoot());
    }
      break;

    case 2: {
      std::cout << "Opción Buscar Clave" << std::endl;
      std::cout << "Clave a buscar: " << std::endl;
      Clave param = ManualGenerator();
      bool comprob = arbolB.Search(param);
      if (comprob) { std::cout << "Clave encontrada!" << std::endl; }
      else std::cout << "No se ha encontrado." << std::endl;
    }
      break;
 
    case 0: {
      repeat = false;
    }
      break;
    
    default:
      std::cout << "ERROR.Opción no válida." << std::endl;
      break;
    }
  } while (repeat);
  


  return 0;
}