#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

class Sedan : public Car {
public:
   Sedan(std::string model, std::string number, double cost, std::string description)
      : Car(model, number, cost, description)
      {}
   virtual std::string type() const override {
      return "Sedan";
   }
};

#endif