#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Car.h"

// Customer class
class Customer 
{
public:
   Customer(std::string name);

   void setTotal(double total);
   double total() const;
   std::string name() const;
   Car* car() const;

   bool rentCar(Car* car, int days);


private:
   std::string m_name; // name of customer
   double m_total{0}; // total money
   Car* m_car{nullptr}; // rented car
   int m_days{0}; // rented car days
};

#endif