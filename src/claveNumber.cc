#include "../include/claveNumber.h"
ClaveNumber::ClaveNumber() {
  srand(time(0));
  int randValue = (rand()%1)+50;
  value = randValue;
}

ClaveNumber::ClaveNumber(int parametre) {
  value = parametre;
}

ClaveNumber::~ClaveNumber() {}

int ClaveNumber::getValue() const {
  return value;
}

void ClaveNumber::setValue(int parametre) {
  value = parametre;
}

ClaveNumber& ClaveNumber::operator=(const ClaveNumber &parametre) {
  this->value = parametre.value;
  return *this;
}

bool ClaveNumber::operator==(const ClaveNumber &parametre) const {
  if (this->value == parametre.value){
    return true;
  } else { 
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, ClaveNumber parametre) {
  os << parametre.getValue() << " ";
  return os;
}