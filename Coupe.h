#ifndef COUPE_H
#define COUPE_H

#include "Car.h"

class Coupe : public Car {
public:
   Coupe(std::string model, std::string number, double cost, std::string description)
      : Car(model, number, cost, description)
      {}
   virtual std::string type() const override {
      return "Coupe";
   }
};

#endif