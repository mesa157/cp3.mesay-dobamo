#ifndef MINIVAN_H
#define MINIVAN_H

#include "Car.h"

class Minivan : public Car {
public:
   Minivan(std::string model, std::string number, double cost, std::string description)
      : Car(model, number, cost, description)
      {}
   virtual std::string type() const override {
      return "Minivan";
   }
};

#endif