#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

class ClaveNumber {
  private:
    int value;

  public:
    ClaveNumber();
    ClaveNumber(int newValue);
    ~ClaveNumber();
    int getValue() const;
    void setValue(int parametre);
    ClaveNumber& operator=(const ClaveNumber &parameter);
    bool operator==(const ClaveNumber &parameter) const;
    friend std::ostream& operator<<(std::ostream& os,  ClaveNumber parameter);
};