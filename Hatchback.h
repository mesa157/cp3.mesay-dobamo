#ifndef HATCHBACK_H
#define HATCHBACK_H

#include "Car.h"

class Hatchback : public Car {
public:
   Hatchback(std::string model, std::string number, double cost, std::string description)
      : Car(model, number, cost, description)
      {}
   virtual std::string type() const override {
      return "Hatchback";
   }
};

#endif