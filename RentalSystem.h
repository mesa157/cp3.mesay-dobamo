#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <vector>
#include "Car.h"
#include "Customer.h"

class RentalSystem {
public:
   RentalSystem() = default;

   void loadCars(const std::string& filename);
   void printMenu() const;
   void printCars() const;
   bool rentCar(Customer& customer, std::size_t i);

private:
   std::vector<Car*> m_cars;
};

#endif